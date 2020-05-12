#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

using namespace std;

int main()
{
    int serverSocket=0; 
    int readlen=0;
    struct sockaddr_in serverAddr; 
    struct sockaddr_in clientAddr; 
    socklen_t clientlen = sizeof(clientAddr); 
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0); 
    if(serverSocket < 0)
    {
        cout<<"socket"<<endl;
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1234);
    serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    
    {
        cout<<"bind"<<endl;
        return -2;
    }

    for(;;)
    {   
        char recv_buff[1024]="";
        readlen=recvfrom(serverSocket,recv_buff,1024,0,(struct sockaddr *)&clientAddr, &clientlen); // чтение (получение) данных из сокета
        cout<<recv_buff<<endl;
        sendto(serverSocket, recv_buff, sizeof(recv_buff), 0,(struct sockaddr *)&clientAddr, sizeof(clientAddr)); // отправка данных
               }
    close(serverSocket);

    return 0;
}