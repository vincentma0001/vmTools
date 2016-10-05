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
//        Notes : 这个类简单封装的std::Map操作
//
/////////////////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2> 
class CSimpleMap 
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef typename std::map < T1, T2 >                    tMap;           // 为简化map使用，对重新定义Map
	typedef typename std::map < T1, T2 >::iterator		    tMapItor;       // 为简化map使用，对其iterator进行重定义 
	typedef typename std::map < T1, T2 >::value_type		tMapValue;      // 为简化map使用，对其value_type进行重定义 
    typedef typename std::map < T1, T2 >::const_iterator    tcMapItor;      // 为简化map使用，对其const_iterator进行重定义 

/////////////////////////////////////////////////////////////////////////////////////
// data members :
private :
	tMap		                    mUserTypeMap;

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public :
	inline int	GetSize( void ) const;              // 获取数据图中元素个数
	inline bool	IsEmpty( void ) const;              // 判断数据图是否为空

	inline bool	IsExist( T1 key_value ) const;      // 判断数据元素是否存在
    
    inline bool AddData( T1 key_value, T2 Data);    // 添加数据元素
	inline T2*  GetData( T1 key_value );            // 获取数据元素
	inline bool DelData( T1 key_value );            // 删除数据元素

    inline void DelAll( void );                     // 删除所有数据元数

    inline tMapItor GetFirst( void );                   // 获取数据图中首元素
    inline tMapItor GetLast( void );                    // 获取数据图中尾元素

}; // End of class CSimpleMap
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetSize()
// full name : 
// Brief     : 获取数据图中元素个数
// Parameter : 无
// Return    : 返回数据途中元素个数
// Notes     : 无
template <typename T1, typename T2>
int CSimpleMap< T1,T2 >::GetSize(void) const { return (int)mUserTypeMap.size(); };

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsEmpty()
// full name : 
// Brief     : 判断数据图是否为空
// Parameter : 无
// Return    : bool  数据图没有元素
//             false 数据图中存在元素 
// Notes     : 无
template <typename T1, typename T2>
bool CSimpleMap< T1,T2 >::IsEmpty(void) const { return mUserTypeMap.empty(); };

/////////////////////////////////////////////////////////////////////////////////////
// Name      : IsExist()
// full name : CSimpleMap< T1,T2 >::IsExist
// Brief     : 判断数据元素是否存在
// Parameter : T1 key_value 需要判断的元素索引值
// Return    : bool  数据图中存在此元素
//             false 数据图不纯在此元素（包含数据图中不纯在元素的情况） 
// Notes     : 无
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
// Brief     : 添加数据元素
// Parameter : T1 key_value  需要添加的元素索引值
//             T2 Data       需要添加的元素数据 
// Return    : bool  添加成功
//             false 添加失败 
// Notes     : 若Key_value已经存在，则用Data值代替原有值
template <typename T1, typename T2>
bool CSimpleMap< T1,T2 >::AddData( T1 key_value, T2 Data)
{
	std::pair<tMapItor, bool> temp_pair = mUserTypeMap.insert( tMapValue( key_value, Data ) );
	return temp_pair.second;
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetData()
// full name : CSimpleMap< T1,T2 >::GetData
// Brief     : 获取数据元素
// Parameter : T1 key_value  需要获取的元素索引值
// Return    : T2*           一个指向所需要的数据元素的指针
//             NULL          数据图中不存在此数据（包含数据图为空情况）
// Notes     : 无
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
// Brief     : 删除数据元素
// Parameter : T1 key_value  需要获取的元素索引值
// Return    : true      删除成功
//             false     数据图中不存在此数据（包含数据图为空情况）
// Notes     : 无
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
// Brief     : 获取数据图中末元素
// Parameter : 无
// Return    : 无
// Notes     : 无
template <typename T1, typename T2>
void CSimpleMap< T1,T2 >::DelAll()
{
	mUserTypeMap.clear();
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      ：GetFirst()
// full name : CSimpleMap< T1,T2 >::GetFirst
// Brief     : public
// Parameter : void
// Return    : 数据图中首元素的迭代引用
// Notes     : 此函数多用于需要遍历数据图的情况
template <typename T1, typename T2>
typename CSimpleMap< T1,T2 >::tMapItor CSimpleMap< T1,T2 >::GetFirst( void )
{ 
    return mUserTypeMap.begin();
};

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetLast()
// full name : CSimpleMap< T1,T2 >::GetLast
// Brief     : 获取数据图中末元素
// Parameter : 无
// Return    : 数据图中末元素的迭代引用
// Notes     : 此函数多用于需要遍历数据图的情况
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