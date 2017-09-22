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
// Brief     : 构造函数 
// Parameter :  enum enExpType lenExpLevel,         - 异常类型
//              const unsigned long lulExpCode,     - 异常代码
//              const std::string lstrExpDes,       - 异常描述
//              /* const std::string lstrTime, */   - 异常产生时间
//              const std::string lstrFunc,         - 异常产生时所在的函数名
//              const std::string lstrFile,         - 异常产生时所在的文件名
//              const unsigned long lulLine         - 异常产生时所在的文件行数
// Return    : 无
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
// Brief     : 构造函数
// Parameter : const CExpUnit& cEu      - 错误发生时的情况汇总
// Return    : 无
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
// Brief     : 赋值函数
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
// Brief     : 格式化错误信息
// Parameter : 无
// Return    : std::string          - 格式化后的字符串
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
// Brief     : 构造函数
// Parameter :  enum CExpUnit::enExpType lenExpLevel,      - 错误类型 , 详见结构 enExpType
//              const unsigned long lulExpCode,            - 错误代码
//              const std::string lstrExpDes,              - 错误描述
//              /*const std::string lstrTime, */           - 错误产生的时间
//              const std::string lstrFunc,                - 错误产生的函数名
//              const std::string lstrFile,                - 错误产生的文件名
//              const unsigned long lulLine                - 错误产生的文件行数
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
    // 构建一个记录单元
    CExpUnit lEu(lenExpType, lulExpCode, lstrExpDes,/* lstrTime, */lstrFunc, lstrFile, lulLine ) ;

    // 将数据添加到异常列表中
    mlistExps.push_back( lEu );

} // End of function CMyExption(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMyExption
// Full name : CMyExption::CMyExption
// Access    : public 
// Brief     : 析构函数
// Parameter : const CExpUnit& lEu
// Return    : 无
// Notes     : 
CMyExpTrack::CMyExpTrack(const CExpUnit& lEu)
{
    // 将数据添加到异常列表中
    mlistExps.push_back(lEu);
} // End of function CMyExption(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddExp
// Full name : CMyExption::AddExp
// Access    : public 
// Brief     : 添加一条异常记录
// Brief     : 构造函数
// Parameter :  enum CExpUnit::enExpType lenExpLevel,      - 错误类型 , 详见结构 enExpType
//              const unsigned long lulExpCode,            - 错误代码
//              const std::string lstrExpDes,              - 错误描述
//              /*const std::string lstrTime, */           - 错误产生的时间
//              const std::string lstrFunc,                - 错误产生的函数名
//              const std::string lstrFile,                - 错误产生的文件名
//              const unsigned long lulLine                - 错误产生的文件行数
// Return    : void
// Notes     : 
void CMyExpTrack::AddExp(
    enum CExpUnit::enExpType    lenExpLevel,        // 异常类型
    const unsigned long		    lulExpCode,         // 异常代码
    const std::string		    lstrExpDes,         // 异常描述
    // const std::string		lstrTime,           // 异常产生的时间
    const std::string		    lstrFunc,           // 异常产生的函数名
    const std::string		    lstrFile,           // 异常产生的文件
    const unsigned long		    lulLine             // 异常产生的行数
    )

{
    // 构建一个记录单元
    CExpUnit lEu(lenExpLevel, lulExpCode, lstrExpDes, /*lstrTime, */ lstrFunc, lstrFile, lulLine ) ;

    // 将数据添加到异常列表中
    mlistExps.push_back( lEu );
} // End of function AddExp(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddExp
// Full name : CMyException::AddExp
// Access    : public 
// Brief     : 添加一条异常记录
// Parameter : CExpUnit& lcEu
// Return    : void
// Notes     : 
void CMyExpTrack::AddExp(CExpUnit& lcEu)
{
    // 将数据添加到异常列表中
    mlistExps.push_back( lcEu );
} // End of function AddExp(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFirstExp
// Full name : CMyExption::GetFirstExp
// Access    : public 
// Brief     : 获取错误
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