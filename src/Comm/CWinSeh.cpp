/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CSeToCe.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 20/12/2015 13:20:16
// Modify time 	: 20/12/2015 13:20:16
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
#include "CWinSeh.h"
#include "CException.h"

/////////////////////////////////////////////////////////////////////////////////////////
// windows seh �쳣������
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ZERO_EN                       =   "The exception code is zero.";
const char* GCP_EXCEPTION_ZERO_CN                       =   "�쳣����Ϊ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_UNDEFINED_EN                  =   "The exception code is undefined.";
const char* GCP_EXCEPTION_UNDEFINED_CN                  =   "δ�����쳣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ACCESS_VIOLATION_EN           =   "The thread tried to read from or write to a "
                                                            "virtual address for which it does not have the "
                                                            "appropriate access.";
const char* GCP_EXCEPTION_ACCESS_VIOLATION_CN           =   "�߳�Υ���дû���ʵ�Ȩ�޵������ַ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_EN      =   "The thread tried to access an array element "
                                                            "that is out of bounds and the underlying hardware "
                                                            "supports bounds checking.";
const char* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_CN      =   "�߳��ڵײ�Ӳ��֧�ֵı߽����·�������Խ�硣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_BREAKPOINT_EN                 =   "A breakpoint was encountered.";
const char* GCP_EXCEPTION_BREAKPOINT_CN                 =   "����һ���ϵ㡣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_EN      =   "The thread tried to read or write data that "
                                                            "is misaligned on hardware that does not provide "
                                                            "alignment.For example, 16-bit values must be "
                                                            "aligned on 2-byte boundaries; 32-bit values on "
                                                            "4-byte boundaries, and so on.";
const char* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_CN      =   "�߳���ͼ�ڲ�֧�ֶ����Ӳ���϶�дδ��������ݡ�"
                                                            "���磬16λֵ����2�ֽڶ��룬32λֵ����4�ֽڶ��룬"
                                                            "�Դ����ơ�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_EN       =   "One of the operands in a floating-point operation "
                                                            "is denormal. A denormal value is one that is too "        
                                                            "small to represent as a standard floating-point "
                                                            "value.";
const char* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_CN       =   "���������һ�������������档�������ֵ��ʾ̫"
                                                            "С�����ܱ�ʾһ����׼�ĸ���ֵ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_EN         =   "The thread tried to divide a floating-point "
                                                            "value by a floating-point divisor of zero.";
const char* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_CN         =   "�̸߳�����������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_INEXACT_RESULT_EN         =   "The result of a floating-point operation can "
                                                            "not be represented exactly as a decimal fraction.";
const char* GCP_EXCEPTION_FLT_INEXACT_RESULT_CN         =   "�������Ĳ�������׼ȷ�Ĵ���С����";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_INVALID_OPERATION_EN      =   "This exception represents any floating-point "
                                                             "exception not included in this list.";
const char* GCP_EXCEPTION_FLT_INVALID_OPERATION_CN      =   "����쳣����������б���û���г������������쳣��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_OVERFLOW_EN               =   "The exponent of a floating-point operation "
                                                            "is greater than the magnitude allowed by the "
                                                            "corresponding type.";
const char* GCP_EXCEPTION_FLT_OVERFLOW_CN               =   "���������ָ����������Ӧ���͵����ֵ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_STACK_CHECK_EN            =   "The stack overflowed or underflowed as the "
                                                            "result of a floating-point operation.";
const char* GCP_EXCEPTION_FLT_STACK_CHECK_CN            =   "���������ջԽ����������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_UNDERFLOW_EN              =   "The exponent of a floating-point operation "
                                                            "is less than the magnitude allowed by the "
                                                             "corresponding type.";
const char* GCP_EXCEPTION_FLT_UNDERFLOW_CN              =   "���������ָ��û�г�����Ӧ���͵����ֵ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_EN        =   "The thread tried to execute an invalid instruction.";
const char* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_CN        =   "�߳���ͼִ����Чָ�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_IN_PAGE_ERROR_EN              =   "The thread tried to access a page that was "
                                                            "not present, and the system was unable to load "
                                                            "the page. For example, this exception might occur "
                                                            "if a network connection is lost while running a "
                                                            "program over the network.";
const char* GCP_EXCEPTION_IN_PAGE_ERROR_CN              =   "�߳���ͼ����һ�������ڵ�ҳ�����޷����ص�ҳ��"
                                                            "���磬�쳣���������е��������ʧ���ӵ�ʱ������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_EN         =   "The thread tried to divide an integer value "
                                                            "by an integer divisor of zero.";
const char* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_CN         =   "�߳���ͼ�������㡣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INT_OVERFLOW_EN               =   "The result of an integer operation caused a "
                                                            "carry out of the most significant bit of the result.";
const char* GCP_EXCEPTION_INT_OVERFLOW_CN               =   "���������Ľ��ռ���˽����������λ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INVALID_DISPOSITION_EN        =   "An exception handler returned an invalid "
                                                            "disposition to the exception dispatcher. Programmers "
                                                            "using a high-level language such as C should never "
                                                            "encounter this exception.";
const char* GCP_EXCEPTION_INVALID_DISPOSITION_CN        =   "�쳣���������쳣������������һ����Ч���á�ʹ��"
                                                            "�߼����ԣ�����C���ԣ��ĳ�����Զ������������쳣��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_EN   =   "The thread tried to continue execution after a "
                                                            "noncontinuable exception occurred.";
const char* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_CN   =   "�߳���ͼ��һ�����ɼ���ִ�е��쳣���������ִ�С�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_PRIV_INSTRUCTION_EN           =   "The thread tried to execute an instruction whose "
                                                            "operation is not allowed in the current machine mode.";
const char* GCP_EXCEPTION_PRIV_INSTRUCTION_CN           =   "�߳���ͼִ�е�ǰ����ģʽ��֧�ֵ�ָ�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_SINGLE_STEP_EN                =   "A trace trap or other single-instruction mechanism "
                                                            "signaled that one instruction has been executed.";
const char* GCP_EXCEPTION_SINGLE_STEP_CN                =   "���򵥵�˵�ǣ�������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_STACK_OVERFLOW_EN             =   "The thread used up its stack.";
const char* GCP_EXCEPTION_STACK_OVERFLOW_CN             =   "���򵥵�˵�ǣ�ջ�����";
// --------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CWinSehObj
//        Notes : ��������Ϊȫ�ֶ����ض���SEH������
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinSehObj
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
	CWinSehObj(){  CWinSeh::ResetSeh(); };		            // Construct define
	virtual ~CWinSehObj(){};                                // Destruct define

}; // End of class CWinSehObj
/////////////////////////////////////////////////////////////////////////////////////////

CWinSehObj gWinSehObj;

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CSeToCe
// Full name : CSeToCe::CSeToCe
// Access    : public 
// Brief     : ���캯��
// Parameter : PEXCEPTION_POINTERS pep                      -- �쳣��Ϣ
// Return    : 
// Notes     : 
CWinSeh::CWinSeh(PEXCEPTION_POINTERS pep)
{
    mEr        = *pep->ExceptionRecord;
    mContest   = *pep->ContextRecord;
} // End of function CSeToCe(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MapSetoCe
// Full name : CSeToCe::MapSetoCe
// Access    : public static 
// Brief     : �ض���SEH�쳣������
// Parameter : void
// Return    : void
// Notes     : 
void CWinSeh::ResetSeh(void)
{
    _set_se_translator( TranslatrSeh );
} // End of function MapSetoCe(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : TranslatrSeToCe
// Full name : CSeToCe::TranslatrSeToCe
// Access    : public static 
// Brief     : SEH�쳣������
// Parameter : UINT dwEc,                                   
//             PEXCEPTION_POINTERS pep
// Return    : void _cdecl
// Notes     : 
#include <IOSTREAM>
void _cdecl CWinSeh::TranslatrSeh(UINT dwEc, PEXCEPTION_POINTERS pep)
{
    //std::cout << "Output Seh exception!" << std::endl;
    throw CWinSeh( pep );
} // End of function TranslatrSeToCe(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDesEN
// Full name : CWinSe::GetExpDesEN
// Access    : public static 
// Brief     : ��ȡ�쳣����(Ӣ��)
// Parameter : const DWORD dwExpCode                            -- �쳣����
// Return    : const char*                                      -- �쳣����
// Notes     : 
const char* CWinSeh::GetExpDesEN(const DWORD dwExpCode)
{
    switch ( dwExpCode )
    {
    case 0:
        return GCP_EXCEPTION_ZERO_EN;
    case EXCEPTION_ACCESS_VIOLATION:
        return GCP_EXCEPTION_ACCESS_VIOLATION_EN;
    case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
        return GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_EN;
    case EXCEPTION_BREAKPOINT:
        return GCP_EXCEPTION_BREAKPOINT_EN;
    case EXCEPTION_DATATYPE_MISALIGNMENT:
        return GCP_EXCEPTION_DATATYPE_MISALIGNMENT_EN;
    case EXCEPTION_FLT_DENORMAL_OPERAND:
        return GCP_EXCEPTION_FLT_DENORMAL_OPERAND_EN;
    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
        return GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_EN;
    case EXCEPTION_FLT_INEXACT_RESULT:
        return GCP_EXCEPTION_FLT_INEXACT_RESULT_EN;
    case EXCEPTION_FLT_INVALID_OPERATION:
        return GCP_EXCEPTION_FLT_INVALID_OPERATION_EN;
    case EXCEPTION_FLT_OVERFLOW:
        return GCP_EXCEPTION_FLT_OVERFLOW_EN;
    case EXCEPTION_FLT_STACK_CHECK:
        return GCP_EXCEPTION_FLT_STACK_CHECK_EN;
    case EXCEPTION_FLT_UNDERFLOW:
        return GCP_EXCEPTION_FLT_UNDERFLOW_EN;
    case EXCEPTION_ILLEGAL_INSTRUCTION:
        return GCP_EXCEPTION_ILLEGAL_INSTRUCTION_EN;
    case EXCEPTION_IN_PAGE_ERROR:
        return GCP_EXCEPTION_IN_PAGE_ERROR_EN;
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
        return GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_EN;
    case EXCEPTION_INT_OVERFLOW:
        return GCP_EXCEPTION_INT_OVERFLOW_EN;
    case EXCEPTION_INVALID_DISPOSITION:
        return GCP_EXCEPTION_INVALID_DISPOSITION_EN;
    case EXCEPTION_NONCONTINUABLE_EXCEPTION:
        return GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_EN;
    case EXCEPTION_PRIV_INSTRUCTION:
        return GCP_EXCEPTION_PRIV_INSTRUCTION_EN;
    case EXCEPTION_SINGLE_STEP:
        return GCP_EXCEPTION_SINGLE_STEP_EN;
    case EXCEPTION_STACK_OVERFLOW:
        return GCP_EXCEPTION_STACK_OVERFLOW_EN;
    default:
        break;
    } // End of switch

    return GCP_EXCEPTION_UNDEFINED_EN;
} // End of function GetExpDes(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDesCN
// Full name : CWinSe::GetExpDesCN
// Access    : public static 
// Brief     : ��ȡ�쳣����(����)
// Parameter : const DWORD dwExpCode                                    -- �쳣����
// Return    : const char*                                              -- �쳣����
// Notes     : 
const char* CWinSeh::GetExpDesCN(const DWORD dwExpCode)
{
    switch ( dwExpCode )
    {
    case 0:
        return GCP_EXCEPTION_ZERO_CN;
    case EXCEPTION_ACCESS_VIOLATION:
        return GCP_EXCEPTION_ACCESS_VIOLATION_CN;
    case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
        return GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_CN;
    case EXCEPTION_BREAKPOINT:
        return GCP_EXCEPTION_BREAKPOINT_CN;
    case EXCEPTION_DATATYPE_MISALIGNMENT:
        return GCP_EXCEPTION_DATATYPE_MISALIGNMENT_CN;
    case EXCEPTION_FLT_DENORMAL_OPERAND:
        return GCP_EXCEPTION_FLT_DENORMAL_OPERAND_CN;
    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
        return GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_CN;
    case EXCEPTION_FLT_INEXACT_RESULT:
        return GCP_EXCEPTION_FLT_INEXACT_RESULT_CN;
    case EXCEPTION_FLT_INVALID_OPERATION:
        return GCP_EXCEPTION_FLT_INVALID_OPERATION_CN;
    case EXCEPTION_FLT_OVERFLOW:
        return GCP_EXCEPTION_FLT_OVERFLOW_CN;
    case EXCEPTION_FLT_STACK_CHECK:
        return GCP_EXCEPTION_FLT_STACK_CHECK_CN;
    case EXCEPTION_FLT_UNDERFLOW:
        return GCP_EXCEPTION_FLT_UNDERFLOW_CN;
    case EXCEPTION_ILLEGAL_INSTRUCTION:
        return GCP_EXCEPTION_ILLEGAL_INSTRUCTION_CN;
    case EXCEPTION_IN_PAGE_ERROR:
        return GCP_EXCEPTION_IN_PAGE_ERROR_CN;
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
        return GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_CN;
    case EXCEPTION_INT_OVERFLOW:
        return GCP_EXCEPTION_INT_OVERFLOW_CN;
    case EXCEPTION_INVALID_DISPOSITION:
        return GCP_EXCEPTION_INVALID_DISPOSITION_CN;
    case EXCEPTION_NONCONTINUABLE_EXCEPTION:
        return GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_CN;
    case EXCEPTION_PRIV_INSTRUCTION:
        return GCP_EXCEPTION_PRIV_INSTRUCTION_CN;
    case EXCEPTION_SINGLE_STEP:
        return GCP_EXCEPTION_SINGLE_STEP_CN;
    case EXCEPTION_STACK_OVERFLOW:
        return GCP_EXCEPTION_STACK_OVERFLOW_CN;
    default:
        break;
    } // End of switch

    return GCP_EXCEPTION_UNDEFINED_CN;
} // End of function GetExpDesCN(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDes
// Full name : CWinSeh::GetExpDes
// Access    : public static 
// Brief     : ��ȡ�쳣����
// Parameter : const DWORD dwExpCode,                                   -- �쳣����
//             const DWORD dwLanguage/*=LANG_ENGLISH */                 -- ���Դ��룬���windows���Զ�����룬��֧�����ģ�Ӣ�ġ�
// Return    : const char*
// Notes     : 
const char* CWinSeh::SGetExpDes(const DWORD dwExpCode, const DWORD dwLanguage/*=LANG_ENGLISH */)
{
    switch( dwLanguage )
    {
    case LANG_ENGLISH:
        return GetExpDesEN( dwExpCode );
    case LANG_CHINESE:
        return GetExpDesCN( dwExpCode );
    default:
        break;
    }

    return GetExpDesEN( dwExpCode );
} // End of function GetExpDes(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDes
// Full name : CWinSeh::GetExpDes
// Access    : public static 
// Brief     : ��ȡ�û��쳣����
// Parameter : const DWORD dwLanguage/*=LANG_ENGLISH */                 -- ���Դ��룬���windows���Զ�����룬��֧�����ģ�Ӣ�ġ�
// Return    : const char*                                              -- �쳣����
// Notes     : 
const char* CWinSeh::GetExpDes(const DWORD dwLanguage/*=LANG_ENGLISH */)
{
    return SGetExpDes(mEr.ExceptionCode, dwLanguage);
} // End of function GetExpDes(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpCode
// Full name : CWinSeh::GetExpCode
// Access    : public 
// Brief     : ��ȡ�쳣����
// Parameter : 
// Return    : const DWORD                                              -- �쳣����
// Notes     : 
DWORD CWinSeh::GetExpCode()
{
    return mEr.ExceptionCode;
} // End of function GetExpCode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CSeToCe.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
