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

#ifndef __VM_UTIL_STD_STRING_H__
#define __VM_UTIL_STD_STRING_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef   __VM_CFG_TSTRING_H__
#   include <vmCfg/vmCfgtString.h>
#endif // __VM_CFG_TSTRING_H__

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{
namespace vStd{

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_std_strtrim(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline vStdStr v_std_strtrim( const vStdStr& strData )
{
    size_t lsztDataLen = strData.length();
    if ( lsztDataLen == 0 ) return vStdStr(vT(""));
    
    size_t lsztStartPos = 0;
    tchar lszValue = strData[lsztStartPos];
    // while ( (lsztStartPos!=lsztDataLen) && ( (lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n') ) )
    while ( (lsztStartPos!=lsztDataLen) && (isspace(lszValue)))
    {
        lsztStartPos++;
        lszValue = strData[lsztStartPos];
    }

    size_t lsztEndPos = lsztDataLen;
    lszValue = strData[lsztEndPos];
    // while( (lsztEndPos!=lsztStartPos) && ( (lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n') )  )
    while( (lsztEndPos!=lsztStartPos) && (isspace(lszValue)))
    {
        lsztEndPos --;
        lszValue = strData[lsztEndPos];
    }

    size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
    return strData.substr( lsztStartPos, lsztNewDataLen );
}
// End of function v_std_strtrim(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_std_strtrim_left(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline vStdStr v_std_strtrim_left( const vStdStr& strData )
{
    size_t lsztDataLen = strData.length();
    if (lsztDataLen == 0) return vStdStr(vT(""));

    size_t lsztStartPos = 0;
    tchar lszValue = strData[lsztStartPos];
    // while ((lsztStartPos != lsztDataLen) && ((lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n')))
    while ((lsztStartPos != lsztDataLen) && (isspace(lszValue)))
    {
        lsztStartPos++;
        lszValue = strData[lsztStartPos];
    }

    size_t lsztNewDataLen = lsztDataLen - lsztStartPos;
    return strData.substr(lsztStartPos, lsztNewDataLen);
}
// End of function v_std_strtrim_left(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_std_strtrim_right(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline vStdStr v_std_strtrim_right(const vStdStr& strData)
{
    size_t lsztDataLen = strData.length();
    if (lsztDataLen == 0) return vStdStr(vT(""));

    size_t lsztEndPos = lsztDataLen;
    tchar lszValue = strData[lsztEndPos];
    // while ((lsztEndPos != 0)  && ((lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n')))
    while ((lsztEndPos != 0)  && (isspace(lszValue)))
    {
        lsztEndPos--;
        lszValue = strData[lsztEndPos];
    }

    size_t lsztNewDataLen = lsztDataLen - lsztEndPos;
    return strData.substr(0, lsztNewDataLen);
}
// End of function v_std_strtrim_right(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_std_str_substr(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline vStdStr v_std_str_substr(const vStdStr& strData, const tchar const cszBegin, const tchar const cszEnd )
{
    // 获取整个字符串长度
    size_t lsztDataLen = strData.length();
    if (lsztDataLen == 0) return vStdStr(vT(""));

    // 获取子字符串开头的位置
    size_t lsztStartPos = strData.find_first_of( cszBegin );
    if ( lsztStartPos == vStdStr::npos )
        return vStdStr(vT(""));

    // 获取子字符串结尾的位置
    size_t lsztEndPos = strData.rfind(cszEnd);
    if ( lsztEndPos == vStdStr::npos )
        return vStdStr(vT(""));

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lsztEndPos<=lsztStartPos)
        return vStdStr(vT(""));

    // 计算子字符串长度
    size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
    return strData.substr(lsztStartPos, lsztNewDataLen);
}
// End of function v_std_str_substr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_std_str_substr_first(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline vStdStr v_std_str_substr_first(const vStdStr& strData, const tchar const cszBegin, const tchar const cszEnd)
{
    // 获取整个字符串长度
    size_t lsztDataLen = strData.length();
    if (lsztDataLen == 0) return vStdStr(vT(""));

    // 获取子字符串开头的位置
    size_t lsztStartPos = strData.find_first_of(cszBegin);
    if (lsztStartPos == vStdStr::npos)
        return vStdStr(vT(""));

    // 获取子字符串结尾的位置
    size_t lsztEndPos = strData.find_first_of(cszEnd);
    if (lsztEndPos == vStdStr::npos)
        return vStdStr(vT(""));

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lsztEndPos <= lsztStartPos)
        return vStdStr(vT(""));

    // 计算子字符串长度
    size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
    return strData.substr(lsztStartPos, lsztNewDataLen);
}
// End of function v_std_str_substr_first(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace std
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_UTIL_STD_STRING_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmStdUtil.h
/////////////////////////////////////////////////////////////////////////////////////////