/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CMemPtr.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/20 08:41:03
// Modify time  : 2019/12/20 08:41:03
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

#ifndef __CMEMPTR_H__
#define __CMEMPTR_H__

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
// Macro define

#ifndef   vCMemPtr
#   define  vCMemPtr( szBuf ) vm::CMemPtr(szBuf,sizeof(szBuf))
#endif // vCStrPtr

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CMemPtr : 此类封装了mem系列函数。
//
/////////////////////////////////////////////////////////////////////////////////////////
class CMemPtr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CMemPtr( void* pAddr, const size_t csztBufSize );
    // Destruct define
    inline virtual ~CMemPtr();

private:
    // Copy construct define
    CMemPtr(const CMemPtr& obj):mpBuf(obj.mpBuf),msztBufSize(obj.msztBufSize){};
    // No Assignment function
    CMemPtr& operator = (const CMemPtr& obj){};

/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    void*  mpBuf;
    size_t msztBufSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取缓存区地址
    inline void* operator * ();
    // 获取偏移后的地址
    inline void* operator [] (const size_t csztPos)
    {
        // TODO 修改位置
        void* lpPos = ((char*)mpBuf + csztPos);
        return lpPos;
    }
    // 获取缓存区字符串
    inline const void* c_str();

    // 获取缓存区大小
    inline size_t size(){ return msztBufSize; }
    // 获取缓存区中字符串长度
    inline size_t len();
    // 清理数据
    inline void clear() { v_memset(mpBuf, 0x00, sizeof(msztBufSize)); };

public:
    // 获取字符串中子字符串地址
    inline void* At(const size_t csztBufOffset) { return ((char*)mpBuf+csztBufOffset); };

    // 格式化字符串
    inline void* Fmt(const char* const   cpFmt, ...);
    // 格式化字符串
    inline void* Fmt(const size_t        csztBufOffset,
                     const char* const   cpFmt, 
                     ...);
    // 格式化字符串
    inline void* Fmt(const char* const   cpFmt, va_list vp);
    // 格式化字符串
    inline void* Fmt(const size_t        csztBufOffset, 
                     const char* const   cpFmt, 
                     va_list             vp );
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
        char* lpPos = (char*)mpBuf + csztBufOffset;
        size_t lsztBufLeft = msztBufSize-csztBufOffset;
        return v_vsprintf(lpPos, lsztBufLeft, cpFmt, vList);
    };


    // 将源数据区的数据复制到缓存区
    inline size_t CopyFm( const void* const   cpSrc,
                          const size_t        csztDataLen );
    // 将源数据区的数据复制到缓存区
    inline size_t CopyFm( const size_t        csztBufOffset,
                          const void* const   cpSrc,
                          const size_t        csztDataLen );
    // 将缓存区中的数据复制到目标区域
    inline size_t CopyTo( void*         cpDst,
                          const size_t  csztDstSize );
    // 将缓存区中的数据复制到目标区域
    inline size_t CopyTo( void*         cpDst,
                          const size_t  csztDstSize,
                          const size_t  csztDataLen );
    // 将缓存区中的数据复制到目标区域
    inline size_t CopyTo( void*         cpDst,
                          const size_t  csztDstSize,
                          const size_t  csztBufOffset,
                          const size_t  csztDataLen );

    // 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyFm( const int           ciFlag,
                           const void* const   cpSrc,
                           const size_t        csztDataLen );
    // 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyFm( const size_t        csztBufOffset,
                           const int           ciFlag,
                           const void* const   cpSrc,
                           const size_t        csztDataLen );
    // 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyTo( const int           ciFlag,
                           void*               cpDst,
                           const size_t        csztDstSize );
    // 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyTo( const int           ciFlag,
                           void*               cpDst,
                           const size_t        csztDstSize,
                           const size_t        csztDataLen );
    // 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
    inline size_t CCopyTo( const int           ciFlag,
                           void*               cpDst,
                           const size_t        csztDstSize,
                           const size_t        csztBufOffset,
                           const size_t        csztDataLen );

    // 将源数据区中的数据复制到缓存区
    inline size_t MoveFm( const void* const   cpSrc,
                          const size_t        csztDataLen );
    // 将源数据区中的数据复制到缓存区
    inline size_t MoveFm( const size_t        csztBufOffset,
                          const void* const   cpSrc,
                          const size_t        csztDataLen );
    // 将缓存区中的数据复制到目标区
    inline size_t MoveTo( void*               cpDst,
                          const size_t        csztDstSize );
    // 将缓存区中的数据复制到目标区
    inline size_t MoveTo( void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztDataLen );
    // 将缓存区中的数据复制到目标区
    inline size_t MoveTo( void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztBufOffset,
                          const size_t        csztDataLen );

    // 按字典顺序对字符串比较，并只比较前csztDataLen个字符
    inline bool Cmp( const void* const  cpData,
                     const size_t       csztDataLen );
    // 按字典顺序对字符串比较，并只比较前csztDataLen个字符
    inline bool Cmp( const size_t       csztBufOffset,
                     const void* const  cpData,
                     const size_t       csztDataLen );

    // 按字典顺序对字符串比较,不考虑大小写,并只比较前csztDataLen个字符
    inline bool iCmp( const void* const  cpData,
                      const size_t       csztDataLen );
    // 按字典顺序对字符串比较, 不考虑大小写, 并只比较前csztDataLen个字符
    inline bool iCmp( const size_t       csztBufOffset,
                      const void* const  cpData,
                      const size_t       csztDataLen );

    // 缓存区中寻找指定字符的位置
    inline void* Find( const int      ciValue );
    // 缓存区中寻找指定字符的位置
    inline void* Find( const int      ciValue,
                       const size_t   csztLookforLen );
    // 缓存区中寻找指定字符的位置
    inline void* Find( const size_t   csztBufOffset,
                       const int      ciValue );
    // 缓存区中寻找指定字符的位置
    inline void* Find( const size_t   csztBufOffset,
                       const int      ciValue,
                       const size_t   csztLookforLen );

    // 设置缓存区的内容
    inline void Set( const int       ciValue );
    // 设置缓存区的内容
    inline void Set( const size_t    csztBufOffset,
                     const int       ciValue,
                     const size_t    csztDataLen );

}; // End of class CMemPtr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMemPtr()
// Brief     : 构造函数
// Return    : null
// Parameter : pAddr                    - 初始化内存地址
//             csztBufSize              - 初始化内存长度
CMemPtr::CMemPtr(void* pAddr, const size_t csztBufSize) 
    :mpBuf(pAddr),msztBufSize(csztBufSize)
{

};
// End of function CMemPtr()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ~CMemPtr()
// Brief     : 析构函数
// Return    : null
// Parameter : null
CMemPtr::~CMemPtr()
{

};
// End of function ~CMemPtr()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator *()
// Brief     : 获取缓存区地址
// Return    : null
// Parameter : null
inline void* CMemPtr::operator * ()
{
    return mpBuf;
};
// End of function operator *()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : c_str()
// Brief     : 获取缓存区中第一个字符串
// Return    : null
// Parameter : null
inline const void*  CMemPtr::c_str()
{
    return (void*)mpBuf;
};
// End of function c_str()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Len()
// Brief     : 获取缓存区中字符串长度
// Return    : null
// Parameter : null
inline size_t CMemPtr::len()
{
    return strlen((char*)mpBuf);
};
// End of function Len()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : cpFmtStr                         - 数据格式
//           : ...                              - 可变数据参数
inline void* CMemPtr::Fmt( const char* const cpFmt, ... )
{
    va_list vp;
    va_start(vp, cpFmt);
    void* lpRet = Fmt(0, cpFmt, vp );
    va_end(vp);

    return lpRet;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : csztBufOffset                    - 缓存区数据偏移量
//             cpFmtStr                         - 数据格式
//           : ...                              - 可变数据参数
inline void* CMemPtr::Fmt(const size_t csztBufOffset, const char* const cpFmt, ...)
{
    va_list vp;
    va_start(vp, cpFmt);
    void* lpRet = Fmt(csztBufOffset, cpFmt, vp);
    va_end(vp);

    return lpRet;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : cpFmtStr                         - 数据格式
//           : va_list vList                       - 可变数据参数
inline void* CMemPtr::Fmt(const char* const cpFmt, va_list vp)
{
    return Fmt( 0, cpFmt, vp );
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化字符串
// Return    : char*                            - 生成的字符串地址
// Parameter : csztBufOffset                    - 缓存区数据偏移量
//             cpFmtStr                         - 数据格式
//           : va_list vList                       - 可变数据参数
inline void* CMemPtr::Fmt(const size_t csztBufOffset, const char* const cpFmt, va_list vList)
{
    char* lpPos = (char*)mpBuf + csztBufOffset;
    int liBufLeft   = msztBufSize-csztBufOffset;
    int liRet = v_vsprintf(lpPos, liBufLeft, (char*)cpFmt, vList);
    return lpPos;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     : 将源数据区的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : cpSrc                                - 源数据起始地址
//             csztDataLen                          - 需要复制数据长度
size_t CMemPtr::CopyFm(const void* const cpSrc, const size_t csztDataLen)
{
    return CopyFm(0, cpSrc, csztDataLen);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CopyFm( ... )
// Brief     : 将源数据区的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : csztBufOffset                        - 缓存区数据偏移量
//             cpSrc                                - 源数据起始地址
//             csztDataLen                         - 需要复制数据长度
inline size_t CMemPtr::CopyFm( const size_t        csztBufOffset,
                               const void* const   cpSrc,  
                               const size_t        csztDataLen)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // 复制数据
    void* lpBufPos = &mpBuf + csztDataLen;
    return v_memcpy( lpBufPos, lsztBufLeft, cpSrc, csztDataLen );
}
// End of function CopyFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     : 将缓存区中的数据复制到目标区域
// Return    : size_t                              - 复制的数据量
// Parameter : pDst                                - 目标区域地址
//             csztDstSize                         - 目标区域大小
inline size_t CMemPtr::CopyTo(void* cpDst, const size_t csztDstSize)
{
    return CopyTo(cpDst, csztDstSize, 0, msztBufSize);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     : 将缓存区中的数据复制到目标区域
// Return    : size_t                              - 复制的数据量
// Parameter : pDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztDataLen                        - 需要复制数据的大小
inline size_t CMemPtr::CopyTo( void*        cpDst, 
                               const size_t csztDstSize, 
                               const size_t csztDataLen)
{
    return CopyTo(cpDst, csztDstSize, 0, csztDataLen);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CopyTo( ... )
// Brief     : 将缓存区中的数据复制到目标区域
// Return    : size_t                              - 复制的数据量
// Parameter : pDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztBufOffset                       - 缓存区偏移量
//             csztDataLen                        - 需要复制数据的大小
inline size_t CMemPtr::CopyTo( void*               cpDst,
                               const size_t        csztDstSize,
                               const size_t        csztBufOffset,
                               const size_t        csztDataLen)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // 复制数据
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memcpy( cpDst, csztDstSize, lpBufPos, csztDataLen );
}
// End of function CopyTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CCopyFm( ... )
// Brief     : 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                               - 复制的数据量
// Parameter : csztBufOffset                        - 缓存区偏移量
//             cFlag                                - 标志字符
//             cpSrc                                - 源数据起始地址
//             csztDataLen                          - 需要拷贝的数据长度
inline size_t CMemPtr::CCopyFm( const size_t        csztBufOffset,
                                const int           ciFlag,
                                const void* const   cpSrc,
                                const size_t        csztDataLen)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // 复制数据
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memccpy(lpBufPos, msztBufSize, cpSrc, ciFlag, csztDataLen);
}
// End of function CCopyFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyFm(...)
// Brief     : 从源数据区复制数据到缓存区，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                               - 复制的数据量
// Parameter : cFlag                                - 标志字符
//             cpSrc                                - 源数据起始地址
//             csztDataLen                         - 需要拷贝的数据长度
size_t CMemPtr::CCopyFm( const int           ciFlag,
                         const void* const  cpSrc,
                         const size_t       csztDataLen)
{
    return CCopyFm(0, ciFlag, cpSrc, csztDataLen);
}
// End of function CCopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CCopyTo( ... )
// Brief     : 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                              - 复制的数据量
// Parameter : cFlag                               - 标志字符
//             pDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztBufOffset                       - 缓存区偏移量
//             csztDataLen                        - 需要复制数据的大小
inline size_t CMemPtr::CCopyTo( const int           ciFlag,
                                void*               cpDst,
                                const size_t        csztDstSize,
                                const size_t        csztBufOffset,
                                const size_t        csztDataLen )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // 复制数据
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memccpy(cpDst, csztDstSize, lpBufPos, ciFlag, csztDataLen);
}
// End of function CCopyTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo(...)
// Brief     : 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                              - 复制的数据量
// Parameter : cFlag                               - 标志字符
//             pDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
inline size_t CMemPtr::CCopyTo( const int           ciFlag,
                                void*         cpDst,
                                const size_t  csztDstSize )
{
    return CCopyTo(ciFlag, cpDst, 0, msztBufSize);
}
// End of function CCopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo(...)
// Brief     : 复制缓存区内的内容到目标区域，到指定长度或遇到指定字符时停止拷贝
// Return    : size_t                              - 复制的数据量
// Parameter : cFlag                               - 标志字符
//             pDst                               - 目标区域地址
//             csztDstSize                         - 目标区域大小
//             csztDataLen                        - 需要复制数据的大小
size_t CMemPtr::CCopyTo( const int      ciFlag,
                         void*          cpDst,
                         const size_t   csztDstSize,
                         const size_t   csztDataLen )
{
    return CCopyTo(ciFlag, cpDst, 0, csztDataLen);
}
// End of function CCopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : MoveFm( ... )
// Brief     : 将源数据区中的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : csztBufOffset                        - 缓存区偏移量
//             cpSrc                                - 源数据区起始地址
//             csztDataLen                         - 需要复制数据长度
inline size_t CMemPtr::MoveFm( const size_t        csztBufOffset,
                               const void* const   cpSrc,
                               const size_t        csztDataLen )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // 复制数据 
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove( lpBufPos, lsztBufLeft, cpSrc, csztDataLen );
}
// End of function MoveFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveFm(...)
// Brief     : 将源数据区中的数据复制到缓存区
// Return    : size_t                               - 复制的数据量
// Parameter : cpSrc                                - 源数据区起始地址
//             csztDataLen                         - 需要复制数据长度
inline size_t CMemPtr::MoveFm( const void* const   cpSrc,
                               const size_t        csztDataLen)
{
    return MoveFm(0, cpSrc, csztDataLen);
}
// End of function MoveFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : MoveTo( ... )
// Brief     : 将缓存区中的数据复制到目标区
// Return    : size_t                               - 复制的数据量
// Parameter : pDst                                 - 目标区域地址
//             csztDstSize                          - 目标数据区大小
//             csztBufOffset                        - 缓存区偏移量
//             csztDataLen                          - 复制数据的大小
inline size_t CMemPtr::MoveTo( void*               pDst,
                               const size_t        csztDstSize,
                               const size_t        csztBufOffset,
                               const size_t        csztDataLen)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // 复制数据
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove( pDst, csztDstSize, lpBufPos, csztDataLen );
}
// End of function MoveTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : 将缓存区中的数据复制到目标区
// Return    : size_t                                - 复制的数据量
// Parameter : pDst                                 - 目标区域地址
//             csztDstSize                           - 目标数据区大小
inline size_t CMemPtr::MoveTo(void* cpDst, const size_t csztDstSize)
{
    return MoveTo(cpDst, csztDstSize, 0, msztBufSize);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : 将缓存区中的数据复制到目标区
// Return    : size_t                                - 复制的数据量
// Parameter : pDst                                 - 目标区域地址
//             csztDstSize                           - 目标数据区大小
//             csztDataLen                          - 复制数据的大小
inline size_t CMemPtr::MoveTo( void*           cpDst,
                               const size_t    csztDstSize,
                               const size_t    csztDataLen)
{
    return MoveTo(cpDst, csztDstSize, 0, csztDataLen);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Compare( ... )
// Brief     : 按字典顺序对字符串比较，并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : csztBufOffset                        - 缓存区偏移量
//             cpData                               - 对比数据区地址
//             csztDataLen                          - 需要对比的数据长度
inline bool CMemPtr::Cmp( const size_t       csztBufOffset,
                              const void* const  cpData,
                              const size_t       csztDataLen )
{
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memcmp_equl(lpBufPos, cpData, csztDataLen);
}
// End of function Compare( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Compare(...)
// Brief     : 按字典顺序对字符串比较，并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : cpData                               - 对比数据区地址
//             csztDataLen                          - 需要对比的数据长度
inline bool CMemPtr::Cmp(const void* const cpData, const size_t csztDataLen)
{
    return Cmp(0, cpData, csztDataLen);
}
// End of function Compare(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ICompare( ... )
// Brief     : 按字典顺序对字符串比较,不考虑大小写,并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : csztBufOffset,                       - 缓存区偏移量
//             cpData                               - 对比数据地址
//             csztDataLen                          - 需要对比的数据大小
inline bool CMemPtr::iCmp( const size_t         csztBufOffset,
                               const void* const    cpData,
                               const size_t         csztDataLen )
{
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memicmp_equl(lpBufPos, cpData, csztDataLen);
}
// End of function ICompare( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ICompare()
// Brief     : 按字典顺序对字符串比较,不考虑大小写,并只比较前csztDataLen个字符
// Return    : true                                 - 相同
//             false                                - 不同
// Parameter : cpData                               - 对比数据地址
//             csztDataLen                          - 需要对比的数据大小
inline bool CMemPtr::iCmp(const void* const cpData, const size_t csztDataLen)
{
    return iCmp(0, cpData, csztDataLen);
}
// End of function ICompare()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : At( ... )
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : csztBufOffset                        - 缓存区偏移量
//             ciValue,                             - 需要查询的字符
//             csztLookforLen                       - 查询的字符数
inline void* CMemPtr::Find( const size_t          csztBufOffset,
                            const int             ciValue,
                            const size_t          csztLookforLen )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    void* lpBufPos = &mpBuf + csztBufOffset;
    void* lpEndPos = v_memchr( lpBufPos, ciValue, csztLookforLen );
    if (lpEndPos == 0 )
        return nullptr;

    return lpEndPos;
}
// End of function Find( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : csztBufOffset                        - 缓存区偏移量
//             ciValue,                             - 需要查询的字符
inline void* CMemPtr::Find(const size_t csztBufOffset, const int ciValue)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    return Find(csztBufOffset, ciValue, lsztBufLeft);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : ciValue,                             - 需要查询的字符
//             csztLookforLen                       - 查询的字符数
inline void* CMemPtr::Find(const int ciValue, const size_t csztLookforLen)
{
    return Find(0, ciValue, csztLookforLen);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     : 缓存区中寻找指定字符的位置
// Return    : int                                  - 返回找到字符相对应缓存区基地址的偏移量
//             nullptr                              - 未查找到标识的字符
// Parameter : ciValue,                             - 需要查询的字符
inline void* CMemPtr::Find( const int ciValue )
{
    return Find(0, ciValue, msztBufSize);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Set( ... )
// Brief     : 设置缓存区的内容
// Return    : void
// Parameter : csztBufOffset                - 缓存区偏移量
//             ciValue,                     - 需要设置的字符
//             csztDataLen                  - 设置的字符数
inline void CMemPtr::Set( const size_t      csztBufOffset,
                          const int         ciValue,
                          const size_t      csztDataLen )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    void* lpBufPos = &mpBuf + csztBufOffset;
    v_memset(lpBufPos, ciValue, csztDataLen);
}
// End of function Set( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Set(...)
// Brief     : 设置缓存区的内容
// Return    : void
// Parameter : csztBufOffset                - 缓存区偏移量
//             ciValue,                     - 需要设置的字符
//             csztDataLen                  - 设置的字符数
inline void CMemPtr::Set(const int ciValue)
{
    return Set(0, ciValue, msztBufSize);
}
// End of function Set(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMEMPTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMemPtr.h
/////////////////////////////////////////////////////////////////////////////////////////