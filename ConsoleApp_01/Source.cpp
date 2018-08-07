//Server
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <iostream>
#include <ws2tcpip.h>
#include <tchar.h>
#include <string>
#include <thread>
#include "Connector01.h"

using namespace std;

int main(int argc, char** argv)
{
#pragma region Test
	//WSAData wsaData;
	//WORD DllVersion = MAKEWORD(2, 2);
	//if (WSAStartup(DllVersion, &wsaData) != 0)
	//{
	//	MessageBoxA(NULL, "winsock startup failed", "Error", MB_OK | MB_ICONERROR);
	//	return 1;
	//}

	//SOCKADDR_IN addr;
	//int addrlen = sizeof(addr);
	//addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//addr.sin_port = htons(1005);
	//addr.sin_family = AF_INET;


	//SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, NULL);
	//bind(listenSocket, (SOCKADDR*)&addr, addrlen);
	//listen(listenSocket, SOMAXCONN);

	//SOCKET newClientConnection;
	//newClientConnection = accept(listenSocket, (SOCKADDR*)&addr, &addrlen);
	//if (newClientConnection == 0)
	//{
	//	cout << "Failed to accept the client's connection" << endl;
	//}
	//else
	//{
	//	cout << "Client connected and ready to send messages" << endl;
	//}
	//system("pause");

	//return 0;
#pragma endregion


	string listeningPort;
	cout << "Enter the Listening Port: ";
	getline(cin, listeningPort);
	int i = stoi(listeningPort);

	string sendingPort;
	cout << "Enter the Sending Port: ";
	getline(cin, sendingPort);

	Connector01 *conn = new Connector01();

	thread lisThread(&Connector01::listen_message, conn, i);
	

	while (true)
	{
		string message;
		cout << "Console App_01>";
		getline(cin, message);
		send_message((int)&sendingPort, message);
	}
	
	lisThread.join();

	return 0;
}