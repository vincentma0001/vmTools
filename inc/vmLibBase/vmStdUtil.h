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

#ifndef __VM_STD_UTIL_H__
#define __VM_STD_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#ifndef   _STRING_
#	error this file need #include <string>
#endif // _STRING_

// Config files included
#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{
namespace vStd{

    inline vString v_std_strtrim( const vString& strData )
    {
        size_t lsztDataLen = strData.length();
        if ( lsztDataLen == 0 ) return vString(vT(""));
        
        size_t lsztStartPos = 0;
        vChar lszValue = strData[lsztStartPos];
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

    inline vString v_std_strtrim_left( const vString& strData )
    {
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return vString(vT(""));

        size_t lsztStartPos = 0;
        vChar lszValue = strData[lsztStartPos];
        // while ((lsztStartPos != lsztDataLen) && ((lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n')))
        while ((lsztStartPos != lsztDataLen) && (isspace(lszValue)))
        {
            lsztStartPos++;
            lszValue = strData[lsztStartPos];
        }

        size_t lsztNewDataLen = lsztDataLen - lsztStartPos;
        return strData.substr(lsztStartPos, lsztNewDataLen);
    }

    inline vString v_std_strtrim_right(const vString& strData)
    {
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return vString(vT(""));

        size_t lsztEndPos = lsztDataLen;
        vChar lszValue = strData[lsztEndPos];
        // while ((lsztEndPos != 0)  && ((lszValue == ' ') || (lszValue == '\t') || (lszValue == '\n')))
        while ((lsztEndPos != 0)  && (isspace(lszValue)))
        {
            lsztEndPos--;
            lszValue = strData[lsztEndPos];
        }

        size_t lsztNewDataLen = lsztDataLen - lsztEndPos;
        return strData.substr(0, lsztNewDataLen);
    }

    inline vString v_std_str_substr(const vString& strData, const vChar const cszBegin, const vChar const cszEnd )
    {
        // 获取整个字符串长度
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return vString(vT(""));

        // 获取子字符串开头的位置
        size_t lsztStartPos = strData.find_first_of( cszBegin );
        if ( lsztStartPos == vString::npos )
            return vString(vT(""));

        // 获取子字符串结尾的位置
        size_t lsztEndPos = strData.rfind(cszEnd);
        if ( lsztEndPos == vString::npos )
            return vString(vT(""));

        // 判断子字符串是否有效，解决类似“}{”问题
        if (lsztEndPos<=lsztStartPos)
            return vString(vT(""));

        // 计算子字符串长度
        size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
        return strData.substr(lsztStartPos, lsztNewDataLen);
    }

    inline vString v_std_str_substr_first(const vString& strData, const vChar const cszBegin, const vChar const cszEnd)
    {
        // 获取整个字符串长度
        size_t lsztDataLen = strData.length();
        if (lsztDataLen == 0) return vString(vT(""));

        // 获取子字符串开头的位置
        size_t lsztStartPos = strData.find_first_of(cszBegin);
        if (lsztStartPos == vString::npos)
            return vString(vT(""));

        // 获取子字符串结尾的位置
        size_t lsztEndPos = strData.find_first_of(cszEnd);
        if (lsztEndPos == vString::npos)
            return vString(vT(""));

        // 判断子字符串是否有效，解决类似“}{”问题
        if (lsztEndPos <= lsztStartPos)
            return vString(vT(""));

        // 计算子字符串长度
        size_t lsztNewDataLen = lsztEndPos - lsztStartPos;
        return strData.substr(lsztStartPos, lsztNewDataLen);
    }

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace std
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_STD_UTIL_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmStdUtil.h
/////////////////////////////////////////////////////////////////////////////////////////