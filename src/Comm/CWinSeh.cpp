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
// windows seh 异常描述：
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ZERO_EN                       =   "The exception code is zero.";
const char* GCP_EXCEPTION_ZERO_CN                       =   "异常代码为零";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_UNDEFINED_EN                  =   "The exception code is undefined.";
const char* GCP_EXCEPTION_UNDEFINED_CN                  =   "未定义异常";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ACCESS_VIOLATION_EN           =   "The thread tried to read from or write to a "
                                                            "virtual address for which it does not have the "
                                                            "appropriate access.";
const char* GCP_EXCEPTION_ACCESS_VIOLATION_CN           =   "线程违规读写没有适当权限的虚拟地址。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_EN      =   "The thread tried to access an array element "
                                                            "that is out of bounds and the underlying hardware "
                                                            "supports bounds checking.";
const char* GCP_EXCEPTION_ARRAY_BOUNDS_EXCEEDED_CN      =   "线程在底层硬件支持的边界检查下访问数组越界。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_BREAKPOINT_EN                 =   "A breakpoint was encountered.";
const char* GCP_EXCEPTION_BREAKPOINT_CN                 =   "遇到一个断点。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_EN      =   "The thread tried to read or write data that "
                                                            "is misaligned on hardware that does not provide "
                                                            "alignment.For example, 16-bit values must be "
                                                            "aligned on 2-byte boundaries; 32-bit values on "
                                                            "4-byte boundaries, and so on.";
const char* GCP_EXCEPTION_DATATYPE_MISALIGNMENT_CN      =   "线程试图在不支持对齐的硬件上读写未对齐的数据。"
                                                            "例如，16位值必须2字节对齐，32位值必须4字节对齐，"
                                                            "以此类推。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_EN       =   "One of the operands in a floating-point operation "
                                                            "is denormal. A denormal value is one that is too "        
                                                            "small to represent as a standard floating-point "
                                                            "value.";
const char* GCP_EXCEPTION_FLT_DENORMAL_OPERAND_CN       =   "浮点操作的一个操作数不正规。不正规的值表示太"
                                                            "小而不能表示一个标准的浮点值。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_EN         =   "The thread tried to divide a floating-point "
                                                            "value by a floating-point divisor of zero.";
const char* GCP_EXCEPTION_FLT_DIVIDE_BY_ZERO_CN         =   "线程浮点除零操作。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_INEXACT_RESULT_EN         =   "The result of a floating-point operation can "
                                                            "not be represented exactly as a decimal fraction.";
const char* GCP_EXCEPTION_FLT_INEXACT_RESULT_CN         =   "浮点结果的操作不能准确的代替小数。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_INVALID_OPERATION_EN      =   "This exception represents any floating-point "
                                                             "exception not included in this list.";
const char* GCP_EXCEPTION_FLT_INVALID_OPERATION_CN      =   "这个异常代表了这个列表里没有列出的其他浮点异常。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_OVERFLOW_EN               =   "The exponent of a floating-point operation "
                                                            "is greater than the magnitude allowed by the "
                                                            "corresponding type.";
const char* GCP_EXCEPTION_FLT_OVERFLOW_CN               =   "浮点操作的指数超过了相应类型的最大值。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_STACK_CHECK_EN            =   "The stack overflowed or underflowed as the "
                                                            "result of a floating-point operation.";
const char* GCP_EXCEPTION_FLT_STACK_CHECK_CN            =   "浮点操作的栈越界或下溢出。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_FLT_UNDERFLOW_EN              =   "The exponent of a floating-point operation "
                                                            "is less than the magnitude allowed by the "
                                                             "corresponding type.";
const char* GCP_EXCEPTION_FLT_UNDERFLOW_CN              =   "浮点操作的指数没有超过相应类型的最大值。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_EN        =   "The thread tried to execute an invalid instruction.";
const char* GCP_EXCEPTION_ILLEGAL_INSTRUCTION_CN        =   "线程试图执行无效指令。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_IN_PAGE_ERROR_EN              =   "The thread tried to access a page that was "
                                                            "not present, and the system was unable to load "
                                                            "the page. For example, this exception might occur "
                                                            "if a network connection is lost while running a "
                                                            "program over the network.";
const char* GCP_EXCEPTION_IN_PAGE_ERROR_CN              =   "线程试图访问一个不存在的页或者无法加载的页。"
                                                            "例如，异常可能在运行的网络程序丢失连接的时候发生。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_EN         =   "The thread tried to divide an integer value "
                                                            "by an integer divisor of zero.";
const char* GCP_EXCEPTION_INT_DIVIDE_BY_ZERO_CN         =   "线程试图整数除零。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INT_OVERFLOW_EN               =   "The result of an integer operation caused a "
                                                            "carry out of the most significant bit of the result.";
const char* GCP_EXCEPTION_INT_OVERFLOW_CN               =   "整数操作的结果占用了结果的最大符号位。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_INVALID_DISPOSITION_EN        =   "An exception handler returned an invalid "
                                                            "disposition to the exception dispatcher. Programmers "
                                                            "using a high-level language such as C should never "
                                                            "encounter this exception.";
const char* GCP_EXCEPTION_INVALID_DISPOSITION_CN        =   "异常处理程序给异常调度器返回了一个无效配置。使用"
                                                            "高级语言（例如C语言）的程序永远不会遇到这个异常。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_EN   =   "The thread tried to continue execution after a "
                                                            "noncontinuable exception occurred.";
const char* GCP_EXCEPTION_NONCONTINUABLE_EXCEPTION_CN   =   "线程试图在一个不可继续执行的异常发生后继续执行。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_PRIV_INSTRUCTION_EN           =   "The thread tried to execute an instruction whose "
                                                            "operation is not allowed in the current machine mode.";
const char* GCP_EXCEPTION_PRIV_INSTRUCTION_CN           =   "线程试图执行当前机器模式不支持的指令。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_SINGLE_STEP_EN                =   "A trace trap or other single-instruction mechanism "
                                                            "signaled that one instruction has been executed.";
const char* GCP_EXCEPTION_SINGLE_STEP_CN                =   "（简单的说是）单步。";
// --------------------------------------------------------------------------------------
const char* GCP_EXCEPTION_STACK_OVERFLOW_EN             =   "The thread used up its stack.";
const char* GCP_EXCEPTION_STACK_OVERFLOW_CN             =   "（简单的说是）栈溢出。";
// --------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CWinSehObj
//        Notes : 此类设置为全局对象重定义SEH处理函数
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
// Brief     : 构造函数
// Parameter : PEXCEPTION_POINTERS pep                      -- 异常信息
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
// Brief     : 重定义SEH异常处理函数
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
// Brief     : SEH异常处理函数
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
// Brief     : 获取异常描述(英文)
// Parameter : const DWORD dwExpCode                            -- 异常代码
// Return    : const char*                                      -- 异常描术
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
// Brief     : 获取异常描述(中文)
// Parameter : const DWORD dwExpCode                                    -- 异常代码
// Return    : const char*                                              -- 异常描述
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
// Brief     : 获取异常描术
// Parameter : const DWORD dwExpCode,                                   -- 异常代码
//             const DWORD dwLanguage/*=LANG_ENGLISH */                 -- 语言代码，详见windows语言定义代码，现支持中文，英文。
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
// Brief     : 获取用户异常描述
// Parameter : const DWORD dwLanguage/*=LANG_ENGLISH */                 -- 语言代码，详见windows语言定义代码，现支持中文，英文。
// Return    : const char*                                              -- 异常描术
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
// Brief     : 获取异常代码
// Parameter : 
// Return    : const DWORD                                              -- 异常代码
// Notes     : 
DWORD CWinSeh::GetExpCode()
{
    return mEr.ExceptionCode;
} // End of function GetExpCode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CSeToCe.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
