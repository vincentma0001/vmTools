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

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <sstream>
#include <DllMacro.h>

#include <DBase/CMySqlExpTrack.h>

/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib,"libmysql.lib")

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CExpUnit
// Full name : CExpUnit::CExpUnit
// Access    : public 
// Brief     : 
// Parameter : enum enExpType lenExpLevel, 
//             const unsigned long lulExpCode, 
//             const std::string lstrExpDes, 
//             /* const std::string lstrTime, */ 
//             const std::string lstrFunc, 
//             const std::string lstrFile, 
//             const unsigned long lulLine
// Return    : 
// Notes     : 
CMySqlExpUnit::CMySqlExpUnit( enum enExpType lenExpLevel, 
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
// Brief     : 
// Parameter : const CExpUnit& cEu
// Return    : 
// Notes     : 
CMySqlExpUnit::CMySqlExpUnit(const CMySqlExpUnit& cEu) 
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
// Name      : CExpUnit
// Full name : CExpUnit::CExpUnit
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlExpUnit::CMySqlExpUnit()
{

} // End of function CExpUnit(...
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : CExpUnit::operator=
// Access    : public 
// Brief     : 
// Parameter : const CExpUnit& cEu
// Return    : CExpUnit&
// Notes     : 
CMySqlExpUnit& CMySqlExpUnit::operator=(const CMySqlExpUnit& cEu)
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
// Brief     : 
// Parameter : 
// Return    : std::string
// Notes     : 
std::string CMySqlExpUnit::ToString()
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

    lssBuf << mulExpCode << ") : " 
           << mstrExpDes.c_str() << " (" 
           << mstrFile.c_str() << ")" 
           << std::ends;

    return lssBuf.str();
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CExpUnit
// Full name : CExpUnit::~CExpUnit
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlExpUnit::~CMySqlExpUnit()
{

} // End of function ~CExpUnit(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMyExption
// Full name : CMyExption::CMyExption
// Access    : public 
// Brief     : 
// Parameter : enum CExpUnit::enExpType lenExpLevel, 
//             const unsigned long lulExpCode, 
//             const std::string lstrExpDes, 
//             /*const std::string lstrTime, */ 
//             const std::string lstrFunc, 
//             const std::string lstrFile, 
//             const unsigned long lulLine
// Return    : 
// Notes     : 
CMySqlExpTrack::CMySqlExpTrack( enum CMySqlExpUnit::enExpType lenExpLevel, 
                        const unsigned long lulExpCode, 
                        const std::string lstrExpDes, 
                        /*const std::string lstrTime, */ 
                        const std::string lstrFunc, 
                        const std::string lstrFile, 
                        const unsigned long lulLine )
{
    CMySqlExpUnit lEu(lenExpLevel, lulExpCode, lstrExpDes,/* lstrTime, */lstrFunc, lstrFile, lulLine ) ;

    mlistExps.push_back( lEu );
} // End of function CMyExption(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMyExption
// Full name : CMyExption::CMyExption
// Access    : public 
// Brief     : 
// Parameter : const CExpUnit& lEu
// Return    : 
// Notes     : 
CMySqlExpTrack::CMySqlExpTrack(const CMySqlExpUnit& lEu)
{
    mlistExps.push_back(lEu);
} // End of function CMyExption(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMyExpTrack
// Full name : CMyExpTrack::CMyExpTrack
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlExpTrack::CMySqlExpTrack()
{

} // End of function CMyExpTrack(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddExp
// Full name : CMyExption::AddExp
// Access    : public 
// Brief     : 
// Parameter : enum CExpUnit::enExpType lenExpLevel, 
//             const unsigned long lulExpCode, 
//             const std::string lstrExpDes, 
//             /* const std::string lstrTime, */ 
//             const std::string lstrFunc, 
//             const std::string lstrFile, 
//             const unsigned long lulLine
// Return    : void
// Notes     : 
void CMySqlExpTrack::AddExp(
    enum CMySqlExpUnit::enExpType    lenExpLevel,        // 异常类型
    const unsigned long		    lulExpCode,         // 异常代码
    const std::string		    lstrExpDes,         // 异常描述
    // const std::string		lstrTime,           // 异常产生的时间
    const std::string		    lstrFunc,           // 异常产生的函数名
    const std::string		    lstrFile,           // 异常产生的文件
    const unsigned long		    lulLine             // 异常产生的行数
    )

{
    CMySqlExpUnit lEu(lenExpLevel, lulExpCode, lstrExpDes, /*lstrTime, */ lstrFunc, lstrFile, lulLine ) ;

    mlistExps.push_back( lEu );
} // End of function AddExp(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddExp
// Full name : CMyException::AddExp
// Access    : public 
// Brief     : 
// Parameter : CExpUnit& lcEu
// Return    : void
// Notes     : 
void CMySqlExpTrack::AddExp(CMySqlExpUnit& lcEu)
{
    mlistExps.push_back( lcEu );
} // End of function AddExp(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFirstExp
// Full name : CMyExption::GetFirstExp
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CMyExption::Itor
// Notes     : 
CMySqlExpTrack::tItor CMySqlExpTrack::GetFirstExp(void)
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
CMySqlExpTrack::tItor CMySqlExpTrack::GetLastExp(void)
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
unsigned int CMySqlExpTrack::GetSize(void)
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
void CMySqlExpTrack::Clear(void)
{
    mlistExps.clear();
} // End of function Clear(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CMyExpTrack
// Full name : CMyExpTrack::~CMyExpTrack
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlExpTrack::~CMySqlExpTrack()
{

} // End of function ~CMyExpTrack(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMyException.cpp
/////////////////////////////////////////////////////////////////////////////////////////