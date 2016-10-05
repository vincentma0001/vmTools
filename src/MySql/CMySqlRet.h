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
    tVector                             mlistpRows;     // �����
    CAbsMySqlRow*                       mpBaseRow;      // �л���

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CMySqlRet();                            			// Construct define
    virtual ~CMySqlRet();			                            // Destruct define

public:
    void Clear( void );                                 // ��������

    tVectorItor  GetBeginRow    ( void );               // ��ȡ������е�һ�����еص�����
    tVectorItor  GetEndRow      ( void );               // ��ȡ����������һ�еĵ�����
    unsigned int GetResult      ( CMySql& cMySQL );     // ��ȡ�����
    unsigned int GetRowsNum     ( void );               // ��ȡ������е�����

    template< class TRowType>
    bool SetRowBase( TRowType& lcRowType )              // ����Row����
    {
        // ��ԭ�����������,��ԭ�����ݽ��л���
        if ( mpBaseRow != NULL )
            delete mpBaseRow;

        // �������û�������
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