#pragma once
#include "Connector01.h"

Connector01::Connector01()
{
	//listeningPort = listenPort;
}


Connector01::~Connector01()
{
}


void Connector01::listen_message(int listeningPort)
{
	char msgBuf[256];

	WSADATA WSAData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	server = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(listeningPort);

	while (true) {
		bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
		listen(server, 0);
		char buffer[1024];
		memset(buffer, 0, sizeof(buffer));
		int clientAddrSize = sizeof(clientAddr);
		int serverAddrSize = sizeof(serverAddr);
		if ((client = accept(server, NULL, NULL)) != INVALID_SOCKET)
		{
			//char *ip = inet_ntoa(clientAddr.sin_addr);
			recv(client, buffer, sizeof(buffer), 0);
			string message = buffer;
			cout << message << endl;
			closesocket(client);
		}
		else
		{
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), msgBuf, sizeof(msgBuf), NULL);
			cout << msgBuf << endl;
		}
	}
}



void send_message(int sendingPort, string message)
{
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;
	string IP = "127.0.0.1";

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	inet_pton(AF_INET, IP.c_str(), &addr.sin_addr.s_addr);			//_T(IP.c_str())
	addr.sin_family = AF_INET;
	addr.sin_port = htons((int)&sendingPort);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	send(server, message.c_str(), strlen(message.c_str()), 0);
	closesocket(server);
	WSACleanup();
}