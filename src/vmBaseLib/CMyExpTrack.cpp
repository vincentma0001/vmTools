/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMyException.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 9/12/2015 9:17:15
// Modify time 	: 9/12/2015 9:17:15
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition

#if( _MSC_VER <= 1200 )
#pragma warning( disable:4786 )
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <CMyExpTrack.h>

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CExpUnit
// Full name : CExpUnit::CExpUnit
// Access    : public 
// Brief     : ���캯�� 
// Parameter :  enum enExpType lenExpLevel,         - �쳣����
//              const unsigned long lulExpCode,     - �쳣����
//              const std::string lstrExpDes,       - �쳣����
//              /* const std::string lstrTime, */   - �쳣����ʱ��
//              const std::string lstrFunc,         - �쳣����ʱ���ڵĺ�����
//              const std::string lstrFile,         - �쳣����ʱ���ڵ��ļ���
//              const unsigned long lulLine         - �쳣����ʱ���ڵ��ļ�����
// Return    : ��
// Notes     : 
CExpUnit::CExpUnit( enum enExpType lenExpLevel, 
                    const unsigned long lulExpCode, 
                    const std::string lstrExpDes, 
                    /* const std::string lstrTime, */ 
                    const std::string lstrFunc, 
                    const std::string lstrFile, 
                    const unsigned long lulLine )
                    :menExpType(lenExpLevel),
                    mulExpCode(lulExpCode),
                    mstrExpDes(lstrExpDes),
                    // mstrTime(lstrTime),
                    mstrFunc(lstrFunc),
                    mstrFile(lstrFile),
                    mulLine(lulLine)
{ } // End of function CExpUnit(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CExpUnit
// Full name : CExpUnit::CExpUnit
// Access    : public 
// Brief     : ���캯��
// Parameter : const CExpUnit& cEu      - ������ʱ���������
// Return    : ��
// Notes     : 
CExpUnit::CExpUnit(const CExpUnit& cEu) 
    :menExpType(cEu.menExpType),
    mulExpCode(cEu.mulExpCode),
    mstrExpDes(cEu.mstrExpDes),
    // mstrTime(cEu.mstrTime),
    mstrFunc(cEu.mstrFunc),
    mstrFile(cEu.mstrFile),
    mulLine(cEu.mulLine)
{ } // End of function CExpUnit(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : CExpUnit::operator=
// Access    : public 
// Brief     : ��ֵ����
// Parameter : const CExpUnit& cEu
// Return    : CExpUnit&
// Notes     : 
CExpUnit& CExpUnit::operator=(const CExpUnit& cEu)
{
    menExpType		= cEu.menExpType;
    mulExpCode		= cEu.mulExpCode;
    mstrExpDes		= cEu.mstrExpDes;
    // mstrTime		= cEu.mstrTime;
    mstrFunc	    = cEu.mstrFunc;
    mstrFile		= cEu.mstrFile;
    mulLine		    = cEu.mulLine;

    return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CExpUnit::ToString
// Access    : public 
// Brief     : ��ʽ��������Ϣ
// Parameter : ��
// Return    : std::string          - ��ʽ������ַ���
// Notes     : 
std::string CExpUnit::ToString()
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
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMyExption
// Full name : CMyExption::CMyExption
// Access    : public 
// Brief     : ���캯��
// Parameter :  enum CExpUnit::enExpType lenExpLevel,      - �������� , ����ṹ enExpType
//              const unsigned long lulExpCode,            - �������
//              const std::string lstrExpDes,              - ��������
//              /*const std::string lstrTime, */           - ���������ʱ��
//              const std::string lstrFunc,                - ��������ĺ�����
//              const std::string lstrFile,                - ����������ļ���
//              const unsigned long lulLine                - ����������ļ�����
// Return    : 
// Notes     : 
CMyExpTrack::CMyExpTrack( enum CExpUnit::enExpType lenExpType, 
                        const unsigned long lulExpCode, 
                        const std::string lstrExpDes, 
                        /*const std::string lstrTime, */ 
                        const std::string lstrFunc, 
                        const std::string lstrFile, 
                        const unsigned long lulLine )
{
    // ����һ����¼��Ԫ
    CExpUnit lEu(lenExpType, lulExpCode, lstrExpDes,/* lstrTime, */lstrFunc, lstrFile, lulLine ) ;

    // ��������ӵ��쳣�б���
    mlistExps.push_back( lEu );

} // End of function CMyExption(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMyExption
// Full name : CMyExption::CMyExption
// Access    : public 
// Brief     : ��������
// Parameter : const CExpUnit& lEu
// Return    : ��
// Notes     : 
CMyExpTrack::CMyExpTrack(const CExpUnit& lEu)
{
    // ��������ӵ��쳣�б���
    mlistExps.push_back(lEu);
} // End of function CMyExption(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddExp
// Full name : CMyExption::AddExp
// Access    : public 
// Brief     : ���һ���쳣��¼
// Brief     : ���캯��
// Parameter :  enum CExpUnit::enExpType lenExpLevel,      - �������� , ����ṹ enExpType
//              const unsigned long lulExpCode,            - �������
//              const std::string lstrExpDes,              - ��������
//              /*const std::string lstrTime, */           - ���������ʱ��
//              const std::string lstrFunc,                - ��������ĺ�����
//              const std::string lstrFile,                - ����������ļ���
//              const unsigned long lulLine                - ����������ļ�����
// Return    : void
// Notes     : 
void CMyExpTrack::AddExp(
    enum CExpUnit::enExpType    lenExpLevel,        // �쳣����
    const unsigned long		    lulExpCode,         // �쳣����
    const std::string		    lstrExpDes,         // �쳣����
    // const std::string		lstrTime,           // �쳣������ʱ��
    const std::string		    lstrFunc,           // �쳣�����ĺ�����
    const std::string		    lstrFile,           // �쳣�������ļ�
    const unsigned long		    lulLine             // �쳣����������
    )

{
    // ����һ����¼��Ԫ
    CExpUnit lEu(lenExpLevel, lulExpCode, lstrExpDes, /*lstrTime, */ lstrFunc, lstrFile, lulLine ) ;

    // ��������ӵ��쳣�б���
    mlistExps.push_back( lEu );
} // End of function AddExp(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddExp
// Full name : CMyException::AddExp
// Access    : public 
// Brief     : ���һ���쳣��¼
// Parameter : CExpUnit& lcEu
// Return    : void
// Notes     : 
void CMyExpTrack::AddExp(CExpUnit& lcEu)
{
    // ��������ӵ��쳣�б���
    mlistExps.push_back( lcEu );
} // End of function AddExp(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFirstExp
// Full name : CMyExption::GetFirstExp
// Access    : public 
// Brief     : ��ȡ����
// Parameter : void
// Return    : CMyExption::Itor
// Notes     : 
CMyExpTrack::Itor CMyExpTrack::GetFirstExp(void)
{
    return mlistExps.begin();
} // End of function GetFirstExp(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetLastExp
// Full name : CMyExption::GetLastExp
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CMyExption::Itor
// Notes     : 
CMyExpTrack::Itor CMyExpTrack::GetLastExp(void)
{
    return mlistExps.end();
} // End of function GetLastExp(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetSize
// Full name : CMyExpTrack::GetSize
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : unsigned int
// Notes     : 
unsigned int CMyExpTrack::GetSize(void)
{
    return mlistExps.size();
} // End of function GetSize(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Clear
// Full name : CMyExpTrack::Clear
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : void
// Notes     : 
void CMyExpTrack::Clear(void)
{
    mlistExps.clear();
} // End of function Clear(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMyException.cpp
/////////////////////////////////////////////////////////////////////////////////////////