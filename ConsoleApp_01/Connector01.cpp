#pragma once
#include "Connector01.h"

Connector01::Connector01()
{
}


Connector01::~Connector01()
{
}


void Connector01::listen_message()
{
	WSADATA WSAData;
	SOCKET server, client;
	SOCKADDR_IN serverAddr, clientAddr;
	WSAStartup(MAKEWORD(2, 0), &WSAData);

	server = socket(AF_INET, SOCK_STREAM, 0);		//Create new socket
	serverAddr.sin_addr.s_addr = INADDR_ANY;		//INADDR_ANY is used when you don't need to bind a socket to a specific IP
	serverAddr.sin_family = AF_INET;				//IPv4 socket
	serverAddr.sin_port = htons(2005);				//Port

	while (true) {
		bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));		//Bind the address to the socket
		listen(server, 0);												//Places server socket in a state in which it is listening for an incoming connection. Note:SOMAXCONN = Socket Oustanding Max Connections
		char buffer[1024];												//Buffer to store incoming messages
		memset(buffer, 0, sizeof(buffer));								//Number of bytes to be set to the value
		int clientAddrSize = sizeof(clientAddr);
		if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
		{
			//char *ip = inet_ntoa(clientAddr.sin_addr);
			recv(client, buffer, sizeof(buffer), 0);
			string receivingMessage = buffer;
			cout << receivingMessage << endl;

			string sendingMessage;
			cout << "Console App_01>";
			getline(cin, sendingMessage);
			send(client, sendingMessage.c_str(), strlen(sendingMessage.c_str()), 0);

			closesocket(client);
		}
	}
}



//void send_message(string message)
//{
//	WSADATA WSAData;
//	SOCKET server;
//	SOCKADDR_IN addr;
//	string IP = "127.0.0.1";
//
//	WSAStartup(MAKEWORD(2, 0), &WSAData);
//	server = socket(AF_INET, SOCK_STREAM, 0);
//
//	inet_pton(AF_INET, IP.c_str(), &addr.sin_addr.s_addr);			//_T(IP.c_str())
//	addr.sin_family = AF_INET;
//	addr.sin_port = htons(2005);
//
//	connect(server, (SOCKADDR *)&addr, sizeof(addr));
//	send(server, message.c_str(), strlen(message.c_str()), 0);
//	closesocket(server);
//	WSACleanup();
//}