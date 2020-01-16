/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CMem.hpp
// Version      : 1.0.0.0
// Brief        : �����װ��memϵ�к�����
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
// class CMem : �����װ��memϵ�к�����
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
    // ��ȡ��������ַ
    inline void* operator * ();
    // ��ȡƫ�ƺ�ĵ�ַ
    inline void* operator [] ( const size_t csztPos )
    {
        // TODO �޸�λ��
        void* lpPos = mszBuf+csztPos;
        return lpPos;
    }
    // ��ȡ�������ַ���
    inline const void* c_str();

    // ��ȡ���������С
    inline size_t size();
    // ��ȡ���������ַ�������
    inline size_t len();
    // ��������
    inline void clear(){ v_memset(mszBuf,0x00,sizeof(mszBuf)); };

public:
    // ��ȡ�ַ��������ַ�����ַ
    inline void* At(const size_t csztBufOffset) {};

    // ��ʽ���ַ���
    inline void* Fmt(const char* const   cpFmtStr, ...);
    // ��ʽ���ַ���
    inline void* Fmt(const size_t        csztBufOffset,
                     const char* const   cpFmtStr,
                     ...);
    // ��ʽ���ַ���
    inline void* Fmt(const char* const   cpFmtStr, va_list vp);
    // ��ʽ���ַ���
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


    // ��Դ�����������ݸ��Ƶ�������
    inline size_t CopyFm(const void* const   cpSrc,
                         const size_t        csztDataLen);
    // ��Դ�����������ݸ��Ƶ�������
    inline size_t CopyFm(const size_t        culBufOffset,
                         const void* const   cpSrc,
                         const size_t        csztDataLen);
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo(void*         cpDst,
                         const size_t  csztDstSize);
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo(void*         cpDst,
                         const size_t  csztDstSize,
                         const size_t  csztDataLen);
    // ���������е����ݸ��Ƶ�Ŀ������
    inline size_t CopyTo(void*         cpDst,
                         const size_t  csztDstSize,
                         const size_t  csztBufOffset,
                         const size_t  csztDataLen);

    // ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyFm(const int           ciFlag,
                          const void* const   cpSrc,
                          const size_t        csztDataLen);
    // ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyFm(const size_t        csztBufOffset,
                          const int           ciFlag,
                          const void* const   cpSrc,
                          const size_t        csztDataLen);
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo(const int           ciFlag,
                          void*               cpDst,
                          const size_t        csztDstSize);
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo(const int           ciFlag,
                          void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztDataLen);
    // ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
    inline size_t CCopyTo(const int           ciFlag,
                          void*               cpDst,
                          const size_t        csztDstSize,
                          const size_t        csztBufOffset,
                          const size_t        csztDataLen);

    // ��Դ�������е����ݸ��Ƶ�������
    inline size_t MoveFm(const void* const   cpSrc,
                         const size_t        csztDataLen);
    // ��Դ�������е����ݸ��Ƶ�������
    inline size_t MoveFm(const size_t        csztBufOffset,
                         const void* const   cpSrc,
                         const size_t        csztDataLen);
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo(void*               cpDst,
                         const size_t        csztDstSize);
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo(void*               cpDst,
                         const size_t        csztDstSize,
                         const size_t        csztDataLen);
    // ���������е����ݸ��Ƶ�Ŀ����
    inline size_t MoveTo(void*               cpDst,
                         const size_t        csztDstSize,
                         const size_t        csztBufOffset,
                         const size_t        csztDataLen);

    // ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool Cmp(const void* const  cpData,
                        const size_t       csztDataLen);
    // ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool Cmp(const size_t       csztBufOffset,
                        const void* const  cpData,
                        const size_t       csztDataLen);

    // ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool iCmp(const void* const  cpData,
                         const size_t       csztDataLen);
    // ���ֵ�˳����ַ����Ƚ�, �����Ǵ�Сд, ��ֻ�Ƚ�ǰcsztDataLen���ַ�
    inline bool iCmp(const size_t       csztBufOffset,
                         const void* const  cpData,
                         const size_t       csztDataLen);

    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find(const int      ciValue);
    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find(const int      ciValue,
                      const size_t   csztLookforLen);
    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find(const size_t   csztBufOffset,
                            const int      ciValue);
    // ��������Ѱ��ָ���ַ���λ��
    inline void* Find(const size_t   csztBufOffset,
                      const int      ciValue,
                      const size_t   csztLookforLen);

    // ���û�����������
    void Set(const int       ciValue);
    // ���û�����������
    void Set(const size_t    csztBufOffset,
             const int       ciValue,
             const size_t    csztDataLen);

private:

}; // End of class CMem
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CMem()
// Brief     : ���캯��
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
// Brief     : ��������
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
// Brief     : ��ȡ��������ַ
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
// Brief     : ��ȡ�������ַ���
// Return    : ����������ַ
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
// Brief     : ���������С
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
// Brief     : ��ȡ���������ַ�������
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
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : const void* const cpFmtStr       - ���ݸ�ʽ
//           : ...                              - �ɱ����ݲ���
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
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : csztBufOffset                    - ����������ƫ����
//             const void* const cpFmtStr       - ���ݸ�ʽ
//           : ...                              - �ɱ����ݲ���
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
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : cpFmtStr                         - ���ݸ�ʽ
//           : va_list vp                       - �ɱ����ݲ���
template <size_t sztBufSize>
inline void* CMem<sztBufSize>::Fmt(const char* const cpFmt, va_list vp)
{
    return Fmt(0, cpFmt, vp);
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : ��ʽ���ַ���
// Return    : char*                            - ���ɵ��ַ�����ַ
// Parameter : csztBufOffset                    - ����������ƫ����
//             cpFmtStr                         - ���ݸ�ʽ
//           : va_list vp                       - �ɱ����ݲ���
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
// Brief     : ��Դ�����������ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
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
// Brief     : ��Դ�����������ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ����������ƫ����
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
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
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : cpDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
template <size_t sztBufSize>
inline size_t vm::CMem<sztBufSize>::CopyTo(void* cpDst, const size_t csztDstSize)
{
    return CopyTo(cpDst, csztDstSize, 0, sztBufSize);
}
// End of function CopyTo()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo()
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : cpDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
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
// Brief     : ���������е����ݸ��Ƶ�Ŀ������
// Return    : size_t                              - ���Ƶ�������
// Parameter : cpDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztBufOffset                       - ������ƫ����
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
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
// Brief     : ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                               - ���Ƶ�������
// Parameter : cFlag                                - ��־�ַ�
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ���������ݳ���
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
// Brief     : ��Դ�������������ݵ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ������ƫ����
//             cFlag                                - ��־�ַ�
//             cpSrc                                - Դ������ʼ��ַ
//             csztDataLen                         - ��Ҫ���������ݳ���
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
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             cpDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
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
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             cpDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
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
// Brief     : ���ƻ������ڵ����ݵ�Ŀ�����򣬵�ָ�����Ȼ�����ָ���ַ�ʱֹͣ����
// Return    : size_t                              - ���Ƶ�������
// Parameter : cFlag                               - ��־�ַ�
//             cpDst                               - Ŀ�������ַ
//             csztDstSize                         - Ŀ�������С
//             csztBufOffset                       - ������ƫ����
//             csztDataLen                        - ��Ҫ�������ݵĴ�С
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
// Brief     : ��Դ�������е����ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : cpSrc                                - Դ��������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
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
// Brief     : ��Դ�������е����ݸ��Ƶ�������
// Return    : size_t                               - ���Ƶ�������
// Parameter : csztBufOffset                        - ������ƫ����
//             cpSrc                                - Դ��������ʼ��ַ
//             csztDataLen                         - ��Ҫ�������ݳ���
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
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                                - ���Ƶ�������
// Parameter : cpDst                                 - Ŀ�������ַ
//             csztDstSize                           - Ŀ����������С
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
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                                - ���Ƶ�������
// Parameter : cpDst                                 - Ŀ�������ַ
//             csztDstSize                           - Ŀ����������С
//             csztDataLen                          - �������ݵĴ�С
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
// Brief     : ���������е����ݸ��Ƶ�Ŀ����
// Return    : size_t                                - ���Ƶ�������
// Parameter : cpDst                                 - Ŀ�������ַ
//             csztDstSize                           - Ŀ����������С
//             csztBufOffset                         - ������ƫ����
//             csztDataLen                          - �������ݵĴ�С
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
// Brief     : ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : cpData                               - �Ա���������ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݳ���
template <size_t sztBufSize>
inline bool vm::CMem<sztBufSize>::Cmp(const void* const cpData, const size_t csztDataLen)
{
    return Cmp(0, cpData, csztDataLen);
}
// End of function Cmp()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cmp()
// Brief     : ���ֵ�˳����ַ����Ƚϣ���ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : csztBufOffset                        - ������ƫ����
//             cpData                               - �Ա���������ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݳ���
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
// Brief     : ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : cpData                               - �Ա����ݵ�ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݴ�С
template <size_t sztBufSize>
inline bool vm::CMem<sztBufSize>::iCmp( const void* const cpData, const size_t csztDataLen )
{
    return iCmp(0, cpData, csztDataLen);
}
// End of function iCmp()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : iCmp()
// Brief     : ���ֵ�˳����ַ����Ƚ�,�����Ǵ�Сд,��ֻ�Ƚ�ǰcsztDataLen���ַ�
// Return    : true                                 - ��ͬ
//             false                                - ��ͬ
// Parameter : csztBufOffset,                       - ������ƫ����
//             cpData                               - �Ա����ݵ�ַ
//             csztDataLen                          - ��Ҫ�Աȵ����ݴ�С
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
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : ciValue,                             - ��Ҫ��ѯ���ַ�
template <size_t sztBufSize>
inline void* vm::CMem<sztBufSize>::Find(const int ciValue)
{
    return Find(0, ciValue, sztBufSize);
}
// End of function Find()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find()
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : ciValue,                             - ��Ҫ��ѯ���ַ�
//             csztLookforLen                       - ��ѯ���ַ���
template <size_t sztBufSize>
inline void* vm::CMem<sztBufSize>::Find(const int ciValue, const size_t csztLookforLen)
{

    return Find(0, ciValue, csztLookforLen);
}
// End of function Find()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find()
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : csztBufOffset                        - ������ƫ����
//             ciValue,                             - ��Ҫ��ѯ���ַ�
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
// Brief     : ��������Ѱ��ָ���ַ���λ��
// Return    : int                                  - �����ҵ��ַ����Ӧ����������ַ��ƫ����
//             nullptr                              - δ���ҵ���ʶ���ַ�
// Parameter : csztBufOffset                        - ������ƫ����
//             ciValue,                             - ��Ҫ��ѯ���ַ�
//             csztLookforLen                       - ��ѯ���ַ���
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
// Brief     : ���û�����������
// Return    : void
// Parameter : ciValue,                     - ��Ҫ���õ��ַ�
template <size_t sztBufSize>
inline void vm::CMem<sztBufSize>::Set(const int ciValue)
{
    return Set(0, ciValue, sztBufSize);
}
// End of function Set()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Set()
// Brief     : ���û�����������
// Return    : void
// Parameter : csztBufOffset                - ������ƫ����
//             ciValue,                     - ��Ҫ���õ��ַ�
//             csztDataLen                  - ���õ��ַ���
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