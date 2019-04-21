#ifndef SERVICE
#define SERVICE
#include "winsock2.h"
#include <iostream>
#include <thread>
#include <string>
using namespace std;
#pragma comment (lib,"ws2_32.lib") 

class service{
    private:
        WORD sockVersion;
        WSADATA wsaData;

        SOCKET listener;//监听
        sockaddr_in sin;
        int POST = 8888;

        int nAddrlen; 
        SOCKET clienter[64];//客户连接socket
        sockaddr_in remoteAddr;
        
        char recDataBuff[256];
        
    public:
        void _send(SOCKET _clienter,char *sendD);
        void _recv(LPVOID n);
    
        service();
        ~service();
};
#endif // !SERVICE

