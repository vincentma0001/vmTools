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
#   include <vmCfg.h>
#endif // __VM_CFG_H__

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#   include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define

#ifndef    vCMemPtr
#   define vCMemPtr( szBuf ) vm::CMemPtr(szBuf,sizeof(szBuf))
#endif  // vCStrPtr

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CMemPtr : �����װ��memϵ�к�����
//
/////////////////////////////////////////////////////////////////////////////////////////
class CMemPtr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CMemPtr( void* const pAddr, const size_t csztBufSize );
    // Destruct define
    inline virtual ~CMemPtr();

public:
    // Copy construct define
    inline CMemPtr(const CMemPtr& obj);
    // No Assignment function
    inline CMemPtr& operator = (const CMemPtr& obj);

/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    void*  mpBuf;
    size_t msztBufSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ȡ��������ַ
    inline void*        operator *  ();
    // ��ȡƫ�ƺ�ĵ�ַ
    inline void*        operator [] (const size_t csztPos);
    // ��ȡ�������ַ���
    inline const void*  c_str       ();

    // ��ȡ��������С
    inline size_t size  ();
    // ��ȡ���������ַ�������
    inline size_t len   ();
    // ��������
    inline void   clear ();

public:
    // ��ȡ�ַ��������ַ�����ַ
    inline void*  At     ( const size_t csztBufOffset );

    // ��ʽ���ַ���
    inline void*  Fmt    ( const tchar* const cpFmt,                                       ... );
    // ��ʽ���ַ���
    inline void*  Fmt    ( const size_t csztBufOffset, const tchar* const cpFmt,           ... );
    // ��ʽ���ַ���
    inline void*  Fmt    ( const size_t csztBufOffset, const tchar* const cpFmt, va_list vList );

    // ��ʽ���ַ���
    inline int    Fmt2   (                             const tchar* const cpFmt,           ... );
    // ��ʽ���ַ���
    inline int    Fmt2   ( const size_t csztBufOffset, const tchar* const cpFmt,           ... );
    // ��ʽ���ַ���
    inline int    Fmt2   ( const size_t csztBufOffset, const tchar* const cpFmt, va_list vList );

    // ��Դ�����������ݸ��Ƶ�������
    inline size_t CopyFm ( const void* const cpSrc, const size_t csztDataLen, const size_t csztBufOffset = 0 );
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo (       void* const cpDst, const size_t csztDstSize, const size_t csztBufOffset = 0 );
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo (       void* const cpDst, const size_t csztDstSize, const size_t  csztDataLen, const size_t  csztBufOffset );

    // ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyFm( const int ciFlag, const void* const cpSrc, const size_t csztDataLen, const size_t csztBufOffset = 0 );
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo( const int ciFlag,       void* const cpDst, const size_t csztDstSize, const size_t csztBufOffset = 0 );
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo( const int ciFlag,       void* const cpDst, const size_t csztDstSize, const size_t csztDataLen, const size_t csztBufOffset );

    // ��Դ�������е����ݸ��Ƶ�������
    inline size_t MoveFm ( const void* const cpSrc,  const size_t csztDataLen, const size_t csztBufOffset = 0 );
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo (       void* const cpDst,  const size_t csztDstSize, const size_t csztBufOffset = 0 );
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo (       void* const cpDst,  const size_t csztDstSize, const size_t csztDataLen, const size_t csztBufOffset );

    // ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool   Cmp    ( const void* const cpData, const size_t csztDataLen, const size_t csztBufOffset = 0 );
    // ���ֵ�˳����ַ����Ƚ�, �����Ǵ�Сд, ��ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool   iCmp   ( const void* const cpData, const size_t csztDataLen, const size_t csztBufOffset = 0 );

    // ��������Ѱ��ָ���ַ���λ��
    inline void*  Find   ( const int ciValue,                              const size_t csztBufOffset = 0 );
    // ��������Ѱ��ָ���ַ���λ��
    inline void*  Find   ( const int ciValue, const size_t csztLookforLen, const size_t csztBufOffset = 0 );

    // ���û�����������
    inline void   Set    ( const int ciValue,                           const size_t csztBufOffset = 0 );
    // ���û�����������
    inline void   Set    ( const int ciValue, const size_t csztDataLen, const size_t csztBufOffset = 0 );

}; // End of class CMemPtr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMemPtr()
// Brief     : ���캯��
// Return    : null
// Parameter : pAddr                    - ��ʼ���ڴ��ַ
//             csztBufSize              - ��ʼ���ڴ泤��
CMemPtr::CMemPtr(void* const pAddr, const size_t csztBufSize) 
                :mpBuf(pAddr), msztBufSize(csztBufSize)
{

};
// End of function CMemPtr()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ~CMemPtr()
// Brief     : ��������
// Return    : null
// Parameter : null
CMemPtr::~CMemPtr()
{

};
// End of function ~CMemPtr()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMemPtr(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
// Copy construct define
CMemPtr::CMemPtr(const CMemPtr& obj) 
{ 
    *this = obj; 
};
// End of function CMemPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMemPtr(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
// No Assignment function
CMemPtr& CMemPtr::operator = (const CMemPtr& obj)
{ 
    v_memcpy(mpBuf, msztBufSize, obj.mpBuf, obj.msztBufSize); 
};
// End of function CMemPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator *()
// Brief     : ��ȡ��������ַ
// Return    : null
// Parameter : null
inline void* CMemPtr::operator * ()
{
    return mpBuf;
};
// End of function operator *()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator [](...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline void* CMemPtr::operator [] (const size_t csztPos)
{
    void*  lpPos = ((tchar*)mpBuf + csztPos);
    return lpPos;
}
// End of function operator [](...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : c_str()
// Brief     : ��ȡ�������е�һ���ַ���
// Return    : null
// Parameter : null
inline const void*  CMemPtr::c_str()
{
    return (void*)mpBuf;
};
// End of function c_str()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : size(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline size_t CMemPtr::size() 
{ 
    return msztBufSize; 
}
// End of function size(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Len()
// Brief     : ��ȡ���������ַ�������
// Return    : null
// Parameter : null
inline size_t CMemPtr::len()
{
    return vStrlen((tchar*)mpBuf);
};
// End of function Len()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : clear(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline void CMemPtr::clear()
{ 
    v_memset(mpBuf, 0x00, sizeof(msztBufSize)); 
};
// End of function clear(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : At(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline void* CMemPtr::At(const size_t csztBufOffset)
{ 
    return ((tchar*)mpBuf + csztBufOffset); 
};
// End of function At(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : ��ʽ���ַ���
// Return    : tchar*                            - ���ɵ��ַ�����ַ
// Parameter : cpFmtStr                         - ���ݸ�ʽ
//           : ...                              - �ɱ����ݲ���
inline void* CMemPtr::Fmt( const tchar* const cpFmt, ... )
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
// Brief     : ��ʽ���ַ���
// Return    : tchar*                            - ���ɵ��ַ�����ַ
// Parameter : csztBufOffset                    - ����������ƫ����
//             cpFmtStr                         - ���ݸ�ʽ
//           : ...                              - �ɱ����ݲ���
inline void* CMemPtr::Fmt(const size_t csztBufOffset, const tchar* const cpFmt, ...)
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
// Brief     : ��ʽ���ַ���
// Return    : tchar*                            - ���ɵ��ַ�����ַ
// Parameter : csztBufOffset                    - ����������ƫ����
//             cpFmtStr                         - ���ݸ�ʽ
//           : va_list vList                       - �ɱ����ݲ���
inline void* CMemPtr::Fmt(const size_t csztBufOffset, const tchar* const cpFmt, va_list vList)
{
    tchar* lpPos = (tchar*)mpBuf + csztBufOffset;
    size_t lsztBufLeft   = msztBufSize-csztBufOffset;
    int liRet = v_vsprintf(lpPos, lsztBufLeft, (tchar*)cpFmt, vList);
    return lpPos;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt2(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline int CMemPtr::Fmt2(const tchar* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    int liRet = Fmt2(0, cpFmt, vList);
    va_end(vList);

    return liRet;
};
// End of function Fmt2(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt2(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline int CMemPtr::Fmt2(const size_t csztBufOffset, const tchar* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    int liRet = Fmt2(csztBufOffset, cpFmt, vList);
    va_end(vList);

    return liRet;
};
// End of function Fmt2(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt2(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline int CMemPtr::Fmt2(const size_t csztBufOffset, const tchar* const cpFmt, va_list vList)
{
    tchar* lpPos = (tchar*)mpBuf + csztBufOffset;
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    return v_vsprintf(lpPos, lsztBufLeft, cpFmt, vList);
};
// End of function Fmt2(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CopyFm( ... )
// Brief     : ��Դ�����������ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ����������ƫ����
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
inline size_t CMemPtr::CopyFm( const void* const           cpSrc, 
                               const size_t          csztDataLen,
                               const size_t        csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztDataLen;
    return v_memcpy( lpBufPos, lsztBufLeft, cpSrc, csztDataLen );
}
// End of function CopyFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : pDst                                - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
inline size_t CMemPtr::CopyTo(void* cpDst, const size_t csztDstSize, const size_t csztBufOffset = 0 )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memcpy(cpDst, csztDstSize, lpBufPos, lsztBufLeft);

}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CopyTo( ... )
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztBufOffset                       - ������ƫ����
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
inline size_t CMemPtr::CopyTo( void*            cpDst,
                               const size_t     csztDstSize,
                               const size_t     csztDataLen,
                               const size_t     csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memcpy( cpDst, csztDstSize, lpBufPos, csztDataLen );
}
// End of function CopyTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CCopyFm( ... )
// Brief     : ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ������ƫ����
//             cFlag                                - ��־�ַ�
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                          - ��Ҫ���������ݳ���
inline size_t CMemPtr::CCopyFm( const int           ciFlag,
                                const void* const   cpSrc,
                                const size_t        csztDataLen, 
                                const size_t        csztBufOffset)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memccpy(lpBufPos, msztBufSize, cpSrc, ciFlag, csztDataLen);
}
// End of function CCopyFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CCopyTo( ... )
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztBufOffset                       - ������ƫ����
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
inline size_t CMemPtr::CCopyTo( const int           ciFlag,
                                void* const         cpDst,
                                const size_t        csztDstSize,
                                const size_t        csztDataLen,
                                const size_t        csztBufOffset)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memccpy(cpDst, csztDstSize, lpBufPos, ciFlag, csztDataLen);
}
// End of function CCopyTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo(...)
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
inline size_t CMemPtr::CCopyTo( const int           ciFlag,
                                void* const         cpDst,
                                const size_t        csztDstSize,
                                const size_t        csztBufOffset)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memccpy(cpDst, csztDstSize, lpBufPos, ciFlag, lsztBufLeft);
}
// End of function CCopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : MoveFm( ... )
// Brief     : ��Դ�������е����ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ������ƫ����
//             cpSrc                                - Դ��������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
inline size_t CMemPtr::MoveFm( const void* const   cpSrc,
                               const size_t        csztDataLen, 
                               const size_t        csztBufOffset)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // �������� 
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove( lpBufPos, lsztBufLeft, cpSrc, csztDataLen );
}
// End of function MoveFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : MoveTo( ... )
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                               - ���Ƶ�������
// Parameter : pDst                                 - Ŀ�������ַ
//             csztDstSize                          - Ŀ����������С
//             csztBufOffset                        - ������ƫ����
//             csztDataLen                          - �������ݵĴ�С
inline size_t CMemPtr::MoveTo( void* const         pDst,
                               const size_t        csztDstSize,
                               const size_t        csztDataLen, 
                               const size_t        csztBufOffset)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove( pDst, csztDstSize, lpBufPos, lsztBufLeft);
}
// End of function MoveTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                                - ���Ƶ�������
// Parameter : pDst                                 - Ŀ�������ַ
//             csztDstSize                           - Ŀ����������С
inline size_t CMemPtr::MoveTo( void* const          pDst, 
                               const size_t         csztDstSize, 
                               const size_t         csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove(pDst, csztDstSize, lpBufPos, lsztBufLeft);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Compare( ... )
// Brief     : ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : csztBufOffset                        - ������ƫ����
//             cpData                               - �Ա���������ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݳ���
inline bool CMemPtr::Cmp( const void* const     cpData,
                          const size_t          csztDataLen, 
                          const size_t          csztBufOffset )
{
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memcmp_equl(lpBufPos, cpData, csztDataLen);
}
// End of function Compare( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ICompare( ... )
// Brief     : ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : csztBufOffset,                       - ������ƫ����
//             cpData                               - �Ա����ݵ�ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݴ�С
inline bool CMemPtr::iCmp( const void* const        cpData,
                           const size_t             csztDataLen, 
                           const size_t             csztBufOffset )
{
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memicmp_equl(lpBufPos, cpData, csztDataLen);
}
// End of function ICompare( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : At( ... )
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : csztBufOffset                        - ������ƫ����
//             ciValue,                             - ��Ҫ��ѯ���ַ�
//             csztLookforLen                       - ��ѯ���ַ���
inline void* CMemPtr::Find( const int             ciValue,
                            const size_t          csztLookforLen,
                            const size_t          csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    size_t lsztDatalen = vMin( lsztBufLeft, csztLookforLen );

    void* lpBufPos     = &mpBuf + csztBufOffset;
    void* lpEndPos     = v_memchr( lpBufPos, ciValue, lsztDatalen);
    if (lpEndPos == 0 )
        return nullptr;

    return lpEndPos;
}
// End of function Find( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : csztBufOffset                        - ������ƫ����
//             ciValue,                             - ��Ҫ��ѯ���ַ�
inline void* CMemPtr::Find( const int               ciValue, 
                            const size_t            csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    void* lpBufPos     = &mpBuf + csztBufOffset;
    void* lpEndPos     = v_memchr(lpBufPos, ciValue, lsztBufLeft);
    if (lpEndPos == 0)
        return nullptr;

    return lpEndPos;
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Set( ... )
// Brief     : ���û�����������
// Return    : void
// Parameter : csztBufOffset                - ������ƫ����
//             ciValue,                     - ��Ҫ���õ��ַ�
//             csztDataLen                  - ���õ��ַ���
inline void CMemPtr::Set( const int         ciValue,
                          const size_t      csztDataLen, 
                          const size_t      csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    void* lpBufPos = &mpBuf + csztBufOffset;
    v_memset(lpBufPos, ciValue, lsztBufLeft);
}
// End of function Set( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Set(...)
// Brief     : ���û�����������
// Return    : void
// Parameter : csztBufOffset                - ������ƫ����
//             ciValue,                     - ��Ҫ���õ��ַ�
//             csztDataLen                  - ���õ��ַ���
inline void CMemPtr::Set( const int          ciValue, 
                          const size_t       csztBufOffset )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    void* lpBufPos = &mpBuf + csztBufOffset;
    v_memset(lpBufPos, ciValue, lsztBufLeft);
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