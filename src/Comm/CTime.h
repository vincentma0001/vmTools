/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTime.h
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/1/2016 15:36:56
// Modify time 	: 15/1/2016 15:36:56
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <sys/TIMEB.H>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#define _MAX_TIME_BUF_ 128
#define _TIME_SEC_OF_ONE_DAY_ (60*60*24)

namespace JL {

//////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CTime
//        Notes : ��ȡʱ���ַ���
//
//////////////////////////////////////////////////////////////////////////////////////////
class CTime
{
//////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    //time_t          mTime;
    char            mszBuf[_MAX_TIME_BUF_];
	struct _timeb	mTime;

//////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    CTime();                                                    // Construct define
    CTime( const char* szTime );                                // Construct define
    CTime( time_t tTime );
    virtual ~CTime();;                                          // Destruct define
    CTime( const CTime& Obj );                                  // Copy Construct
    CTime& operator = ( const CTime& Obj );                     // Assignment
    bool operator > ( const CTime& Obj );
    bool operator < ( const CTime& Obj );
    double operator - ( const CTime& Obj );
	bool operator == ( const CTime& Obj );
	bool operator != ( const CTime& Obj );

public:
    const char* ToString( const char* szFormat );
    const char* ToStringDay();                                  // ��ȡʱ���ַ�������ʽ"%Y-%m-%d"
    const char* ToStringDayTime();                              // ��ȡʱ���ַ�������ʽ"%Y-%m-%d %H:%M:%S"
    const char* ToStringMillitm( const char* szFormat );                              // ��ȡʱ���ַ�������ʽ"%Mill"
    const char* ToStringTime();                                 // ��ȡʱ���ַ�������ʽ"%H:%M:%S"
    const char* ToStringFull();                                 // ��ȡʱ���ַ�������ʽ""%Y-%m-%d %H:%M:%S:%Mill"
    static CTime GetCurrTime();                                 // ��ȡ��ǰʱ��
    
public:
    time_t GetTime( void );
	unsigned short GetMillitm();
	
    void SetTime( const char* szFormat);
    void SetTime( unsigned int uiHour=0, unsigned int uiMin=0, unsigned int uiSec=0, unsigned short usMill=0 );
    void AddTime( double tTimeDiff );
}; // End of class CTime
//////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namesapce JL
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// namespace



/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTime.h
/////////////////////////////////////////////////////////////////////////////////////////