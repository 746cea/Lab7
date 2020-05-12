import socket

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM) 

sock.connect(('localhost', 1234)) 

while(True):
    toSend = input()
    sock.send(toSend.encode())
    toRecv = sock.recv(1024) 
    print ("Server:",toRecv.decode())

sock.close() 