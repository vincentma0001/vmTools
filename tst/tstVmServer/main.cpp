/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: main.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 6/7/2017 7:53:38
// Modify time 	: 6/7/2017 7:53:38
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by vm's tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <stdio.h>
#include <WinSock2.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Todo : add application

void CALLBACK WorkFcuntion(DWORD dwError, DWORD dwBytesTransferred, LPWSAOVERLAPPED lpOverLapped, DWORD dwFlag)
{

}

void main(void)
{


	vm::CSocket loSocket = vm::CSocket::TCP();
	loSocket.Listen(vm::CSockAddr(NULL, 123456));

	vm::CSocket loAcceptSocket = loSocket.Accept();
	
	while (loAcceptSocket.Recv() >= 0)
	{

	}

	loAcceptSocket.Send(  );

/////////////////////////////////////////////////////////////////////////////////////////
// overlapped io model
	/*

	WSADATA loWSAData;
	WSAStartup(MAKEWORD(2, 2), &loWSAData);
	
	SOCKET loListenSocket;
	loListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	int liPort = 5100;
	SOCKADDR_IN loSockAddrServer;
	loSockAddrServer.sin_family = AF_INET;
	loSockAddrServer.sin_port = htons(liPort);
	loSockAddrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	bind(loListenSocket, (sockaddr*)&loSockAddrServer, sizeof(loSockAddrServer));

	listen(loListenSocket, 5);

	SOCKET loAcceptSocket;
	loAcceptSocket = ::accept(loListenSocket, NULL, NULL);

	WSAOVERLAPPED loOverLapped;
	memset(&loOverLapped, 0x00, sizeof(WSAOVERLAPPED));

	char lszBuf[4096] = { 0 };

	DWORD ldwFlags = 0;
	WSABUF loData;
	loData.buf = lszBuf;
	loData.len = 4096;

	DWORD lodwRecvBytes = 0;

	if (WSARecv(loAcceptSocket, &loData, 1, &lodwRecvBytes, &ldwFlags,&loOverLapped, WorkFcuntion)==SOCKET_ERROR)
	{
		if (WSAGetLastError() != WSA_IO_PENDING)
		{
			printf("WSARecv failed with error(%d)", WSAGetLastError());
			return;
		}
	}

	WSAEVENT loEventArray[MAXIMUM_WAIT_OBJECTS] = { 0 };
	loEventArray[0] = WSACreateEvent();

	while (true)
	{
		DWORD ldwIndex = WSAWaitForMultipleEvents(1, loEventArray, FALSE, WSA_INFINITE, true);
		if (ldwIndex==WAIT_IO_COMPLETION)
		{
			continue;
		}
		else
		{
			return;
		}
	}
	*/
}



/////////////////////////////////////////////////////////////////////////////////////////
// End of file main.cpp
/////////////////////////////////////////////////////////////////////////////////////////