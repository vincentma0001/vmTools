/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinError.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 5/12/2015 12:55:52
// Modify time 	: 5/12/2015 12:55:52
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//                  windows ������붨��
//-----------------------------------------------------------------------------------
//   λ  ��     | 31 - 30  |    29     |  28  |       27 - 16       |         15 -0
//-----------------------------------------------------------------------------------
// �����ƣ�     |   00     |     0     |  0   |  0000 0000 0000     | 0000 0000 0000 0000
//-----------------------------------------------------------------------------------
//                 ������  | ϵͳ/�û� | ���� |      �豸����       |        �쳣����
//                 -------------------------------------------------------------------
//                 0=�ɹ�  |  0=ϵͳ   |  0   |      ϵͳ����       |      ϵͳ/�ͻ�����
//                 1=���ο�|  1=�ͻ�   |      |                     |
//                 2=����  |           |      |                     |
//                 3=����  |           |      |                     |
/////////////////////////////////////////////////////////////////////////////////////////
// ʮ�����Ʊ�ʾ��
//    30-31 �����ԣ�   ��  ����0x00000000
//                     ���ο���0x40000000
//                     ��  �棺0x80000000
//                     ��  ��0xc0000000
//    29    ϵ  ͳ:    ϵ  ͳ��0x00000000
//                     ��  ����0x20000000
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

#ifndef __CWINERROR_H__
#define __CWINERROR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef _WINDOWS_
#	error this file need #include <windows.h>
#endif

#include <string>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define

#ifndef vmErr
#define vmErr( x, y ) vm::CWinErr(x).Format(y)
#endif

#ifndef __VM_WINERR_MAX_BUF__
#define  __VM_WINERR_MAX_BUF__ 4096
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// namespace 
namespace vm{

	/////////////////////////////////////////////////////////////////////////////////////
	//
	// class define : CWinError
	//        Notes : �����װ��window������뼰������Ϣ�Ļ�ȡ����
	//
	/////////////////////////////////////////////////////////////////////////////////////
	class CWinErr
	{
	/////////////////////////////////////////////////////////////////////////////////////////
	// members :
	private:
		unsigned long			mdwErrorCode;						// �������
		std::string				mstrErrorDes;						// �����������
		static unsigned char	mszBuf[__VM_WINERR_MAX_BUF__];		// ����
	/////////////////////////////////////////////////////////////////////////////////////
	// functions :
	public:
		CWinErr(const unsigned long cdwError = GetLastError());     // Construct define
		~CWinErr(){};			                                    // Destruct define
	/////////////////////////////////////////////////////////////////////////////////////////
	// static functions:
	public:
		// ��ȡ��������
		inline const char* ToString();
		// ��ȡ������
		unsigned long ToCode();
		// ��ʽ���������
		const char* Format(const char* const szFormat);

	}; // End of class CWinError
	/////////////////////////////////////////////////////////////////////////////////////

}; // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINERROR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinError.h
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
//
//         1. CWinErr().Format( "%C:%S" );
//         2. CWinErr( 10086 ).ToString();
//         3. CWinErr().ToCode();
//         
/////////////////////////////////////////////////////////////////////////////////////////