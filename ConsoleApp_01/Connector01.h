#pragma once
#include <winsock2.h>
#include <iostream>
#include <tchar.h>
#include <ws2tcpip.h>
#include <string>
#include <sstream>

using namespace std;

class Connector01
{
//private:
//	int listeningPort;

public:
	Connector01();
	~Connector01();
	void listen_message(int listeningPort);
};

void send_message(int sendingPort, string message);
