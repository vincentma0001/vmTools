/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlRet.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 7/12/2015 16:25:16
// Modify time 	: 7/12/2015 16:25:16
// Note 		:
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

#ifndef __CMYSQLRET_H__
#define __CMYSQLRET_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <vector>

#ifndef __VM_TOOLS_DLLMACRO_H__
#   error This file is need #include <DllMacro.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// class release :
class CAbsMySqlRow;
class CMySql;

/////////////////////////////////////////////////////////////////////////////////////////
EXPORT_STL_STRING( DLL_MACRO )
EXPORT_STL_VECTOR( DLL_MACRO,CAbsMySqlRow* )

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMySqlRet
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////
class DLL_MACRO CMySqlRet
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef std::vector<CAbsMySqlRow*>                    tVector;
    typedef std::vector<CAbsMySqlRow*>::iterator          tVectorItor;
    typedef std::vector<CAbsMySqlRow*>::const_iterator    ctVectorItor;

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    tVector                             mlistpRows;     // 结果集
    CAbsMySqlRow*                       mpBaseRow;      // 行基类

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CMySqlRet();                            			// Construct define
    virtual ~CMySqlRet();			                            // Destruct define

public:
    void Clear( void );                                 // 清理结果集

    tVectorItor  GetBeginRow    ( void );               // 获取结果集中第一个行中地迭代器
    tVectorItor  GetEndRow      ( void );               // 获取结果集中最后一行的迭代器
    unsigned int GetResult      ( CMySql& cMySQL );     // 获取结果集
    unsigned int GetRowsNum     ( void );               // 获取结果集中的行数

    template< class TRowType>
    bool SetRowBase( TRowType& lcRowType )              // 设置Row基类
    {
        // 若原基类包含数据,对原有数据进行回收
        if ( mpBaseRow != NULL )
            delete mpBaseRow;

        // 重新设置基类数据
        mpBaseRow = lcRowType.clone();
        if ( mpBaseRow == NULL )
            return false;

        return true;
    }
}; // End of class CMySqlRet
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYSQLRET_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlRet.h
/////////////////////////////////////////////////////////////////////////////////////////