/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CMem.hpp
// Version      : 1.0.0.0
// Brief        : 此类封装了mem系列函数。
// Author       : v.m.
// Create time  : 2019/12/18 10:41:19
// Modify time  : 2019/12/18 10:41:19
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#ifndef __CMEM_H__
#define __CMEM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#	error this file need #include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CMem : 此类封装了mem系列函数。
//
/////////////////////////////////////////////////////////////////////////////////////////
template <size_t sztBufSize>
class CMem
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro define :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
	// Construct define
    explicit CMem();
    // Destruct define
    virtual ~CMem();
    
private:
    // No Copy
    inline CMem(const CMem& obj){};
    // No Assignment
    inline CMem& operator = ( const CMem& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    char mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取缓存区地址
    inline void* operator * ();
    // 获取偏移后的地址
    inline void* operator [] ( const size_t csztPos )
    {
        // TODO 修改位置
        void* lpPos = mszBuf+csztPos;
        return lpPos;
    }
    // 获取缓存区字符串
    inline const void* c_str();

    // 获取缓存区域大小
    inline size_t size();
    // 获取缓存区中字符串长度
    inline size_t len();
    // 清理数据
    inline void clear(){ v_memset(mszBuf,0x00,sizeof(mszBuf)); };

public:
    // 获取字符串中子字符串地址
    inline void* At(const size_t csztBufOffset) {};

    // 格式化字符串
    inline void* Fmt(const char* const   cpFmtStr, ...);
    // 格式化字符串
    inline void* Fmt(const size_t        csztBufOffset,
                     const char* const   cpFmtStr,
                     ...);
    // 格式化字符串
    inline void* Fmt(const char* const   cpFmtStr, va_list vp);
    // 格式化字符串
    inline void* Fmt(const size_t        csztBufOffset,
                     const char* const   cpFmtStr,
                     va_list             vp);
    inline int Fmt2(const char* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(0, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    inline int Fmt2(const size_t csztBufOffset, const char* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(csztBufOffset, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    inline int Fmt2(const char* const cpFmt, va_list vList)
    {
        return Fmt2(0, cpFmt, vList);
    };
    inline int Fmt2(const size_t csztBufOffset, const char* const cpFmt, va_list vList)
    {
        char* lpPos = mszBuf + csztBufOffset;
        size_t lsztBufLeft = sztBufSize-csztBufOffset;
        return v_vsprintf(lpPos, lsztBufLeft, cpFmt, vList);
    };


    // 将源数据区的数据复制到缓存区
    inline size_t CopyFm(const void* const   cpSrc,
                         const size_t        csztDataLen);
    // 将源数据区的数据复制到缓存区
    inline size_t CopyFm(const size_t        culBufOffset,
                         const void* const   cpSrc,
                         const size_t        csztDataLen);
    // 将缓存区中的数据复制到目标区域
    inline size_t CopyTo(void*         cpDst,
                         const size_t  csztDstSize);
    // 将缓存区中的数据复制到目标区域
    inline size_t CopyTo(void*         cpDst,
                         const size_t  csztDstSize,
                         const size_t  csztDataLen);
    // 将缓存区中的数据复制到目标区域
    inline size_t CopyTo(void*         cpDst,
                         const size_t  csztDstSize,
                         const size_t  csztBufOffset,
                         const size_t  csztDataLen);

    // 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyFm(const int           ciFlag,
                          const void* const   cpSrc,
                          const size_t        csztDataLen);
    // 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyFm(const size_t        csztBufOffset,
                          const int           ciFlag,
                          const void* const   cpSrc,
                          const size_t        csztDataLen);
    // 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyTo(const int           ciFlag,
                          void*               cpDst,
                          const size_t        csztDstSize);
    // 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyTo(const int           ciFlag,
                          void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztDataLen);
    // 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyTo(const int           ciFlag,
                          void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztBufOffset,
                          const size_t        csztDataLen);

    // 将源数据区中的数据复制到缓存区
    inline size_t MoveFm(const void* const   cpSrc,
                         const size_t        csztDataLen);
    // 将源数据区中的数据复制到缓存区
    inline size_t MoveFm(const size_t        csztBufOffset,
                         const void* const   cpSrc,
                         const size_t        csztDataLen);
    // 将缓存区中的数据复制到目标区
    inline size_t MoveTo(void*               cpDst,
                         const size_t        csztDstSize);
    // 将缓存区中的数据复制到目标区
    inline size_t MoveTo(void*               cpDst,
                         const size_t        csztDstSize,
                         const size_t        csztDataLen);
    // 将缓存区中的数据复制到目标区
    inline size_t MoveTo(void*               cpDst,
                         const size_t        csztDstSize,
                         const size_t        csztBufOffset,
                         const size_t        csztDataLen);

    // 按字典顺序对字符串比较，并只比较前csztDataLen个字符
    inline bool Cmp(const void* const  cpData,
                        const size_t       csztDataLen);
    // 按字典顺序对字符串比较，并只比较前csztDataLen个字符
    inline bool Cmp(const size_t       csztBufOffset,
                        const void* const  cpData,
                        const size_t       csztDataLen);

    // 按字典顺序对字符串比较,不考虑大小写,并只比较前csztDataLen个字符
    inline bool iCmp(const void* const  cpData,
                         const size_t       csztDataLen);
    // 按字典顺序对字符串比较, 不考虑大小写, 并只比较前csztDataLen个字符
    inline bool iCmp(const size_t       csztBufOffset,
                         const void* const  cpData,
                         const size_t       csztDataLen);

    // 缓存区中寻找指定字符的位置
    inline void* Find(const int      ciValue);
    // 缓存区中寻找指定字符的位置
    inline void* Find(const int      ciValue,
                      const size_t   csztLookforLen);
    // 缓存区中寻找指定字符的位置
    inline void* Find(const size_t   csztBufOffset,
                            const int      ciValue);
    // 缓存区中寻找指定字符的位置
    inline void* Find(const size_t   csztBufOffset,
                      const int      ciValue,
                      const size_t   csztLookforLen);

    // 设置缓存区的内容
    void Set(const int       ciValue);
    // 设置缓存区的内容
    void Set(const size_t    csztBufOffset,
             const int       ciValue,
             const size_t    csztDataLen);

private:

}; // End of class CMem
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMem()
// Brief     : 构造函数
// Return    : null
// Parameter : null
template <size_t sztBufSize>
CMem<sztBufSize>::CMem()
{
    vMemZero(mszBuf);
};
// End of function CMem()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ~CMem()
// Brief     : 析构函数
// Return    : null
// Parameter : null
template <size_t sztBufSize>
CMem<sztBufSize>::~CMem() 
{

};
// End of function ~CMem()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator *()
// Brief     : 获取缓存区地址
// Return    : null
// Parameter : null
template <size_t sztBufSize>
inline void* CMem<sztBufSize>::operator * () 
{ 
    return mszBuf; 
};
// End of function operator *()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : c_str()
// Brief     : 获取缓存区字符串
// Return    : 缓存区基地址
// Parameter : null
template <size_t sztBufSize>
inline const void*  CMem<sztBufSize>::c_str()
{ 
    return mszBuf; 
};
// End of function c_str()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Size()
// Brief     : 缓存区域大小
// Return    : null
// Parameter : null
template <size_t sztBufSize>
inline size_t CMem<sztBufSize>::size()
{ 
    return sizeof(mszBuf); 
};
// End of function Size()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Len()
// Brief     : 获取缓存区中字符串长度
// Return    : null
// Parameter : null
template <size_t sztBufSize>
inline size_t CMem<sztBufSize>::len()
{ 
    return strlen(mszBuf); 
};
// End of function Len()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : const void* const cpFmtStr       - 数据格式
//           : ...                              - 可变数据参数
template <size_t sztBufSize>
inline void* CMem<sztBufSize>::Fmt(const char* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    void* lpRet = Fmt(0, cpFmt, vList );
    va_end(vList);
    return lpRet;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : csztBufOffset                    - 缓存区数据偏移量
//             const void* const cpFmtStr       - 数据格式
//           : ...                              - 可变数据参数
template <size_t sztBufSize>
inline void* CMem<sztBufSize>::Fmt(const size_t csztBufOffset, const char* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    void* lpRet = Fmt(csztBufOffset, cpFmt, vList);
    va_end(vList);
    return lpRet;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : cpFmtStr                         - 数据格式
//           : va_list vp                       - 可变数据参数
template <size_t sztBufSize>
inline void* CMem<sztBufSize>::Fmt(const char* const cpFmt, va_list vp)
{
    return Fmt(0, cpFmt, vp);
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : csztBufOffset                    - 缓存区数据偏移量
//             cpFmtStr                         - 数据格式
//           : va_list vp                       - 可变数据参数
template <size_t sztBufSize>
inline void* CMem<sztBufSize>::Fmt(const size_t csztBufOffset, const char* const cpFmt, va_list vList)
{
    void* lpPos         = mszBuf+csztBufOffset;
    size_t lsztBufLeft  = sztBufSize - csztBufOffset;
    int liRet           = v_vsprintf(lpPos, lsztBufLeft, cpFmt, vList);
    return lpPos;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm()
// Brief     : 将源数据区的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : cpSrc                                - 源数据起始地址
//             csztDataLen                         - 需要复制数据长度
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CopyFm( const void* const   cpSrc, 
                                            const size_t        csztDataLen )
{
    return CopyFm(0, cpSrc, csztDataLen);
}
// End of function CopyFm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm()
// Brief     : 将源数据区的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : csztBufOffset                        - 缓存区数据偏移量
//             cpSrc                                - 源数据起始地址
//             csztDataLen                         - 需要复制数据长度
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CopyFm( const size_t       csztBufOffset,
                                            const void* const  cpSrc,
                                            const size_t       csztDataLen)
{
    void* lpPos = mszBuf + csztBufOffset;
    size_t lsztBufLeft = sztBufSize-csztBufOffset;
    return v_memcpy( lpPos, lsztBufLeft, cpSrc, csztDataLen);
}
// End of function CopyFm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo()
// Brief     : 将缓存区中的数据复制到目标区域
// Return    : size_t                              - 复制的数据量
// Parameter : cpDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CopyTo(void* cpDst, const size_t csztDstSize)
{
    return CopyTo(cpDst, csztDstSize, 0, sztBufSize);
}
// End of function CopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo()
// Brief     : 将缓存区中的数据复制到目标区域
// Return    : size_t                              - 复制的数据量
// Parameter : cpDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztDataLen                        - 需要复制数据的大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CopyTo( void*           cpDst, 
                                            const size_t    csztDstSize, 
                                            const size_t    csztDataLen )
{
    return CopyTo(cpDst, csztDstSize, 0, csztDataLen);
}
// End of function CopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo()
// Brief     : 将缓存区中的数据复制到目标区域
// Return    : size_t                              - 复制的数据量
// Parameter : cpDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztBufOffset                       - 缓存区偏移量
//             csztDataLen                        - 需要复制数据的大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CopyTo( void*           cpDst, 
                                            const size_t    csztDstSize, 
                                            const size_t    csztBufOffset, 
                                            const size_t    csztDataLen )
{
    void* lpPos = mszBuf + csztBufOffset;
    return v_memcpy( cpDst, csztDstSize, lpPos, csztDataLen  );
}
// End of function CopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyFm()
// Brief     : 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                               - 复制的数据量
// Parameter : cFlag                                - 标志字符
//             cpSrc                                - 源数据起始地址
//             csztDataLen                         - 需要拷贝的数据长度
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CCopyFm( const int          ciFlag, 
                                             const void* const  cpSrc, 
                                             const size_t       csztDataLen )
{
    return CCopyFm(0, ciFlag, cpSrc, csztDataLen);
}
// End of function CCopyFm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyFm()
// Brief     : 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                               - 复制的数据量
// Parameter : csztBufOffset                        - 缓存区偏移量
//             cFlag                                - 标志字符
//             cpSrc                                - 源数据起始地址
//             csztDataLen                         - 需要拷贝的数据长度
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CCopyFm( const size_t       csztBufOffset, 
                                             const int          ciFlag, 
                                             const void* const  cpSrc, 
                                             const size_t       csztDataLen )
{
    void* lpPos        = mszBuf+csztBufOffset;
    size_t lsztBufLeft = sztBufSize - csztBufOffset;

    return v_memccpy( lpPos, lsztBufLeft, cpSrc, ciFlag, csztDataLen );
}
// End of function CCopyFm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo()
// Brief     : 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                              - 复制的数据量
// Parameter : cFlag                               - 标志字符
//             cpDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CCopyTo( const int      ciFlag, 
                                             void*          cpDst, 
                                             const size_t   csztDstSize )
{
    return CCopyTo(ciFlag, cpDst, csztDstSize, 0, sztBufSize);
}
// End of function CCopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo()
// Brief     : 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                              - 复制的数据量
// Parameter : cFlag                               - 标志字符
//             cpDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztDataLen                        - 需要复制数据的大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CCopyTo( const int      ciFlag, 
                                             void*          cpDst, 
                                             const size_t   csztDstSize, 
                                             const size_t   csztDataLen )
{
    return CCopyTo(ciFlag, cpDst, csztDstSize, 0, csztDataLen);
}
// End of function CCopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo()
// Brief     : 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                              - 复制的数据量
// Parameter : cFlag                               - 标志字符
//             cpDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztBufOffset                       - 缓存区偏移量
//             csztDataLen                        - 需要复制数据的大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CCopyTo( const int      ciFlag, 
                                             void*          cpDst, 
                                             const size_t   csztDstSize, 
                                             const size_t   csztBufOffset, 
                                             const size_t   csztDataLen )
{
    void* lpPos = mszBuf + csztBufOffset;
    return v_memccpy( cpDst, csztDstSize, lpPos, ciFlag, csztDataLen );
}
// End of function CCopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveFm()
// Brief     : 将源数据区中的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : cpSrc                                - 源数据区起始地址
//             csztDataLen                         - 需要复制数据长度
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::MoveFm( const void* const   cpSrc, 
                                            const size_t        csztDataLen )
{
    return MoveFm(0, cpSrc, csztDataLen);
}
// End of function MoveFm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveFm()
// Brief     : 将源数据区中的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : csztBufOffset                        - 缓存区偏移量
//             cpSrc                                - 源数据区起始地址
//             csztDataLen                         - 需要复制数据长度
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::MoveFm( const size_t        csztBufOffset, 
                                            const void* const   cpSrc, 
                                            const size_t        csztDataLen )
{
    void* lpPos         = mszBuf+csztBufOffset;
    size_t lsztBufLeft  = sztBufSize-csztBufOffset;
    return v_memmove( mszBuf, lsztBufLeft, cpSrc, csztDataLen );
}
// End of function MoveFm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : 将缓存区中的数据复制到目标区
// Return    : size_t                                - 复制的数据量
// Parameter : cpDst                                 - 目标区域地址
//             csztDstSize                           - 目标数据区大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::MoveTo( void*        cpDst, 
                                            const size_t csztDstSize )
{
    return MoveTo(cpDst, csztDstSize, 0, sztBufSize);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : 将缓存区中的数据复制到目标区
// Return    : size_t                                - 复制的数据量
// Parameter : cpDst                                 - 目标区域地址
//             csztDstSize                           - 目标数据区大小
//             csztDataLen                          - 复制数据的大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::MoveTo( void*           cpDst, 
                                            const size_t    csztDstSize, 
                                            const size_t    csztDataLen )
{
    return MoveTo(cpDst, csztDstSize, 0, csztDataLen);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : 将缓存区中的数据复制到目标区
// Return    : size_t                                - 复制的数据量
// Parameter : cpDst                                 - 目标区域地址
//             csztDstSize                           - 目标数据区大小
//             csztBufOffset                         - 缓存区偏移量
//             csztDataLen                          - 复制数据的大小
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::MoveTo( void*           cpDst, 
                                            const size_t    csztDstSize, 
                                            const size_t    csztBufOffset, 
                                            const size_t    csztDataLen )
{
    void* lpPos = mszBuf+csztBufOffset;
    return v_memmove(cpDst, csztDstSize, lpPos, csztDataLen);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cmp()
// Brief     : 按字典顺序对字符串比较，并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : cpData                               - 对比数据区地址
//             csztDataLen                          - 需要对比的数据长度
template <size_t sztBufSize>
inline bool vm::CMem<sztBufSize>::Cmp(const void* const cpData, const size_t csztDataLen)
{
    return Cmp(0, cpData, csztDataLen);
}
// End of function Cmp()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cmp()
// Brief     : 按字典顺序对字符串比较，并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : csztBufOffset                        - 缓存区偏移量
//             cpData                               - 对比数据区地址
//             csztDataLen                          - 需要对比的数据长度
template <size_t sztBufSize>
inline bool vm::CMem<sztBufSize>::Cmp( const size_t         csztBufOffset, 
                                       const void* const    cpData, 
                                       const size_t         csztDataLen )
{
    void* lpPos = mszBuf + csztBufOffset;
    return v_memcmp_equl( lpPos, cpData, csztDataLen );
}
// End of function Cmp()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : iCmp()
// Brief     : 按字典顺序对字符串比较,不考虑大小写,并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : cpData                               - 对比数据地址
//             csztDataLen                          - 需要对比的数据大小
template <size_t sztBufSize>
inline bool vm::CMem<sztBufSize>::iCmp( const void* const cpData, const size_t csztDataLen )
{
    return iCmp(0, cpData, csztDataLen);
}
// End of function iCmp()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : iCmp()
// Brief     : 按字典顺序对字符串比较,不考虑大小写,并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : csztBufOffset,                       - 缓存区偏移量
//             cpData                               - 对比数据地址
//             csztDataLen                          - 需要对比的数据大小
template <size_t sztBufSize>
inline bool vm::CMem<sztBufSize>::iCmp( const size_t        csztBufOffset, 
                                        const void* const   cpData, 
                                        const size_t        csztDataLen )
{
    void* lpPos = mszBuf+csztBufOffset;
    return v_memicmp_equl( lpPos, cpData, csztDataLen );
}
// End of function iCmp()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find()
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : ciValue,                             - 需要查询的字符
template <size_t sztBufSize>
inline void* vm::CMem<sztBufSize>::Find(const int ciValue)
{
    return Find(0, ciValue, sztBufSize);
}
// End of function Find()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find()
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : ciValue,                             - 需要查询的字符
//             csztLookforLen                       - 查询的字符数
template <size_t sztBufSize>
inline void* vm::CMem<sztBufSize>::Find(const int ciValue, const size_t csztLookforLen)
{

    return Find(0, ciValue, csztLookforLen);
}
// End of function Find()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find()
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : csztBufOffset                        - 缓存区偏移量
//             ciValue,                             - 需要查询的字符
template <size_t sztBufSize>
inline void* vm::CMem<sztBufSize>::Find(const size_t csztBufOffset, const int ciValue)
{
    size_t lsztBufLeft = sztBufSize - csztBufOffset;
    return Find(csztBufOffset, ciValue, lsztBufLeft);
}
// End of function Find()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find()
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : csztBufOffset                        - 缓存区偏移量
//             ciValue,                             - 需要查询的字符
//             csztLookforLen                       - 查询的字符数
template <size_t sztBufSize>
inline void* vm::CMem<sztBufSize>::Find( const size_t   csztBufOffset, 
                                         const int      ciValue,
                                         const size_t   csztLookforLen)
{
    void* lpPos = mszBuf+csztBufOffset;
    return v_memchr( lpPos, ciValue, csztLookforLen );
}
// End of function Find()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Set()
// Brief     : 设置缓存区的内容
// Return    : void
// Parameter : ciValue,                     - 需要设置的字符
template <size_t sztBufSize>
inline void vm::CMem<sztBufSize>::Set(const int ciValue)
{
    return Set(0, ciValue, sztBufSize);
}
// End of function Set()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Set()
// Brief     : 设置缓存区的内容
// Return    : void
// Parameter : csztBufOffset                - 缓存区偏移量
//             ciValue,                     - 需要设置的字符
//             csztDataLen                  - 设置的字符数
template <size_t sztBufSize>
inline void vm::CMem<sztBufSize>::Set( const size_t     csztBufOffset, 
                                       const int        ciValue, 
                                       const size_t     csztDataLen )
{
    void* lpPos = mszBuf+csztBufOffset;
    v_memset( lpPos, ciValue, csztDataLen );
}
// End of function Set()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMEM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMem.h
/////////////////////////////////////////////////////////////////////////////////////////