/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CBit.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 7/12/2015 11:10:46
// Modify time 	: 8/12/2015 11:10:46
// Note 		:
//
//          位操作总结
//                  1. 位与运算符(&)
//                      例：00000011 & 00000101 = 00000001
//                  2. 位或运算符(|)
//                      例：00000011 | 00000101 = 00000111
//                  3. 位异或运算符(^)
//                      例：00000011 | 00000101 = 00000110
//                  4. 位取反运算符(~)
//                      例：00000011 ~ 00000101 = 11111000
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CBit.h"

/////////////////////////////////////////////////////////////////////////////////////////
// functions : 

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CBit::ToString
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : std::string
// Notes     : 
std::string CBit::ToString()
{
    const PSTBIT pBit = (PSTBIT)(&muiBit);
    std::stringstream ssBuf;
    ssBuf   << pBit->bit31 << pBit->bit30 << pBit->bit29 << pBit->bit28  << " "
        << pBit->bit27 << pBit->bit26 << pBit->bit25 << pBit->bit24 << " "
        << pBit->bit23 << pBit->bit22 << pBit->bit21 << pBit->bit20 <<  " "
        << pBit->bit19 << pBit->bit18 << pBit->bit17 << pBit->bit16 << " "
        << pBit->bit15 << pBit->bit14 << pBit->bit13 << pBit->bit12 << " "
        << pBit->bit11 << pBit->bit10 << pBit->bit09 << pBit->bit08 << " "
        << pBit->bit07 << pBit->bit06 << pBit->bit05 << pBit->bit04 << " "
        << pBit->bit03 << pBit->bit02 << pBit->bit01 << pBit->bit00 ;
    return ssBuf.str();
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Merge
// Full name : CBit::Merge
// Access    : public 
// Brief     : 
// Parameter : const unsigned int uiBit
// Return    : void
// Notes     : 
void CBit::Merge(const unsigned int uiBit)
{
    muiBit = muiBit|uiBit;
} // End of function Merge(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Resolve
// Full name : CBit::Resolve
// Access    : public 
// Brief     : 
// Parameter : const unsigned int uiBit
// Return    : void
// Notes     : 
void CBit::Resolve(const unsigned int uiBit)
{
    muiBit = muiBit^uiBit;
} // End of function Resolve(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsSet
// Full name : CBit::IsSet
// Access    : public 
// Brief     : 
// Parameter : const unsigned int uiBit
// Return    : bool
// Notes     : 
bool CBit::IsSet(const unsigned int uiBit)
{
    return muiBit&uiBit^uiBit?false:true;
} // End of function IsSet(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : SetBit
// Full name : CBit::SetBit
// Access    : public 
// Brief     : 
// Parameter : const unsigned int uiPos, enum enBitVal enVal
// Return    : bool
// Notes     : 
bool CBit::SetBit(const unsigned int uiPos, enum enBitVal enVal)
{
    PSTBIT pBit = (PSTBIT)&muiBit;
    switch( uiPos )
    {
    case 0:
        pBit->bit00 = enVal;
        break;
    case 1:
        pBit->bit01 = enVal;
        break;
    case 2:
        pBit->bit02 = enVal;
        break;
    case 3:
        pBit->bit03 = enVal;
        break;

    case 4:
        pBit->bit04 = enVal;
        break;
    case 5:
        pBit->bit05 = enVal;
        break;
    case 6:
        pBit->bit06 = enVal;
        break;
    case 7:
        pBit->bit07 = enVal;
        break;

    case 8:
        pBit->bit08 = enVal;
        break;
    case 9:
        pBit->bit09 = enVal;
        break;
    case 10:
        pBit->bit10 = enVal;
        break;
    case 11:
        pBit->bit11 = enVal;
        break;

    case 12:
        pBit->bit12 = enVal;
        break;
    case 13:
        pBit->bit13 = enVal;
        break;
    case 14:
        pBit->bit14 = enVal;
        break;
    case 15:
        pBit->bit15 = enVal;
        break;

    case 16:
        pBit->bit16 = enVal;
        break;
    case 17:
        pBit->bit17 = enVal;
        break;
    case 18:
        pBit->bit18 = enVal;
        break;
    case 19:
        pBit->bit19 = enVal;
        break;

    case 20:
        pBit->bit20 = enVal;
        break;
    case 21:
        pBit->bit21 = enVal;
        break;
    case 22:
        pBit->bit22 = enVal;
        break;
    case 23:
        pBit->bit23 = enVal;
        break;

    case 24:
        pBit->bit24 = enVal;
        break;
    case 25:
        pBit->bit25 = enVal;
        break;
    case 26:
        pBit->bit26 = enVal;
        break;
    case 27:
        pBit->bit27 = enVal;
        break;

    case 28:
        pBit->bit28 = enVal;
        break;
    case 29:
        pBit->bit29 = enVal;
        break;
    case 30:
        pBit->bit30 = enVal;
        break;
    case 31:
        pBit->bit31 = enVal;
        break;
    default:         
        return false;
    }
    return true;
} // End of function SetBit(...
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit.cpp
/////////////////////////////////////////////////////////////////////////////////////////
