import socket
import json

def main():
    config = {}
    with open('config.json') as f:
        config = json.load(f) 
    host = config['client']['ip']
    port = config['client']['port']
    
    server = (config['client']['ip'], config['client']['port'])
    
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind((host,port))
    
    message = input("-> ")
    while message !='q':
        s.sendto(message.encode('utf-8'), server)
        data, addr = s.recvfrom(1024)
        data = data.decode('utf-8')
        print("Received from server: " + data)
        message = input("-> ")
    s.close()

if __name__=='__main__':
    main()