///////////////////////////////////////////////////////////////////////////////
//
// File           : Event.cpp
// Version        : 1
// Function       : 
//
// Author         : vincent ma
// Date           : 09/17/2004 13:22
//
// Notes          : 
//
// Modifications  :
//
//                  1) 09/24/2004 11:16 add namespace Thread
//
//                  2) 09/24/2004 11:16 replace exception to stl exception
// 
///////////////////////////////////////////////////////////////////////////////
//
// Copyright 
//
///////////////////////////////////////////////////////////////////////////////
// locale header included
#include "CException.h"
#include "CWinError.h"

#include "CEvent.h"


///////////////////////////////////////////////////////////////////////////////
// Lint options
//
// lint -save
// lint -esym(1763, CEvent::GetEvent) const member indirectly modifies obj
//
// Member not defined
// lint -esym(1526, CEvent::CEvent)
// lint -esym(1526, CEvent::operator=)
//
// lint -esym(534, CloseHandle)   ignoring return value
//
///////////////////////////////////////////////////////////////////////////////

namespace JL{

	///////////////////////////////////////////////////////////////////////////
	// Static helper methods declare
	///////////////////////////////////////////////////////////////////////////

	static HANDLE Create( LPSECURITY_ATTRIBUTES lpEventAttributes, 
						  bool bManualReset, 
						  bool bInitialState, 
						  LPCTSTR lpName );

	///////////////////////////////////////////////////////////////////////////
	// CEvent
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// construction & destruction function

	CEvent::CEvent( LPSECURITY_ATTRIBUTES lpEventAttributes, 
					bool bManualReset, 
					bool bInitialState ) 
					:m_hEvent( Create(lpEventAttributes,bManualReset,bInitialState,0) )
	{ }

	
	CEvent::CEvent( LPSECURITY_ATTRIBUTES lpEventAttributes, 
					bool bManualReset, 
					bool bInitialState, 
					const std::string &name)
					:m_hEvent(Create(lpEventAttributes, bManualReset, bInitialState, name.c_str()))
	{ }

	CEvent::~CEvent()
	{
		::CloseHandle(m_hEvent);
	}

	////////////////////////////////////////////////////////////////////////////
	// function : get current event handle

	HANDLE CEvent::GetEvent() const
	{
		return m_hEvent;
	}

	////////////////////////////////////////////////////////////////////////////
	// function : wait the event signal no time limited

	void CEvent::Wait() const
	{
		if ( !Wait(INFINITE) )
		{
			throw CEXP( "CEvent::Wait() Unexpected timeout on infinite wait" );
		}
	}

	////////////////////////////////////////////////////////////////////////////
	// function : wait the event signal until timeout
	// input    : the time that want to waited
	// ouput    : if the event signaled in the time, it will return true, else return false

	bool CEvent::Wait(DWORD timeoutMillis) const
	{
		bool ok;

		DWORD result = ::WaitForSingleObject(m_hEvent, timeoutMillis);

		if (result == WAIT_TIMEOUT)
		{
			ok = false;
		}
		else if (result == WAIT_OBJECT_0)
		{
			ok = true;
		}
		else
		{
            CWinError loErr;
			throw CEXP( "CEvent::Wait() - WaitForSingleObject failed(%d:%s) ", loErr.GetErrorCode(), loErr.GetErrorInfo() );
		} // end of if
		    
		return ok;
	}

	////////////////////////////////////////////////////////////////////////////
	// function : the event reset to nonsignaled 

	void CEvent::Reset()
	{
		if (!::ResetEvent(m_hEvent))
		{
            CWinError loErr;
			throw CEXP( "CEvent::Reset","ResetEvent failed(%d:%s)!", loErr.GetErrorCode(), loErr.GetErrorInfo());
		} // end of if
	}

	////////////////////////////////////////////////////////////////////////////
	// function : set the event to signaled

	void CEvent::Set()
	{
		if (!::SetEvent(m_hEvent))
		{
            CWinError loErr;
			throw CEXP( "CEvent::Set()", ("SetEvent failed(%d:%s)!"), loErr.GetErrorCode(), loErr.GetErrorInfo() );
		} // end of if
	}

	///////////////////////////////////////////////////////////////////////////
	// function : The PulseEvent function sets the specified event object to the 
	//            signaled state and then resets it to the nonsignaled state after 
	//            releasing the appropriate number of waiting threads.

	void CEvent::Pulse()
	{
		if (!::PulseEvent(m_hEvent))
		{
            CWinError loErr;
			throw CEXP( ("CEvent::Pulse()"), loErr.GetErrorCode(), loErr.GetErrorInfo() );
		} // end of if
	}

	///////////////////////////////////////////////////////////////////////////////
	// Static helper methods
	///////////////////////////////////////////////////////////////////////////////

	static HANDLE Create( LPSECURITY_ATTRIBUTES lpEventAttributes,
						  bool bManualReset, 
						  bool bInitialState, 
						  LPCTSTR lpName )
	{
		HANDLE hEvent = ::CreateEvent( lpEventAttributes,
									   bManualReset, 
									   bInitialState, 
									   lpName );

		if (hEvent == NULL)
		{
            CWinError loErr;
			throw CEXP( ("CreateEvent failed(%d:%s)!"), loErr.GetErrorCode(), loErr.GetErrorInfo() );
		} // end of if

		return hEvent;
	}

	//////////////////////////////////////////////////////////////////////////
	// CManualResetEvent
	//////////////////////////////////////////////////////////////////////////

	// constructor 
	CManualResetEvent::CManualResetEvent( bool initialState /* = false */ )
		:CEvent( 0, true, initialState )
	{ }
	CManualResetEvent::CManualResetEvent( const std::string &name, 
		bool initialState /* = false */ )
		:CEvent( 0, true, initialState, name )
	{ }

	///////////////////////////////////////////////////////////////////////////////
	// CAutoResetEvent
	///////////////////////////////////////////////////////////////////////////////

	CAutoResetEvent::CAutoResetEvent( bool initialState /* = false */)
	:  CEvent(0, false, initialState)
	{

	}

	CAutoResetEvent::CAutoResetEvent( const std::string &name, bool initialState /* = false */)
	:  CEvent(0, false, initialState, name)
	{

	}

}

///////////////////////////////////////////////////////////////////////////////
// Lint options
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// End of file...
///////////////////////////////////////////////////////////////////////////////