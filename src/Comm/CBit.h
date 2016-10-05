/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CBit.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 1/12/2015 18:12:24
// Modify time 	: 1/12/2015 18:12:24
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

#ifndef __VM_TOOLS_CBIT_H__
#define __VM_TOOLS_CBIT_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>
#include <sstream>

/////////////////////////////////////////////////////////////////////////////////////
// type define :
typedef struct stBit
{
    unsigned int  bit00:1;
    unsigned int  bit01:1;
    unsigned int  bit02:1;
    unsigned int  bit03:1;
    unsigned int  bit04:1;
    unsigned int  bit05:1;
    unsigned int  bit06:1;
    unsigned int  bit07:1;
    unsigned int  bit08:1;
    unsigned int  bit09:1;
    unsigned int  bit10:1;
    unsigned int  bit11:1;
    unsigned int  bit12:1;
    unsigned int  bit13:1;
    unsigned int  bit14:1;
    unsigned int  bit15:1;
    unsigned int  bit16:1;
    unsigned int  bit17:1;
    unsigned int  bit18:1;
    unsigned int  bit19:1;
    unsigned int  bit20:1;
    unsigned int  bit21:1;
    unsigned int  bit22:1;
    unsigned int  bit23:1;
    unsigned int  bit24:1;
    unsigned int  bit25:1;
    unsigned int  bit26:1;
    unsigned int  bit27:1;
    unsigned int  bit28:1;
    unsigned int  bit29:1;
    unsigned int  bit30:1;
    unsigned int  bit31:1;
} STBIT,*PSTBIT;

/////////////////////////////////////////////////////////////////////////////////////
// enum define :
enum enBitVal{ B0=0,B1=1 };

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CBit
//        Notes : ## add class notes ##
//
/////////////////////////////////////////////////////////////////////////////////////
class CBit
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    unsigned int& muiBit;

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CBit( unsigned int& uiVal ):muiBit(uiVal){  }; 	// construct define
	~CBit(){ }	                                        // destruct define

public:
    std::string ToString();
    void Merge( const unsigned int uiBit  );
    void Resolve( const unsigned int uiBit );
    bool IsSet( const unsigned int uiBit );
    bool IsSetPos( const unsigned int uiPos )
    {
        PSTBIT pBit = (PSTBIT)&muiBit;
        switch( uiPos )
        {
            case 0:
                return int( pBit->bit00 )>0?true:false;
            case 1:
                return int( pBit->bit01 )>0?true:false;
            case 2:
                return int( pBit->bit02 )>0?true:false;
            case 3:
                return int( pBit->bit03 )>0?true:false;

//             case 4:
//                 pBit->bit04 = enVal;
//                 break;
//             case 5:
//                 pBit->bit05 = enVal;
//                 break;
//             case 6:
//                 pBit->bit06 = enVal;
//                 break;
//             case 7:
//                 pBit->bit07 = enVal;
//                 break;
// 
//             case 8:
//                 pBit->bit08 = enVal;
//                 break;
//             case 9:
//                 pBit->bit09 = enVal;
//                 break;
//             case 10:
//                 pBit->bit10 = enVal;
//                 break;
//             case 11:
//                 pBit->bit11 = enVal;
//                 break;
// 
//             case 12:
//                 pBit->bit12 = enVal;
//                 break;
//             case 13:
//                 pBit->bit13 = enVal;
//                 break;
//             case 14:
//                 pBit->bit14 = enVal;
//                 break;
//             case 15:
//                 pBit->bit15 = enVal;
//                 break;
// 
//             case 16:
//                 pBit->bit16 = enVal;
//                 break;
//             case 17:
//                 pBit->bit17 = enVal;
//                 break;
//             case 18:
//                 pBit->bit18 = enVal;
//                 break;
//             case 19:
//                 pBit->bit19 = enVal;
//                 break;
// 
//             case 20:
//                 pBit->bit20 = enVal;
//                 break;
//             case 21:
//                 pBit->bit21 = enVal;
//                 break;
//             case 22:
//                 pBit->bit22 = enVal;
//                 break;
//             case 23:
//                 pBit->bit23 = enVal;
//                 break;
// 
//             case 24:
//                 pBit->bit24 = enVal;
//                 break;
//             case 25:
//                 pBit->bit25 = enVal;
//                 break;
//             case 26:
//                 pBit->bit26 = enVal;
//                 break;
//             case 27:
//                 pBit->bit27 = enVal;
//                 break;
// 
//             case 28:
//                 pBit->bit28 = enVal;
//                 break;
//             case 29:
//                 pBit->bit29 = enVal;
//                 break;
//             case 30:
//                 pBit->bit30 = enVal;
//                 break;
//             case 31:
//                 pBit->bit31 = enVal;
//                 break;
            default:         
                return false;
        }
        return true;
    }

    bool SetBit( const unsigned int uiPos, enum enBitVal enVal  );

}; // End of class CBit
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CBIT_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit.h
/////////////////////////////////////////////////////////////////////////////////////////