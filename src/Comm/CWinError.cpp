/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinError.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 11/12/2015 8:58:40
// Modify time 	: 11/12/2015 8:58:40
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition

#if( _MSC_VER <= 1200 )
#pragma warning( disable:4786 )
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CWinError.h"

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// full name : CWinError::ToString
// Brief     : ��ȡ��������
// Parameter : ��
// Return    : �ǿ�     - ��������
//             ��       - ��ȡ��������ʧ��,���޴�����Ϣ
// Notes     : 
const char* CWinErr::ToString()
{
    try
    {
        mstrErrorDes = "";
        /////////////////////////////////////////////////////////////////////////////////////////
        //
        // FormateMessage ˵��
        //      ԭ�ζ��壺 DWORD WINAPI FormatMessage( 
        //                  __in DWORD dwFlags,      // ��ʽ��ѡ���lpSource����ֵ��ָ�����á�dwFlags
        //                                              �ĵ�λֵָ���˺�����δ������������������ת����
        //                                              Ҳ����ָ����ʽ������ַ�������е�����ȡ�
        //                  __in LPCVOID lpSource,   // ���ֵ����Ϣ����Դ����������ֵ����dwFlags,
        //                                              ��ϸ�뿴FORMAT_MESSAGE_FROM_HMODULE��FORMAT_MESSAGE_FROM_STRING��
        //                                              �����������ʾ����û���ã���ôlpSource���ᱻ���ԡ�
        //                  __in DWORD dwMessageId,  // �����ʽ����Ϣ�ı�ʶ������dwFlags������FORMAT_MESSAGE_FROM_STRING��
        //                                              ����������ᱻ���ԡ�
        //                  __in DWORD dwLanguageId, // ��ʽ����Ϣ���Ա�ʶ����
        //                  __out LPTSTR lpBuffer,   // һ��������ָ�������ܸ�ʽ�������Ϣ����dwFlags������
        //                                              FORMAT_MESSAGE_ALLOCATE_BUFFER��־���������������
        //                                              ʹ��LocalAlloc��������һ�黺������lpBuffer��Ҫ����
        //                                              һ����ַ��ʹ�������������������Ҫע�⴫��һ��Ҫ����ַ����
        //                  __in DWORD nSize,        // ���FORMAT_MESSAGE_ALLOCATE_BUFFERû�����ã���ô�������
        //                                              ָ�����������������Ϣ����TCHARsΪ��λ�����FORMAT_MESSAGE_ALLOCATE_BUFFER�����ˣ�
        //                                              �������������TCHARsΪ��λ���������������Сֵ�����������������ܴ���64KB��
        //                  __in va_list* Arguments
        //              );
        /////////////////////////////////////////////////////////////////////////////////////////
        //      ����˵����
        //***************************************************************************************
        //              dwFlags :   [in] Specifies aspects of the formatting process and how to interpret the lpSource parameter. The low-order 
        //                          byte of dwFlags specifies how the function handles line breaks in the output buffer. The low-order byte can 
        //                          also specify the maximum width of a formatted output line.This parameter can be a combination of the following 
        //                          bit flags.
        //---------------------------------------------------------------------------------------
        //                          FORMAT_MESSAGE_ALLOCATE_BUFFER             Specifies that the lpBuffer parameter is a pointer to a 
        //                                                                  PVOID pointer, and that the nSize parameter specifies the 
        //                                                                  minimum number of bytes (ANSI version) or characters 
        //                                                                  (Unicode version) to allocate for an output message buffer. 
        //                                                                  The function allocates a buffer large enough to hold the 
        //                                                                  formatted message, and places a pointer to the allocated 
        //                                                                  buffer at the address specified by lpBuffer. The caller 
        //                                                                  should use the LocalFree function to free the buffer when 
        //                                                                  it is no longer needed.
        //                          FORMAT_MESSAGE_IGNORE_INSERTS               Specifies that insert sequences in the message definition 
        //                                                                  are to be ignored and passed through to the output buffer 
        //                                                                  unchanged. This flag is useful for fetching a message for 
        //                                                                  later formatting. If this flag is set, the Arguments parameter 
        //                                                                  is ignored.
        //                          FORMAT_MESSAGE_FROM_STRING                  Specifies that lpSource is a pointer to a null-terminated message 
        //                                                                  definition. The message definition may contain insert sequences, 
        //                                                                  just as the message text in a message table resource may. Cannot 
        //                                                                  be used with FORMAT_MESSAGE_FROM_HMODULE or FORMAT_MESSAGE_FROM_SYSTEM.
        //                          FORMAT_MESSAGE_FROM_HMODULE                 Specifies that lpSource is a module handle containing the 
        //                                                                  message-table resources to search. If this lpSource handle is NULL, 
        //                                                                  the current process's application image file will be searched. Cannot 
        //                                                                  be used with FORMAT_MESSAGE_FROM_STRING.
        //                          FORMAT_MESSAGE_FROM_SYSTEM                  Specifies that the function should search the system message-table 
        //                                                                  resources for the requested message. If this flag is specified 
        //                                                                  with FORMAT_MESSAGE_FROM_HMODULE, the function searches the system 
        //                                                                  message table if the message is not found in the module specified 
        //                                                                  by lpSource. Cannot be used with FORMAT_MESSAGE_FROM_STRING.
        //                                                                      If this flag is specified, an application can pass the result 
        //                                                                  of the GetLastError function to retrieve the message text for a 
        //                                                                  system-defined error.Not all Windows Embedded CE�Cbased devices 
        //                                                                  will contain the system message-table resources. This is a selectable 
        //                                                                  part of the Windows Embedded CE operating system and is often removed 
        //                                                                  to conserve space.
        //                          FORMAT_MESSAGE_ARGUMENT_ARRAY               Specifies that the Arguments parameter is not a va_list structure, 
        //                                                                  but instead is just a pointer to an array of 32-bit values that represent 
        //                                                                  the arguments.
        //
        //                              the low-order byte of dwFlags can specify the maximum width of a formatted output line. Use the 
        //                          FORMAT_MESSAGE_MAX_WIDTH_MASK constant and bitwise Boolean operations to set and retrieve this maximum width value.
        //                          The following list shows how FormatMessage interprets the value of the low-order byte.
        //
        //                          0                                           There are no output line width restrictions. The function stores line 
        //                                                                  breaks that are in the message definition text into the output buffer.
        //                          A nonzero value other than 
        //                          FORMAT_MESSAGE_MAX_WIDTH_MASK               The nonzero value is the maximum number of characters in an output line. 
        //                                                                  The function ignores regular line breaks in the message definition text. 
        //                                                                  The function never splits a string delimited by white space across a line 
        //                                                                  break. The function stores hard-coded line breaks in the message definition 
        //                                                                  text into the output buffer. Hard-coded line breaks are coded with the %n 
        //                                                                  escape sequence.
        //                          FORMAT_MESSAGE_MAX_WIDTH_MASK               The function ignores regular line breaks in the message definition text. 
        //                                                                  The function stores hard-coded line breaks in the message definition text 
        //                                                                  into the output buffer. The function generates no new line breaks.
        //***************************************************************************************
        //              lpSource : [in] Pointer to the location of the message definition. The type of this parameter depends on the settings in the 
        //                         dwFlags parameter.
        //---------------------------------------------------------------------------------------
        //                          FORMAT_MESSAGE_FROM_HMODULE                 The lpSource parameter is an hModule of the module that contains the 
        //                                                                  message table to search.
        //                          FORMAT_MESSAGE_FROM_STRING                  The lpSource parameter is an LPTSTR that points to unformatted message 
        //                                                                  text. It will be scanned for inserts and formatted accordingly.
        //***************************************************************************************
        //              dwMessageId : [in] Specifies the 32-bit message identifier for the requested message. This parameter is ignored if dwFlags 
        //                            includes FORMAT_MESSAGE_FROM_STRING.
        //***************************************************************************************
        //              dwLanguageId : [in] Not supported.
        //***************************************************************************************
        //              lpBuffer : [out] Pointer to a buffer for the formatted (and null-terminated) message. If dwFlags includes 
        //                         FORMAT_MESSAGE_ALLOCATE_BUFFER, the function allocates a buffer using the LocalAlloc function, and places 
        //                         the pointer to the buffer at the address specified in lpBuffer.
        //***************************************************************************************
        //              nSize : [in] If the FORMAT_MESSAGE_ALLOCATE_BUFFER flag is not set, this parameter specifies the maximum number of characters 
        //                      that can be stored in the output buffer. If FORMAT_MESSAGE_ALLOCATE_BUFFER is set, this parameter specifies the minimum 
        //                      number of bytes or characters to allocate for an output buffer.
        //***************************************************************************************
        //              Arguments :     [in] Pointer to an array of 32-bit values that are used as insert values in the formatted message. A %1 in the format 
        //                          string indicates the first value in the Arguments array; a %2 indicates the second argument; and so on.
        //                              The interpretation of each 32-bit value depends on the formatting information associated with the insert in the 
        //                          message definition. The default is to treat each value as a pointer to a null-terminated string.
        //                              By default, the Arguments parameter is of type va_list*, which is a language- and implementation-specific data 
        //                          type for describing a variable number of arguments. If you do not have a pointer of type va_list*, then specify the 
        //                          FORMAT_MESSAGE_ARGUMENT_ARRAY flag and pass a pointer to an array of 32-bit values; those values are input to the 
        //                          message formatted as the insert values. Each insert must have a corresponding element in the array.
        /////////////////////////////////////////////////////////////////////////////////////////
        LPVOID lpMsgBuf;
        ::FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER |
                         FORMAT_MESSAGE_FROM_SYSTEM | 
                         FORMAT_MESSAGE_IGNORE_INSERTS,
                         NULL,
                         mdwErrorCode,
                         MAKELANGID( LANG_ENGLISH,SUBLANG_ENGLISH_US ), // Default language
                         (LPSTR) &lpMsgBuf,
                         0,
                         NULL );

        // ����õ���Ϣ
        mstrErrorDes = std::string( (LPCSTR)(lpMsgBuf) ); //ssBuf.str().c_str();
        mstrErrorDes.replace( (mstrErrorDes.end()-2),mstrErrorDes.end(), std::string() );

        return mstrErrorDes.c_str();
    } // End of __try
    catch( ... )
    {
        // ��ȡ�������ʧ�ܵ�����·��ؿ��ַ�
        return NULL;
    } // End of __except ( EXCEPTION_EXECUTE_HANDLER )
} // End of function virtual std::string&  CWinError::ToString()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrorCode
// full name : CWinError::GetErrorCode
// Brief     : ��̬����: Ϊ�ⲿ��ȡwindows��������ṩ�ӿ�
// Parameter : ��
// Return    : windows �������, ���ͨ��GetErrorInfo��ȡ��������
// Notes     : 
DWORD CWinErr::GetErrCode()
{
    mdwErrorCode = ::GetLastError();
    return mdwErrorCode;
} // End of function CWinError::GetErrorCode()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrorInfo
// full name : CWinError::GetErrorInfo
// Brief     : ��̬���� : Ϊ�ⲿ��ȡ������Ϣ�ṩ�ӿ�
// Parameter : cdwErrCode - ��Ҫ��ȡ��Ϣ�Ĵ������
// Return    : �������������Ĵ�������
// Notes     : 
const char* CWinErr::GetErrMsg(void)
{
  return ToString();
    
} // End of Function CWinError::GetErrorInfo
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinError.cpp
/////////////////////////////////////////////////////////////////////////////////////////