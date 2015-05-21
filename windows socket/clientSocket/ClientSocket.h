#pragma once
#ifndef CLIENT_SOCKET_H_
#define CLIENT_SOCKET_H_


// Networking libraries
#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h> 

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class ClientSocket{
protected:
	SOCKET connectSocket;
public:
	ClientSocket();
	virtual ~ClientSocket();
	int Connect(const char* address,const char* port);
	int Close();
	int Recv(char* buffer,int length,int timeout);
	int Send(char* buffer,int length);
};

#endif