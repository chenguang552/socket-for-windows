#ifndef CLIENT
#define CLIENT
#include "winsock2.h"
#include <iostream>
#include <thread>

using namespace std;
#pragma comment (lib,"ws2_32.lib") 

#define IP 127.0.0.1
#define CPOST 8888
class client{
    private:
        WORD sockVersion;
        WSADATA wsaData;

        sockaddr_in sin;

        SOCKET service;//socket
        sockaddr_in remoteAddr;
        
        //char recDataBuff[255];
        
    public:
        void _send();
        void _recv();
   
        client();
        ~client();
};
#endif // !CLIENT

