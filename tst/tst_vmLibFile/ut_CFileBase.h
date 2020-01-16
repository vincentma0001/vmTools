/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CFileBase.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 11:11:31
// Modify time  : 2020/01/15 11:11:31
// Note         :
//  
//     [Q 0001] - file path string : D:\\XXX\\XXX\\XXX\\filename.ext
//     [Q 0002] - file path string : D:\\XXX\\XXX\\XXX\\filename
//     [Q 0003] - file path string : filename.ext
//     [Q 0004] - file path string : filename
//     [Q 0005] - file path string : .\\filename.ext
//     [Q 0006] - file path string : .\\filename
//     [Q 0007] - file path string : .\\..\\filename.ext
//     [Q 0008] - file path string : .\\..\\filename
//     [Q 0009] - file path string : .\\..\\..\\filename.ext
//     [Q 0010] - file path string : .\\..\\..\\filename
//     [Q 0011] - file path string : D:\\XXX\\XXX\\.\\..\\..\\filename.ext
//     [Q 0012] - file path string : D:\\XXX\\XXX\\.\\..\\..\\filename
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

#ifndef __UT_CFILEBASE_H__
#define __UT_CFILEBASE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warning
// Example : #pragma warning(disable:4996)
// #if defined (_MSC_VER)
// #   pragma warning(disable:4996)
// #endif

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :
#pragma comment (lib,"vmLibFile.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <string>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmLibBase/CUnitTestFrame.h>

// test function's files
#include <vmLibBase/vmUtil.h>
#include <vmLibFile/CFileBase.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :
void  Print_CFileBase( const vm::CFileBase& loFile )
{
    vm::utLogLine( vT("FilePath : %s"), loFile.cs_Path() );
    vm::utLogLine( vT("FileDir  : %s"), loFile.cs_Dir () );
    vm::utLogLine( vT("FileName : %s"), loFile.cs_FileName () );
    vm::utLogLine( vT("FileBase : %s"), loFile.cs_FileBase () );
    vm::utLogLine( vT("FileExt  : %s"), loFile.cs_Ext () );
}
/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t1 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    char lszBuf[1024] = {0x00};
    vm::CFileBase::GetExecDir( lszBuf, sizeof(lszBuf) );
    vm::utLogLine("%s", lszBuf);
   
    vMemZero(lszBuf);
    vm::CFileBase::GetExecName( lszBuf, sizeof(mszName) );
    vm::utLogLine("%s", lszBuf);

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t2 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    char lszBuf[ _V_FILE_MAX_PATH_ ] = { 0x00 };
    vm::CFileBase::GetExecName(lszBuf, sizeof(mszName));
    vm::utLogLine("Execute name path : %s", lszBuf);

    char lszBufForDir[_V_FILE_MAX_DIR_] = {0x00};
    vm::CFileBase::GetFileDir( lszBuf, vStrLen(lszBuf), lszBufForDir, sizeof(lszBufForDir) );
    vm::utLogLine("FileDir is  : %s", lszBufForDir);

    char lszBufForFileName[ _V_FILE_MAX_FNAME_ ] = { 0x00 };
    vm::CFileBase::GetFileName(lszBuf, vStrLen(lszBuf), lszBufForFileName, sizeof(lszBufForFileName));
    vm::utLogLine("FileName is : %s", lszBufForFileName);

    char lszBufForFileBase[ _V_FILE_MAX_FNAME_ ] = { 0x00 };
    vm::CFileBase::GetFileBase(lszBuf, vStrLen(lszBuf), lszBufForFileBase, sizeof(lszBufForFileBase));
    vm::utLogLine("FileBase is : %s", lszBufForFileBase);

    char lszBufForExt[_V_FILE_MAX_EXT_] = {0x00};
    vm::CFileBase::GetFileExt( lszBuf, vStrLen(lszBuf), lszBufForExt, sizeof(lszBufForExt) );
    vm::utLogLine("FileExt is  : %s", lszBufForExt);

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t3 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT("D:\\MyWork\\MyGitHubs\\vmTools\\bin\\tst_vmLibFile.exe");
    vm::utLogLine( "The string is %s", lpPath );
    lbRet = vm::CFileBase::HasDir( lpPath );
  	vm::utLogLine( "Check string has direct is %s!", lbRet ==true?vT("true"):vT("false") );

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t4 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT("tst_vmLibFile.exe");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasDir(lpPath);
    vm::utLogLine("Check string has direct is %s!", lbRet == true ? vT("true") : vT("false"));

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t5 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT("tst_vmLibFile.exe");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasExt(lpPath);
    vm::utLogLine("Check string has ext is %s!", lbRet == true ? vT("true") : vT("false"));


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t6 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT("tst_vmLibFile");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasExt(lpPath);
    vm::utLogLine("Check string has ext is %s!", lbRet == true ? vT("true") : vT("false"));


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t7 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT(".\\tst_vmLibFile.exe");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasExt(lpPath);
    vm::utLogLine("Check string has ext is %s!", lbRet == true ? vT("true") : vT("false"));


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t8 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT(".\\tst_vmLibFile");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasExt(lpPath);
    vm::utLogLine("Check string has ext is %s!", lbRet == true ? vT("true") : vT("false"));


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t9 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT(".\\..\\tst_vmLibFile.exe");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasExt(lpPath);
    vm::utLogLine("Check string has ext is %s!", lbRet == true ? vT("true") : vT("false"));


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t10 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lpPath = vT(".\\..\\tst_vmLibFile");
    vm::utLogLine("The string is %s", lpPath);
    lbRet = vm::CFileBase::HasExt(lpPath);
    vm::utLogLine("Check string has ext is %s!", lbRet == true ? vT("true") : vT("false"));


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t11 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");
    // #Add test content here#
    //     [Q 0001] - file path string : D:\\XXX\\XXX\\XXX\\filename.ext
    const tChar* lpPath = vT("D:\\XXX\\XXX\\XXX\\filename.ext");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase( loFile );

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t12 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0002] - file path string : D:\\XXX\\XXX\\XXX\\filename
    const tChar* lpPath = vT("D:\\XXX\\XXX\\XXX\\filename");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t13 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0003] - file path string : filename.ext
    const tChar* lpPath = vT("filename.ext");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t14 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0004] - file path string : filename
    const tChar* lpPath = vT("filename");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t15 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0005] - file path string : .\\filename.ext
    const tChar* lpPath = vT(".\\filename.ext");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t16 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0006] - file path string : .\\filename
    const tChar* lpPath = vT(".\\filename");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t17 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0007] - file path string : .\\..\\filename.ext
    const tChar* lpPath = vT(".\\..\\filename.ext");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t18 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0008] - file path string : .\\..\\filename
    const tChar* lpPath = vT(".\\..\\filename");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t19 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0009] - file path string : .\\..\\..\\filename.ext
    const tChar* lpPath = vT(".\\..\\..\\filename.ext");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t20 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0010] - file path string : .\\..\\..\\filename
    const tChar* lpPath = vT(".\\..\\..\\filename");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t21 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0011] - file path string : D:\\XXX\\XXX\\.\\..\\..\\filename.ext
    const tChar* lpPath = vT("D:\\XXX\\XXX\\.\\..\\..\\filename.ext");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t22 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    //     [Q 0012] - file path string : D:\\XXX\\XXX\\.\\..\\..\\filename
    const tChar* lpPath = vT("D:\\XXX\\XXX\\.\\..\\..\\filename");
    vm::utLogLine("The string is %s", lpPath);
    vm::CFileBase loFile(lpPath);
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CFileBase_t23 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vm::CFileBase loFile( nullptr );
    Print_CFileBase(loFile);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CFileBase )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CFileBase_t1);
    UNIT_TEST_REGIST(ut_CFileBase_t2);
    UNIT_TEST_REGIST(ut_CFileBase_t3);
    UNIT_TEST_REGIST(ut_CFileBase_t4);
    UNIT_TEST_REGIST(ut_CFileBase_t5);
    UNIT_TEST_REGIST(ut_CFileBase_t6);
    UNIT_TEST_REGIST(ut_CFileBase_t7);
    UNIT_TEST_REGIST(ut_CFileBase_t8);
    UNIT_TEST_REGIST(ut_CFileBase_t9);
    UNIT_TEST_REGIST(ut_CFileBase_t10);
    UNIT_TEST_REGIST(ut_CFileBase_t11);
    UNIT_TEST_REGIST(ut_CFileBase_t12);
    UNIT_TEST_REGIST(ut_CFileBase_t13);
    UNIT_TEST_REGIST(ut_CFileBase_t14);
    UNIT_TEST_REGIST(ut_CFileBase_t15);
    UNIT_TEST_REGIST(ut_CFileBase_t16);
    UNIT_TEST_REGIST(ut_CFileBase_t17);
    UNIT_TEST_REGIST(ut_CFileBase_t18);
    UNIT_TEST_REGIST(ut_CFileBase_t19);
    UNIT_TEST_REGIST(ut_CFileBase_t20);
    UNIT_TEST_REGIST(ut_CFileBase_t21);
    UNIT_TEST_REGIST(ut_CFileBase_t22);
    UNIT_TEST_REGIST(ut_CFileBase_t23);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CFILEBASE_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CFileBase.h
/////////////////////////////////////////////////////////////////////////////////////////