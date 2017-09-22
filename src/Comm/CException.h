/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CException.h
// Version      : 0.0.1.0
// Brief        : 
// Auther       : v.m.
// Create time  : 9/1/2016 20:26:26
// Modify time  : 9/1/2016 20:26:26
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

#ifndef __VM_TOOLS_CEXCEPTION_H__
#define __VM_TOOLS_CEXCEPTION_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define

// 异常类型定义
#define EXPTYPE_USER                0x10000000                  // 用户定义异常
#define ET_USER                     0x00000001                  // 用户定义异常
#define ET_UNKNOWN                  0x00000002                  // 未知异常
#define ET_SYSTEM                   0x00000003                  // 系统异常
#define ET_CPP                      0x00000004                  // CPP异常
#define MAKEUSEREXP( EXPVAlUE )     EXPTYPE_USER|EXPVAlUE       // 生成用户定义异常码

// 异常创建宏
//#if defined (_MSC_VER) && (_MSC_VER<=1300)
#   define CEXP                                                                JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_F                                                              JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_T                                                              JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_C                                                              JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_S                                                              JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_TC                                                             JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_FTC                                                            JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_TCS                                                            JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_FTCS                                                           JL::CException( "Func", __LINE__, __FILE__ )
#   define CEXP_E( ex )                                                        JL::CException( ex, "Func", __LINE__, __FILE__, NULL )
// #else
// #   define CEXP( szFormat, ... )                                               JL::CException( szFormat, __FUNCTION__, __LINE__, __FILE__, MAKEUSEREXP(ET_UNKNOWN),MAKEUSEREXP(ET_UNKNOWN), NULL, __VA_ARGS__ )
// #   define CEXP_F( szFormat, szFunc, ... )                                     JL::CException( szFormat, szFunc, __LINE__, __FILE__, MAKEUSEREXP(ET_UNKNOWN),MAKEUSEREXP(ET_UNKNOWN), NULL, __VA_ARGS__ )
// #   define CEXP_T( szFormat, ulExpType, ... )                                  JL::CException( szFormat, __FUNCTION__, __LINE__, __FILE__,ulExpType, MAKEUSEREXP(ET_UNKNOWN), NULL, __VA_ARGS__ )
// #   define CEXP_C( szFormat, ulExpCode, ... )                                  JL::CException( szFormat, __FUNCTION__, __LINE__, __FILE__,  MAKEUSEREXP(ET_UNKNOWN),ulExpCode,NULL, __VA_ARGS__ )
// #   define CEXP_S( szFormat, szTime, ... )                                     JL::CException( szFormat, __FUNCTION__, __LINE__, __FILE__, MAKEUSEREXP(ET_UNKNOWN),MAKEUSEREXP(ET_UNKNOWN), szTime, __VA_ARGS__ )
// #   define CEXP_TC( szFormat,ulExpType,ulExpCode, ... )                        JL::CException( szFormat, __FUNCTION__,  __LINE__, __FILE__, ulExpType,ulExpCode, NULL, __VA_ARGS__ )
// #   define CEXP_FTC( szFormat,szFunc,ulExpType,ulExpCode, ... )                JL::CException( szFormat, szFunc,  __LINE__, __FILE__, ulExpType,ulExpCode, NULL, __VA_ARGS__ )
// #   define CEXP_TCS( szFormat, ulExpType,ulExpCode, szTime, ... )              JL::CException( szFormat, __FUNCTION__,  __LINE__, __FILE__, ulExpType,ulExpCode, szTime, __VA_ARGS__ )
// #   define CEXP_FTCS( szFormat, szFunc, ulExpType, ulExpCode, szTime,  ... )   JL::CException( szFormat, szFunc,  __LINE__, __FILE__, ulExpType,ulExpCode, szTime, __VA_ARGS__ )
// 
// #   define CEXP_E( ex )                                                        JL::CException( ex, __FUNCTION__, __LINE__, __FILE__, NULL )
//#   define CEXP_E_F( ex, szFunc )                                              CException( ex, szFunc, MAKEUSEREXP(ET_UNKNOWN),MAKEUSEREXP(ET_UNKNOWN), __LINE__, __FILE__, NULL )
//#   define CEXP_E_T( ex, ulExpType )                                           CException( ex, __FUNCTION__, ulExpType,MAKEUSEREXP(ET_UNKNOWN), __LINE__, __FILE__, NULL )
//#   define CEXP_E_C( ex, ulExpCode )                                           CException( ex, __FUNCTION__, MAKEUSEREXP(ET_UNKNOWN),ulExpCode, __LINE__, __FILE__, NULL )
//#   define CEXP_E_S( ex, szTime )                                              CException( ex, __FUNCTION__, MAKEUSEREXP(ET_UNKNOWN),MAKEUSEREXP(ET_UNKNOWN), __LINE__, __FILE__, szTime )
//#   define CEXP_E_TC( ex,ulExpType,ulExpCode )                                 CException( ex, __FUNCTION__, ulExpType,ulExpCode, __LINE__, __FILE__, NULL )
//#   define CEXP_E_FTC( ex,szFunc,ulExpType,ulExpCode )                         CException( ex, szFunc, ulExpType,ulExpCode, __LINE__, __FILE__, NULL )
//#   define CEXP_E_TCS( ex, ulExpType,ulExpCode, szTime )                       CException( ex, __FUNCTION__, ulExpType,ulExpCode, __LINE__, __FILE__, szTime )
//#   define CEXP_E_FTCS( ex, szFunc, ulExpType, ulExpCode, szTime )             CException( ex, szFunc, ulExpType,ulExpCode, __LINE__, __FILE__, szTime )
//#endif

namespace JL {

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CException
//        Notes : 自定义异常记录异常信息
//
/////////////////////////////////////////////////////////////////////////////////////////
class CException
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    // Exception Type
    unsigned long       mulExpType;             // 异常类型: 详见异常类型定义

    // Exception Code
    unsigned long       mulExpCode;             // 异常代码

    // Where
    unsigned long       mulLine;                // 异常产生的文件行数
    std::string         mstrFile;               // 异常产生的文件名
    std::string         mstrFunc;               // 异常产生的函数名

    // When
    std::string         mstrTime;               // 异常产生的时间

    // What
    std::string         mstrMsg;                // 异常信息

    // Buffer
    std::string         mstrBuf;                // 异常信息

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
//     CException( const char* szFormat,
//                 const char* szFunc,
//                 const unsigned long culLine,
//                 const char* szFile,
//                 const unsigned long culExpType = MAKEUSEREXP(ET_UNKNOWN),
//                 const unsigned long culExpCode = MAKEUSEREXP(ET_UNKNOWN),
//                 const char* szTime = NULL,
//                 ...);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    CException( const char* szFunc,
                const unsigned long culLine,
                 const char* szFile
//                 const unsigned long culExpType = MAKEUSEREXP(ET_UNKNOWN),
//                 const unsigned long culExpCode = MAKEUSEREXP(ET_UNKNOWN),
//                 const char* szTime = NULL 
            );
    CException& operator()( const char* szFormat, ... );
#endif
    // Destruct define
    virtual ~CException(){};
    // Copy Construct
    CException( const JL::CException& ex,
        const char* szFunc,
        const unsigned long culLine,
        const char* szFile ,
        const char* szTime = NULL );
    CException( const CException& ex );
    // Evaluation
    CException& operator = (const CException& ex);

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 输出格式化信息
    // 异常格式替换字符定义：
    //             %M                -- 异常产生的函数名
    //             %L                -- 异常产生的行数
    //             %F                -- 异常产生的文件名
    //             %T                -- 异常类型
    //             %C                -- 异常代码
    //             %I                -- 异常信息
    //             %D                -- 异常产生的时间
    virtual const char* ToString( const char* szFormat="[%D][%M:%L][%T:%C] %I [%F]" );

}; // End of class CException
/////////////////////////////////////////////////////////////////////////////////////////

}; // End of namespace JL

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CEXCEPTION_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CException.h
/////////////////////////////////////////////////////////////////////////////////////////
