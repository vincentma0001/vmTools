/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMyExpTrack.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 9/12/2015 9:18:00
// Modify time 	: 9/12/2015 9:18:00
// Note 		:
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

#ifndef __CMYEXPTRACK_H__
#define __CMYEXPTRACK_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>
#include <vector>

#ifndef __VM_TOOLS_DLLMACRO_H__
#   error This file is need #include <DllMacro.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// class release :
class CMySqlExpUnit;

/////////////////////////////////////////////////////////////////////////////////////////
EXPORT_STL_STRING( DLL_MACRO )
EXPORT_STL_VECTOR( DLL_MACRO, CMySqlExpUnit )

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CExpUnit
//         Notes : 此类记录了一个异常的信息
//
/////////////////////////////////////////////////////////////////////////////////////
class DLL_MACRO CMySqlExpUnit
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
enum enExpType                          // 异常类型
{
    ET_USER			= 0x00000001,		// 用户定义异常
    ET_SYSTEM		= 0x00000002,		// 系统异常
    ET_MYSQL		= 0x00000003,		// MySQL调用异常
    ET_CPP          = 0x00000004        // CPP异常
};

/////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    // when :
    // std::string         mstrTime;           // 异常产生的时间

    // where :
	std::string			mstrFile;              // 异常产生的文件名
	std::string			mstrFunc;              // 异常产生的函数名

    // what :
	std::string			mstrExpDes;				// 异常代码描述
    unsigned long		mulLine;                // 异常产生的文件行数
	unsigned long		mulExpCode;				// 异常代码

	// Exception type
	enExpType			menExpType;				// 异常类型: 详见enExpType说明

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CMySqlExpUnit(
		enum enExpType		    lenExpLevel,        // 异常类型
		const unsigned long		lulExpCode,         // 异常代码
		const std::string		lstrExpDes,         // 异常描述
		// const std::string		lstrTime,       // 异常产生的时间
		const std::string		lstrFunc,           // 异常产生的函数名
		const std::string		lstrFile,           // 异常产生的文件名
		const unsigned long		lulLine             // 异常产生的行数
		);                                          // 构造函数
	CMySqlExpUnit( const CMySqlExpUnit& cEu );                // 拷贝构造函数
    CMySqlExpUnit();;                                    // 构造函数
	virtual ~CMySqlExpUnit();;                                   // 析构函数
    CMySqlExpUnit& operator = ( const CMySqlExpUnit& cEu );   // 复值操作

public:
    std::string ToString();

}; // End of class ststExpUnit
/////////////////////////////////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMyExption
//        Notes : 此类记录的一个异常产生后的调用过程
//
/////////////////////////////////////////////////////////////////////////////////////
class DLL_MACRO CMySqlExpTrack
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef std::vector<CMySqlExpUnit>                     tVector;
	typedef std::vector<CMySqlExpUnit>::iterator			tItor;       
	typedef std::vector<CMySqlExpUnit>::const_iterator	    ctItor;

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
	tVector		            mlistExps;                  // 异常调用过程记录

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CMySqlExpTrack();                                        // Construct define
    virtual ~CMySqlExpTrack(); 			                            // Destruct define
    CMySqlExpTrack( 
        enum CMySqlExpUnit::enExpType    lenExpType,         // 异常类型
        const unsigned long		    lulExpCode,         // 异常代码
        const std::string		    lstrExpDes,         // 异常描述
        //const std::string		    lstrTime,           // 异常产生的时间
        const std::string		    lstrFunc,           // 异常产生的函数名
        const std::string		    lstrFile,           // 异常产生的文件
		const unsigned long		    lulLine             // 异常产生的行数
        );                                              // 构造函数
    CMySqlExpTrack( const CMySqlExpUnit& lEu );                   // 拷贝构造函数
    

public: 
	void AddExp( 
        enum CMySqlExpUnit::enExpType    lenExpLevel,        // 异常类型
		const unsigned long		    lulExpCode,         // 异常代码
		const std::string		    lstrExpDes,         // 异常描述
		// const std::string		lstrTime,           // 异常产生的时间
		const std::string		    lstrFunc,           // 异常产生的函数名
		const std::string		    lstrFile,           // 异常产生的文件
		const unsigned long		    lulLine             // 异常产生的行数
		);                                              // 添加一个异常返回
    void AddExp( CMySqlExpUnit& lcEu );;                     // 添加一个异常返回
    tItor GetFirstExp( void );                          // 获取第一层异常信息
    tItor GetLastExp( void );                           // 获取最后一层异常信息
    unsigned int GetSize( void );;                      // 获取记录的异常信息数
    void Clear( void );                                 // 清空异常信息记录
}; // End of class CMyExption
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYEXPTRACK_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMyExpTrack.h
/////////////////////////////////////////////////////////////////////////////////////////