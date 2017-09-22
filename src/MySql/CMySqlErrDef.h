/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlErrDef.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 7/12/2015 8:17:07
// Modify time 	: 7/12/2015 8:17:07
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
#endif

#ifndef __CMYSQLERRDEF_H__
#define __CMYSQLERRDEF_H__

/////////////////////////////////////////////////////////////////////////////////////////
// macro definition
#define RET_CMYSQL_SUCCESS                          0x00000000               // 返回成功
#define RET_CMYSQL_FAILED                           0x00000001               // 返回失败
#define RET_CMYSQL_EXCEPTION                        0xffffffff               // 返回异常

#define RET_CMYSQL_INIT_FAILED                      0x00000002               // 初始化失败
#define RET_CMYSQL_INIT_EXP                         0x00010002               // 初始化异常
#define RET_CMYSQL_SELECTDB_FAILED                  0x00000003               // 更改数据库操作失败
#define RET_CMYSQL_CONNECT_FAILED                   0x00000004               // 执行连接操作失败
#define RET_CMYSQL_QUERY_FAILED                     0x00000005               // 执行SQL语句操作失败
#define RET_CMYSQL_PING_FAILED                      0x00000006               // 执行连接检测操作失败
#define RET_CMYSQL_RECONNECT_FAILED                 0x00000007               // 重新连接数据库失败
#define RET_CMYSQL_SETCHAR_FAILED                   0x00000008               // 设置字符集失败
#define RET_CMYSQL_GETRET_STORN_FAILED              0x00000009               // 获取MYSQL_RES*失败
#define RET_CMYSQL_GETRET_DIFFNUM                   0x00000010               // 分析获得的行数与从系统中获得的不同
#define RET_CMYSQL_EXECUT_FAILED                    0x00000011               // 执行MYSQL查询失败

///////////////////////////////////////////////////////////////////////////////////////////
#define EXP_CMYSQL_CPP                              0x00010001                  // CPP异常
#define EXP_CMYSQL_UNKNOWN                          0x00010002                  // 未知异常

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYSQLERRDEF_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlErrDef.h
/////////////////////////////////////////////////////////////////////////////////////////