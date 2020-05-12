#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

using namespace std;


int main()
{
    int clientSocket=0; 
    int listenSocket=0; 
    int readlen=0;
    struct sockaddr_in serverAddr; 

    listenSocket = socket(AF_INET, SOCK_STREAM, 0); 
    if(listenSocket < 0)
    {
        cout<<"socket"<<endl;
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1234); 
    serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if(bind(listenSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
   
    {
        cout<<"bind"<<endl;
        return -2;
    }

    listen(listenSocket, 3); 

    for (;;)
    {
        clientSocket = accept(listenSocket, nullptr, nullptr); 
        
        if(clientSocket < 0)
        {
            cout<<"accept"<<endl;
            return -3;
        }

        for (;;)
        {
            char recv_buff[1024]="";
            readlen = recv(clientSocket, recv_buff, 1024, 0);
            if(readlen <= 0)
                break;
            cout<<recv_buff<<endl; 
            send(clientSocket, recv_buff, readlen, 0);
        }
        
        close(clientSocket);
    }

    close(listenSocket);
    
    return 0;
}