/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CXml.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 8/4/2016 13:12:35
// Modify time 	: 8/4/2016 13:12:35
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <WINDOWS.H>
#include "CXml.h"

//#include <tinyxml>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace

/////////////////////////////////////////////////////////////////////////////////////////
// class release 

/////////////////////////////////////////////////////////////////////////////////////////
// Todo : add application

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CXml
// Full name : CXml::CXml
// Access    : public 
// Brief     : 
// Parameter : const char* szDocName
// Return    : 
// Notes     : 
CXml::CXml(const char* szDocName) :mDoc( szDocName )
{
    if ( mDoc.Error() )
        throw CEXP( "%d:%s", "CXml::CXml()", mDoc.ErrorId(), mDoc.ErrorDesc() );
} // End of function CXml(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CXml
// Full name : CXml::CXml
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CXml::CXml()
{

} // End of function CXml(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CXml
// Full name : CXml::~CXml
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CXml::~CXml()
{

} // End of function ~CXml(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : LoadFile
// Full name : CXml::LoadFile
// Access    : public 
// Brief     : 
// Parameter : const char* szDocName
// Return    : void
// Notes     : 
void CXml::LoadFile(const char* szDocName)
{
    try{
        _VERIFY_( szDocName );
        bool lbRet = mDoc.LoadFile( szDocName );

        if ( mDoc.Error() )
        {
            throw CEXP( "CXml loadFile(%s) failed! Because( %d:%s )", szDocName, mDoc.ErrorId(), mDoc.ErrorDesc() );
        }

    }catch( JL::CException& ex ){
        EXP_TRACK_ADD( ex );
        throw  CEXP_E( ex );
    }catch( CWinSeh& ex ){
        throw CEXP_SEH( ex );
    }catch( std::exception& ex ){
        throw CEXP_CPP( ex );

    }catch( ... ){
        throw CEXP( "Get an unknown exception!" );
    }
} // End of function LoadFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SaveFile
// Full name : CXml::SaveFile
// Access    : public 
// Brief     : 
// Parameter : const char* szDocName
// Return    : void
// Notes     : 
void CXml::SaveFile(const char* szDocName)
{
    _VERIFY_( szDocName );
    bool lbRet = mDoc.SaveFile( szDocName );

    if ( mDoc.Error() )
        throw CEXP( "%d:%s", "CXml::Parse()", mDoc.ErrorId(), mDoc.ErrorDesc() );
} // End of function SaveFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SaveFile
// Full name : CXml::SaveFile
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CXml::SaveFile()
{
    bool lbRet = mDoc.SaveFile( );

    if ( mDoc.Error() )
        throw CEXP( "%d:%s", "CXml::Parse()", mDoc.ErrorId(), mDoc.ErrorDesc() );
} // End of function SaveFile(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Save
// Full name : CXml::Save
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : std::string
// Notes     : 
std::string CXml::Save()
{
    TiXmlPrinter loPrinter;
    mDoc.Accept(&loPrinter);
    return loPrinter.CStr();
} // End of function Save(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Parse
// Full name : CXml::Parse
// Access    : public 
// Brief     : 
// Parameter : const char* szXMLStr
// Return    : void
// Notes     : 
void CXml::Parse(const char* szXMLStr)
{
    _VERIFY_( szXMLStr );
    mDoc.Parse( szXMLStr );

    if ( mDoc.Error() )
    {
        throw CEXP( "%d:%s", mDoc.ErrorId(), mDoc.ErrorDesc() );
    }
} // End of function Parse(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Print
// Full name : CXml::Print
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CXml::Print()
{
    mDoc.Print();
} // End of function Print(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetRoot
// Full name : CXml::GetRoot
// Access    : public 
// Brief     : 
// Parameter : const char* szNodeName
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::GetRoot(const char* szNodeName)
{
    TiXmlElement* lpXE = mDoc.FirstChildElement( szNodeName );
    return lpXE;
} // End of function GetRoot(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetSubNode
// Full name : CXml::GetSubNode
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szNodeName
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::GetSubNode(TiXmlElement* pTiXmlElement, const char* szNodeName)
{
    _VERIFY_2_( pTiXmlElement, szNodeName );
    TiXmlElement* lpXE = (pTiXmlElement->FirstChildElement( szNodeName ));
    return lpXE;
} // End of function GetSubNode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetSubNode
// Full name : CXml::GetSubNode
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::GetSubNode(TiXmlElement* pTiXmlElement)
{
    _VERIFY_( pTiXmlElement );
    TiXmlElement* lpXE = (pTiXmlElement->FirstChildElement());
    return lpXE;
} // End of function GetSubNode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeValue
// Full name : CXml::GetNodeValue
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement
// Return    : const char*
// Notes     : 
const char* CXml::GetNodeValue(const TiXmlElement* pTiXmlElement)
{
    _VERIFY_( pTiXmlElement );
    return pTiXmlElement->Value();
} // End of function GetNodeValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetSubNodes
// Full name : CXml::GetSubNodes
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szNodeName
// Return    : CXml::tVector
// Notes     : 
CXml::tVector CXml::GetSubNodes(TiXmlElement* pTiXmlElement, const char* szNodeName)
{
    _VERIFY_2_( pTiXmlElement, szNodeName );
    tVector loNodes;

    TiXmlElement* lpXE = pTiXmlElement->FirstChildElement( szNodeName );
    while( lpXE!=NULL )
    {
        loNodes.push_back( lpXE );
        lpXE = pTiXmlElement->NextSiblingElement( szNodeName );
    }

    return loNodes;
} // End of function GetSubNodes(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNextNode
// Full name : CXml::GetNextNode
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szNodeName
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::GetNextNode(TiXmlElement* pTiXmlElement, const char* szNodeName)
{
    _VERIFY_2_( pTiXmlElement, szNodeName );
    TiXmlElement* lpXE = (pTiXmlElement->NextSiblingElement( szNodeName ));
    return lpXE;
} // End of function GetNextNode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNextNode
// Full name : CXml::GetNextNode
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::GetNextNode(TiXmlElement* pTiXmlElement)
{
    _VERIFY_( pTiXmlElement );
    TiXmlElement* lpXE = (pTiXmlElement->NextSiblingElement( ));
    return lpXE;
} // End of function GetNextNode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RemoveNode
// Full name : CXml::RemoveNode
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiFNode, TiXmlElement* pTiSNode
// Return    : void
// Notes     : 
void CXml::RemoveNode(TiXmlElement* pTiFNode, TiXmlElement* pTiSNode)
{
    _VERIFY_2_( pTiFNode, pTiSNode );
    pTiFNode->RemoveChild( (TiXmlNode*)(pTiSNode) );
} // End of function RemoveNode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : AddSubNode
// Full name : CXml::AddSubNode
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szNodeName
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::AddSubNode(TiXmlElement* pTiXmlElement, const char* szNodeName)
{
    _VERIFY_2_( pTiXmlElement, szNodeName );
    TiXmlElement* lpXE= new TiXmlElement( szNodeName );
    pTiXmlElement->LinkEndChild( lpXE );
    return lpXE;
} // End of function AddSubNode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : AddSubNodeUnion
// Full name : CXml::AddSubNodeUnion
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szNodeName
// Return    : TiXmlElement*
// Notes     : 
TiXmlElement* CXml::AddSubNodeUnion(TiXmlElement* pTiXmlElement, const char* szNodeName)
{
    _VERIFY_2_( pTiXmlElement, szNodeName );
    TiXmlElement* lpXE = GetSubNode( pTiXmlElement, szNodeName );
    if ( lpXE==NULL )
    {
        lpXE= new TiXmlElement( szNodeName );
        pTiXmlElement->LinkEndChild( lpXE );
    }
    return lpXE;
} // End of function AddSubNodeUnion(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetNodeAttr
// Full name : CXml::SetNodeAttr
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szAttrName, const char* szAttrValue
// Return    : void
// Notes     : 
void CXml::SetNodeAttr(TiXmlElement* pTiXmlElement, const char* szAttrName, const char* szAttrValue)
{
    _VERIFY_3_( pTiXmlElement, szAttrName, szAttrValue );
    pTiXmlElement->SetAttribute( szAttrName, szAttrValue );
} // End of function SetNodeAttr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetNodeAttr
// Full name : CXml::SetNodeAttr
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szAttrName, int iAttrValue
// Return    : void
// Notes     : 
void CXml::SetNodeAttr(TiXmlElement* pTiXmlElement, const char* szAttrName, int iAttrValue)
{
    _VERIFY_2_( pTiXmlElement, szAttrName );
    pTiXmlElement->SetAttribute( szAttrName, iAttrValue );
} // End of function SetNodeAttr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetNodeAttr
// Full name : CXml::SetNodeAttr
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szAttrName, double dAttrValue
// Return    : void
// Notes     : 
void CXml::SetNodeAttr(TiXmlElement* pTiXmlElement, const char* szAttrName, double dAttrValue)
{
    _VERIFY_2_( pTiXmlElement, szAttrName );
    pTiXmlElement->SetDoubleAttribute( szAttrName, dAttrValue );
} // End of function SetNodeAttr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeAttrForS
// Full name : CXml::GetNodeAttrForS
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement, const char* szAttrName
// Return    : char*
// Notes     : 
char* CXml::GetNodeAttrForS(const TiXmlElement* pTiXmlElement, const char* szAttrName)
{
    _VERIFY_2_( pTiXmlElement, szAttrName );
    char* lp = const_cast<char*>(pTiXmlElement->Attribute( szAttrName ));
    return lp;
} // End of function GetNodeAttrForS(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeAttrForStr
// Full name : CXml::GetNodeAttrForStr
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement, const char* szAttrName
// Return    : std::string
// Notes     : 
std::string CXml::GetNodeAttrForStlS(const TiXmlElement* pTiXmlElement, const char* szAttrName)
{
    _VERIFY_2_( pTiXmlElement, szAttrName );
    char* lp = const_cast<char*>(pTiXmlElement->Attribute( szAttrName ));
    if ( lp==NULL )
    {
        return "";
    }
    return lp;
} // End of function GetNodeAttrForStr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeAttrForI
// Full name : CXml::GetNodeAttrForI
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement, const char* szAttrName
// Return    : int
// Notes     : 
int CXml::GetNodeAttrForI(const TiXmlElement* pTiXmlElement, const char* szAttrName)
{
    _VERIFY_2_( pTiXmlElement, szAttrName );
    int liAttrValue = 0;
    pTiXmlElement->Attribute( szAttrName, &liAttrValue );
    return liAttrValue;
} // End of function GetNodeAttrForI(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeAttrForD
// Full name : CXml::GetNodeAttrForD
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement, const char* szAttrName
// Return    : double
// Notes     : 
double CXml::GetNodeAttrForD(const TiXmlElement* pTiXmlElement, const char* szAttrName)
{
    _VERIFY_2_( pTiXmlElement, szAttrName );
    double ldAttrValue = 0;
    pTiXmlElement->Attribute( szAttrName, &ldAttrValue );
    return ldAttrValue;
} // End of function GetNodeAttrForD(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeTxt
// Full name : CXml::GetNodeTxt
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement
// Return    : char*
// Notes     : 
char* CXml::GetNodeTxt(const TiXmlElement* pTiXmlElement)
{
    _VERIFY_( pTiXmlElement );
    char* lpTxt = const_cast<char*>(pTiXmlElement->GetText());
    return lpTxt;
} // End of function GetNodeTxt(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetNodeTxtFotStl
// Full name : CXml::GetNodeTxtFotStl
// Access    : public 
// Brief     : 
// Parameter : const TiXmlElement* pTiXmlElement
// Return    : std::string
// Notes     : 
std::string CXml::GetNodeTxtFotStl(const TiXmlElement* pTiXmlElement)
{
    _VERIFY_( pTiXmlElement );
    char* lpTxt = const_cast<char*>(pTiXmlElement->GetText());
    if ( lpTxt==NULL )
    {
        return "";
    }
    return lpTxt;
} // End of function GetNodeTxtFotStl(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetNodeTxt
// Full name : CXml::SetNodeTxt
// Access    : public 
// Brief     : 
// Parameter : TiXmlElement* pTiXmlElement, const char* szNodeName
// Return    : TiXmlText*
// Notes     : 
TiXmlText* CXml::SetNodeTxt(TiXmlElement* pTiXmlElement, const char* szNodeName)
{
    _VERIFY_2_( pTiXmlElement, szNodeName );
    TiXmlText* lpXE= new TiXmlText( szNodeName );
    pTiXmlElement->Clear();
    pTiXmlElement->LinkEndChild( lpXE );

    return lpXE;
} // End of function SetNodeTxt(...
/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// End of file CXml.cpp
/////////////////////////////////////////////////////////////////////////////////////////