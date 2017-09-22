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
#define RET_CMYSQL_SUCCESS                          0x00000000               // ���سɹ�
#define RET_CMYSQL_FAILED                           0x00000001               // ����ʧ��
#define RET_CMYSQL_EXCEPTION                        0xffffffff               // �����쳣

#define RET_CMYSQL_INIT_FAILED                      0x00000002               // ��ʼ��ʧ��
#define RET_CMYSQL_INIT_EXP                         0x00010002               // ��ʼ���쳣
#define RET_CMYSQL_SELECTDB_FAILED                  0x00000003               // �������ݿ����ʧ��
#define RET_CMYSQL_CONNECT_FAILED                   0x00000004               // ִ�����Ӳ���ʧ��
#define RET_CMYSQL_QUERY_FAILED                     0x00000005               // ִ��SQL������ʧ��
#define RET_CMYSQL_PING_FAILED                      0x00000006               // ִ�����Ӽ�����ʧ��
#define RET_CMYSQL_RECONNECT_FAILED                 0x00000007               // �����������ݿ�ʧ��
#define RET_CMYSQL_SETCHAR_FAILED                   0x00000008               // �����ַ���ʧ��
#define RET_CMYSQL_GETRET_STORN_FAILED              0x00000009               // ��ȡMYSQL_RES*ʧ��
#define RET_CMYSQL_GETRET_DIFFNUM                   0x00000010               // ������õ��������ϵͳ�л�õĲ�ͬ
#define RET_CMYSQL_EXECUT_FAILED                    0x00000011               // ִ��MYSQL��ѯʧ��

///////////////////////////////////////////////////////////////////////////////////////////
#define EXP_CMYSQL_CPP                              0x00010001                  // CPP�쳣
#define EXP_CMYSQL_UNKNOWN                          0x00010002                  // δ֪�쳣

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYSQLERRDEF_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlErrDef.h
/////////////////////////////////////////////////////////////////////////////////////////