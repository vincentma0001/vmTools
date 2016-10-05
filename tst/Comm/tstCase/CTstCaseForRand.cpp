/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTstCaseForRand.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 16/3/2016 9:04:46
// Modify time 	: 16/3/2016 9:04:46
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <Windows.h>
#include <iostream>
#include <CommInc.h>

#include "CTstCaseForRand.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CTstCaseForRand::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const stCmd& stuCmd
// Return    : void
// Notes     : 
void CTstCaseForRand::OnExcute(const stCmd& stuCmd)
{
    std::cout << "This is a rand test!" << std::endl;

    CRand loRand;
    int liC1 = 0;
    int liC2 = 0;
    int liC3 = 0;
    int liC4 = 0;
    int liC5 = 0;
    int liC6 = 0;
    int liC7 = 0;
    int liC8 = 0;
    int liC9 = 0;
    int liC10 = 0;

    for( int i=0; i<10000; i++ )
    {
        long liValue = loRand.Random( CRand::RT_AVERAGE_DISTRIBUTION, 1, 10  );
        std::cout << liValue << " ";

        switch( liValue )
        {
        case 1:
            liC1++;
            break;
        case 2:
            liC2++;
            break;
        case 3:
            liC3++;
            break;
        case 4:
            liC4++;
            break;
        case 5:
            liC5++;
            break;
        case 6:
            liC6++;
            break;
        case 7:
            liC7++;
            break;
        case 8:
            liC8++;
            break;
        case 9:
            liC9++;
            break;
        case 10:
            liC10++;
            break;
        };

        if ( i%10 == 9 )
        {
            std::cout << std::endl;
        }
    }

    std::cout << "C1 : " << liC1 << std::endl;
    std::cout << "C2 : " << liC2 << std::endl;
    std::cout << "C3 : " << liC3 << std::endl;
    std::cout << "C4 : " << liC4 << std::endl;
    std::cout << "C5 : " << liC5 << std::endl;
    std::cout << "C6 : " << liC6 << std::endl;
    std::cout << "C7 : " << liC7 << std::endl;
    std::cout << "C8 : " << liC8 << std::endl;
    std::cout << "C9 : " << liC9 << std::endl;
    std::cout << "C10 : " << liC10 << std::endl;


} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTstCaseForRand.cpp
/////////////////////////////////////////////////////////////////////////////////////////