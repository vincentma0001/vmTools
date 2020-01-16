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
//     [Q 0002] - TODO：需要解决setlocal多国语言输出问题
//     [Q 0001] - TODO：需要解决多字节错误信息输出问题
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
// windows seh 异常描述：
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_ZERO_EN                  = vT("The exception code is zero.");
const tChar* GCP_EXCEPTION_ZERO_CN                  = vT("异常代码为零");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_UNDEFINED_EN             = vT("The exception code is undefined.");
const tChar* GCP_EXCEPTION_UNDEFINED_CN             = vT("未定义异常");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_ACCESS_VIOLATION_EN      = vT("The thread tried to read from or write to a ")
                                                      vT("virtual address for which it does not have the ")
                                                      vT("appropriate access.");
const tChar* GCP_EXCEPTION_ACCESS_VIOLATION_CN      = vT("线程违规读写没有适当权限的虚拟地址。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_EN = vT("The thread tried to access an array element ")
                                                      vT("that is out of bounds and the underlying hardware ")
                                                      vT("supports bounds checking.");
const tChar* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_CN = vT("线程在底层硬件支持的边界检查下访问数组越界。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_BREAKPOINT_EN            = vT("A breakpoint was encountered.");
const tChar* GCP_EXCEPTION_BREAKPOINT_CN            = vT("遇到一个断点。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_EN = vT("The thread tried to read or write data that ")
                                                      vT("is misaligned on hardware that does not provide ")
                                                      vT("alignment.For example, 16-bit values must be ")
                                                      vT("aligned on 2-byte boundaries; 32-bit values on ")
                                                      vT("4-byte boundaries, and so on.");
const tChar* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_CN = vT("线程试图在不支持对齐的硬件上读写未对齐的数据。")
                                                      vT("例如，16位值必须2字节对齐，32位值必须4字节对齐，")
                                                      vT("以此类推。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_EN = vT("One of the operands in a floating-point operation ")
                                                     vT("is denormal. A denormal value is one that is too ")
                                                     vT("small to represent as a standard floating-point ")
                                                     vT("value.");
const tChar* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_CN = vT("浮点操作的一个操作数不正规。不正规的值表示太")
                                                     vT("小而不能表示一个标准的浮点值。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_EN   = vT("The thread tried to divide a floating-point ")
                                                     vT("value by a floating-point divisor of zero.");
const tChar* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_CN   = vT("线程浮点除零操作。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_INEXACT_RESULT_EN   = vT("The result of a floating-point operation can ")
                                                     vT("not be represented exactly as a decimal fraction.");
const tChar* GCP_EXCEPTION_FLT_INEXACT_RESULT_CN   = vT("浮点结果的操作不能准确的代替小数。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_INVALID_OPERATION_EN = vT("This exception represents any floating-point ")
                                                      vT("exception not included in this list.");
const tChar* GCP_EXCEPTION_FLT_INVALID_OPERATION_CN = vT("这个异常代表了这个列表里没有列出的其他浮点异常。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_OVERFLOW_EN         = vT("The exponent of a floating-point operation ")
                                                     vT("is greater than the magnitude allowed by the ")
                                                     vT("corresponding type.");
const tChar* GCP_EXCEPTION_FLT_OVERFLOW_CN         = vT("浮点操作的指数超过了相应类型的最大值。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_STACK_CHECK_EN      = vT("The stack overflowed or underflowed as the ")
                                                     vT("result of a floating-point operation.");
const tChar* GCP_EXCEPTION_FLT_STACK_CHECK_CN      = vT("浮点操作的栈越界或下溢出。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_FLT_UNDERFLOW_EN        = vT("The exponent of a floating-point operation ")
                                                     vT("is less than the magnitude allowed by the ")
                                                     vT("corresponding type.");
const tChar* GCP_EXCEPTION_FLT_UNDERFLOW_CN        = vT("浮点操作的指数没有超过相应类型的最大值。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_EN  = vT("The thread tried to execute an invalid instruction.");
const tChar* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_CN  = vT("线程试图执行无效指令。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_IN_PAGE_ERROR_EN        = vT("The thread tried to access a page that was ")
                                                     vT("not present, and the system was unable to load ")
                                                     vT("the page. For example, this exception might occur ")
                                                     vT("if a network connection is lost while running a ")
                                                     vT("program over the network.");
const tChar* GCP_EXCEPTION_IN_PAGE_ERROR_CN        = vT("线程试图访问一个不存在的页或者无法加载的页。")
                                                     vT("例如，异常可能在运行的网络程序丢失连接的时候发生。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_EN   = vT("The thread tried to divide an integer value ")
                                                     vT("by an integer divisor of zero.");
const tChar* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_CN   = vT("线程试图整数除零。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_INT_OVERFLOW_EN         = vT("The result of an integer operation caused a ")
                                                     vT("carry out of the most significant bit of the result.");
const tChar* GCP_EXCEPTION_INT_OVERFLOW_CN         = vT("整数操作的结果占用了结果的最大符号位。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_INVALID_DISPOSITION_EN  = vT("An exception handler returned an invalid ")
                                                     vT("disposition to the exception dispatcher. Programmers ")
                                                     vT("using a high-level language such as C should never ")
                                                     vT("encounter this exception.");
const tChar* GCP_EXCEPTION_INVALID_DISPOSITION_CN =  vT("异常处理程序给异常调度器返回了一个无效配置。使用")
                                                     vT("高级语言（例如C语言）的程序永远不会遇到这个异常。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_EN = vT("The thread tried to continue execution after a ")
                                                         vT("noncontinuable exception occurred.");
const tChar* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_CN = vT("线程试图在一个不可继续执行的异常发生后继续执行。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_PRIV_INSTRUCTION_EN    = vT("The thread tried to execute an instruction whose ")
                                                    vT("operation is not allowed in the current machine mode.");
const tChar* GCP_EXCEPTION_PRIV_INSTRUCTION_CN    = vT("线程试图执行当前机器模式不支持的指令。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_SINGLE_STEP_EN         = vT("A trace trap or other single-instruction mechanism ")
                                                    vT("signaled that one instruction has been executed.");
const tChar* GCP_EXCEPTION_SINGLE_STEP_CN         = vT("（简单的说是）单步。");
// --------------------------------------------------------------------------------------
const tChar* GCP_EXCEPTION_STACK_OVERFLOW_EN      = vT("The thread used up its stack.");
const tChar* GCP_EXCEPTION_STACK_OVERFLOW_CN      = vT("（简单的说是）栈溢出。");
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExpDesEN
// Brief     : 获取异常描述(英文)
// Return    : const tChar*                                      -- 异常描术
// Parameter : const DWORD dwExpCode                            -- 异常代码
const tChar* v_GetExpDesEN(const DWORD dwExpCode)
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
// Brief     : 获取异常描述(中文)
// Return    : const tChar*                                              -- 异常描述
// Parameter : const DWORD dwExpCode                                    -- 异常代码
const tChar* v_GetExpDesCN(const DWORD dwExpCode)
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

const tChar* v_GetExpDes(const DWORD dwExpCode, const DWORD dwLanguage)
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
// Return    : const tChar*
const tChar* CWinSeh::cs_Msg(const DWORD dwLanguage /*= LANG_ENGLISH*/) const
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
