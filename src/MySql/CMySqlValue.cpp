/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlValue.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 20/12/2015 14:25:36
// Modify time 	: 20/12/2015 14:25:36
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <Windows.h>
#include <DllMacro.h>

#include <DBase/CMySqlValue.h>

/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib,"libmysql.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMySqlValue
// Full name : CMySqlValue::CMySqlValue
// Access    : public 
// Brief     : 
// Parameter : const char* pStr
// Return    : 
// Notes     : 
CMySqlValue::CMySqlValue(const char* pStr) :mpStr(pStr)
{

} // End of function CMySqlValue(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMySqlValue
// Full name : CMySqlValue::CMySqlValue
// Access    : private 
// Brief     : 
// Parameter : const CMySqlValue& oVal
// Return    : 
// Notes     : 
CMySqlValue::CMySqlValue(const CMySqlValue& oVal)
{

} // End of function CMySqlValue(...
/////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CMySqlValue
// Full name : CMySqlValue::~CMySqlValue
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlValue::~CMySqlValue()
{

} // End of function ~CMySqlValue(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CMySqlValue::ToString
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : std::string
// Notes     : 
std::string CMySqlValue::ToString(void)
{
    if( mpStr == 0 )
        return "NULL";
    return mpStr;
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToInt
// Full name : CMySqlValue::ToInt
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : int
// Notes     : 
//int CMySqlValue::ToInt(void)
//{
//    __try
//    {
//        if( mpStr == 0 )
//            return 0;
//
//        int iTmp = atoi( mpStr );
//        return iTmp;
//    }
//    __except( EXCEPTION_EXECUTE_HANDLER )
//    {
//        return 0xffffffff;
//    }
//} // End of function ToInt(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToLong
// Full name : CMySqlValue::ToLong
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : long
// Notes     : 
long CMySqlValue::ToLong(void)
{
    __try
    {
        if( mpStr == 0 )
            return 0;

        long llTmp = atol( mpStr );
        return llTmp;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        return 0xffffffff;
    }
} // End of function ToLong(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToDouble
// Full name : CMySqlValue::ToDouble
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : double
// Notes     : 
double CMySqlValue::ToDouble(void)
{
    __try
    {
        if( mpStr == 0 )
            return 0;

        double dTmp = strtod( mpStr, NULL );
        return dTmp;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        return 0xffffffff;
    }
} // End of function ToDouble(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToULong
// Full name : CMySqlValue::ToULong
// Access    : public 
// Brief     : 
// Parameter : int iRadix
// Return    : unsigned long
// Notes     : 
unsigned long CMySqlValue::ToULong(int iRadix)
{
    __try
    {
        if( mpStr == 0 )
            return 0;

        unsigned long ulTmp = strtoul( mpStr, NULL, iRadix );
        return ulTmp;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        return 0xffffffff;
    }
} // End of function ToULong(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : CMySqlValue::operator=
// Access    : private 
// Brief     : 
// Parameter : const CMySqlValue& oVal
// Return    : CMySqlValue&
// Notes     : 
CMySqlValue& CMySqlValue::operator=(const CMySqlValue& oVal)
{
    return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlValue.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
