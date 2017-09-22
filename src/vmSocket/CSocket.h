/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CSocket.h
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 28/8/2017 14:56:25
// Modify time 	: 28/8/2017 14:56:25
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CSOCKET_H__
#define __CSOCKET_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <WinSock2.h>

/////////////////////////////////////////////////////////////////////////////////////////
// namespace
namespace vm {

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CSocket
//        Notes : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CSocket
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
	SOCKET			mSocket;
	SOCKADDR_IN		mSockAddr;
	static unsigned char mszBuf[];

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
	CSocket(){};											// Construct define
	~CSocket(){};											// Destruct define
public:
	CSocket( const CSocket& obj ){
		*this = obj;
	};
	CSocket& operator = ( const CSocket& obj ){
		mSocket = obj.mSocket;
		memcpy(&mSockAddr, &obj.mSockAddr, sizeof(mSockAddr));
	};
	CSocket& operator = (const SOCKET& Socket)
	{
		mSocket = Socket;
		memset(&mSockAddr, 0x00, sizeof(mSockAddr));
	}

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
	static CSocket& TCPv4()
	{
		CSocket loSocket;
		loSocket.mSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (loSocket.mSocket == INVALID_SOCKET)
		{
			throw "Error";
		}
		loSocket.mSockAddr.sin_family = AF_INET;

		return loSocket;
	}
	static CSocket& TCPv6()
	{
		CSocket loSocket;
		loSocket.mSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (loSocket.mSocket == INVALID_SOCKET)
		{
			throw "Error";
		}
		loSocket.mSockAddr.sin_family = AF_INET;

		return loSocket;
	}
	static CSocket& UDPv4()
	{
		CSocket loSocket;
		loSocket.mSocket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (loSocket.mSocket == INVALID_SOCKET)
		{
			throw "Error";
		}
		loSocket.mSockAddr.sin_family = AF_INET;

		return loSocket;
	}
	static CSocket& UDPv6()
	{
		CSocket loSocket;
		loSocket.mSocket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (loSocket.mSocket == INVALID_SOCKET)
		{
			throw "Error";
		}
		loSocket.mSockAddr.sin_family = AF_INET;

		return loSocket;
	}

	bool Listen(const char* const szAddr, unsigned int uiPort, unsigned int uiMaxLinkNum)
	{
		// 设置需要监听的地址与端口
		mSockAddr.sin_port = htons(uiPort);
		if ( szAddr != 0 )
		{
			mSockAddr.sin_addr.S_un.S_addr = inet_addr(szAddr);
		}
		else
		{
			mSockAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
		}

		// 绑定端口
		int liRetForBind = bind(mSocket, (sockaddr*)&mSockAddr, sizeof(mSockAddr));
		if ( liRetForBind == SOCKET_ERROR )
		{
			throw CEXP("Bind addr(%s:%d) failed[%s]!", szAddr, uiPort, Err(WSAGetLastError(), "%C:%M"));
		}

		// 对端口进行监听
		bool lbRetForListen = ::listen(mSocket, uiMaxLinkNum);
		if (lbRetForListen == false )
		{
			throw CEXP("Listen addr(%s:%d) failed[%s]!", szAddr, uiPort, Err(WSAGetLastError(), "%C:%M"));
		}


	}
	bool Connect(const char* const szAddr, unsigned int uiPort)
	{
		// 设置需要连接的服务器地址
		mSockAddr.sin_port = htons(uiPort);
		mSockAddr.sin_addr.S_un.S_addr = inet_addr(szAddr);

		// 建立连接
		int liRetForConnect = ::connect(mSocket, (sockaddr*)mSockAddr, sizeof(mSockAddr));
		if ( liRetForConnect == SOCKET_ERROR )
		{
			throw CEXP("Connect Addr(%s:%d) failed[%s]!", szAddr, uiPort, Err(WSAGetLastError(), "%C:%M"));
		}
	}
	CSocket Accept(){
		CSocket loSocketClient;
		int liSocketAcceptAddrlen = sizeof(loSocketClient.mSockAddr);
		loSocketClient.mSocket = ::accept(mSocket, (sockaddr*)&loSocketClient.mSockAddr, &liSocketAcceptAddrlen);
		if ( loSocketClient.mSocket == SOCKET_ERROR )
		{
			throw CEXP("Accept connect failed!");
		}
		return loSocketClient;
	};
	
	int Recv( unsigned char* szBuf, const unsigned int uiBufLen ){
		
		unsigned int luiOffset = 0;
		unsigned int luiRecved = 0;
		unsigned int luiLeft = uiBufLen;

		do 
		{
			int luiRecvedCur = ::recv(mSocket, (char*)(szBuf + luiRecved), luiLeft, 0);
			if ( luiRecvedCur == 0 )
			{
				break;
			}

			luiLeft		-= luiRecvedCur;
			luiRecved	+= luiRecvedCur;
			
		} while ( luiLeft >0 );

		return luiRecved;

	};
	int Send( const unsigned char* const szBuf, const unsigned int uiBufLen ){

		unsigned int luiLeft = uiBufLen;
		unsigned int luiOffSet = 0;

		while ( luiLeft > 0 )
		{
			int luiRetForSend = ::send(mSocket, (char*)(szBuf + luiOffSet), luiLeft, 0);
			if ( luiRetForSend == SOCKET_ERROR )
			{
				throw CEXP("Send Msg failed[%s]!", Err(WSAGetLastError(), "%C:%M"));
			}
			luiLeft   -= luiRetForSend;
			luiOffSet += luiRetForSend;
		}

		return luiOffSet;
	};
	int RecvFrom();
	int SendTo(){};

	bool Close();
	


private:
protected:

}; // End of class CSocket
/////////////////////////////////////////////////////////////////////////////////////////

}; // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
 


/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSOCKET_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CSocket.h
/////////////////////////////////////////////////////////////////////////////////////////