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
//         Notes : �����¼��һ���쳣����Ϣ
//
/////////////////////////////////////////////////////////////////////////////////////
class CExpUnit
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
enum enExpType                          // �쳣����
{
    ET_USER			= 0x00000001,		// �û������쳣
    ET_SYSTEM		= 0x00000002,		// ϵͳ�쳣
    ET_MYSQL		= 0x00000003,		// MySQL�����쳣
    ET_CPP          = 0x00000004        // CPP�쳣
};

/////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    // when :
    // std::string         mstrTime;           // �쳣������ʱ��

    // where :
	std::string			mstrFile;              // �쳣�������ļ���
	std::string			mstrFunc;              // �쳣�����ĺ�����

    // what :
	std::string			mstrExpDes;				// �쳣��������
    unsigned long		mulLine;                // �쳣�������ļ�����
	unsigned long		mulExpCode;				// �쳣����

	// Exception type
	enExpType			menExpType;				// �쳣����: ���enExpType˵��

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CExpUnit(
		enum enExpType		    lenExpLevel,        // �쳣����
		const unsigned long		lulExpCode,         // �쳣����
		const std::string		lstrExpDes,         // �쳣����
		// const std::string		lstrTime,       // �쳣������ʱ��
		const std::string		lstrFunc,           // �쳣�����ĺ�����
		const std::string		lstrFile,           // �쳣�������ļ���
		const unsigned long		lulLine             // �쳣����������
		)
        :menExpType(lenExpLevel),
        mulExpCode(lulExpCode),
        mstrExpDes(lstrExpDes),
        // mstrTime(lstrTime),
        mstrFunc(lstrFunc),
        mstrFile(lstrFile),
        mulLine(lulLine)
    { }                                             // ���캯��
	CExpUnit( const CExpUnit& cEu );                // �������캯��
    CExpUnit(){};                                   // ���캯��
	~CExpUnit(){};                                  // ��������
    CExpUnit& operator = ( const CExpUnit& cEu );   // ��ֵ����

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
    }                        // ��ʽ��������Ϣ


}; // End of class ststExpUnit
/////////////////////////////////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMyExption
//        Notes : �����¼��һ���쳣������ĵ��ù���
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
	std::list<CExpUnit>		mlistExps;                  // �쳣���ù��̼�¼

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CMyExpTrack();                                      // Construct define
    ~CMyExpTrack();			                            // Destruct define
    CMyExpTrack( 
        enum CExpUnit::enExpType        lenExpType,         // �쳣����
        const unsigned long		        lulExpCode,         // �쳣����
        const std::string		        lstrExpDes,         // �쳣����
        //const std::string		        lstrTime,           // �쳣������ʱ��
        const std::string		        lstrFunc,           // �쳣�����ĺ�����
        const std::string		        lstrFile,           // �쳣�������ļ�
        const unsigned long		        lulLine             // �쳣����������
        );                                                  // ���캯��


    CMyExpTrack( const CExpUnit& lEu );                             // �������캯��
    CMyExpTrack& operator = (CMyExpTrack& cMyExpTrack);             // ��ֵ����

public: 
	inline void AddExp( 
            enum CExpUnit::enExpType    lenExpLevel,        // �쳣����
		    const unsigned long		    lulExpCode,         // �쳣����
		    const std::string		    lstrExpDes,         // �쳣����
		    // const std::string		lstrTime,           // �쳣������ʱ��
		    const std::string		    lstrFunc,           // �쳣�����ĺ�����
		    const std::string		    lstrFile,           // �쳣�������ļ�
		    const unsigned long		    lulLine             // �쳣����������
		    );                                              // ���һ���쳣����
    void AddExp( CExpUnit& lcEu );                          // ���һ���쳣����
    Itor GetFirstExp( void )
    { return mlistExps.begin(); }                           // ��ȡ��һ���쳣��Ϣ
    Itor GetLastExp( void )
    { return mlistExps.end(); }                             // ��ȡ���һ���쳣��Ϣ
    unsigned int GetSize( void )
    { return mlistExps.size(); }                            // ��ȡ��¼���쳣��Ϣ��
    void Clear( void )
    { return mlistExps.clear(); }                           // ����쳣��Ϣ��¼
}; // End of class CMyExption
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYEXPTRACK_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMyExpTrack.h
/////////////////////////////////////////////////////////////////////////////////////////