/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CSingleton.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/12 21:56:29
// Modify time  : 2020/01/12 21:56:29
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

#ifndef __CSINGLETON_H__
#define __CSINGLETON_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// Platform files included

// Used files included
#include <vmLibIPC/CLocker.hpp>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define :
#ifndef    vSingleTon
#   define vSingleTon( tInstance, tMutex ) vm::CSingleton<tInstance, tMutex>::Instance()
#endif  // vSingleTon

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CSingleton : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template< class tInstance, class tMutex >
class CSingleton
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CSingleton(){};
    // Destruct define
    virtual ~CSingleton(){};
    
private:
    // No Copy
    CSingleton(const CSingleton& obj){};
    // No Assignment
    CSingleton& operator = ( const CSingleton& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    // 锁，要考虑多线程，多核计算机同步问题
    static tMutex		mtMutex;		        
    // 实例对象
    static tInstance*	mptInstance;			

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取实例对象指针
    static tInstance* Instance()
    {
        // three time checked locking for multithreading safe and performance
        // the detail see the <Modern c++ design> singleton
        if (mptInstance == NULL)
        {
            CLocker<tMutex> lock(mtMutex);

            if (mptInstance == NULL)
                mptInstance = new T;
        }

        return mptInstance;

    };        
    // 销毁实例对象
    static void Destory()
    {
        if (mptInstance != NULL)
        {
            CLocker<tMutex> lock(mtMutex);

            if (mptInstance!=NULL)
            {
                delete mptInstance;
                mptInstance = NULL;
            } 
        }
    };

}; // End of class CSingleton
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSINGLETON_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CSingleton.h
/////////////////////////////////////////////////////////////////////////////////////////