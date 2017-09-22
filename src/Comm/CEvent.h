#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef VIN_TOOLS_WIN32_EVENT_INCLUDED__
#define VIN_TOOLS_WIN32_EVENT_INCLUDED__
///////////////////////////////////////////////////////////////////////////////
//
// File           : Event.h
// Version        : 1
// Function       : 
//
// Author         : vincent ma
// Date           : 09/17/2004 13:59
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

///////////////////////////////////////////////////////////////////////////////
// Lint options
//
// lint -save
//
// Private copy constructor
// lint -esym(1704, CEvent::CEvent)
//
// No default constructor
// lint -esym(1712, CEvent) 
// 
///////////////////////////////////////////////////////////////////////////////

#include <STRING>

#ifndef _WINDOWS_
#	error this file need #include <windows.h>
#endif

namespace JL{

	///////////////////////////////////////////////////////////////////////////////
	// CEvent
	///////////////////////////////////////////////////////////////////////////////

	class CEvent 
	{
		// constructor & destructor :
		public :
		   	CEvent( LPSECURITY_ATTRIBUTES lpSecurityAttributes,
					bool manualReset,
					bool initialState );
		   
			CEvent(	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
					bool manualReset,
					bool initialState,
					const std::string &name );
		      
			virtual ~CEvent();

		// functions :
		public :
			HANDLE GetHandle	(  ) const;
			void Wait		(  ) const;
			bool Wait		( DWORD timeoutMillis ) const;
			void Reset		(  );
			void Set		(  );
			void Pulse		(  );

		// members :
		private :
			HANDLE m_hEvent;

		// No copies do not implement
		public :
			CEvent(const CEvent &rhs);
			CEvent &operator=(const CEvent &rhs);
	};

	///////////////////////////////////////////////////////////////////////////
	// CManualResetEvent
	///////////////////////////////////////////////////////////////////////////

	class CManualResetEvent : public CEvent
	{
		// constructor :
		public :
			explicit CManualResetEvent( bool initialState = false );
			explicit CManualResetEvent( const std::string &name, bool initialState = false );

		// No copies do not implement
		private :      
			CManualResetEvent(const CManualResetEvent &rhs);
			CManualResetEvent &operator=(const CManualResetEvent &rhs);
	};

	///////////////////////////////////////////////////////////////////////////////
	// CAutoResetEvent
	///////////////////////////////////////////////////////////////////////////////
	
	class CAutoResetEvent : public CEvent
	{
	public :
	   
		explicit CAutoResetEvent(
			bool initialState = false);
	      
		explicit CAutoResetEvent(
			const std::string &name, 
			bool initialState = false);

	private :

		// No copies do not implement
		CAutoResetEvent(const CAutoResetEvent &rhs);
		CAutoResetEvent &operator=(const CAutoResetEvent &rhs);
	};
	
} // End of namespace JL

///////////////////////////////////////////////////////////////////////////////
// Lint options
//
//lint -restore
//
///////////////////////////////////////////////////////////////////////////////

#endif // VIN_TOOLS_WIN32_EVENT_INCLUDED__

///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
