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
    const PSTBIT pBit = (PSTBIT)(&mcBit);
    std::stringstream ssBuf;
    ssBuf << pBit->bit00 << pBit->bit01 << pBit->bit02 << pBit->bit03
          << pBit->bit04 << pBit->bit05 << pBit->bit06 << pBit->bit07 ;
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
    mcBit = mcBit|uiBit;
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
    mcBit = mcBit^uiBit;
} // End of function Resolve(...
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
    PSTBIT pBit = (PSTBIT)&mcBit;
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

    default:         
        return false;
    }
    return true;
} // End of function SetBit(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : IsSet
// Full name : CBit::IsSet
// Access    : public 
// Brief     : 
// Parameter : const unsigned int uiPos
// Return    : bool
// Notes     : 
bool CBit::IsSet(const unsigned int uiPos)
{
    PSTBIT pBit = (PSTBIT)&mcBit;
    switch( uiPos )
    {
    case 0:
        return unsigned int(pBit->bit00)>0?true:false;
    case 1:
        return unsigned int(pBit->bit01)>0?true:false;
    case 2:
        return unsigned int(pBit->bit02)>0?true:false;
    case 3:
        return unsigned int(pBit->bit03)>0?true:false;
    case 4:
        return unsigned int(pBit->bit04)>0?true:false;
    case 5:
        return unsigned int(pBit->bit05)>0?true:false;
    case 6:
        return unsigned int(pBit->bit06)>0?true:false;
    case 7:
        return unsigned int(pBit->bit07)>0?true:false;

    default:         
        return false;
    }
    return true;
} // End of function IsSet(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit.cpp
/////////////////////////////////////////////////////////////////////////////////////////
