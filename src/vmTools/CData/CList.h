/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CList.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/03/29 10:40:22
// Modify time  : 2020/03/29 10:40:22
// Note         :
// 
// Test         :
//              - [ ] Add()
//              - [F] AddHead()
//              - [F] AddTail()
//              - [F] AddTail()
//              - [ ] Remove()
//              - [ ] RmHead()
//              - [ ] RmTail()
//              - [ ] Get()
//              - [ ] Set()
//              - [ ] Root()
//              - [ ] Last()
//              - [ ] Prev()
//              - [ ] Next()
//              - [ ] IsTail()
//              - [ ] IsRoot()
//              - [ ] IsEmpty()
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

#ifndef __CLIST_H__
#define __CLIST_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CList : this class package the functions of list operator
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CList
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CList();
    // Destruct define
    inline virtual ~CList();
    
private:
    // No Copy
    inline CList(const CList& obj){};
    // No Assignment
    inline CList& operator = ( const CList& obj ){ return *this; };
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    // The previous list node
    CList*  mpPrev;
    // The nest list node
    CList*  mpNext;

public:
    // The data pointer
    void*   mpData;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // Add a list node to current list node
    inline CList* Add( void* pData );
    // Add a data to list head
    inline CList* AddHead( void* pData );
    // Add a data to list tail
    inline CList* AddTail( void* pData );

    // Get the list root node    
    inline CList* Root();
    // Get the last list node
    inline CList* Last();

    // Remove current node
    inline void* Remove();
    // Remove the list first data
    inline void* RmHead( );
    // Remove the list last data
    inline void* RmTail( );

    // Get current data
    inline void* Get( );
    // Set current data
    inline void* Set( void* pData );

    // The current node is first node?
    inline bool IsRoot( );
    // The current node is last node?
    inline bool IsTail( );;
    // The list is empty?
    inline bool IsEmpty();

    // Get previous node
    inline CList* Prev( );
    // Get next node
    inline CList* Next( );

}; // End of class CList
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CList(...)
// Brief     : Construct define
// Return    : null
CList::CList() :mpPrev(nullptr), mpNext(nullptr), mpData(nullptr)
{

}
// End of function CList(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CList(...)
// Brief     : Destruct define
// Return    : null
CList::~CList()
{

}
// End of function ~CList(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Method(...)
// Brief     : Add a new list node follow the current node
// Return    : CList*                                    -     return new list node pointer
// Parameter : pData                                     - [I] data pointer
inline CList* CList::Add(void* pData)
{
    if (mpNext == nullptr && mpData == nullptr)
    {
        mpData = pData;
        return this;
    }

    CList* lpList = new CList;
    lpList->mpPrev = this;
    lpList->mpNext = mpNext;
    lpList->mpData = pData;

    mpNext = lpList;

    return lpList;
};
// End of function Method(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : AddHead(...)
// Brief     : Add a new node to the list head.
// Return    : Clist*                                    -     new node pointer
// Parameter : pData                                     - [I] data pointer
CList* CList::AddHead(void* pData)
{
    CList* lpHead = Root();
    if (lpHead->mpNext == nullptr && lpHead->mpData == nullptr)
    {
        lpHead->mpData = pData;
        return lpHead;
    }

    CList* lpNode  = new CList;
    lpNode->mpData = lpHead->mpData;
    lpNode->mpPrev = lpHead;
    lpNode->mpNext = lpHead->mpNext;

    lpHead->mpNext = lpNode;
    lpHead->mpData = pData;

    return lpHead;
}
// End of function AddHead(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : AddTail(...)
// Brief     : Add a new node to the list tail
// Return    : void
// Parameter : CList*                                    -     new node pointer
// Parameter : pData                                     - [I] data pointer
CList* CList::AddTail(void* pData)
{
    CList* lpLast = Last();
    if (lpLast->mpNext == nullptr && lpLast->mpData == nullptr)
    {
        lpLast->mpData = pData;
        return lpLast;
    }

    CList* lpNode  = new CList;
    lpNode->mpData = pData;
    lpNode->mpPrev = nullptr;
    lpNode->mpNext = nullptr;

    lpLast->mpNext = lpNode;
    lpNode->mpPrev = lpLast;

    return lpNode;
}
// End of function AddTail(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Root(...)
// Brief     : Get list first node.
// Return    : CList*                                   -     return list first node pointer
vm::CList* CList::Root()
{
    CList* lpHead = this;
    while (lpHead->mpPrev != nullptr)
    {
        lpHead = lpHead->mpPrev;
    }

    return lpHead;
}
// End of function Root(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Last(...)
// Brief     : Get list last node.
// Return    : CList*                                    -     return list last node pointer
vm::CList* CList::Last()
{
    CList* lpLast = this;
    while (lpLast->mpNext != nullptr)
    {
        lpLast = lpLast->mpNext;
    }

    return lpLast;
}
// End of function Last(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Remove(...)
// Brief     : Remove current node
// Return    : void*                                     -     return the data pointer of current node
inline void* CList::Remove()
{
    void* lpData = mpData;
    // if the current node is first node, do follow things.
    if (mpPrev == nullptr)
    {
        // if the list just has one node. doing follow things.
        if (mpNext == nullptr)
        {
            mpData = nullptr;
            return lpData;
        }

        CList* lpNext = mpNext;
        CList* lpNextNext = lpNext->mpNext;
        // if current node has next next node, doing follow things.
        if (lpNextNext != nullptr)
        {
            lpNextNext->mpPrev = this;
        }

        mpNext = lpNext->mpNext;
        mpData = lpNext->mpData;
        return lpData;
    }

    // The current node isn't first node
    // Link the next node to the previous node 
    CList* lpThis = this;
    CList* lpPrev = this->mpPrev;
    CList* lpNext = this->mpNext;
    lpPrev->mpNext = lpNext;
    lpNext->mpPrev = lpPrev;

    // Free this node space
    delete lpThis;

    // return current node data pointer
    return lpData;
};
// End of function Method(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RmHead(...)
// Brief     : remove the list first node. if there are just one node in the list, set the data pointer to null
// Return    : void*                                     -     return the data pointer of the node has been removed
void* CList::RmHead()
{
    CList* lpHead = Root();
    void* lpData = lpHead->mpData;

    if (lpHead->mpNext == nullptr)
    {
        mpData = nullptr;
        return lpData;
    }

    CList* lpNext = lpHead->mpNext;
    mpNext = lpNext->mpNext;
    mpData = lpNext->mpData;

    CList* lpNextNext = lpNext->mpNext;
    if (lpNextNext != nullptr)
    {
        lpNextNext->mpPrev = this;
    }

    delete lpNext;

    return lpData;
}
// End of function RmHead(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RmTail(...)
// Brief     : remove the last node of list, if there are just one node in the list, set the data pointer to null
// Return    : void*                                     -     return the data pointer of the node has been removed
void* CList::RmTail()
{
    CList* lpLast = Last();
    void* lpData = lpLast->mpData;

    if (lpLast == this)
    {
        mpNext = nullptr;
        return lpData;
    }

    CList* lpProv = lpLast->mpPrev;
    lpProv->mpNext = nullptr;

    delete lpLast;

    return lpData;
}
// End of function RmTail(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Get(...)
// Brief     : Get the data pointer of current node.
// Return    : void*                                     -     return the data pointer. 
void* CList::Get()
{
    return mpData;
}
// End of function Get(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Set(...)
// Brief     : Set the data pointer of current node.
// Return    : void*                                     -     return the old data pointer before setting. 
// Parameter : pData                                     - [I] the new data pointer,
void* CList::Set(void* pData)
{

    void* lpOldData = mpData;
    mpData = pData;
    return lpOldData;
}
// End of function Set(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : IsRoot(...)
// Brief     : the current node is root node or not?
// Return    : true                                     -     the current is the root.
//           : false                                    -     the current isn't the root.
bool CList::IsRoot()
{
    return mpPrev == nullptr ? true : false;
}
// End of function IsRoot(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : IsTail(...)
// Brief     : the current node is tailed node or not?
// Return    : true                                     -     the current is the tail.
//           : false                                    -     the current isn't the tail.
bool CList::IsTail()
{
    return mpNext == nullptr ? true : false;
}
// End of function IsTail(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : IsEmpty(...)
// Brief     : the current node is empty or not?
// Return    : true                                     -     the current is the empty.
//           : false                                    -     the current isn't the empty.
bool CList::IsEmpty()
{
    if (mpData == nullptr && mpNext == nullptr)
    {
        return true;
    }

    return false;
}
// End of function IsEmpty(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Prov(...)
// Brief     : Get the previous node pointer of current node.
// Return    : CList*                                   -     the previous node pointer.
vm::CList* CList::Prev()
{
    return mpPrev;
}
// End of function Prov(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Next(...)
// Brief     : Get the next node pointer of current node.
// Return    : CList*                                   -     the next node pointer.
vm::CList* CList::Next()
{
    return mpNext;
}
// End of function Next(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CLIST_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CList.h
/////////////////////////////////////////////////////////////////////////////////////////