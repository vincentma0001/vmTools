/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CSingleTon.h
// Version 		: 0.0.0.1
// Brief 		: 
// Author 		: v.m
// Create time 	: 5/12/2015 14:27:32
// Modify time 	: 5/12/2015 14:27:32
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CSINGLETON_H__
#define __CSINGLETON_H__

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CSingleton
//        Notes : 这个是一个单件的模板类，用于根据模板创建一个特定的单件对象。
//
/////////////////////////////////////////////////////////////////////////////////////////
template< class T, class TMutex >
class CSingleton
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    static TMutex		mtMutex;		        // 锁，要考虑多线程，多核计算机同步问题
    static T*			mptInstance;			// 实例对象

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CSingleton(){};			                                // Construct define
    ~CSingleton(){};			                            // Destruct define
private:
    CSingleton( const CSingleton& cSingleton ){}            // no copy
    CSingleton& operator = ( const CSingleton& obj ){};     // no assignment

public:
    static T* Instance()
    {
        // three time checked locking for multithreading safe and performance
        // the detail see the <Modern c++ design> singleton
        if (mptInstance == NULL)
        {
            TMutex::Locker lock(mtMutex);

            if (mptInstance == NULL)
                mptInstance = new T;
        }

        return mptInstance;

    };         // 获取实例对象指针
    static void Destory()
    {
        if (mptInstance != NULL)
        {
            delete mptInstance;
            mptInstance = NULL;
        }
    };       // 销毁实例对象

}; // End of class CSingleton
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSINGLETON_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CSingleTon.h
/////////////////////////////////////////////////////////////////////////////////////////