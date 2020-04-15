/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinSeh.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/01 15:00:37
// Modify time  : 2020/01/01 15:00:37
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CWINSEH_H__
#define __CWINSEH_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

#ifndef   __VM_CFG_DLL_H__
#	error this file need #include <vmCfgDll.h>
#endif // __VM_CFG_DLL_H__

#ifndef   _WINDOWS_
#   error This file need #include <windows.h>
#endif // _WINDOWS_

#include <eh.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Describes an exception.�����쳣�Ľṹ��
// 
//  Syntax C++
//  typedef struct _EXCEPTION_RECORD {
//      DWORD                       ExceptionCode;                         // �����쳣��ԭ��
//      DWORD                       ExceptionFlags;                        // �쳣��־��
//      struct _EXCEPTION_RECORD    *ExceptionRecord;                      // ָ��EXCEPTION_RECORD�ṹ���ָ�롣
//      PVOID                       ExceptionAddress;                      // �쳣�����ĵ�ַ��
//      DWORD                       NumberParameters;                      // ���쳣��صĲ���������
//      ULONG_PTR                   ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
//                                                                         // ���������쳣�ĸ��Ӳ��������顣
//  } EXCEPTION_RECORD, *PEXCEPTION_RECORD;
//
//=======================================================================================
//
// Members                 
//    ExceptionCode           The reason the exception occurred. This is the code generated 
//                        by a hardware exception, or the code specified in theRaiseException 
//                        function for a software-generated exception. The following tables 
//                        describes the exception codes that are likely to occur due to common 
//                        programming errors.
//                            �����쳣��ԭ������һ��Ӳ���쳣�����Ĵ��������RaiseException
//                        ����ָ������������쳣�롣
//
// --------------------------------------------------------------------------------------
//
// Value	                                Meaning
// EXCEPTION_ACCESS_VIOLATION                   The thread tried to read from or write to a 
//                                          virtual address for which it does not have the 
//                                          appropriate access.
//                                              �߳�Υ���дû���ʵ�Ȩ�޵������ַ��
// EXCEPTION_ARRAY_BOUNDS_EXCEEDED              The thread tried to access an array element 
//                                          that is out of bounds and the underlying hardware 
//                                          supports bounds checking.
//                                              �߳��ڵײ�Ӳ��֧�ֵı߽����·�������Խ�硣
// EXCEPTION_BREAKPOINT                         A breakpoint was encountered.
//                                              ����һ���ϵ㡣
// EXCEPTION_DATATYPE_MISALIGNMENT              The thread tried to read or write data that 
//                                          is misaligned on hardware that does not provide 
//                                          alignment.For example, 16-bit values must be 
//                                          aligned on 2-byte boundaries; 32-bit values on 
//                                          4-byte boundaries, and so on.
//                                              �߳���ͼ�ڲ�֧�ֶ����Ӳ���϶�дδ��������ݡ�
//                                          ���磬16λֵ����2�ֽڶ��룬32λֵ����4�ֽڶ��룬
//                                          �Դ����ơ�
// EXCEPTION_FLT_DENORMAL_OPERAND               One of the operands in a floating-point operation 
//                                          is denormal. A denormal value is one that is too 
//                                          small to represent as a standard floating-point 
//                                          value.
//                                              ���������һ�������������档�������ֵ��ʾ̫
//                                          С�����ܱ�ʾһ����׼�ĸ���ֵ��
// EXCEPTION_FLT_DIVIDE_BY_ZERO                 The thread tried to divide a floating-point 
//                                          value by a floating-point divisor of zero.
//                                              �̸߳�����������
// EXCEPTION_FLT_INEXACT_RESULT                 The result of a floating-point operation can 
//                                          not be represented exactly as a decimal fraction.
//                                              �������Ĳ�������׼ȷ�Ĵ���С����
// EXCEPTION_FLT_INVALID_OPERATION              This exception represents any floating-point 
//                                          exception not included in this list.
//                                              ����쳣����������б���û���г������������쳣��
// EXCEPTION_FLT_OVERFLOW                       The exponent of a floating-point operation 
//                                          is greater than the magnitude allowed by the 
//                                          corresponding type.
//                                              ���������ָ����������Ӧ���͵����ֵ��
// EXCEPTION_FLT_STACK_CHECK                    The stack overflowed or underflowed as the 
//                                          result of a floating-point operation.
//                                              ���������ջԽ����������
// EXCEPTION_FLT_UNDERFLOW                      The exponent of a floating-point operation 
//                                          is less than the magnitude allowed by the 
//                                          corresponding type.
//                                              ���������ָ��û�г�����Ӧ���͵����ֵ��
// EXCEPTION_ILLEGAL_INSTRUCTION                The thread tried to execute an invalid instruction.
//                                              �߳���ͼִ����Чָ�
// EXCEPTION_IN_PAGE_ERROR                      The thread tried to access a page that was 
//                                          not present, and the system was unable to load 
//                                          the page. For example, this exception might occur 
//                                          if a network connection is lost while running a 
//                                          program over the network.
//                                              �߳���ͼ����һ�������ڵ�ҳ�����޷����ص�ҳ��
//                                          ���磬�쳣���������е��������ʧ���ӵ�ʱ������
// EXCEPTION_INT_DIVIDE_BY_ZERO                 The thread tried to divide an integer value 
//                                          by an integer divisor of zero.
//                                              �߳���ͼ�������㡣
// EXCEPTION_INT_OVERFLOW                       The result of an integer operation caused a 
//                                          carry out of the most significant bit of the result.
//                                              ���������Ľ��ռ���˽����������λ��
// EXCEPTION_INVALID_DISPOSITION                An exception handler returned an invalid 
//                                          disposition to the exception dispatcher. Programmers 
//                                          using a high-level language such as C should never 
//                                          encounter this exception.
//                                              �쳣���������쳣������������һ����Ч���á�ʹ��
//                                          �߼����ԣ�����C���ԣ��ĳ�����Զ������������쳣��
// EXCEPTION_NONCONTINUABLE_EXCEPTION           The thread tried to continue execution after a 
//                                          noncontinuable exception occurred.
//                                              �߳���ͼ��һ�����ɼ���ִ�е��쳣���������ִ�С�
// EXCEPTION_PRIV_INSTRUCTION                   The thread tried to execute an instruction whose 
//                                          operation is not allowed in the current machine mode.
//                                              �߳���ͼִ�е�ǰ����ģʽ��֧�ֵ�ָ�
// EXCEPTION_SINGLE_STEP                        A trace trap or other single-instruction mechanism 
//                                          signaled that one instruction has been executed.
//                                              ���򵥵�˵�ǣ�������
// EXCEPTION_STACK_OVERFLOW                     The thread used up its stack.
//                                              ���򵥵�˵�ǣ�ջ�����
//
//      Another exception code is likely to occur when debugging console processes. It does not 
// arise because of a programming error. TheLOG_CONTROL_C exception code occurs when CTRL+C is 
// input to a console process that handles CTRL+C signals and is being debugged. This exception 
// code is not meant to be handled by applications.It is raised only for the benefit of the debugger, 
// and is raised only when a debugger is attached to the console process.
//      �������쳣�ڵ��Կ���̨�����ʱ����ܷ�������Ϊ��̵Ĵ�����ܲ��ᷢ����LOG_CONTROL_C�쳣
// ���ڵ��Կ���̨����ʱ����CTRL+C������CTRL+C�źŵ�ʱ������ ����쳣�벢���ᱻӦ�ó�����
// ���Ĳ���ֻ�Ǹ��õ�Ϊ����������Ҳֻ�ڵ��������ӵ�����̨�����ʱ������
//
// --------------------------------------------------------------------------------------
//
// ExceptionFlags               The exception flags. This member can be either zero, indicating 
//                          a continuable exception,or EXCEPTION_NONCONTINUABLE indicating a 
//                          noncontinuable exception. Any attempt to continue execution after 
//                          a noncontinuable exception causes the EXCEPTION_NONCONTINUABLE_EXCEPTION 
//                          exception.
//                              �������������0����ʾ�ɼ���ִ�е��쳣��Ҳ������EXCEPTION_NONCONTINUABLE
//                          ��ʾ���ɼ���ִ�е��쳣���κ���ͼ�ڲ��ɼ���ִ�е��쳣���������
//                          ִ�л����EXCEPTION_NONCONTINUABLE_EXCEPTION�쳣��
//
// --------------------------------------------------------------------------------------
//
// ExceptionRecord              A pointer to an associated EXCEPTION_RECORD structure. Exception 
//                          records can be chained together to provide additional information 
//                          when nested exceptions occur.
//                              ��Ƕ���쳣������ʱ���쳣��¼�����γ�һ�������ṩ�������Ϣ��
//
// --------------------------------------------------------------------------------------
//
// ExceptionAddress             The address where the exception occurred.
//
// --------------------------------------------------------------------------------------
//
// NumberParameters             The number of parameters associated with the exception. This 
//                          is the number of defined elements in the ExceptionInformation 
//                          array.
//                              ����theExceptionInformation�����Ԫ�ظ�����
//
// --------------------------------------------------------------------------------------
//
// ExceptionInformation         An array of additional arguments that describe the exception. 
//                          The RaiseException function can specify this array of arguments. 
//                          RaiseException For most exception codes, the array elements are 
//                          undefined. The following table describes the exception codes 
//                          whose array elements are defined.
//                              ��������ָ������������顣�Դ�����쳣����ԣ��������Ԫ��
//                          ��δ����ġ�����ı��չʾ����Щ�쳣�������Ԫ���Ƕ����˵ġ�
//
// --------------------------------------------------------------------------------------
// 
// Exception code	                        Meaning
// EXCEPTION_ACCESS_VIOLATION                   The first element of the array contains a 
//                                          read-write flag that indicates the type of 
//                                          operation that caused the access violation. If 
//                                          this value is zero, the thread attempted to read 
//                                          the inaccessible data. If this value is 1, the 
//                                          thread attempted to write to an inaccessible 
//                                          address. If this value is 8, the thread causes 
//                                          a user-mode data execution prevention (DEP) 
//                                          violation.
//                                              ����ĵ�һ��Ԫ�ذ�����һ����д��־����ʾ����
//                                          ����Υ��Ĳ������͡�������ֵΪ0����ʾ�߳���ͼ
//                                          ��ȡ���ɷ��ʵ����ݡ�������ֵΪ1����ʾ�߳���ͼ
//                                          д�벻�ɷ��ʵĵ�ַ��������ֵ��8����ʾ�߳��߳�
//                                          ������һ���û�ģʽ��DEPΥ�档
//                                              The second array element specifies the virtual 
//                                          address of the inaccessible data.
//                                              ����ĵڶ���Ԫ��ָ���˲��ɷ������ݵ������ַ��
// EXCEPTION_IN_PAGE_ERROR                      The first element of the array contains a 
//                                          read-write flag that indicates the type of 
//                                          operation that caused the access violation. If 
//                                          this value is zero, the thread attempted to read 
//                                          the inaccessible data. If this value is 1, the 
//                                          thread attempted to write to an inaccessible 
//                                          address. If this value is 8, the thread causes 
//                                          a user-mode data execution prevention (DEP) 
//                                          violation.
//                                              ����ĵ�һ��Ԫ�ذ�����һ����д��־�����ڱ�ʾ
//                                          �������Υ��Ĳ������͡����ֵΪ0����ʾ�߳���ͼ
//                                          ��ȡ���ɷ��ʵ����ݡ����ֵΪ1����ʾ�߳���ͼд��
//                                          ���ɷ��ʵĵ�ַ�����ֵΪ8����ʾ�߳�����
//                                          ��һ���û�ģʽ��DEPΥ�档
//                                              The second array element specifies the virtual 
//                                          address of the inaccessible data.
//                                              ����ĵڶ���Ԫ��ָ���˲��ɷ������ݵ������ַ��
//                                              The third array element specifies the underlying 
//                                          NTSTATUS code that resulted in the exception.
//                                              ����ĵ�����Ԫ�ر�ʾ�ײ��NTSTATUS������ı�
//                                          ���쳣��
//
// --------------------------------------------------------------------------------------
//
// Remarks :
//      To enable a debugger to debug a target that is running on a different architecture 
// (32-bit versus 64-bit), use one of the explicit forms of this structure.
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinSeh : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CWinSeh
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinSeh();
    explicit CWinSeh(PEXCEPTION_POINTERS pep);
    // Destruct define
    virtual ~CWinSeh();
    
public:
    // Copy construct define
    CWinSeh(const CWinSeh& obj);
    // Assignment define
    CWinSeh& operator = ( const CWinSeh& obj );
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    EXCEPTION_RECORD                mEr;                    // �쳣��Ϣ
    CONTEXT                         mContest;               // �Ĵ�����Ϣ

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ȡ�쳣����
    const tchar* cs_Msg(const DWORD dwLanguage = LANG_ENGLISH) const;
    // ��ȡ�쳣����
    const DWORD code() const;

public:
    // �ض���SEH�쳣������
    static void ResetSeh(void);
    // SEH������
    static void _cdecl TranslatrSeh(UINT dwEc, PEXCEPTION_POINTERS pep);

}; // End of class CWinSeh
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINSEH_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinSeh.h
/////////////////////////////////////////////////////////////////////////////////////////