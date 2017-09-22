

#include <CommInc.h>

///////////////////////////////////////////////////////////////////////////
// function : construcot & destructor
CThread::CThread( ) : m_hThread(INVALID_HANDLE_VALUE) { }
CThread::~CThread()
{
	if ( m_hThread != INVALID_HANDLE_VALUE)
	{
		::CloseHandle(m_hThread);
	} // end of if
}

///////////////////////////////////////////////////////////////////////////
// function : Resume the thread
void CThread::ResumeThread( void )
{ 
	if( m_hThread == INVALID_HANDLE_VALUE )
		throw CEXP( "invalid thread handle." );

	::ResumeThread( m_hThread ); 
}

///////////////////////////////////////////////////////////////////////////
// function : Suspend the thread
void CThread::SuspendThread( void )
{
	if( m_hThread == INVALID_HANDLE_VALUE )
		throw CEXP( "invalid thread handle." );

	::SuspendThread( m_hThread );
}

///////////////////////////////////////////////////////////////////////////
// function : return the thread's handle
HANDLE CThread::GetHandle() const
{	
	return m_hThread;
}

///////////////////////////////////////////////////////////////////////////
// function : create a thread.
void CThread::Start( DWORD dwCreationFlags /*!= CREATE_SUSPENDED*/ )
{
	if (m_hThread == INVALID_HANDLE_VALUE)
	{
		unsigned long threadID = 0;

		m_hThread = ::CreateThread( NULL,
			0,
			CThread::ThreadFunction,
			(void*)this,
			dwCreationFlags,
			&threadID );

		if (m_hThread == INVALID_HANDLE_VALUE)
		{
            CWinError   loWinErr;
			throw CEXP( "CreateThread failed(%d:%s)!", loWinErr.GetErrorCode(), loWinErr.GetErrorInfo() );
		} // end of if
	}
	else
	{
		throw CEXP( "Thread already running - you can only call Start() once!"  );
	} // end of if
}

///////////////////////////////////////////////////////////////////////////
// function : no limited the wait the thread when thread handle is nosigned
void CThread::Wait() const
{
	if ( !Wait(INFINITE) )
	{
		throw CEXP( "Unexpected timeout on infinite wait" );
	} // end of if
}

///////////////////////////////////////////////////////////////////////////
// function : wait the thread when thread handle is nosigned and waited timeoutMillis
bool CThread::Wait( DWORD timeoutMillis ) const
{
	bool ok;

	DWORD result = ::WaitForSingleObject(m_hThread, timeoutMillis);

	if (result == WAIT_TIMEOUT)
	{
		ok = false;
	}
	else if ( result == WAIT_OBJECT_0 )
	{
		ok = true;
	} // end of else if
	else
	{
        CWinError loWinErr;
		throw CEXP( "WaitForSingleObject failed(%d:%s)!", loWinErr.GetErrorCode(), loWinErr.GetErrorInfo());
	} // end of if
		
	return ok;
}

///////////////////////////////////////////////////////////////////////////
// function : start the thread's run() virtual function 
unsigned long __stdcall CThread::ThreadFunction( void *pV )
{
	int result = 0;

	CThread* pThis = (CThread*)pV;
		
	if (pThis)
	{
        CWinSeh::ResetSeh();
		try{
		    result = pThis->Run();
		} // End of try
        catch( std::exception &ex )
        {
            std::cout << "Cpp    Exception : " << ex.what() << std::endl;
        }
        catch( CWinSeh &ex )
        {
            std::cout << "System Exception : " << ex.GetExpCode() << " : " << ex.GetExpDes( ) << std::endl;
        }
		catch(...){
            std::cout << "Get an unknown exception!" << std::endl;
		} // End of catch( ... )
	} // end of if

	return result;
}

////////////////////////////////////////////////////////////////////////////
// function : terminate the thread

void CThread::Terminate( DWORD exitCode /* = 0 */ )
{
	if ( !::TerminateThread( m_hThread, exitCode ) )
	{
		// TODO we could throw an exception here...
	} // end of if
}

/////////////////////////////////////////////////////////////////////////////////////////
// End of file
/////////////////////////////////////////////////////////////////////////////////////////
