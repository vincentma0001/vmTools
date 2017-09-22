/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinCS.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 7/12/2015 19:57:20
// Modify time 	: 7/12/2015 19:57:20
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <Windows.h>

#include "CWinCS.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

#if( WIN32_WINNT  >= 0x0403 )
/////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinCS
// Full name : CWinCS::CWinCS
// Access    : public 
// Brief     : 
// Parameter : DWORD dwSpinCount /*= 0xFA0 */  : 尝试进入次数
// Return    : 无
// Notes     : 
CWinCS::CWinCS(DWORD dwSpinCount /*= 0xFA0 */)
{
    ::InitializeCriticalSectionAndSpinCount( &m_cWinCS, dwSpinCount )
} // End of function CWinCS(...
/////////////////////////////////////////////////////////////////////////////////////

#else
/////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinCS
// Full name : CWinCS::CWinCS
// Access    : public 
// Brief     : 
// Parameter : DWORD dwSpinCount /*= 0xFA0 */  ：尝试进入次数
// Return    : 无
// Notes     : 
CWinCS::CWinCS(DWORD dwSpinCount /*= 0xFA0 */)
{
    ::InitializeCriticalSection(&m_cWinCS);
} // End of function CWinCS(...
/////////////////////////////////////////////////////////////////////////////////////
#endif	

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CWinCS
// Full name : CWinCS::~CWinCS
// Access    : public 
// Brief     : 
// Parameter :  no
// Return    :  no
// Notes     : 
CWinCS::~CWinCS()
{
    ::DeleteCriticalSection(&m_cWinCS);
} // End of function ~CWinCS(...
/////////////////////////////////////////////////////////////////////////////////////

#if(_WIN32_WINNT >= 0x0403)
/////////////////////////////////////////////////////////////////////////////////////
// Name      : TryEnter
// Full name : CWinCS::TryEnter
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : bool ： 尝试进入是否成功
// Notes     : 
bool CWinCS::TryEnter()
{
    return ((::TryEnterCriticalSection(&m_cWinCS))==TRUE)?true:false;
} // End of function TryEnter(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : SetCSSpinCount
// Full name : CWinCS::SetCSSpinCount
// Access    : public 
// Brief     : 
// Parameter : DWORD dwSpinCount /*= 0xFA0 */  ： 尝试进入次数
// Return    : void
// Notes     : 
void CWinCS::SetCSSpinCount(DWORD dwSpinCount /*= 0xFA0 */)
{
    ::SetCriticalSectionSpinCount( &m_cWinCS, dwSpinCount );
} // End of function SetCSSpinCount(...
/////////////////////////////////////////////////////////////////////////////////////
#endif

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Enter
// Full name : CWinCS::Enter
// Access    : public 
// Brief     : 获取CS控制权
// Parameter : 
// Return    : void
// Notes     : 
void CWinCS::Enter()
{
#if(_WIN32_WINNT >= 0x0403)
    TryEnter();
#else
    ::EnterCriticalSection(&m_cWinCS);
#endif
} // End of function Enter(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Leave
// Full name : CWinCS::Leave
// Access    : public 
// Brief     : 释放CS控制权
// Parameter : 
// Return    : void
// Notes     : 
void CWinCS::Leave()
{
    ::LeaveCriticalSection(&m_cWinCS);
} // End of function Leave(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Locker
// Full name : CWinCS::Locker::Locker
// Access    : private 
// Brief     : 
// Parameter : CWinCS &cWinCS
// Return    : 
// Notes     : 
CWinCS::Locker::Locker(CWinCS &cWinCS) : m_cWinCS(cWinCS)
{
    m_cWinCS.Enter();
} // End of function Locker(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~Locker
// Full name : CWinCS::Locker::~Locker
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CWinCS::Locker::~Locker()
{
    m_cWinCS.Leave();
} // End of function ~Locker(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinCS.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
