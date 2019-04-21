#include "service.h"
service::service()
{
    sockVersion = MAKEWORD(2, 2);
    if (WSAStartup(sockVersion, &wsaData) != 0)
    {
        return;
    }
    listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == INVALID_SOCKET)
    {
        std::cout << "socket error !" << std::endl;
        return;
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(POST);            //端口
    sin.sin_addr.S_un.S_addr = INADDR_ANY; //ip
    if (bind(listener, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        std::cout << "bind error !" << std::endl;
    }

    //开始监听
    if (listen(listener, 5) == SOCKET_ERROR)
    {
        std::cout << "listen error !" << std::endl;
        return;
    }

    nAddrlen = sizeof(remoteAddr);
    int i = 0;
    while (i < 64)
    {
        clienter[i++] = accept(listener, (SOCKADDR *)&remoteAddr, &nAddrlen);
        if (clienter[i - 1] == INVALID_SOCKET)
        {
            std::cout << "accept error !" << std::endl; //接受数据错误 后边不执行
        }
        else
        {
            //std::cout << "远程连接：" << inet_ntoa(remoteAddr.sin_addr) << std::endl;
			std::cout << "远程连接" << std::endl;
            //接收数据并输出  开线程
            //CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)_recv, (LPVOID)i, NULL, NULL);
            // thread t(_recv, (LPVOID)i);
            // t.detach();

            _recv((LPVOID)i);
        }
    }
}

service::~service()
{
    //关闭  释放资源
    for (int i = 0; i < 64; i++)
        closesocket(clienter[i]);
    closesocket(listener);
    WSACleanup();
}

void service::_send(SOCKET _clienter, char *sendD)
{
    //发送消息
    const char *sendData = sendD;
    send(_clienter, sendData, strlen(sendData), 0);
}

void service::_recv(LPVOID n)
{
    //接收消息
    while (1)
    {
        memset(recDataBuff, 0, 256);
        int ret = recv(clienter[(int)n - 1], recDataBuff, 255, 0);
        if (ret > 0)
        { //输出数据
            std::cout << recDataBuff << std::endl;
        }
    }
}