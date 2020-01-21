/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmTypeFmt.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/20 09:11:56
// Modify time 	: 2020/01/20 09:11:56
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

#ifndef __VMTYPEFMT_H__
#define __VMTYPEFMT_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

    enum emFlags
    {
        // �ڸ������ֶο�������������
        emLeft = vT('-'),
        // ������ֵΪ�з��ŵ����ͣ����ڸ�ֵǰʹ�÷��ţ�+ �� -����Ϊǰ׺��
        emRight = vT('+'),
        // �� o��x �� X ��ʽһ��ʹ��ʱ�� # ��־���ֱ�ʹ�� 0��0x �� 0X ��Ϊ�κη������ֵ��ǰ׺��
        // �� e��E��f��F��a �� A ��ʽһ��ʹ��ʱ�� # ��־��ǿ�����ֵ����С���㡣
        // �� g �� G ��ʽһ��ʹ��ʱ�� # ��־��ǿ�����ֵ����С���㣬����ֹ�ض�β���㡣
        // �� c��d��i��u �� s һ��ʹ��ʱ���򽫱����ԡ�
        emPound = vT('#'),
        // ����� 0 ��Ϊ��ȵ�ǰ׺������ڴﵽ��С���ǰ���ǰ���㡣 ��� 0 �� - ͬʱ���֣�0 �򽫱����ԡ� 
        // ���Ϊ������ʽ��i��u��x��X��o��d��ָ���� 0�����һ����ھ��ȹ淶������ %04.d����0 �򽫱����ԡ� 
        // ���Ϊ a �� A �����ʽָ���� 0������� 0x �� 0X ǰ׺����β��ǰ׷��ǰ���㡣
        emZero = vT('0'),
        // ������ֵΪ�з��ŵ���ֵ����ʹ�ÿհ���Ϊ��ǰ׺�� ����հ׺� + ��־ͬʱ���֣��հ��򽫱����ԡ�
        emSpace = vT(' ')

    };
    
    struct vfm_char
    {
        const tchar* const fmt_c = vT("hc");
        const tchar* const fmt_C = vT("hC");

    };
    struct vfm_wchar_t
    {
        const tchar* const fmt_c = vT("wc");
        const tchar* const fmt_C = vT("wC");
    };
    char
    unsigned char	hh	d��i��o��u��x �� X
    short int
    short unsigned int	h	d��i��o��u��x �� X
    __int32
    unsigned __int32	I32	d��i��o��u��x �� X
    __int64
    unsigned __int64	I64	d��i��o��u��x �� X
    intmax_t
    uintmax_t	j �� I64	d��i��o��u��x �� X
        long double	l��Сд�� L���� L	a��A��e��E��f��F��g �� G
        long int
        long unsigned int	l��Сд�� L��	d��i��o��u��x �� X
        long long int
        unsigned long long int	ll��Сд�� LL��	d��i��o��u��x �� X
        ptrdiff_t	t �� I����д�� i��	d��i��o��u��x �� X
        size_t	z �� I����д�� i��	d��i��o��u��x �� X
        ���ֽ��ַ�	h	c �� C
        ���ַ�	l��Сд�� L���� w	c �� C
        ���ֽ��ַ���	h	s��S �� Z
        ���ַ��ַ���	l��Сд�� L���� w	s��S �� Z

struct vformat

struct vfm_int
{
   
};

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VMTYPEFMT_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmTypeFmt.h
/////////////////////////////////////////////////////////////////////////////////////////