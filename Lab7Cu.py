import socket

addr = ('localhost', 1234)
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 

while(True):
    toSend = input() 
    sock.sendto(toSend.encode(), addr) 
    toRecv = sock.recv(1024)
    print("Server:", toRecv.decode())

sock.close()