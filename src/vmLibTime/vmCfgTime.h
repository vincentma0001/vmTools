/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmCfgTime.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/18 17:49:59
// Modify time 	: 2020/01/18 17:49:59
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

#ifndef __VM_CFG_TIME_H__
#define __VM_CFG_TIME_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#ifndef   _INC_TIME
#   include <time.h>
#endif // _INC_TIME

// Config files included

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{
namespace vTime{

/////////////////////////////////////////////////////////////////////////////////////////

#define tTimeb                  _timeb
#define tTimet                  time_t

#define tTimeDiv_t              lldiv_t
#define vTimeDiv                lldiv

/////////////////////////////////////////////////////////////////////////////////////////

//#define Y4_MM_DD                vT("%Y4-%MM-%DD")
//#define MM_DD_Y4                vT("%MM-%DD-%Y4")
//#define Y4$MM$DD                vT("%Y4/%MM/%DD")
//#define MM$DD$Y4                vT("%MM/%DD/%Y4")
//#define Y4MMDD                  vT("%Y4%MM%DD")
//#define MMDDY4                  vT("%MM%DD%Y4")
//#define Y2_MM_DD                vT("%Y2-%MM-%DD")
//#define MM_DD_Y2                vT("%MM-%DD-%Y2")
//#define Y2$MM$DD                vT("%MM/%DD/%Y2")
//#define MM$DD$Y2                vT("%MM/%DD/%Y2")
//#define Y2MMDD                  vT("%Y2%MM%DD")
//#define MMDDY2                  vT("%MM%DD%Y2")
//
//#define hh$mm$ss$ms             vT("%hh:%mm:%ss.%ms")
//#define ii$mm$ss$ms             vT("%ii:%mm:%ss.%ms")
//#define AP_ii$mm$ss$ms          vT("%AP %ii:%mm:%ss.%ms")
//#define ii$mm$ss$ms_AP          vT("%ii:%mm:%ss.%ms %AP")
//#define hh$mm$ss                vT("%hh:%mm:%ss")
//#define ii$mm$ss                vT("%ii:%mm:%ss")
//#define AP_ii$mm$ss             vT("%AP %ii:%mm:%ss")
//#define ii$mm$ss_AP             vT("%ii:%mm:%ss %AP")
//
//#define Y4_MM_DD_hh$mm$ss$ms    vT("%Y4-%MM-%DD %hh:%mm:%ss.%ms")
//#define MM_DD_Y4_hh$mm$ss$ms    vT("%MM-%DD-%Y4 %hh:%mm:%ss.%ms")
//#define Y2_MM_DD_hh$mm$ss$ms    vT("%Y2-%MM-%DD %hh:%mm:%ss.%ms")
//#define MM_DD_Y2_hh$mm$ss$ms    vT("%MM-%DD-%Y2 %hh:%mm:%ss.%ms")
//#define Y4$MM$DD_hh$mm$ss$ms    vT("%Y4/%MM/%DD %hh:%mm:%ss.%ms")
//#define MM$DD$Y4_hh$mm$ss$ms    vT("%MM/%DD/%Y4 %hh:%mm:%ss.%ms")
//#define Y2$MM$DD_hh$mm$ss$ms    vT("%Y2/%MM/%DD %hh:%mm:%ss.%ms")
//#define MM$DD$Y2_hh$mm$ss$ms    vT("%MM/%DD/%Y2 %hh:%mm:%ss.%ms")
//#define Y4_MM_DD_hh$mm$ss       vT("%Y4-%MM-%DD %hh:%mm:%ss")
//#define MM_DD_Y4_hh$mm$ss       vT("%MM-%DD-%Y4 %hh:%mm:%ss")
//#define Y2_MM_DD_hh$mm$ss       vT("%Y2-%MM-%DD %hh:%mm:%ss")
//#define MM_DD_Y2_hh$mm$ss       vT("%MM-%DD-%Y2 %hh:%mm:%ss")
//#define Y4$MM$DD_hh$mm$ss       vT("%Y4/%MM/%DD %hh:%mm:%ss")
//#define MM$DD$Y4_hh$mm$ss       vT("%MM/%DD/%Y4 %hh:%mm:%ss")
//#define Y2$MM$DD_hh$mm$ss       vT("%Y2/%MM/%DD %hh:%mm:%ss")
//#define MM$DD$Y2_hh$mm$ss       vT("%MM/%DD/%Y2 %hh:%mm:%ss")

const tchar*  Y4_MM_DD               = vT("%Y4-%MM-%DD");
const tchar*  MM_DD_Y4               = vT("%MM-%DD-%Y4");
const tchar*  Y4$MM$DD               = vT("%Y4/%MM/%DD");
const tchar*  MM$DD$Y4               = vT("%MM/%DD/%Y4");
const tchar*  Y4MMDD                 = vT("%Y4%MM%DD");
const tchar*  MMDDY4                 = vT("%MM%DD%Y4");
const tchar*  Y2_MM_DD               = vT("%Y2-%MM-%DD");
const tchar*  MM_DD_Y2               = vT("%MM-%DD-%Y2");
const tchar*  Y2$MM$DD               = vT("%MM/%DD/%Y2");
const tchar*  MM$DD$Y2               = vT("%MM/%DD/%Y2");
const tchar*  Y2MMDD                 = vT("%Y2%MM%DD");
const tchar*  MMDDY2                 = vT("%MM%DD%Y2");

const tchar*  hh$mm$ss$ms            = vT("%hh:%mm:%ss.%ms");
const tchar*  ii$mm$ss$ms            = vT("%ii:%mm:%ss.%ms");
const tchar*  AP_ii$mm$ss$ms         = vT("%AP %ii:%mm:%ss.%ms");
const tchar*  ii$mm$ss$ms_AP         = vT("%ii:%mm:%ss.%ms %AP");
const tchar*  hh$mm$ss               = vT("%hh:%mm:%ss");
const tchar*  ii$mm$ss               = vT("%ii:%mm:%ss");
const tchar*  AP_ii$mm$ss            = vT("%AP %ii:%mm:%ss");
const tchar*  ii$mm$ss_AP            = vT("%ii:%mm:%ss %AP");

const tchar*  Y4_MM_DD_hh$mm$ss$ms   = vT("%Y4-%MM-%DD %hh:%mm:%ss.%ms");
const tchar*  MM_DD_Y4_hh$mm$ss$ms   = vT("%MM-%DD-%Y4 %hh:%mm:%ss.%ms");
const tchar*  Y2_MM_DD_hh$mm$ss$ms   = vT("%Y2-%MM-%DD %hh:%mm:%ss.%ms");
const tchar*  MM_DD_Y2_hh$mm$ss$ms   = vT("%MM-%DD-%Y2 %hh:%mm:%ss.%ms");
const tchar*  Y4$MM$DD_hh$mm$ss$ms   = vT("%Y4/%MM/%DD %hh:%mm:%ss.%ms");
const tchar*  MM$DD$Y4_hh$mm$ss$ms   = vT("%MM/%DD/%Y4 %hh:%mm:%ss.%ms");
const tchar*  Y2$MM$DD_hh$mm$ss$ms   = vT("%Y2/%MM/%DD %hh:%mm:%ss.%ms");
const tchar*  MM$DD$Y2_hh$mm$ss$ms   = vT("%MM/%DD/%Y2 %hh:%mm:%ss.%ms");
const tchar*  Y4_MM_DD_hh$mm$ss      = vT("%Y4-%MM-%DD %hh:%mm:%ss");
const tchar*  MM_DD_Y4_hh$mm$ss      = vT("%MM-%DD-%Y4 %hh:%mm:%ss");
const tchar*  Y2_MM_DD_hh$mm$ss      = vT("%Y2-%MM-%DD %hh:%mm:%ss");
const tchar*  MM_DD_Y2_hh$mm$ss      = vT("%MM-%DD-%Y2 %hh:%mm:%ss");
const tchar*  Y4$MM$DD_hh$mm$ss      = vT("%Y4/%MM/%DD %hh:%mm:%ss");
const tchar*  MM$DD$Y4_hh$mm$ss      = vT("%MM/%DD/%Y4 %hh:%mm:%ss");
const tchar*  Y2$MM$DD_hh$mm$ss      = vT("%Y2/%MM/%DD %hh:%mm:%ss");
const tchar*  MM$DD$Y2_hh$mm$ss      = vT("%MM/%DD/%Y2 %hh:%mm:%ss");




/////////////////////////////////////////////////////////////////////////////////////////

#define vDays(x)    vm::vTime::CDays(x)
#define vHours(x)   vm::vTime::CHours(x)
#define vMinutes(x) vm::vTime::CMinutes(x)

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CMinutes : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CMinutes
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :

// Seconds of a hour             60
#define vSecondOfaMinutes        60
// Millie Seconds of a hour      60*1000
#define vMillieSecondOfaMinutes  60000

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CMinutes() :mlMinutes(0) {};
    explicit CMinutes(long ulMinutes) : mlMinutes(ulMinutes) { };
    // Destruct define
    virtual ~CMinutes(){};
    
public:
    // Copy construct define
    CMinutes(const CMinutes& obj) { *this = obj; };
    // Assignment define
    CMinutes& operator = (const CMinutes& obj) { mlMinutes = obj.mlMinutes; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    long mlMinutes;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    tTimet    toSeconds() { return mlMinutes * vSecondOfaMinutes; };
    long long toMillieSeconds() { return (long long)(mlMinutes*vMillieSecondOfaMinutes); };

}; // End of class Minute
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CHours : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CHours
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :

// Seconds of a hour          60*60
#define vSecondOfaHour        3600
// Millie Seconds of a hour   60*60*1000
#define vMillieSecondOfaHour  3600000

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CHours( long lHours ):mlHours(lHours){};
    // Destruct define
    virtual ~CHours(){};
    
public:
    // Copy construct define
    CHours(const CHours& obj) { *this = obj; };
    // Assignment define
    CHours& operator = (const CHours& obj) { mlHours = obj.mlHours; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    long mlHours;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    tTimet    toSeconds() { return mlHours * vSecondOfaHour; };
    long long toMillieSeconds() { return (long long)(mlHours*vMillieSecondOfaHour); };

}; // End of class CHours
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CDays : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CDays
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :

// Seconds of a day 24*60*60
#define vSecondOfaDay        86400
// Millie Seconds of a day 24*60*60*1000
#define vMillieSecondOfaDay  86400000

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CDays():mlDays(0) {};
    explicit CDays( long ulDays ) : mlDays(ulDays) { };
    // Destruct define
    virtual ~CDays(){};
    
public:
    // Copy construct define
    CDays(const CDays& obj){ *this = obj; };
    // Assignment define
    CDays& operator = ( const CDays& obj ){ mlDays = obj.mlDays; };
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    long  mlDays;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    tTimet    toSeconds() const { return mlDays*vSecondOfaDay; };
    long long toMillieSeconds() const { return (long long)(mlDays*vMillieSecondOfaDay); };

}; // End of class CDay
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vTime
/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_CFG_TIME_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmCfgTime.h
/////////////////////////////////////////////////////////////////////////////////////////