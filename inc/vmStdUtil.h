/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmStdUtil.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/07 19:02:07
// Modify time 	: 2020/01/07 19:02:07
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

#ifndef __VMSTDUTIL_H__
#define __VMSTDUTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <string>

// Config files included

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

    std::string v_std_strtrim_left( const std::string& strData )
    {
        size_t lsztDataLen = strData.length();
        if ( lsztDataLen == 0 ) return std::string("");
        
        size_t lsztStartPos = 0;
        char lszValue = strData[lsztStartPos];
        while ( (lsztStartPos!=lsztDataLen) && ( (lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n') ) )
        {
            lsztStartPos++;
            lszValue = strData[lsztStartPos];
        }

        size_t lsztEndPos = lsztDataLen;
        lszValue = strData[lsztEndPos];
        while( (lsztEndPos!=lsztStartPos) && ( (lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n') )  )
        {
            lsztEndPos --;
            lszValue = strData[lsztEndPos];
        }

        size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
        return strData.substr( lsztStartPos, lsztNewDataLen );
    }

    std::string v_std_strtrim_left( const std::string& strData )
    {
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return std::string("");

        size_t lsztStartPos = 0;
        char lszValue = strData[lsztStartPos];
        while ((lsztStartPos != lsztDataLen) && ((lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n')))
        {
            lsztStartPos++;
            lszValue = strData[lsztStartPos];
        }

        size_t lsztNewDataLen = lsztDataLen - lsztStartPos;
        return strData.substr(lsztStartPos, lsztNewDataLen);
    }

    std::string v_std_strtrim_right(const std::string& strData)
    {
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return std::string("");

        size_t lsztEndPos = lsztDataLen;
        char lszValue = strData[lsztEndPos];
        while ((lsztEndPos != 0)  && ((lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n')))
        {
            lsztEndPos--;
            lszValue = strData[lsztEndPos];
        }

        size_t lsztNewDataLen = lsztDataLen - lsztEndPos;
        return strData.substr(0, lsztNewDataLen);
    }

    std::string v_std_str_substr(const std::string& strData, const char const cszBegin, const char const cszEnd )
    {
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return std::string("");

        size_t lsztStartPos = strData.find_first_of( cszBegin );
        if ( lsztStartPos == std::string::npos )
            return std::string("");

        size_t lsztEndPos = strData.rfind(cszEnd);
        if ( lsztEndPos == std::string::npos )
            return std::string("");

        size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
        return strData.substr(lsztStartPos, lsztNewDataLen);
    }



/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VMSTDUTIL_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmStdUtil.h
/////////////////////////////////////////////////////////////////////////////////////////