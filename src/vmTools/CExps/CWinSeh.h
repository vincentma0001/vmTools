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
// Describes an exception.描述异常的结构体
// 
//  Syntax C++
//  typedef struct _EXCEPTION_RECORD {
//      DWORD                       ExceptionCode;                         // 产生异常的原因。
//      DWORD                       ExceptionFlags;                        // 异常标志。
//      struct _EXCEPTION_RECORD    *ExceptionRecord;                      // 指向EXCEPTION_RECORD结构体的指针。
//      PVOID                       ExceptionAddress;                      // 异常发生的地址。
//      DWORD                       NumberParameters;                      // 与异常相关的参数个数。
//      ULONG_PTR                   ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
//                                                                         // 用于描述异常的附加参数的数组。
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
//                            产生异常的原因。这是一个硬件异常产生的代码或者由RaiseException
//                        函数指定产生的软件异常码。
//
// --------------------------------------------------------------------------------------
//
// Value	                                Meaning
// EXCEPTION_ACCESS_VIOLATION                   The thread tried to read from or write to a 
//                                          virtual address for which it does not have the 
//                                          appropriate access.
//                                              线程违规读写没有适当权限的虚拟地址。
// EXCEPTION_ARRAY_BOUNDS_EXCEEDED              The thread tried to access an array element 
//                                          that is out of bounds and the underlying hardware 
//                                          supports bounds checking.
//                                              线程在底层硬件支持的边界检查下访问数组越界。
// EXCEPTION_BREAKPOINT                         A breakpoint was encountered.
//                                              遇到一个断点。
// EXCEPTION_DATATYPE_MISALIGNMENT              The thread tried to read or write data that 
//                                          is misaligned on hardware that does not provide 
//                                          alignment.For example, 16-bit values must be 
//                                          aligned on 2-byte boundaries; 32-bit values on 
//                                          4-byte boundaries, and so on.
//                                              线程试图在不支持对齐的硬件上读写未对齐的数据。
//                                          例如，16位值必须2字节对齐，32位值必须4字节对齐，
//                                          以此类推。
// EXCEPTION_FLT_DENORMAL_OPERAND               One of the operands in a floating-point operation 
//                                          is denormal. A denormal value is one that is too 
//                                          small to represent as a standard floating-point 
//                                          value.
//                                              浮点操作的一个操作数不正规。不正规的值表示太
//                                          小而不能表示一个标准的浮点值。
// EXCEPTION_FLT_DIVIDE_BY_ZERO                 The thread tried to divide a floating-point 
//                                          value by a floating-point divisor of zero.
//                                              线程浮点除零操作。
// EXCEPTION_FLT_INEXACT_RESULT                 The result of a floating-point operation can 
//                                          not be represented exactly as a decimal fraction.
//                                              浮点结果的操作不能准确的代替小数。
// EXCEPTION_FLT_INVALID_OPERATION              This exception represents any floating-point 
//                                          exception not included in this list.
//                                              这个异常代表了这个列表里没有列出的其他浮点异常。
// EXCEPTION_FLT_OVERFLOW                       The exponent of a floating-point operation 
//                                          is greater than the magnitude allowed by the 
//                                          corresponding type.
//                                              浮点操作的指数超过了相应类型的最大值。
// EXCEPTION_FLT_STACK_CHECK                    The stack overflowed or underflowed as the 
//                                          result of a floating-point operation.
//                                              浮点操作的栈越界或下溢出。
// EXCEPTION_FLT_UNDERFLOW                      The exponent of a floating-point operation 
//                                          is less than the magnitude allowed by the 
//                                          corresponding type.
//                                              浮点操作的指数没有超过相应类型的最大值。
// EXCEPTION_ILLEGAL_INSTRUCTION                The thread tried to execute an invalid instruction.
//                                              线程试图执行无效指令。
// EXCEPTION_IN_PAGE_ERROR                      The thread tried to access a page that was 
//                                          not present, and the system was unable to load 
//                                          the page. For example, this exception might occur 
//                                          if a network connection is lost while running a 
//                                          program over the network.
//                                              线程试图访问一个不存在的页或者无法加载的页。
//                                          例如，异常可能在运行的网络程序丢失连接的时候发生。
// EXCEPTION_INT_DIVIDE_BY_ZERO                 The thread tried to divide an integer value 
//                                          by an integer divisor of zero.
//                                              线程试图整数除零。
// EXCEPTION_INT_OVERFLOW                       The result of an integer operation caused a 
//                                          carry out of the most significant bit of the result.
//                                              整数操作的结果占用了结果的最大符号位。
// EXCEPTION_INVALID_DISPOSITION                An exception handler returned an invalid 
//                                          disposition to the exception dispatcher. Programmers 
//                                          using a high-level language such as C should never 
//                                          encounter this exception.
//                                              异常处理程序给异常调度器返回了一个无效配置。使用
//                                          高级语言（例如C语言）的程序永远不会遇到这个异常。
// EXCEPTION_NONCONTINUABLE_EXCEPTION           The thread tried to continue execution after a 
//                                          noncontinuable exception occurred.
//                                              线程试图在一个不可继续执行的异常发生后继续执行。
// EXCEPTION_PRIV_INSTRUCTION                   The thread tried to execute an instruction whose 
//                                          operation is not allowed in the current machine mode.
//                                              线程试图执行当前机器模式不支持的指令。
// EXCEPTION_SINGLE_STEP                        A trace trap or other single-instruction mechanism 
//                                          signaled that one instruction has been executed.
//                                              （简单的说是）单步。
// EXCEPTION_STACK_OVERFLOW                     The thread used up its stack.
//                                              （简单的说是）栈溢出。
//
//      Another exception code is likely to occur when debugging console processes. It does not 
// arise because of a programming error. TheLOG_CONTROL_C exception code occurs when CTRL+C is 
// input to a console process that handles CTRL+C signals and is being debugged. This exception 
// code is not meant to be handled by applications.It is raised only for the benefit of the debugger, 
// and is raised only when a debugger is attached to the console process.
//      其他的异常在调试控制台程序的时候可能发生。因为编程的错误可能不会发生。LOG_CONTROL_C异常
// 码在调试控制台程序时输入CTRL+C来处理CTRL+C信号的时候发生。 这个异常码并不会被应用程序处理。
// 它的产生只是更好的为调试器服务，也只在调试器附加到控制台程序的时候发生。
//
// --------------------------------------------------------------------------------------
//
// ExceptionFlags               The exception flags. This member can be either zero, indicating 
//                          a continuable exception,or EXCEPTION_NONCONTINUABLE indicating a 
//                          noncontinuable exception. Any attempt to continue execution after 
//                          a noncontinuable exception causes the EXCEPTION_NONCONTINUABLE_EXCEPTION 
//                          exception.
//                              这个参数可以是0，表示可继续执行的异常，也可以是EXCEPTION_NONCONTINUABLE
//                          表示不可继续执行的异常。任何试图在不可继续执行的异常发生后继续
//                          执行会产生EXCEPTION_NONCONTINUABLE_EXCEPTION异常。
//
// --------------------------------------------------------------------------------------
//
// ExceptionRecord              A pointer to an associated EXCEPTION_RECORD structure. Exception 
//                          records can be chained together to provide additional information 
//                          when nested exceptions occur.
//                              当嵌套异常发生的时候，异常记录可以形成一个链来提供额外的信息。
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
//                              这是theExceptionInformation数组的元素个数。
//
// --------------------------------------------------------------------------------------
//
// ExceptionInformation         An array of additional arguments that describe the exception. 
//                          The RaiseException function can specify this array of arguments. 
//                          RaiseException For most exception codes, the array elements are 
//                          undefined. The following table describes the exception codes 
//                          whose array elements are defined.
//                              函数可以指定这个参数数组。对大多数异常码而言，这个数组元素
//                          是未定义的。下面的表格展示了哪些异常码的数组元素是定义了的。
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
//                                              数组的第一个元素包含了一个读写标志，表示引起
//                                          访问违规的操作类型。如果这个值为0，表示线程试图
//                                          读取不可访问的数据。如果这个值为1，表示线程试图
//                                          写入不可访问的地址。如果这个值是8，表示线程线程
//                                          引发了一个用户模式的DEP违规。
//                                              The second array element specifies the virtual 
//                                          address of the inaccessible data.
//                                              数组的第二个元素指定了不可访问数据的虚拟地址。
// EXCEPTION_IN_PAGE_ERROR                      The first element of the array contains a 
//                                          read-write flag that indicates the type of 
//                                          operation that caused the access violation. If 
//                                          this value is zero, the thread attempted to read 
//                                          the inaccessible data. If this value is 1, the 
//                                          thread attempted to write to an inaccessible 
//                                          address. If this value is 8, the thread causes 
//                                          a user-mode data execution prevention (DEP) 
//                                          violation.
//                                              数组的第一个元素包含了一个读写标志，用于表示
//                                          引起访问违规的操作类型。如果值为0，表示线程试图
//                                          读取不可访问的数据。如果值为1，表示线程试图写入
//                                          不可访问的地址。如果值为8，表示线程引起
//                                          了一个用户模式的DEP违规。
//                                              The second array element specifies the virtual 
//                                          address of the inaccessible data.
//                                              数组的第二个元素指定了不可访问数据的虚拟地址。
//                                              The third array element specifies the underlying 
//                                          NTSTATUS code that resulted in the exception.
//                                              数组的第三个元素表示底层的NTSTATUS码引起的本
//                                          次异常。
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
    EXCEPTION_RECORD                mEr;                    // 异常信息
    CONTEXT                         mContest;               // 寄存器信息

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取异常描述
    const tchar* cs_Msg(const DWORD dwLanguage = LANG_ENGLISH) const;
    // 获取异常代码
    const DWORD code() const;

public:
    // 重定义SEH异常处理函数
    static void ResetSeh(void);
    // SEH处理函数
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