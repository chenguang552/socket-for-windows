#include "client.h"
client::client(){
    //构造函数  
    sockVersion = MAKEWORD(2, 2);
    if (WSAStartup(sockVersion, &wsaData) != 0)
    {
        return;
    }
    service = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (service == INVALID_SOCKET)
    {
        std::cout << "socket error !" << std::endl;
        return;
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(CPOST);//端口
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//ip  INADDR_ANY
    if (bind(service, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        std::cout << "bind error !" << std::endl;
    }
    //开线程 
    // thread t(_send);
    // t.detach();
    _send();
    
}
client::~client(){
    //析构函数
    closesocket(service);
    WSACleanup();
}
void client::_send(){
    //发送数据
    char buff[256];
	while (1)
	{
		memset(buff, 0, 256);
		std::cout << "输入:" << std::endl;
		std::cin >> buff;
		int _service = send(service, buff, strlen(buff), 0);
		if (_service > 0)
		{
			std::cout << "done! " << _service << "byte" << std::endl;
		}
 
	}
}