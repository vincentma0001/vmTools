/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: DllMacro.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 19/12/2015 23:04:36
// Modify time 	: 19/12/2015 23:04:36
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m. tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __VM_TOOLS_DLLMACRO_H__
#define __VM_TOOLS_DLLMACRO_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Note £ºmacro for DLL import / export
#ifdef  _VM_TOOLS_DLL_IMPORT_
#   define DLL_MACRO _declspec(dllimport)
#endif

#ifdef  _VM_TOOLS_DLL_EXPORT_
#   define DLL_MACRO _declspec(dllexport)
#endif

#ifndef DLL_MACRO
#   define DLL_MACRO
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Note : macro for std string
#if defined (_VM_TOOLS_DLL_IMPORT_) || (_VM_TOOLS_DLL_EXPORT_)
//#   ifndef _STRING_
//#       error this file is need #include <string> 
//#   endif
#   define  EXPORT_STL_STRING( dllmacro ) \
        template class dllmacro  std::allocator<char>;\
        template class dllmacro  std::_String_val<char,std::allocator<char>>;\
        template class dllmacro  std::basic_string<char, std::char_traits<char>, \
        std::allocator<char>>;
#else
#   define  EXPORT_STL_STRING( dllmacro )
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Note : macro for std vector 
#if defined (_VM_TOOLS_DLL_IMPORT_) || (_VM_TOOLS_DLL_EXPORT_)
//#   ifndef _VECTOR_ 
//#       error this file is need #include <vector> 
//#   endif
#   define EXPORT_STL_VECTOR( dllmacro, vectype ) \
        template class dllmacro std::allocator< vectype >; \
        template class dllmacro std::vector<vectype, \
        std::allocator< vectype >>;
#else
#   define EXPORT_STL_VECTOR( dllmacro, vectype ) 
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Note : macro for std string
#if defined (_VM_TOOLS_DLL_IMPORT_) || (_VM_TOOLS_DLL_EXPORT_)
//#   ifndef _LIST_
//#       error this file is need #include <list> 
//#   endif
#   define  EXPORT_STL_LIST( dllmacro, listtype ) \
    template class dllmacro  std::allocator<listtype>;\
    template class dllmacro  std::list<listtype, std::allocator<listtype>>;
#else
#   define  EXPORT_STL_LIST( dllmacro, listtype )
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Note : macro for std set
#if defined (_VM_TOOLS_DLL_IMPORT_) || (_VM_TOOLS_DLL_EXPORT_)
//#   ifndef _SET_
//#       error this file is need #include <set> 
//#   endif
#   define EXPORT_STL_SET( dllmacro, settype ) \
        template class dllmacro std::allocator< settype >; \
        template struct dllmacro std::less< settype >; \
        template class dllmacro std::allocator< \
        std::_Tree_nod<std::_Tset_traits<settype,std::less<settype>, \
        std::allocator<settype>,false> > >; \
        template class dllmacro std::allocator<  \
        std::_Tree_ptr<std::_Tset_traits<settype,std::less<settype>, \
        std::allocator<settype>,false> > >; \
        template class dllmacro std::_Tree_ptr< \
        std::_Tset_traits<settype,std::less<settype>, \
        std::allocator<settype>,false> >; \
        template class dllmacro std::_Tree_nod< \
        std::_Tset_traits<settype,std::less<settype>,\
        std::allocator<settype>,false> >; \	
        // template class dllmacro std::_Tree_val< std::_Tset_traits<settype, std::less<settype>,\
        // std::allocator<settype>,false> >; \	
        // template class dllmacro std::set< settype, std::less< settype >, \
        // std::allocator< settype > >; 
#else
#   define EXPORT_STL_SET( dllmacro, settype )
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Note : macro for std map
#if defined (_VM_TOOLS_DLL_IMPORT_) || (_VM_TOOLS_DLL_EXPORT_)
//#   ifndef _MAP_
//#       error this file is need #include <map> 
//#   endif
#   define EXPORT_STL_MAP( dllmacro, mapkey, mapvalue ) \
        template struct dllmacro std::pair< mapkey,mapvalue >; \
        template class dllmacro std::allocator< \
        std::pair<const mapkey,mapvalue> >; \
        template struct dllmacro std::less< mapkey >; \
        template class dllmacro std::allocator< \
        std::_Tree_ptr<std::_Tmap_traits<mapkey,mapvalue,std::less<mapkey>, \
        std::allocator<std::pair<const mapkey,mapvalue> >,false> > >; \
        template class dllmacro std::allocator< \
        std::_Tree_nod<std::_Tmap_traits<mapkey,mapvalue,std::less<mapkey>, \
        std::allocator<std::pair<const mapkey,mapvalue> >,false> > >; \
        template class dllmacro std::_Tree_nod< \
        std::_Tmap_traits<mapkey,mapvalue,std::less<mapkey>, \
        std::allocator<std::pair<const mapkey,mapvalue> >,false> >; \
        template class dllmacro std::_Tree_ptr< \
        std::_Tmap_traits<mapkey,mapvalue,std::less<mapkey>, \
        std::allocator<std::pair<const mapkey,mapvalue> >,false> >; \
        template class dllmacro std::_Tree_val< \
        std::_Tmap_traits<mapkey,mapvalue,std::less<mapkey>, \
        std::allocator<std::pair<const mapkey,mapvalue> >,false> >; \
        template class dllmacro std::map< \
        mapkey, mapvalue, std::less< mapkey >, \
        std::allocator<std::pair<const mapkey,mapvalue> > >;
#else
#   define EXPORT_STL_SET( dllmacro, settype )
#endif

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_DLLMACRO_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file DllMacro.h
/////////////////////////////////////////////////////////////////////////////////////////