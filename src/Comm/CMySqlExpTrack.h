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
#include <list>

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CExpUnit
//         Notes : �����¼��һ���쳣����Ϣ
//
/////////////////////////////////////////////////////////////////////////////////////
class CMySqlExpUnit
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
	CMySqlExpUnit(
		enum enExpType		    lenExpLevel,        // �쳣����
		const unsigned long		lulExpCode,         // �쳣����
		const std::string		lstrExpDes,         // �쳣����
		// const std::string		lstrTime,       // �쳣������ʱ��
		const std::string		lstrFunc,           // �쳣�����ĺ�����
		const std::string		lstrFile,           // �쳣�������ļ���
		const unsigned long		lulLine             // �쳣����������
		);                                          // ���캯��
	CMySqlExpUnit( const CMySqlExpUnit& cEu );                // �������캯��
    CMySqlExpUnit();;                                    // ���캯��
	~CMySqlExpUnit();;                                   // ��������
    CMySqlExpUnit& operator = ( const CMySqlExpUnit& cEu );   // ��ֵ����

public:
    std::string ToString();

}; // End of class ststExpUnit
/////////////////////////////////////////////////////////////////////////////////////
 
/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMyExption
//        Notes : �����¼��һ���쳣������ĵ��ù���
//
/////////////////////////////////////////////////////////////////////////////////////
class CMySqlExpTrack
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef std::list<CMySqlExpUnit>                     tList;
	typedef std::list<CMySqlExpUnit>::iterator			tItor;       
	typedef std::list<CMySqlExpUnit>::const_iterator	    ctItor;

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
	tList		            mlistExps;                  // �쳣���ù��̼�¼

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CMySqlExpTrack();                                        // Construct define
    ~CMySqlExpTrack(); 			                            // Destruct define
    CMySqlExpTrack( 
        enum CMySqlExpUnit::enExpType    lenExpType,         // �쳣����
        const unsigned long		    lulExpCode,         // �쳣����
        const std::string		    lstrExpDes,         // �쳣����
        //const std::string		    lstrTime,           // �쳣������ʱ��
        const std::string		    lstrFunc,           // �쳣�����ĺ�����
        const std::string		    lstrFile,           // �쳣�������ļ�
		const unsigned long		    lulLine             // �쳣����������
        );                                              // ���캯��
    CMySqlExpTrack( const CMySqlExpUnit& lEu );                   // �������캯��
    

public: 
	void AddExp( 
        enum CMySqlExpUnit::enExpType    lenExpLevel,        // �쳣����
		const unsigned long		    lulExpCode,         // �쳣����
		const std::string		    lstrExpDes,         // �쳣����
		// const std::string		lstrTime,           // �쳣������ʱ��
		const std::string		    lstrFunc,           // �쳣�����ĺ�����
		const std::string		    lstrFile,           // �쳣�������ļ�
		const unsigned long		    lulLine             // �쳣����������
		);                                              // ���һ���쳣����
    void AddExp( CMySqlExpUnit& lcEu );;                     // ���һ���쳣����
    tItor GetFirstExp( void );                          // ��ȡ��һ���쳣��Ϣ
    tItor GetLastExp( void );                           // ��ȡ���һ���쳣��Ϣ
    unsigned int GetSize( void );;                      // ��ȡ��¼���쳣��Ϣ��
    void Clear( void );                                 // ����쳣��Ϣ��¼
}; // End of class CMyExption
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYEXPTRACK_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMyExpTrack.h
/////////////////////////////////////////////////////////////////////////////////////////