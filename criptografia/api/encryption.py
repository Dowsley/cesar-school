import pyaes
import os
import rsa
import base64
from base64 import b64encode, b64decode
import secrets
import ast


class EncryptionSession():
    def __init__(self):
        self.stage = 0

        # Default values
        self.AES_key = None
        self.RSA_public_key = None
        self.RSA_private_key = None
        self.done = False


    # Encryption base functions
    def AES_encrypt(self, plain_text):
        aes = pyaes.AESModeOfOperationCTR(self.AES_key)
        cipher_text = aes.encrypt(plain_text)
        return cipher_text


    def AES_decrypt(self, cipher_text):
        aes = pyaes.AESModeOfOperationCTR(self.AES_key)
        decrypted = aes.decrypt(cipher_text)
        return decrypted


    def RSA_generate_keys(self):
        self.RSA_public_key, self.RSA_private_key = rsa.newkeys(1024)
        self.RSA_public_key = self.RSA_public_key.save_pkcs1('PEM').decode()
        self.RSA_private_key = self.RSA_private_key.save_pkcs1('PEM').decode()


    def RSA_encrypt(self, a_message):
        tmp = rsa.encrypt(a_message.encode(), rsa.PublicKey.load_pkcs1(self.RSA_public_key.encode(), 'PEM'))
        return tmp


    def RSA_decrypt(self, encoded_encrypted_msg):
        key = self.RSA_private_key
        key_a = key.encode() if type(key) == str else self.RSA_private_key
        a = rsa.PrivateKey.load_pkcs1(key_a, 'PEM') 
        res = rsa.decrypt(encoded_encrypted_msg if type(encoded_encrypted_msg) == bytes else encoded_encrypted_msg.encode(), a) 
        return res.decode()

    def AES_key_to_str(self):
        b64_string = str(b64encode(self.AES_key),'utf-8')
        return b64_string

    def AES_str_to_key(self, string):
        return b64decode(string)


if __name__ == '__main__':
    plaintext = "Text may be any length you wish, no padding is required"
    a = EncryptionSession()

    # RSA
    a.RSA_generate_keys()
    msg = a.RSA_encrypt(plaintext)
    print(a.RSA_decrypt(msg))

    # AES
    a.AES_key = secrets.token_bytes(32)
    msg = a.AES_encrypt(plaintext)
    print(a.AES_decrypt(msg))