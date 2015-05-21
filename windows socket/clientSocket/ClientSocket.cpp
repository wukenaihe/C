#include "ClientSocket.h"
#include "Log.h"

ClientSocket::~ClientSocket(){
	Close();
};

ClientSocket::ClientSocket(void):connectSocket(INVALID_SOCKET){}

int ClientSocket::Close(){
	if(connectSocket!=INVALID_SOCKET){
		if(closesocket(connectSocket)==SOCKET_ERROR){
			LOG_ERROR("Close Socket %d error %d",connectSocket,WSAGetLastError());
			return SOCKET_ERROR;
		}
	}

	LOG_DEBUG("Close Socket %d",connectSocket);
	return 0;
}

int ClientSocket::Connect(const char* address,const char* port){
	 // create WSADATA object
    WSADATA wsaData;

    // socket
    connectSocket = INVALID_SOCKET;

    // holds address info for socket to connect to
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;

    // Initialize Winsock
	int iResult=0;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    if (iResult != 0) {
        LOG_ERROR("WSAStartup failed with error: %d\n", WSAGetLastError());
		return iResult;
    }



    // set address info
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;  //TCP connection!!!

	
    //resolve server address and port 
	iResult = getaddrinfo(address, port, &hints, &result);

    if( iResult != 0 ) 
    {
        LOG_ERROR("getaddrinfo failed with error: %d\n", WSAGetLastError());
        WSACleanup();
		return iResult;
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        connectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);

        if (connectSocket == INVALID_SOCKET) {
            LOG_ERROR("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return INVALID_SOCKET;
        }

        // Connect to server.
        iResult = connect( connectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

        if (iResult == SOCKET_ERROR)
        {
            closesocket(connectSocket);
            connectSocket = INVALID_SOCKET;
            LOG_ERROR("The server is down... did not connect");
        }
    }



    // no longer need address info for server
    freeaddrinfo(result);



    // if connection failed
    if (connectSocket == INVALID_SOCKET) 
    {
        LOG_ERROR("Unable to connect to server!");
        WSACleanup();
        return INVALID_SOCKET;
    }
}

int ClientSocket::Recv(char* buffer,int length,int timeout){
	if(connectSocket==INVALID_SOCKET){
		LOG_ERROR("Scoket don't Connect to server");
		return -1;
	}
	LOG_DEBUG("set recv time out:%d",timeout);
	setsockopt(connectSocket,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout,sizeof(timeout));

	int offset=0;
	int recvLength=0;
	while(offset<length){
		recvLength=recv(connectSocket,buffer+offset,length-offset,0);

		if(recvLength==0){
			LOG_ERROR("Connection %d has closed!",connectSocket);
			return 0;
		}else if(recvLength==SOCKET_ERROR){
			LOG_ERROR("Socket error %d",WSAGetLastError());
		}else{
			LOG_INFO("Recv %d bytes",recvLength);
		}
		offset+=recvLength;
	}
	return offset;
}
int ClientSocket::Send(char* buffer,int length){
	if(connectSocket==INVALID_SOCKET){
		LOG_ERROR("Scoket don't Connect to server");
		return -1;
	}

	int offset=0;
	int recvLength=0;

	while(offset<length){
		recvLength=recv(connectSocket,buffer+offset,length-offset,0);

		if(recvLength==0){
			LOG_ERROR("Connection %d has closed!",connectSocket);
			return 0;
		}else if(recvLength==SOCKET_ERROR){
			LOG_ERROR("Socket error %d",WSAGetLastError());
		}else{
			LOG_INFO("Send %d bytes",recvLength);
		}
	}

	return offset;
}