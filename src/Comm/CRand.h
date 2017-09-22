/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CRand.h
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 16/3/2016 8:20:43
// Modify time 	: 16/3/2016 8:20:43
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CRAND_H__
#define __CRAND_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

#if defined (_MSC_VER) && (_MSC_VER<=1200)
#   include <time.h>
#   include <stdlib.h>
#else
#   include <random>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CRand
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////////
class CRand
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    enum enRandType
    {
        RT_AVERAGE_DISTRIBUTION = 1,
        RT_NORMAL_DISTRIBUTION = 2
    };
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
#if defined (_MSC_VER) && (_MSC_VER<=1200)
#else
    std::mt19937 mGen;
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
#if defined (_MSC_VER) && (_MSC_VER<=1200)
	CRand(){
        srand( (unsigned int)time(0) );
#else
    CRand():mGen(std::random_device()){
#endif
    };		            // Construct define
	virtual ~CRand(){};          // Destruct define


public:
    long Random( enum enRandType enRt, const long clMin, const long clMax )
    {
#if defined (_MSC_VER) && (_MSC_VER<=1200)
        long llDiff = clMax-clMin;
        long llRet = rand()%llDiff+clMin;
        return llRet;        
#else
        long llRet = 0;
        switch( enRt )
        {
        case RT_AVERAGE_DISTRIBUTION :
            {
                std::uniform_int_distribution<> dis(clMin, clMax);
                llRet = (long)dis(mGen);
            }
            break;
        case RT_NORMAL_DISTRIBUTION:
            {
                std::normal_distribution<> dis(clMin,clMax);
                llRet = (long)dis(mGen);
            }
            break;
        default:
            break;
        }
        return llRet;
#endif

    }
    long Random( enum enRandType enRt, const long clMax )
    {
#if defined (_MSC_VER) && (_MSC_VER<=1200)
        long liRet = rand()%clMax;
        return liRet;
#else
        long llRet = 0;
        switch( enRt )
        {
        case RT_AVERAGE_DISTRIBUTION :
            {
                std::uniform_int_distribution<> dis(0, clMax);
                llRet = (long)dis(mGen);
            }
            break;
        case RT_NORMAL_DISTRIBUTION:
            {
                std::normal_distribution<> dis(0,clMax);
                llRet = (long)dis(mGen);
            }
            break;
        default:
            break;
        }
        return llRet;
#endif
    }

}; // End of class CRand
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CRAND_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CRand.h
/////////////////////////////////////////////////////////////////////////////////////////
