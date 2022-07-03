import json
import os, sys
from socket import *
from getch import KBHit
from encryption import EncryptionSession
import secrets
import ast
from base64 import b64encode, b64decode
import time

# Crossplatform util. function for fetching single-char input.
kb = KBHit()

class Chat():
    def __init__(self, config, self_key, target_key):
        # Info about target
        self.target_addr = (config[target_key]['ip'], int(config[target_key]['port']))

        # Config socket state
        self_addr = (config[self_key]['ip'], int(config[self_key]['port']))
        self.sock = socket(AF_INET, SOCK_DGRAM)
        self.sock.bind(self_addr)
        self.sock.setblocking(0) # Non-blocking

        # Default messaging data states
        self.received_data = ''
        self.data_to_be_sent = ''
        self.should_send = False

        self.session = EncryptionSession()


    def _receive_data(self):
        try:
            (data, address) = self.sock.recvfrom(1024*10)
            decoded = data.decode()
            if decoded:
                self.received_data = decoded
            return decoded
        except:
            return ""


    def _get_or_send_input_data(self):
        self.data_to_be_sent, self.should_send, changed = self._iterate_keyboard_input(self.data_to_be_sent)
        if self.should_send and self.session.done:
            self.sock.sendto(self.data_to_be_sent.encode(), self.target_addr)
            self.data_to_be_sent = ''  # Flush
        return (self.should_send, changed)


    def loop_auth_as_first(self):
        sesh = self.session
        cond = sesh.AES_key and sesh.RSA_private_key and sesh.RSA_public_key and sesh.done
        while (not cond):
            cond = sesh.AES_key and sesh.RSA_private_key and sesh.RSA_public_key and sesh.done
            if sesh.stage == 0: 
                print("Sending RSA pub key and waiting encrypted AES...")
                if not sesh.RSA_public_key and not sesh.RSA_private_key:
                    sesh.RSA_generate_keys()
                self.sock.sendto(f'PUB:{sesh.RSA_public_key}'.encode(), self.target_addr) 
                try:
                    (data, address) = self.sock.recvfrom(1024*10)
                    decoded = data.decode()
                    if decoded.startswith("AES:"):
                        enc_AES_key = decoded.replace("AES:", '')
                        tmp = ast.literal_eval(enc_AES_key) 
                        sesh.AES_key = sesh.AES_str_to_key(sesh.RSA_decrypt(tmp))
                        sesh.stage = 1
                except:
                    pass
            if sesh.stage == 1:
                print("Sending encrypted private key and waiting confirmation...")
                enc_priv = sesh.AES_encrypt(sesh.RSA_private_key)
                self.sock.sendto(f'PRIV:{enc_priv}'.encode(), self.target_addr) 
                try:
                    (data, address) = self.sock.recvfrom(1024*10)
                    decoded = data.decode()
                    if decoded == "!!OK!!":
                        sesh.done = True
                        self.sock.sendto('Hello! I joined the chat.'.encode(), self.target_addr)
                        return True
                except:
                    pass


    def loop_auth_as_second(self):
        sesh = self.session
        sesh.AES_key = secrets.token_bytes(32) 
        cond = sesh.AES_key and sesh.RSA_private_key and sesh.RSA_public_key and sesh.done
        while (not cond):
            cond = sesh.AES_key and sesh.RSA_private_key and sesh.RSA_public_key and sesh.done
            if sesh.stage == 0:
                print("Waiting for public key...")
                try:
                    (data, address) = self.sock.recvfrom(1024*10)
                    decoded = data.decode()
                    if decoded.startswith("PUB:"):
                        sesh.RSA_public_key = decoded.replace("PUB:", '')
                        sesh.stage = 1
                        print("Pub key received.")
                except:
                    pass
            if sesh.stage == 1: 
                print("Sending encrypted AES and waiting for encrypted private key...")
                AES_hidden = sesh.RSA_encrypt(sesh.AES_key_to_str())
                self.sock.sendto(f'AES:{AES_hidden}'.encode(), self.target_addr)
                try:
                    (data, address) = self.sock.recvfrom(1024*10*10)
                    decoded = data.decode()
                    if decoded.startswith("PRIV:"):
                        encrypted_priv = decoded.replace("PRIV:", '')
                        sesh.RSA_private_key = sesh.AES_decrypt(ast.literal_eval(encrypted_priv))
                        sesh.stage = 2
                        print("Private key received.")
                except:
                    pass
            if sesh.stage == 2: 
                print("Sending ok 200 times seconds")
                for i in range(1000):
                    self.sock.sendto('!!OK!!'.encode(), self.target_addr)
                sesh.done = True
                self.sock.sendto('Hello! I joined the chat.'.encode(), self.target_addr)
                return True


    def _receive_data_post(self):
        try:
            (data, address) = self.sock.recvfrom(1024*10)
            decoded = data.decode()
            if decoded:
                if decoded.startswith('CRIP:'):
                    thing = self.session.RSA_decrypt(ast.literal_eval(decoded.replace('CRIP:', '')))
                    self.received_data = thing
                    return thing
            return decoded
        except:
            return ""


    def _get_or_send_input_data_post(self):
        self.data_to_be_sent, self.should_send, changed = self._iterate_keyboard_input(self.data_to_be_sent)
        if self.should_send and self.session.done:
            data = self.session.RSA_encrypt(self.data_to_be_sent)
            self.sock.sendto(f'CRIP:{data}'.encode(), self.target_addr)
            self.data_to_be_sent = ''  # Flush
        return (self.should_send, changed)


    def ping(self, i):
        prev_message = str(self.received_data)
        rec = self._receive_data_post()
        is_message_new = False if rec == "" else prev_message != rec
        was_sent, changed = self._get_or_send_input_data_post()

        changed = is_message_new or changed
        # Screen feedback
        if i == 0 or changed:
            chat._clear_terminal()
            print(f'*** TICK: {i} ///// TYPE "EXIT" TO QUIT ***\n')
            print(f'You are writing: {self.data_to_be_sent}')
            print(f'Last received message: "{self.received_data}"')


    def end(self):
        self.sock.close()


    def _iterate_keyboard_input(self, data_buffer):
        is_windows = os.name == 'nt'
        BACKSPACE = 8 if is_windows else 127
        ENTER = 13 if is_windows else 10
        ESC = 27

        if kb.kbhit():
            try:
                ch = kb.getch()
                code = ord(ch)
                if code == BACKSPACE:
                    return (data_buffer[:-1], False, True)
                elif code == ENTER:
                    return (data_buffer, True, True)
                elif code == ESC:
                    # Finish program
                    kb.set_normal_term()
                    self.end()
                    os._exit(0)
                else:
                    return (data_buffer+ch, False, True)
            except:
                return (data_buffer, False, False)
        else:
            return (data_buffer, False, False)

    def _clear_terminal(self):
        # check and make call for specific operating system
        os.system('cls' if os.name == 'nt' else 'clear')


i = 0
if __name__ == '__main__':
    with open('config.json') as f:
        config = json.load(f)
        self_key, target_key = sys.argv[1], sys.argv[2]
        mode = sys.argv[3]

        chat = Chat(config, self_key, target_key)

        # Auth first
        if mode == 'sender':
            chat.loop_auth_as_first()
        else:
            chat.loop_auth_as_second()


        # Connection loop
        for i in range(200):
            chat.sock.sendto('Hello! I joined the chat.'.encode(), chat.target_addr)
            chat.received_data = ''
            chat.data_to_be_sent = ''
        while True:
            chat.ping(i)
            i += 1
