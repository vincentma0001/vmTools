/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CXml.h
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 8/4/2016 13:13:30
// Modify time 	: 8/4/2016 13:13:30
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

#ifndef __CXML_H__
#define __CXML_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "tinyxml/tinyxml.h"
#include <VECTOR>

#include <IOSTREAM>
#include "VerifyDef.h"
#include "CException.h"
#include "CExpTrack.h"
#include "CWinSeh.h"
#include "CCppExp.h"
#include "CWinSehExp.h"

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CXml
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////////
class CXml
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef std::vector<TiXmlElement*>  tVector;

/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    TiXmlDocument mDoc;
 
 
/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    CXml( const char* szDocName );;		            // Construct define
    CXml();;
	virtual ~CXml();;          // Destruct define


/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    
    void LoadFile( const char* szDocName );;
    void SaveFile( const char* szDocName );
    void SaveFile(  );
    std::string Save();

    void Parse( const char* szXMLStr );
    void Print(  );
 
    TiXmlElement* GetRoot( const char* szNodeName );

    const char* GetNodeValue( const TiXmlElement* pTiXmlElement );

    TiXmlElement*    GetSubNode( TiXmlElement* pTiXmlElement, const char* szNodeName );
    TiXmlElement*   GetSubNode( TiXmlElement* pTiXmlElement );
    tVector         GetSubNodes( TiXmlElement* pTiXmlElement, const char* szNodeName );

    TiXmlElement* GetNextNode( TiXmlElement* pTiXmlElement, const char* szNodeName );
    TiXmlElement* GetNextNode( TiXmlElement* pTiXmlElement );
    
    void RemoveNode( TiXmlElement* pTiFNode, TiXmlElement* pTiSNode  );
    
    TiXmlElement* AddSubNode( TiXmlElement* pTiXmlElement, const char* szNodeName );
    TiXmlElement* AddSubNodeUnion( TiXmlElement* pTiXmlElement, const char* szNodeName );

    void SetNodeAttr( TiXmlElement* pTiXmlElement, const char* szAttrName, const char* szAttrValue );
    void SetNodeAttr( TiXmlElement* pTiXmlElement, const char* szAttrName, int iAttrValue );
    void SetNodeAttr( TiXmlElement* pTiXmlElement, const char* szAttrName, double dAttrValue );

    char*        GetNodeAttrForS( const TiXmlElement* pTiXmlElement, const char* szAttrName );
    std::string  GetNodeAttrForStlS( const TiXmlElement* pTiXmlElement, const char* szAttrName );
    int    GetNodeAttrForI( const TiXmlElement* pTiXmlElement, const char* szAttrName );
    double GetNodeAttrForD( const TiXmlElement* pTiXmlElement, const char* szAttrName );
    
    char*       GetNodeTxt( const TiXmlElement* pTiXmlElement );
    std::string GetNodeTxtFotStl( const TiXmlElement* pTiXmlElement );;
    TiXmlText*  SetNodeTxt( TiXmlElement* pTiXmlElement, const char* szNodeName );
 
}; // End of class CXml
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CXML_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CXml.h
/////////////////////////////////////////////////////////////////////////////////////////