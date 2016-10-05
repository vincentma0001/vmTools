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
// ������VC6һ�°汾��ʹ��STL��list,map�ȶ������C4786����
#pragma warning( disable:4786 )
#endif 

/////////////////////////////////////////////////////////////////////////////////////////
// ͨ�ö���
// #define RET_CMYSQL_SUCCESS                          0x00000000               // ���سɹ�
const char* GCP_RET_CMYSQL_SUCCESS                  = "���óɹ�";
// #define RET_CMYSQL_FAILED                           0x00000001               // ����ʧ��
const char* GCP_RET_CMYSQL_FAILED                   = "����ʧ��";
// #define RET_CMYSQL_EXCEPTION                        0xffffffff               // �����쳣
const char* GCP_RET_CMYSQL_EXCEPTION                = "�����쳣";

/////////////////////////////////////////////////////////////////////////////////////////
// �쳣����
// #define EXP_CMYSQL_CPP                              0x10000001               // CPP�쳣
// #define EXP_CMYSQL_UNKNOWN                          0x10000002               // δ֪�쳣

/////////////////////////////////////////////////////////////////////////////////////////
// ��ʼ������ֵ
// #define RET_CMYSQL_INIT_FAILED                      0x00010001               // ��ʼ��ʧ��
const char* GCP_RET_CMYSQL_INIT_FAILED              = "��ʼ��ʧ��";
// #define RET_CMYSQL_INIT_EXP                         0x00010002               // ��ʼ���쳣
const char* GCP_RET_CMYSQL_INIT_EXP                 = "��ʼ���쳣";
// #define RET_CMYSQL_INIT_LOGGER_FAILED               0x00010003               // ��ʼ����־ģ��ʧ��
const char* GCP_RET_CMYSQL_INIT_LOGGER_FAILED       = "��ʼ����־ģ��ʧ��";
// #define RET_CMYSQL_INIT_LOGGER_EXP                  0x00010004               // ��ʼ����־ģ���쳣
const char* GCP_RET_CMYSQL_INIT_LOGGER_EXP          = "��ʼ����־ģ���쳣";

/////////////////////////////////////////////////////////////////////////////////////////
// �������ݿ����
// #define RET_CMYSQL_SELECTDB_FAILED                  0x00020001               // �������ݿ����ʧ��
const char* GCP_RET_CMYSQL_SELECTDB_FAILED          = "�������ݿ�ʧ��";

/////////////////////////////////////////////////////////////////////////////////////////
// MYSQL���÷���
// #define RET_CMYSQL_SETCHAR_FAILED                   0x00030001               // �����ַ���ʧ��
const char* GCP_RET_CMYSQL_SETCHAR_FAILED           = "�����ַ���ʧ��";

/////////////////////////////////////////////////////////////////////////////////////////
// �������ݿ����
// #define RET_CMYSQL_PING_FAILED                      0x00040001               // ִ�����Ӽ�����ʧ��
const char* GCP_RET_CMYSQL_PING_FAILED              = "ִ�����Ӽ��ʧ��";
// #define RET_CMYSQL_RECONNECT_FAILED                 0x00040002               // �����������ݿ�ʧ��
const char* GCP_RET_CMYSQL_RECONNECT_FAILED         = "�����������ݿ�ʧ��";
// #define RET_CMYSQL_CONNECT_FAILED                   0x00040003               // ִ�����Ӳ���ʧ��
const char* GCP_RET_CMYSQL_CONNECT_FAILED           = "�������ݿ�ʧ��";


/////////////////////////////////////////////////////////////////////////////////////////
// ���ݿ����
// #define RET_CMYSQL_QUERY_FAILED                     0x00050001               // ִ��SQL������ʧ��
const char* GCP_RET_CMYSQL_QUERY_FAILED             = "ִ��SQL���ʧ��";

/////////////////////////////////////////////////////////////////////////////////////////
// ���ݽ��������
// #define RET_CMYSQL_GETRET_STORN_FAILED              0x00060001               // ��ȡMYSQL_RES*ʧ��
const char* GCP_RET_CMYSQL_GETRET_STORN_FAILED      = "��ȡ�����ʧ��";
// #define RET_CMYSQL_GETRET_DIFFNUM                   0x00060002               // ����������е�����������ݿ��л�ȡ�Ĳ�ͬ
const char* GCP_RET_CMYSQL_GETRET_DIFFNUM           = "����������е�����������ݿ��л�ȡ�Ĳ�ͬ";

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlErrDef.cpp
/////////////////////////////////////////////////////////////////////////////////////////