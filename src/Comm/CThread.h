/////////////////////////////////////////////////////////////////////////////////////////
//
// File           : Thread.h
// Version        : 1.0
// Function       : 
// Author         : vincent ma
// Date           : 2004/12/10 10:23
// Notes          : 
// Modifications  :
// 
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright :
//             This code is absolutely free to use and modify. The code is provided 
//             "as is" with no expressed or implied warranty. The author accepts 
//             no liability if it causes any damage to your computer, causes your 
//             pet to fall ill, increases baldness or makes your car start emitting 
//             strange noises when you start it up. This code has no bugs, just 
//             undocumented features!
//
/////////////////////////////////////////////////////////////////////////////////////////

#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef VIN_TOOLS_THREAD_INCLUDED__
#define VIN_TOOLS_THREAD_INCLUDED__

/////////////////////////////////////////////////////////////////////////////////////////
// options :
//
/////////////////////////////////////////////////////////////////////////////////////////
// add include file here
#ifndef _WINDOWS_
#   include <windows.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// CThread
/////////////////////////////////////////////////////////////////////////////////////////
class CThread 
{
/////////////////////////////////////////////////////////////////////////////////////////
// constructor & destroctor
public :
	CThread();
	virtual ~CThread();

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public :
	HANDLE	GetHandle		(  ) const;
	void	Wait			(  ) const;
	bool	Wait			( DWORD timeoutMillis ) const;
	void	Start			( DWORD dwCreationFlags = 0 /*CREATE_SUSPENDED*/ );
	void	Terminate		( DWORD exitCode = 0 );
	void	ResumeThread	( void );
	void	SuspendThread	( void );
		
/////////////////////////////////////////////////////////////////////////////////////////
// functions :
private :
	virtual int Run( ) = 0;
	static unsigned long __stdcall ThreadFunction(void *pV);

/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private :
	HANDLE m_hThread;

/////////////////////////////////////////////////////////////////////////////////////////
// No copies do not implement
private :
	CThread(const CThread &rhs);
	CThread &operator=(const CThread &rhs);
};

/////////////////////////////////////////////////////////////////////////////////////////

#endif // VIN_TOOLS_THREAD_INCLUDED__

/////////////////////////////////////////////////////////////////////////////////////////
// usage :
//
/////////////////////////////////////////////////////////////////////////////////////////
// example :
//
// --------------------------------------------------------------------------------------
// in thread define file
// --------------------------------------------------------------------------------------
//    class testThread : public VIN::Thread::CThread
//    {
//	       virtual int Run()
//	       {
//             std::cout << "this is a thread test." << std::endl;
//             return 0;
//         }
//    };
// --------------------------------------------------------------------------------------
// in main function
// --------------------------------------------------------------------------------------
//    #include <iostream>
//    #include <testException.h>
//    #include <testCThread.h>
//
//    int main()
//    {
//        vTry
//            testThread test;
//            test.Start();
//            test.Wait();
//        vCatch( VIN::CException& e )
//            std::cout << e.str() << std::endl;
//        vEnd
//    }

/////////////////////////////////////////////////////////////////////////////////////////
// End of file
/////////////////////////////////////////////////////////////////////////////////////////