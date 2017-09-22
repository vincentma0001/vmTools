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
#include <STRING>
#include <LIST>
#include <SSTREAM>

////////////////////////////////////////////////////////////////////////////////////
//
// class define : CExpUnit
//         Notes : 此类记录了一个异常的信息
//
/////////////////////////////////////////////////////////////////////////////////////
class CExpUnit
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
	CExpUnit(
		enum enExpType		    lenExpLevel,        // 异常类型
		const unsigned long		lulExpCode,         // 异常代码
		const std::string		lstrExpDes,         // 异常描述
		// const std::string		lstrTime,       // 异常产生的时间
		const std::string		lstrFunc,           // 异常产生的函数名
		const std::string		lstrFile,           // 异常产生的文件名
		const unsigned long		lulLine             // 异常产生的行数
		)
        :menExpType(lenExpLevel),
        mulExpCode(lulExpCode),
        mstrExpDes(lstrExpDes),
        // mstrTime(lstrTime),
        mstrFunc(lstrFunc),
        mstrFile(lstrFile),
        mulLine(lulLine)
    { }                                             // 构造函数
	CExpUnit( const CExpUnit& cEu );                // 拷贝构造函数
    CExpUnit(){};                                   // 构造函数
	~CExpUnit(){};                                  // 析构函数
    CExpUnit& operator = ( const CExpUnit& cEu );   // 赋值操作

public:
    std::string ToString()
    {
        std::stringstream lssBuf;
        lssBuf << "[" << mstrFunc.c_str() << ":" <<  mulLine << "] ";
        switch( menExpType )
        {
        case ET_USER:
            lssBuf << " USER(" ;
            break;
        case ET_SYSTEM:
            lssBuf << " SYSTEM(" ;
            break;
        case ET_MYSQL:
            lssBuf << " Mysql(";
            break;
        case ET_CPP:
            lssBuf << " CPP(";

        }

        lssBuf << mulExpCode << ") : " << mstrExpDes.c_str() << " (" << mstrFile.c_str() << ")" << std::ends;

        return lssBuf.str();
    }                        // 格式化错误信息


}; // End of class ststExpUnit
/////////////////////////////////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMyExption
//        Notes : 此类记录的一个异常产生后的调用过程
//
/////////////////////////////////////////////////////////////////////////////////////
class CMyExpTrack
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
	typedef std::list<CExpUnit>::iterator			Itor;       
	typedef std::list<CExpUnit>::const_iterator	    cItor;

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
	std::list<CExpUnit>		mlistExps;                  // 异常调用过程记录

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CMyExpTrack();                                      // Construct define
    ~CMyExpTrack();			                            // Destruct define
    CMyExpTrack( 
        enum CExpUnit::enExpType        lenExpType,         // 异常类型
        const unsigned long		        lulExpCode,         // 异常代码
        const std::string		        lstrExpDes,         // 异常描述
        //const std::string		        lstrTime,           // 异常产生的时间
        const std::string		        lstrFunc,           // 异常产生的函数名
        const std::string		        lstrFile,           // 异常产生的文件
        const unsigned long		        lulLine             // 异常产生的行数
        );                                                  // 构造函数


    CMyExpTrack( const CExpUnit& lEu );                             // 拷贝构造函数
    CMyExpTrack& operator = (CMyExpTrack& cMyExpTrack);             // 赋值操作

public: 
	inline void AddExp( 
            enum CExpUnit::enExpType    lenExpLevel,        // 异常类型
		    const unsigned long		    lulExpCode,         // 异常代码
		    const std::string		    lstrExpDes,         // 异常描述
		    // const std::string		lstrTime,           // 异常产生的时间
		    const std::string		    lstrFunc,           // 异常产生的函数名
		    const std::string		    lstrFile,           // 异常产生的文件
		    const unsigned long		    lulLine             // 异常产生的行数
		    );                                              // 添加一个异常返回
    void AddExp( CExpUnit& lcEu );                          // 添加一个异常返回
    Itor GetFirstExp( void )
    { return mlistExps.begin(); }                           // 获取第一层异常信息
    Itor GetLastExp( void )
    { return mlistExps.end(); }                             // 获取最后一层异常信息
    unsigned int GetSize( void )
    { return mlistExps.size(); }                            // 获取记录的异常信息数
    void Clear( void )
    { return mlistExps.clear(); }                           // 清空异常信息记录
}; // End of class CMyExption
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYEXPTRACK_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMyExpTrack.h
/////////////////////////////////////////////////////////////////////////////////////////