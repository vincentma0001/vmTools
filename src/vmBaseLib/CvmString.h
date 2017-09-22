/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CvmString.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 7/12/2015 21:43:40
// Modify time 	: 7/12/2015 21:43:40
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CVMSTRING_H__
#define __CVMSTRING_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace

/////////////////////////////////////////////////////////////////////////////////////////
// class release 

// Todo : ## add application ##
 /////////////////////////////////////////////////////////////////////////////////////
 //
 // class define : CvmString
 //        Notes : ## add class brief here ##
 //
 /////////////////////////////////////////////////////////////////////////////////////
 class CvmString
 {
 /////////////////////////////////////////////////////////////////////////////////////
 // data members :
 private:
     const char* m_pSrc;
 
 
 /////////////////////////////////////////////////////////////////////////////////////
 // interface define :
 
 /////////////////////////////////////////////////////////////////////////////////////
 // functions :
 public:
 	CvmString(){};			// Construct define
 	~CvmString(){};			// Destruct define
 private:
     CvmString( const CvmString& cvmString ){};
     CvmString& operator = ( CvmString& cvmString ){}

public:
    CvmString& operator >> ( int& iVal )
    {
        iVal = ::atoi( m_pSrc );
    }
    CvmString& operator >> ( long& iVal )
    {
        iVal = ::atol( m_pSrc );
    }
    CvmString& operator >> ( short& iVal )
    {
        iVal = ::atol( m_pSrc );
    }
 
 protected:
 
 }; // End of class CvmString
 /////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CVMSTRING_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CvmString.h
/////////////////////////////////////////////////////////////////////////////////////////