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
// class CMemPtr : �����װ��memϵ�к�����
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
    // ��ȡ��������ַ
    inline void* operator * ();
    // ��ȡƫ�ƺ�ĵ�ַ
    inline void* operator [] (const size_t csztPos)
    {
        // TODO �޸�λ��
        void* lpPos = ((char*)mpBuf + csztPos);
        return lpPos;
    }
    // ��ȡ�������ַ���
    inline const void* c_str();

    // ��ȡ��������С
    inline size_t size(){ return msztBufSize; }
    // ��ȡ���������ַ�������
    inline size_t len();
    // ��������
    inline void clear() { v_memset(mpBuf, 0x00, sizeof(msztBufSize)); };

public:
    // ��ȡ�ַ��������ַ�����ַ
    inline void* At(const size_t csztBufOffset) { return ((char*)mpBuf+csztBufOffset); };

    // ��ʽ���ַ���
    inline void* Fmt(const char* const   cpFmt, ...);
    // ��ʽ���ַ���
    inline void* Fmt(const size_t        csztBufOffset,
                     const char* const   cpFmt, 
                     ...);
    // ��ʽ���ַ���
    inline void* Fmt(const char* const   cpFmt, va_list vp);
    // ��ʽ���ַ���
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


    // ��Դ�����������ݸ��Ƶ�������
    inline size_t CopyFm( const void* const   cpSrc,
                          const size_t        csztDataLen );
    // ��Դ�����������ݸ��Ƶ�������
    inline size_t CopyFm( const size_t        csztBufOffset,
                          const void* const   cpSrc,
                          const size_t        csztDataLen );
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo( void*         cpDst,
                          const size_t  csztDstSize );
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo( void*         cpDst,
                          const size_t  csztDstSize,
                          const size_t  csztDataLen );
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo( void*         cpDst,
                          const size_t  csztDstSize,
                          const size_t  csztBufOffset,
                          const size_t  csztDataLen );

    // ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyFm( const int           ciFlag,
                           const void* const   cpSrc,
                           const size_t        csztDataLen );
    // ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyFm( const size_t        csztBufOffset,
                           const int           ciFlag,
                           const void* const   cpSrc,
                           const size_t        csztDataLen );
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo( const int           ciFlag,
                           void*               cpDst,
                           const size_t        csztDstSize );
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo( const int           ciFlag,
                           void*               cpDst,
                           const size_t        csztDstSize,
                           const size_t        csztDataLen );
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo( const int           ciFlag,
                           void*               cpDst,
                           const size_t        csztDstSize,
                           const size_t        csztBufOffset,
                           const size_t        csztDataLen );

    // ��Դ�������е����ݸ��Ƶ�������
    inline size_t MoveFm( const void* const   cpSrc,
                          const size_t        csztDataLen );
    // ��Դ�������е����ݸ��Ƶ�������
    inline size_t MoveFm( const size_t        csztBufOffset,
                          const void* const   cpSrc,
                          const size_t        csztDataLen );
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo( void*               cpDst,
                          const size_t        csztDstSize );
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo( void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztDataLen );
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo( void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztBufOffset,
                          const size_t        csztDataLen );

    // ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool Cmp( const void* const  cpData,
                     const size_t       csztDataLen );
    // ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool Cmp( const size_t       csztBufOffset,
                     const void* const  cpData,
                     const size_t       csztDataLen );

    // ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool iCmp( const void* const  cpData,
                      const size_t       csztDataLen );
    // ���ֵ�˳����ַ����Ƚ�, �����Ǵ�Сд, ��ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool iCmp( const size_t       csztBufOffset,
                      const void* const  cpData,
                      const size_t       csztDataLen );

    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find( const int      ciValue );
    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find( const int      ciValue,
                       const size_t   csztLookforLen );
    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find( const size_t   csztBufOffset,
                       const int      ciValue );
    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find( const size_t   csztBufOffset,
                       const int      ciValue,
                       const size_t   csztLookforLen );

    // ���û�����������
    inline void Set( const int       ciValue );
    // ���û�����������
    inline void Set( const size_t    csztBufOffset,
                     const int       ciValue,
                     const size_t    csztDataLen );

}; // End of class CMemPtr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMemPtr()
// Brief     : ���캯��
// Return    : null
// Parameter : pAddr                    - ��ʼ���ڴ��ַ
//             csztBufSize              - ��ʼ���ڴ泤��
CMemPtr::CMemPtr(void* pAddr, const size_t csztBufSize) 
    :mpBuf(pAddr),msztBufSize(csztBufSize)
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
// Method    : Len()
// Brief     : ��ȡ���������ַ�������
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
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : cpFmtStr                         - ���ݸ�ʽ
//           : ...                              - �ɱ����ݲ���
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
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : csztBufOffset                    - ����������ƫ����
//             cpFmtStr                         - ���ݸ�ʽ
//           : ...                              - �ɱ����ݲ���
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
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : cpFmtStr                         - ���ݸ�ʽ
//           : va_list vList                       - �ɱ����ݲ���
inline void* CMemPtr::Fmt(const char* const cpFmt, va_list vp)
{
    return Fmt( 0, cpFmt, vp );
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : csztBufOffset                    - ����������ƫ����
//             cpFmtStr                         - ���ݸ�ʽ
//           : va_list vList                       - �ɱ����ݲ���
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
// Brief     : ��Դ�����������ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                          - ��Ҫ�������ݳ���
size_t CMemPtr::CopyFm(const void* const cpSrc, const size_t csztDataLen)
{
    return CopyFm(0, cpSrc, csztDataLen);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CopyFm( ... )
// Brief     : ��Դ�����������ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ����������ƫ����
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
inline size_t CMemPtr::CopyFm( const size_t        csztBufOffset,
                               const void* const   cpSrc,  
                               const size_t        csztDataLen)
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
inline size_t CMemPtr::CopyTo(void* cpDst, const size_t csztDstSize)
{
    return CopyTo(cpDst, csztDstSize, 0, msztBufSize);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
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
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztBufOffset                       - ������ƫ����
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
inline size_t CMemPtr::CopyTo( void*               cpDst,
                               const size_t        csztDstSize,
                               const size_t        csztBufOffset,
                               const size_t        csztDataLen)
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
inline size_t CMemPtr::CCopyFm( const size_t        csztBufOffset,
                                const int           ciFlag,
                                const void* const   cpSrc,
                                const size_t        csztDataLen)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memccpy(lpBufPos, msztBufSize, cpSrc, ciFlag, csztDataLen);
}
// End of function CCopyFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyFm(...)
// Brief     : ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                               - ���Ƶ�������
// Parameter : cFlag                                - ��־�ַ�
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ���������ݳ���
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
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztBufOffset                       - ������ƫ����
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
inline size_t CMemPtr::CCopyTo( const int           ciFlag,
                                void*               cpDst,
                                const size_t        csztDstSize,
                                const size_t        csztBufOffset,
                                const size_t        csztDataLen )
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
                                void*         cpDst,
                                const size_t  csztDstSize )
{
    return CCopyTo(ciFlag, cpDst, 0, msztBufSize);
}
// End of function CCopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CCopyTo(...)
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             pDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
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
// Brief     : ��Դ�������е����ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ������ƫ����
//             cpSrc                                - Դ��������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
inline size_t CMemPtr::MoveFm( const size_t        csztBufOffset,
                               const void* const   cpSrc,
                               const size_t        csztDataLen )
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // �������� 
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove( lpBufPos, lsztBufLeft, cpSrc, csztDataLen );
}
// End of function MoveFm( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveFm(...)
// Brief     : ��Դ�������е����ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : cpSrc                                - Դ��������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
inline size_t CMemPtr::MoveFm( const void* const   cpSrc,
                               const size_t        csztDataLen)
{
    return MoveFm(0, cpSrc, csztDataLen);
}
// End of function MoveFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : MoveTo( ... )
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                               - ���Ƶ�������
// Parameter : pDst                                 - Ŀ�������ַ
//             csztDstSize                          - Ŀ����������С
//             csztBufOffset                        - ������ƫ����
//             csztDataLen                          - �������ݵĴ�С
inline size_t CMemPtr::MoveTo( void*               pDst,
                               const size_t        csztDstSize,
                               const size_t        csztBufOffset,
                               const size_t        csztDataLen)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;

    // ��������
    void* lpBufPos = &mpBuf + csztBufOffset;
    return v_memmove( pDst, csztDstSize, lpBufPos, csztDataLen );
}
// End of function MoveTo( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                                - ���Ƶ�������
// Parameter : pDst                                 - Ŀ�������ַ
//             csztDstSize                           - Ŀ����������С
inline size_t CMemPtr::MoveTo(void* cpDst, const size_t csztDstSize)
{
    return MoveTo(cpDst, csztDstSize, 0, msztBufSize);
}
// End of function MoveTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MoveTo()
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                                - ���Ƶ�������
// Parameter : pDst                                 - Ŀ�������ַ
//             csztDstSize                           - Ŀ����������С
//             csztDataLen                          - �������ݵĴ�С
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
// Brief     : ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : csztBufOffset                        - ������ƫ����
//             cpData                               - �Ա���������ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݳ���
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
// Brief     : ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : cpData                               - �Ա���������ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݳ���
inline bool CMemPtr::Cmp(const void* const cpData, const size_t csztDataLen)
{
    return Cmp(0, cpData, csztDataLen);
}
// End of function Compare(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ICompare( ... )
// Brief     : ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : csztBufOffset,                       - ������ƫ����
//             cpData                               - �Ա����ݵ�ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݴ�С
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
// Brief     : ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : cpData                               - �Ա����ݵ�ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݴ�С
inline bool CMemPtr::iCmp(const void* const cpData, const size_t csztDataLen)
{
    return iCmp(0, cpData, csztDataLen);
}
// End of function ICompare()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : At( ... )
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : csztBufOffset                        - ������ƫ����
//             ciValue,                             - ��Ҫ��ѯ���ַ�
//             csztLookforLen                       - ��ѯ���ַ���
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
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : csztBufOffset                        - ������ƫ����
//             ciValue,                             - ��Ҫ��ѯ���ַ�
inline void* CMemPtr::Find(const size_t csztBufOffset, const int ciValue)
{
    size_t lsztBufLeft = msztBufSize - csztBufOffset;
    return Find(csztBufOffset, ciValue, lsztBufLeft);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : ciValue,                             - ��Ҫ��ѯ���ַ�
//             csztLookforLen                       - ��ѯ���ַ���
inline void* CMemPtr::Find(const int ciValue, const size_t csztLookforLen)
{
    return Find(0, ciValue, csztLookforLen);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : ciValue,                             - ��Ҫ��ѯ���ַ�
inline void* CMemPtr::Find( const int ciValue )
{
    return Find(0, ciValue, msztBufSize);
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
// Brief     : ���û�����������
// Return    : void
// Parameter : csztBufOffset                - ������ƫ����
//             ciValue,                     - ��Ҫ���õ��ַ�
//             csztDataLen                  - ���õ��ַ���
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