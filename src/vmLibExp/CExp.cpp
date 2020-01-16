/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CExp.cpp
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 
// Create time  : 2020/01/02 20:51:18
// Modify time  : 2020/01/02 20:51:18
// Note         :
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
#include <string.h>
#include <exception>
#include <time.h>

// Config files included
#include <vmCfg.h>

// platform files included
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
#include <windows.h>
#endif // #if defined(...)

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibErr.h>

#include <vmLibBase/CMemPtr.h>
#include <vmLibBase/CStrPtr.h>
#include <vmLibBase/CDateTime.hpp>

#include <vmLibFile.h>

// Declare file included
#include "CExp.h"
#include "vmVerify.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
CExp::CExp(): mExpLevel(emExp),mpExpNext(nullptr)
{

}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CExp(...)
// Brief     :
// Return    : 
CExp::~CExp()
{
    if ( mpExpNext != nullptr )
        delete [] mpExpNext;
    
    mpExpNext = nullptr;
}
// End of function ~CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const char * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp( const char* const   cpFile, 
            const unsigned long culLine,
            const char* const   cpTimeFmt ):mExpLevel(emExp),mpExpNext(nullptr)
{
    vCStrPtr(mszFile)     = vm::CFile(cpFile).cs_Name();
    muiLine               = culLine;
    vCStrPtr(mszDateTime) = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & oExp
// Parameter : const char * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp( const CExp&         oExp, 
            const char* const   cpFile , 
            const unsigned long culLine,
            const char* const   cpTimeFmt):mExpLevel(emExp), mpExpNext(nullptr)
{
    mpExpNext       = new CExp();
    *mpExpNext      = oExp;

    vCStrPtr(mszFile)         = vm::CFile(cpFile).cs_Name();
    muiLine                   = culLine;
    vCStrPtr(mszDateTime)     = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & obj
CExp::CExp(const CExp& obj)
{
    *this = obj;
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : vm::CExp&
// Parameter : const CExp & obj
vm::CExp& CExp::operator=(const CExp& obj)
{
    // 复制CExp中的数据
    vCStrPtr(mszFunc)        = obj.mszFunc;
    vCStrPtr(mszFile)        = obj.mszFile;
    muiLine                  = obj.muiLine;
    vCStrPtr(mszDateTime)    = obj.mszDateTime;
    vCStrPtr(mszMsg)         = obj.mszMsg;

    // 循环复制上一级异常信息
    if ( obj.mpExpNext == nullptr )
        return *this;

    if ( mpExpNext != nullptr )
        delete [] mpExpNext;

    mpExpNext = new CExp();
    *mpExpNext = *obj.mpExpNext;

    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator()(...)
// Brief     :
// Return    : void
// Parameter : const char * const cpFunc
// Parameter : const char * const cpFmt
// Parameter : ...
CExp& CExp::operator()(const char* const cpFunc, const char* const cpFmt, ...)
{
    vCStrPtr(mszFunc) = cpFunc;

    va_list vList;
    va_start(vList, cpFmt);
    vCMemPtr(mszMsg).Fmt(cpFmt, vList);
    va_end(vList);

    return *this;
}
// End of function operator()(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator()(...)
// Brief     :
// Return    : void
// Parameter : const char * const cpFunc
// Parameter : const char * const cpFmt
// Parameter : va_list vList
CExp& CExp::operator()(const char* const cpFunc, const char* const cpFmt, va_list vList)
{
    vCStrPtr(mszFunc) = cpFunc;
    vCStrPtr(mszMsg).Fmt(cpFmt, vList);

    return *this;
}
// End of function operator()(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Fmt(...)
// Brief     :
// Return    : int
// Parameter : const char * const cpFmt
// Parameter : ...
char* CExp::Fmt(const char* const cpFmt, ...)
{
    // 验证格式代码是否正确
    _VERIFY_(cpFmt);

    // 初始化格式化字符串对象
    size_t lsztFmtStrLen = strlen(cpFmt);
    size_t lsztFmtStrOffset = 0;
    vm::CStrPtr loFmtStr(const_cast<char*>(cpFmt), lsztFmtStrLen);
    char*  lpFmtStrOffset = (char*)cpFmt;

    // 初始化缓存区数据
    size_t lsztBufOffset = 0;
    vm::CMemPtr loBuf(mszBuf,sizeof(mszBuf));
    loBuf.Set(0x00);

    // 根据输入的参数格式化错误信息
    char* lpFmtFlagPos = loFmtStr.Find('%');
    while (lpFmtFlagPos != nullptr)
    {
        // 获取格式化字符串中%标识符之间的数据信息，并添加其偏移量
        size_t loFmtStrDataLen = lpFmtFlagPos - lpFmtStrOffset;
        lsztFmtStrOffset += (loFmtStrDataLen);

        // 将格式化中的数据拷贝到缓存区中，并添加缓存区偏移量
        size_t loCopyedLen = loBuf.CopyFm(lsztBufOffset, lpFmtStrOffset, loFmtStrDataLen);
        lsztBufOffset += loCopyedLen;

        // 根据标识符将异常信息添加到缓存区中
        // 处理所在函数名信息
        if (loFmtStr.Cmp("%Fn", 3, lsztBufOffset) == true)
        {
            // 将错误代码转换为字符串并添加到缓存区中
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszFunc, strlen(mszFunc));
            // 缓存区偏移错误代码所转换的字符串长度
            lsztBufOffset += lsztOffset;
            // 格式化字符串偏移两个字符（%Fn）
            lsztFmtStrOffset += 3;
        }
        // 处理所在文件名信息
        else if (loFmtStr.Cmp("%Fi", 3, lsztBufOffset) == true)
        {
            // 将错误代码代表的错误信息添加到缓存区中
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszFile, strlen(mszFile));
            // 缓存区偏移错误信息的长度
            lsztBufOffset += lsztOffset;
            // 格式化字符串偏移两个字符（%Fi）
            lsztFmtStrOffset += 3;
        }
        // 处理时间信息
        else if (loFmtStr.Cmp("%L", 2, lsztBufOffset) == true)
        {
            // 将错误代码代表的错误信息添加到缓存区中
            size_t lsztOffset = loBuf.Fmt2(lsztBufOffset, "%04d", muiLine);;
            // 缓存区偏移错误信息的长度
            lsztBufOffset += lsztOffset;
            // 格式化字符串偏移两个字符（%L）
            lsztFmtStrOffset += 2;
        }
        // 处理时间信息
        else if (loFmtStr.Cmp("%T", 2, lsztBufOffset) == true)
        {
            // 将错误代码代表的错误信息添加到缓存区中
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszDateTime, strlen(mszDateTime));
            // 缓存区偏移错误信息的长度
            lsztBufOffset += lsztOffset;
            // 格式化字符串偏移两个字符（%T）
            lsztFmtStrOffset += 2;
        }
        // 处理异常信息
        else if (loFmtStr.Cmp("%M", 2, lsztBufOffset) == true)
        {
            // 将错误代码代表的错误信息添加到缓存区中
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszFile, strlen(mszFile));
            // 缓存区偏移错误信息的长度
            lsztBufOffset += lsztOffset;
            // 格式化字符串偏移两个字符（%M）
            lsztFmtStrOffset += 2;
        }

        // 计算剩余的格式化字符串长度，若剩余量小于0，则跳出循环
        size_t lszFmtStrLeft = lsztFmtStrLen - lsztFmtStrOffset;
        if (lszFmtStrLeft < 0)
            break;

        // 重新定位下一个格式化字符串中标识符的位置
        lpFmtFlagPos = loFmtStr.Find(lsztFmtStrOffset, '%');
    }

    return mszBuf;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Next(...)
// Brief     :
// Return    : vm::CExp*
vm::CExp* CExp::Next()
{
    return mpExpNext;
}
// End of function Next(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CExp.cpp
/////////////////////////////////////////////////////////////////////////////////////////
