/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CTstCaseForAtom.cpp
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 16/2/2016 12:16:49
// Modify time  : 16/2/2016 12:16:49
// Note         : 
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

#include "CTstCaseForAtom.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CTstCaseForAtom::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const stCmd& stuCmd
// Return    : void
// Notes     : 
void CTstCaseForAtom::OnExcute(const stCmd& stuCmd)
{
    std::cout << "CTstCaseForAtom runing... " << std::endl;

    CAtom lAtom(0);
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom.Change( 10 );
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom.Add( 10 );
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom.Add( -2 );
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom.Increment();
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom.Decrement();
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom.Change( 5 );
    lAtom.CompareExchange( 5,100 );
    std::cout << "Atom : " << lAtom << " Change : " << 100 << std::endl;

    lAtom.CompareExchange( 10, 10 );
    std::cout << "Atom : " << lAtom << " Change : " << 10  << std::endl;

    lAtom = lAtom + CAtom(10);
    std::cout << "Atom : " << lAtom << std::endl;

    lAtom = 50;
    std::cout << "Atom : " << lAtom << std::endl;

    std::cout << "Atom : " << lAtom+CAtom(11) << std::endl;

} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTstCaseForAtom.cpp
/////////////////////////////////////////////////////////////////////////////////////////
