/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlErrDef.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 14/12/2015 14:04:43
// Modify time 	: 14/12/2015 14:04:43
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition

#if( _MSC_VER <= 1200 )
// 忽略在VC6一下版本中使用STL的list,map等对象产生C4786警告
#pragma warning( disable:4786 )
#endif 

/////////////////////////////////////////////////////////////////////////////////////////
// 通用定义
// #define RET_CMYSQL_SUCCESS                          0x00000000               // 返回成功
const char* GCP_RET_CMYSQL_SUCCESS                  = "调用成功";
// #define RET_CMYSQL_FAILED                           0x00000001               // 返回失败
const char* GCP_RET_CMYSQL_FAILED                   = "调用失败";
// #define RET_CMYSQL_EXCEPTION                        0xffffffff               // 返回异常
const char* GCP_RET_CMYSQL_EXCEPTION                = "调用异常";

/////////////////////////////////////////////////////////////////////////////////////////
// 异常类型
// #define EXP_CMYSQL_CPP                              0x10000001               // CPP异常
// #define EXP_CMYSQL_UNKNOWN                          0x10000002               // 未知异常

/////////////////////////////////////////////////////////////////////////////////////////
// 初始化返回值
// #define RET_CMYSQL_INIT_FAILED                      0x00010001               // 初始化失败
const char* GCP_RET_CMYSQL_INIT_FAILED              = "初始化失败";
// #define RET_CMYSQL_INIT_EXP                         0x00010002               // 初始化异常
const char* GCP_RET_CMYSQL_INIT_EXP                 = "初始化异常";
// #define RET_CMYSQL_INIT_LOGGER_FAILED               0x00010003               // 初始化日志模块失败
const char* GCP_RET_CMYSQL_INIT_LOGGER_FAILED       = "初始化日志模块失败";
// #define RET_CMYSQL_INIT_LOGGER_EXP                  0x00010004               // 初始化日志模块异常
const char* GCP_RET_CMYSQL_INIT_LOGGER_EXP          = "初始化日志模块异常";

/////////////////////////////////////////////////////////////////////////////////////////
// 更改数据库操作
// #define RET_CMYSQL_SELECTDB_FAILED                  0x00020001               // 更改数据库操作失败
const char* GCP_RET_CMYSQL_SELECTDB_FAILED          = "更新数据库失败";

/////////////////////////////////////////////////////////////////////////////////////////
// MYSQL设置返回
// #define RET_CMYSQL_SETCHAR_FAILED                   0x00030001               // 设置字符集失败
const char* GCP_RET_CMYSQL_SETCHAR_FAILED           = "设置字符集失败";

/////////////////////////////////////////////////////////////////////////////////////////
// 连接数据库操作
// #define RET_CMYSQL_PING_FAILED                      0x00040001               // 执行连接检测操作失败
const char* GCP_RET_CMYSQL_PING_FAILED              = "执行连接检测失败";
// #define RET_CMYSQL_RECONNECT_FAILED                 0x00040002               // 重新连接数据库失败
const char* GCP_RET_CMYSQL_RECONNECT_FAILED         = "重新连接数据库失败";
// #define RET_CMYSQL_CONNECT_FAILED                   0x00040003               // 执行连接操作失败
const char* GCP_RET_CMYSQL_CONNECT_FAILED           = "连接数据库失败";


/////////////////////////////////////////////////////////////////////////////////////////
// 数据库操作
// #define RET_CMYSQL_QUERY_FAILED                     0x00050001               // 执行SQL语句操作失败
const char* GCP_RET_CMYSQL_QUERY_FAILED             = "执行SQL语句失败";

/////////////////////////////////////////////////////////////////////////////////////////
// 数据结果集操作
// #define RET_CMYSQL_GETRET_STORN_FAILED              0x00060001               // 获取MYSQL_RES*失败
const char* GCP_RET_CMYSQL_GETRET_STORN_FAILED      = "获取结果集失败";
// #define RET_CMYSQL_GETRET_DIFFNUM                   0x00060002               // 分析结果集中的行数与从数据库中获取的不同
const char* GCP_RET_CMYSQL_GETRET_DIFFNUM           = "分析结果集中的行数与从数据库中获取的不同";

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlErrDef.cpp
/////////////////////////////////////////////////////////////////////////////////////////