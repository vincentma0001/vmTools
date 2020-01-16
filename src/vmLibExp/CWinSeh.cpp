/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinSeh.cpp
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 
// Create time  : 2020/01/02 21:46:31
// Modify time  : 2020/01/02 21:46:31
// Note         :
//
//     [Q 0002] - TODO����Ҫ���setlocal��������������
//     [Q 0001] - TODO����Ҫ������ֽڴ�����Ϣ�������
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warnings :
// Example : #pragma warning(disable:4996)

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>

// Config files included
#include <vmCfg.h>

// platform files included
#include <windows.h>

// Used files included
#include <vmLibBase/vmUtil.h>

// Declare file included
#include "CWinSeh.h"
/////////////////////////////////////////////////////////////////////////////////////////
// windows seh �쳣������
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ZERO_EN                  = "The exception code is zero.";
const char* GCP_EXCEPTION_ZERO_CN                  = "�쳣����Ϊ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_UNDEFINED_EN             = "The exception code is undefined.";
const char* GCP_EXCEPTION_UNDEFINED_CN             = "δ�����쳣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ACCESS_VIOLATION_EN      = "The thread tried to read from or write to a "
                                                     "virtual address for which it does not have the "
                                                     "appropriate access.";
const char* GCP_EXCEPTION_ACCESS_VIOLATION_CN      = "�߳�Υ���дû���ʵ�Ȩ�޵������ַ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_EN = "The thread tried to access an array element "
                                                     "that is out of bounds and the underlying hardware "
                                                     "supports bounds checking.";
const char* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_CN = "�߳��ڵײ�Ӳ��֧�ֵı߽����·�������Խ�硣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_BREAKPOINT_EN            = "A breakpoint was encountered.";
const char* GCP_EXCEPTION_BREAKPOINT_CN            = "����һ���ϵ㡣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_EN = "The thread tried to read or write data that "
                                                     "is misaligned on hardware that does not provide "
                                                     "alignment.For example, 16-bit values must be "
                                                     "aligned on 2-byte boundaries; 32-bit values on "
                                                     "4-byte boundaries, and so on.";
const char* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_CN = "�߳���ͼ�ڲ�֧�ֶ����Ӳ���϶�дδ��������ݡ�"
                                                     "���磬16λֵ����2�ֽڶ��룬32λֵ����4�ֽڶ��룬"
                                                     "�Դ����ơ�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_EN = "One of the operands in a floating-point operation "
                                                    "is denormal. A denormal value is one that is too "
                                                    "small to represent as a standard floating-point "
                                                    "value.";
const char* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_CN = "���������һ�������������档�������ֵ��ʾ̫"
                                                    "С�����ܱ�ʾһ����׼�ĸ���ֵ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_EN   = "The thread tried to divide a floating-point "
                                                    "value by a floating-point divisor of zero.";
const char* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_CN   = "�̸߳�����������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_INEXACT_RESULT_EN   = "The result of a floating-point operation can "
                                                    "not be represented exactly as a decimal fraction.";
const char* GCP_EXCEPTION_FLT_INEXACT_RESULT_CN   = "�������Ĳ�������׼ȷ�Ĵ���С����";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_INVALID_OPERATION_EN = "This exception represents any floating-point "
                                                     "exception not included in this list.";
const char* GCP_EXCEPTION_FLT_INVALID_OPERATION_CN = "����쳣����������б���û���г������������쳣��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_OVERFLOW_EN         = "The exponent of a floating-point operation "
                                                    "is greater than the magnitude allowed by the "
                                                    "corresponding type.";
const char* GCP_EXCEPTION_FLT_OVERFLOW_CN         = "���������ָ����������Ӧ���͵����ֵ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_STACK_CHECK_EN      = "The stack overflowed or underflowed as the "
                                                    "result of a floating-point operation.";
const char* GCP_EXCEPTION_FLT_STACK_CHECK_CN      = "���������ջԽ����������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_UNDERFLOW_EN        = "The exponent of a floating-point operation "
                                                    "is less than the magnitude allowed by the "
                                                    "corresponding type.";
const char* GCP_EXCEPTION_FLT_UNDERFLOW_CN        = "���������ָ��û�г�����Ӧ���͵����ֵ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_EN  = "The thread tried to execute an invalid instruction.";
const char* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_CN  = "�߳���ͼִ����Чָ�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_IN_PAGE_ERROR_EN        = "The thread tried to access a page that was "
                                                    "not present, and the system was unable to load "
                                                    "the page. For example, this exception might occur "
                                                    "if a network connection is lost while running a "
                                                    "program over the network.";
const char* GCP_EXCEPTION_IN_PAGE_ERROR_CN        = "�߳���ͼ����һ�������ڵ�ҳ�����޷����ص�ҳ��"
                                                    "���磬�쳣���������е��������ʧ���ӵ�ʱ������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_EN   = "The thread tried to divide an integer value "
                                                    "by an integer divisor of zero.";
const char* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_CN   = "�߳���ͼ�������㡣";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INT_OVERFLOW_EN         = "The result of an integer operation caused a "
                                                    "carry out of the most significant bit of the result.";
const char* GCP_EXCEPTION_INT_OVERFLOW_CN         = "���������Ľ��ռ���˽����������λ��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INVALID_DISPOSITION_EN  = "An exception handler returned an invalid "
                                                    "disposition to the exception dispatcher. Programmers "
                                                    "using a high-level language such as C should never "
                                                    "encounter this exception.";
const char* GCP_EXCEPTION_INVALID_DISPOSITION_CN = "�쳣���������쳣������������һ����Ч���á�ʹ��"
                                                   "�߼����ԣ�����C���ԣ��ĳ�����Զ������������쳣��";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_EN = "The thread tried to continue execution after a "
                                                        "noncontinuable exception occurred.";
const char* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_CN = "�߳���ͼ��һ�����ɼ���ִ�е��쳣���������ִ�С�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_PRIV_INSTRUCTION_EN    = "The thread tried to execute an instruction whose "
                                                   "operation is not allowed in the current machine mode.";
const char* GCP_EXCEPTION_PRIV_INSTRUCTION_CN    = "�߳���ͼִ�е�ǰ����ģʽ��֧�ֵ�ָ�";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_SINGLE_STEP_EN         = "A trace trap or other single-instruction mechanism "
                                                   "signaled that one instruction has been executed.";
const char* GCP_EXCEPTION_SINGLE_STEP_CN         = "���򵥵�˵�ǣ�������";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_STACK_OVERFLOW_EN      = "The thread used up its stack.";
const char* GCP_EXCEPTION_STACK_OVERFLOW_CN      = "���򵥵�˵�ǣ�ջ�����";
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDesEN
// Brief     : ��ȡ�쳣����(Ӣ��)
// Return    : const char*                                      -- �쳣����
// Parameter : const DWORD dwExpCode                            -- �쳣����
const char* v_GetExpDesEN(const DWORD dwExpCode)
{
    switch (dwExpCode)
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
// Brief     : ��ȡ�쳣����(����)
// Return    : const char*                                              -- �쳣����
// Parameter : const DWORD dwExpCode                                    -- �쳣����
const char* v_GetExpDesCN(const DWORD dwExpCode)
{
    switch (dwExpCode)
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

const char* v_GetExpDes(const DWORD dwExpCode, const DWORD dwLanguage)
{
    if (dwLanguage == LANG_ENGLISH )
    {   
        return v_GetExpDesEN(dwExpCode);
    }
    else if( dwLanguage == LANG_CHINESE_SIMPLIFIED )   
    {
        return v_GetExpDesCN(dwExpCode);
    }

    return nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinSeh(...)
// Brief     :
// Return    : 
CWinSeh::CWinSeh()
{
    vMemZero(mEr);
    vMemZero(mContest);
}
// End of function CWinSeh(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinSeh(...)
// Brief     :
// Return    : 
// Parameter : PEXCEPTION_POINTERS pep
CWinSeh::CWinSeh(PEXCEPTION_POINTERS pep)
{
    mEr      = *pep->ExceptionRecord;
    mContest = *pep->ContextRecord;
}
// End of function CWinSeh(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CWinSeh(...)
// Brief     :
// Return    : 
CWinSeh::~CWinSeh()
{

}
// End of function ~CWinSeh(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinSeh(...)
// Brief     :
// Return    : 
// Parameter : const CWinSeh & obj
CWinSeh::CWinSeh(const CWinSeh& obj)
{
    *this = obj;
}
// End of function CWinSeh(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : vm::CWinSeh&
// Parameter : const CWinSeh & obj
vm::CWinSeh& CWinSeh::operator=(const CWinSeh& obj)
{
    mEr      = obj.mEr;
    mContest = obj.mContest;
    
    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDes(...)
// Brief     :
// Return    : const char*
const char* CWinSeh::cs_Msg(const DWORD dwLanguage /*= LANG_ENGLISH*/) const
{
    return v_GetExpDes(mEr.ExceptionCode, dwLanguage);
}
// End of function GetExpDes(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpCode(...)
// Brief     :
// Return    : DWORD
const DWORD CWinSeh::code() const
{
    return mEr.ExceptionCode;
}
// End of function GetExpCode(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ResetSeh(...)
// Brief     :
// Return    : void
// Parameter : void
void CWinSeh::ResetSeh(void)
{
    _set_se_translator(TranslatrSeh);
}
// End of function ResetSeh(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : TranslatrSeh(...)
// Brief     :
// Return    : void _cdecl
// Parameter : UINT dwEc
// Parameter : PEXCEPTION_POINTERS pep
void _cdecl CWinSeh::TranslatrSeh(UINT dwEc, PEXCEPTION_POINTERS pep)
{
    throw vm::CWinSeh(pep);
}
// End of function TranslatrSeh(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinSeh.cpp
/////////////////////////////////////////////////////////////////////////////////////////
