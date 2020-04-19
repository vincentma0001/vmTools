/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CStdMap.hpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/01 15:03:58
// Modify time  : 2020/01/01 15:03:58
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

#ifndef __CSTDMAP_HPP__
#define __CSTDMAP_HPP__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#ifndef   _MAP_
#   include <map>
#endif // _MAP_

// Config files included

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////
//
// class : �����򵥷�װ��std::Map����
//
/////////////////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2>
class CStdMap
{
/////////////////////////////////////////////////////////////////////////////////////
// Type define :
public:
    // Ϊ��mapʹ�ã������¶���Map
    typedef typename std::map < T1, T2 >                    tMap;
    // Ϊ��mapʹ�ã�����iterator�����ض��� 
    typedef typename std::map < T1, T2 >::iterator		    tMapItor;
    // Ϊ��mapʹ�ã�����value_type�����ض��� 
    typedef typename std::map < T1, T2 >::value_type		tMapValue;
    // Ϊ��mapʹ�ã�����const_iterator�����ض��� 
    typedef typename std::map < T1, T2 >::const_iterator    tcMapItor;

/////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tMap		                    mUserTypeMap;

/////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ȡ����ͼ��Ԫ�ظ���
    inline int	GetSize(void) const;              
    // �ж�����ͼ�Ƿ�Ϊ��
    inline bool	IsEmpty(void) const;              

    // �ж�����Ԫ���Ƿ����
    inline bool	IsExist(T1 key_value) const;      

    // �������Ԫ��
    inline bool AddData(T1 key_value, T2 Data);   
    // ��ȡ����Ԫ�� 
    inline T2*  GetData(T1 key_value);            
    // ɾ������Ԫ��
    inline bool DelData(T1 key_value);            

    // ɾ����������Ԫ��
    inline void DelAll(void);                     

    // ��ȡ����ͼ����Ԫ��
    inline tMapItor GetFirst(void);                   
    // ��ȡ����ͼ��βԪ��
    inline tMapItor GetLast(void);                    

}; // End of class CSimpleMap
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetSize()
// full name : 
// Brief     : ��ȡ����ͼ��Ԫ�ظ���
// Parameter : ��
// Return    : ��������;��Ԫ�ظ���
// Notes     : ��
template <typename T1, typename T2>
int CStdMap< T1, T2 >::GetSize(void) const { return (int)mUserTypeMap.size(); };

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsEmpty()
// full name : 
// Brief     : �ж�����ͼ�Ƿ�Ϊ��
// Parameter : ��
// Return    : bool  ����ͼû��Ԫ��
//             false ����ͼ�д���Ԫ�� 
// Notes     : ��
template <typename T1, typename T2>
bool CStdMap< T1, T2 >::IsEmpty(void) const { return mUserTypeMap.empty(); };

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsExist()
// full name : CSimpleMap< T1,T2 >::IsExist
// Brief     : �ж�����Ԫ���Ƿ����
// Parameter : T1 key_value ��Ҫ�жϵ�Ԫ������ֵ
// Return    : bool  ����ͼ�д��ڴ�Ԫ��
//             false ����ͼ�����ڴ�Ԫ�أ���������ͼ�в�����Ԫ�ص������ 
// Notes     : ��
template <typename T1, typename T2>
bool CStdMap< T1, T2 >::IsExist(T1 key_value) const
{
    if (this->IsEmpty())
        return false;

    tcMapItor iter = mUserTypeMap.find(key_value);
    if (iter == mUserTypeMap.end())
        return false;
    else
        return true;
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AddData() 
// full name : CSimpleMap< T1,T2 >::AddData
// Brief     : �������Ԫ��
// Parameter : T1 key_value  ��Ҫ��ӵ�Ԫ������ֵ
//             T2 Data       ��Ҫ��ӵ�Ԫ������ 
// Return    : bool  ��ӳɹ�
//             false ���ʧ�� 
// Notes     : ��Key_value�Ѿ����ڣ�����Dataֵ����ԭ��ֵ
template <typename T1, typename T2>
bool CStdMap< T1, T2 >::AddData(T1 key_value, T2 Data)
{
    std::pair<tMapItor, bool> temp_pair = mUserTypeMap.insert(tMapValue(key_value, Data));
    return temp_pair.second;
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetData()
// full name : CSimpleMap< T1,T2 >::GetData
// Brief     : ��ȡ����Ԫ��
// Parameter : T1 key_value  ��Ҫ��ȡ��Ԫ������ֵ
// Return    : T2*           һ��ָ������Ҫ������Ԫ�ص�ָ��
//             NULL          ����ͼ�в����ڴ����ݣ���������ͼΪ�������
// Notes     : ��
template <typename T1, typename T2>
T2* CStdMap< T1, T2 >::GetData(T1 key_value)
{
    T2* pData = NULL;
    if (this->IsEmpty())
        return NULL;

    tMapItor iter = mUserTypeMap.find(key_value);
    if (iter == mUserTypeMap.end())
        return NULL;
    else
        pData = &(*iter).second;

    return pData;
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : DelData()
// full name : CSimpleMap< T1,T2 >::DelData
// Brief     : ɾ������Ԫ��
// Parameter : T1 key_value  ��Ҫ��ȡ��Ԫ������ֵ
// Return    : true      ɾ���ɹ�
//             false     ����ͼ�в����ڴ����ݣ���������ͼΪ�������
// Notes     : ��
template <typename T1, typename T2>
bool CStdMap< T1, T2 >::DelData(T1 key_value)
{
    if (mUserTypeMap.empty())
        return false;

    tMapItor iter = mUserTypeMap.find(key_value);
    if (iter == mUserTypeMap.end())
        return false;
    else {
        mUserTypeMap.erase(iter);
        return true;
    }
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : DelAll()
// full name : CSimpleMap< T1,T2 >::DelAll()
// Brief     : ��ȡ����ͼ��ĩԪ��
// Parameter : ��
// Return    : ��
// Notes     : ��
template <typename T1, typename T2>
void CStdMap< T1, T2 >::DelAll()
{
    mUserTypeMap.clear();
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      ��GetFirst()
// full name : CSimpleMap< T1,T2 >::GetFirst
// Brief     : public
// Parameter : void
// Return    : ����ͼ����Ԫ�صĵ�������
// Notes     : �˺�����������Ҫ��������ͼ�����
template <typename T1, typename T2>
typename CStdMap< T1, T2 >::tMapItor CStdMap< T1, T2 >::GetFirst(void)
{
    return mUserTypeMap.begin();
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetLast()
// full name : CSimpleMap< T1,T2 >::GetLast
// Brief     : ��ȡ����ͼ��ĩԪ��
// Parameter : ��
// Return    : ����ͼ��ĩԪ�صĵ�������
// Notes     : �˺�����������Ҫ��������ͼ�����
template <typename T1, typename T2>
typename CStdMap< T1, T2 >::tMapItor CStdMap< T1, T2 >::GetLast(void)
{
    return mUserTypeMap.end();
};

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSTDMAP_HPP__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStdMap.hpp
/////////////////////////////////////////////////////////////////////////////////////////