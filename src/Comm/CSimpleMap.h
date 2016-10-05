/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CSimpleMap.h
// Version 		: 1.0
// Brief 		: 
// Auther 		: VM
// Create time 	: 30/11/2015 13:07:37
// Modify time 	: 30/11/2015 13:07:37
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition

#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#else
#pragma warning( disable : 4786 )
#endif

#ifndef _CSIMPLEMAP_H__
#define _CSIMPLEMAP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include files
#include <map>

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CSimpleMap
//        Notes : �����򵥷�װ��std::Map����
//
/////////////////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2> 
class CSimpleMap 
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef typename std::map < T1, T2 >                    tMap;           // Ϊ��mapʹ�ã������¶���Map
	typedef typename std::map < T1, T2 >::iterator		    tMapItor;       // Ϊ��mapʹ�ã�����iterator�����ض��� 
	typedef typename std::map < T1, T2 >::value_type		tMapValue;      // Ϊ��mapʹ�ã�����value_type�����ض��� 
    typedef typename std::map < T1, T2 >::const_iterator    tcMapItor;      // Ϊ��mapʹ�ã�����const_iterator�����ض��� 

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private :
	tMap		                    mUserTypeMap;

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public :
	inline int	GetSize( void ) const;              // ��ȡ����ͼ��Ԫ�ظ���
	inline bool	IsEmpty( void ) const;              // �ж�����ͼ�Ƿ�Ϊ��

	inline bool	IsExist( T1 key_value ) const;      // �ж�����Ԫ���Ƿ����
    
    inline bool AddData( T1 key_value, T2 Data);    // �������Ԫ��
	inline T2*  GetData( T1 key_value );            // ��ȡ����Ԫ��
	inline bool DelData( T1 key_value );            // ɾ������Ԫ��

    inline void DelAll( void );                     // ɾ����������Ԫ��

    inline tMapItor GetFirst( void );                   // ��ȡ����ͼ����Ԫ��
    inline tMapItor GetLast( void );                    // ��ȡ����ͼ��βԪ��

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
int CSimpleMap< T1,T2 >::GetSize(void) const { return (int)mUserTypeMap.size(); };

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsEmpty()
// full name : 
// Brief     : �ж�����ͼ�Ƿ�Ϊ��
// Parameter : ��
// Return    : bool  ����ͼû��Ԫ��
//             false ����ͼ�д���Ԫ�� 
// Notes     : ��
template <typename T1, typename T2>
bool CSimpleMap< T1,T2 >::IsEmpty(void) const { return mUserTypeMap.empty(); };

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsExist()
// full name : CSimpleMap< T1,T2 >::IsExist
// Brief     : �ж�����Ԫ���Ƿ����
// Parameter : T1 key_value ��Ҫ�жϵ�Ԫ������ֵ
// Return    : bool  ����ͼ�д��ڴ�Ԫ��
//             false ����ͼ�����ڴ�Ԫ�أ���������ͼ�в�����Ԫ�ص������ 
// Notes     : ��
template <typename T1, typename T2>
bool CSimpleMap< T1,T2 >::IsExist( T1 key_value ) const
{
	if( this->IsEmpty() )
		return false;

	tcMapItor iter = mUserTypeMap.find( key_value );
	if( iter == mUserTypeMap.end() )
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
bool CSimpleMap< T1,T2 >::AddData( T1 key_value, T2 Data)
{
	std::pair<tMapItor, bool> temp_pair = mUserTypeMap.insert( tMapValue( key_value, Data ) );
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
T2* CSimpleMap< T1,T2 >::GetData( T1 key_value )
{
	T2* pData = NULL;
	if( this->IsEmpty() )
		return NULL;

	tMapItor iter = mUserTypeMap.find( key_value );
	if( iter == mUserTypeMap.end() )
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
bool CSimpleMap< T1,T2 >::DelData( T1 key_value )
{
	if( mUserTypeMap.empty() )
		return false;
			
	tMapItor iter = mUserTypeMap.find( key_value );
	if( iter == mUserTypeMap.end() )
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
void CSimpleMap< T1,T2 >::DelAll()
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
typename CSimpleMap< T1,T2 >::tMapItor CSimpleMap< T1,T2 >::GetFirst( void )
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
typename CSimpleMap< T1,T2 >::tMapItor CSimpleMap< T1,T2 >::GetLast( void )
{ 
    return mUserTypeMap.end();
};

/////////////////////////////////////////////////////////////////////////////////////

#endif // end of define _CSIMPLEMAP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of files...
/////////////////////////////////////////////////////////////////////////////////////////