/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmMatch.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/09 14:12:16
// Modify time 	: 2020/01/09 14:12:16
// Note         :
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

#ifndef __VM_MATCH_H__
#define __VM_MATCH_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdlib.h>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

inline tDiv v_div( int iNum1, int iNum2 )
{
    return div(iNum1,iNum2);
}

inline tlDiv v_div( long lNum1, long lNum2 )
{
    return div(lNum1,lNum2);
}

inline tllDiv v_div( long long llNum1, long long llNum2 )
{
    return div(llNum1,llNum2);
}

inline int v_abs(int iNum)
{
    return abs(iNum);
}

inline long v_abs(long lNum)
{
    return labs(lNum);
}
inline long long v_abs(long long llNum)
{
    return llabs(llNum);
}
/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_MATCH_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmMatch.h
/////////////////////////////////////////////////////////////////////////////////////////