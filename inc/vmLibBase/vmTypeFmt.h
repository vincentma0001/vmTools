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
        // 在给定的字段宽度内左对齐结果。
        emLeft = vT('-'),
        // 如果输出值为有符号的类型，则在该值前使用符号（+ 或 -）作为前缀。
        emRight = vT('+'),
        // 与 o、x 或 X 格式一起使用时， # 标志将分别使用 0、0x 或 0X 作为任何非零输出值的前缀。
        // 与 e、E、f、F、a 或 A 格式一起使用时， # 标志将强制输出值包含小数点。
        // 与 g 或 G 格式一起使用时， # 标志将强制输出值包含小数点，并阻止截断尾随零。
        // 与 c、d、i、u 或 s 一起使用时，则将被忽略。
        emPound = vT('#'),
        // 如果将 0 作为宽度的前缀，则会在达到最小宽度前添加前导零。 如果 0 和 - 同时出现，0 则将被忽略。 
        // 如果为整数格式（i、u、x、X、o、d）指定了 0，并且还存在精度规范（例如 %04.d），0 则将被忽略。 
        // 如果为 a 或 A 浮点格式指定了 0，则会在 0x 或 0X 前缀后，在尾数前追加前导零。
        emZero = vT('0'),
        // 如果输出值为有符号的正值，则使用空白作为其前缀。 如果空白和 + 标志同时出现，空白则将被忽略。
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
    unsigned char	hh	d、i、o、u、x 或 X
    short int
    short unsigned int	h	d、i、o、u、x 或 X
    __int32
    unsigned __int32	I32	d、i、o、u、x 或 X
    __int64
    unsigned __int64	I64	d、i、o、u、x 或 X
    intmax_t
    uintmax_t	j 或 I64	d、i、o、u、x 或 X
        long double	l（小写的 L）或 L	a、A、e、E、f、F、g 或 G
        long int
        long unsigned int	l（小写的 L）	d、i、o、u、x 或 X
        long long int
        unsigned long long int	ll（小写的 LL）	d、i、o、u、x 或 X
        ptrdiff_t	t 或 I（大写的 i）	d、i、o、u、x 或 X
        size_t	z 或 I（大写的 i）	d、i、o、u、x 或 X
        单字节字符	h	c 或 C
        宽字符	l（小写的 L）或 w	c 或 C
        单字节字符串	h	s、S 或 Z
        宽字符字符串	l（小写的 L）或 w	s、S 或 Z

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