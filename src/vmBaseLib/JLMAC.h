// JLMAC.h: interface for the JLMAC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JLMAC_H__03B92500_9CB7_47D0_BC5D_0B2E5B05D1D8__INCLUDED_)
#define AFX_JLMAC_H__03B92500_9CB7_47D0_BC5D_0B2E5B05D1D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef   _DES_H
#define   _DES_H


#ifndef   ENCRYPT
#define   ENCRYPT  0         /* DES 方向 */
#define   DECRYPT  1
#endif

#ifndef   STAND
#define   STAND    0         /* MAC 标准 */
#define   BPI      1
#endif

#endif

#ifndef uint8
#define uint8  unsigned char
#endif

#ifndef uint32
#define uint32 unsigned long int
#endif

typedef struct
{
    uint32 esk[32];     /* DES encryption subkeys */
    uint32 dsk[32];     /* DES decryption subkeys */
}
des_context;

typedef struct
{
    uint32 esk[96];     /* Triple-DES encryption subkeys */
    uint32 dsk[96];     /* Triple-DES decryption subkeys */
}
des3_context;


//extern JL_MAC_API int nJL_MAC;
 
class JLMAC  
{
public:
	JLMAC();
	virtual ~JLMAC();

public:

	// SM4????
	// ????
	void EncryptSM4( char* pszOutBuf, const unsigned int ulOutBufLen, const char* pszMainKey, const char* pszWorkingKey, const char* pszIV,  bool bIsNeedConvert1, bool bIsNeedConvert2 );
	// ?????
	void AuthenticSM4( char* pszOutBuf, const unsigned int ulOutBufLen, const char* pszWorkKey, const char* pszIV, bool bIsNeedConvert1, bool bIsNeedConvert2 );
	// ??MAC?
	unsigned int GetMacSM4( PBYTE pMacString, UINT iMacStringLen, const char* pszMackey, const char* pszIV, PBYTE pszMacValue, UINT iMacLen );

public:
	int  fnJL_MAC(void);
	int  GetMAC(unsigned char *,int ,unsigned char * ,unsigned char * ,unsigned char);
	void DES(unsigned char *,unsigned char *,unsigned char *,unsigned char );
	int  des_set_key( des_context *ctx, uint8 key[8] );
	void des_encrypt( des_context *ctx, uint8 input[8], uint8 output[8] );
	void des_decrypt( des_context *ctx, uint8 input[8], uint8 output[8] );

	int  des3_set_2keys( des3_context *ctx, uint8 key1[8], uint8 key2[8] );
	int  des3_set_3keys( des3_context *ctx, uint8 key1[8], uint8 key2[8],
											uint8 key3[8] );

	void des3_encrypt( des3_context *ctx, uint8 input[8], uint8 output[8] );
	void des3_decrypt( des3_context *ctx, uint8 input[8], uint8 output[8] );

	void MY_set_key(unsigned char *key1, unsigned char *key2);
	int MY_3des( uint8 input[8], uint8 output[8] ,int TYPE);
	void Stgstr( uint8 input1[8], uint8 input2[8], uint8 output[8] );
	void GetDesMAC( unsigned char *pack, unsigned char *mac, int len, unsigned char *key );
	void Get3DesMAC( unsigned char *pack, unsigned char *mac, int len, 
	unsigned char *key1, unsigned char *key2 );
	int des_main_ks( uint32 SK[32], uint8 key[8] );
	void des_crypt( uint32 SK[32], uint8 input[8], uint8 output[8] );
	void des3_crypt( uint32 SK[96], uint8 input[8], uint8 output[8]);
	int MY_des( uint8 input[8], uint8 output[8] ,int TYPE);
	void MakeXorOpration(UCHAR *pInput1 , UCHAR *pInput2, int length, UCHAR *pOutput);

	void Do_XOR(unsigned char *dest,unsigned char *source,int size);
	static void s_box(char *aa,char *bb);
	static void expand0(unsigned char *in,char *out);
	static void setkeystar(unsigned char bits[64]);
	static void encrypt0(unsigned char *text,unsigned char *mtext);
	static void discrypt0(unsigned char *mtext,unsigned char *text);
	static void compress0(char *out,unsigned char *in);
	static void compress016(char *out,unsigned char *in);
	static void LS(char *bits,char *buffer,int count);
	static void son(char *cc,char *dd,char *kk);
	static void ip(unsigned char *text,char *ll,char *rr);
	static void _ip(unsigned char *text,char *ll,char *rr);
	static void F(int n,char *ll,char *rr,char *LL,char *RR);
    void HostDes(unsigned char *card_no,unsigned char *work_key,unsigned char *pin,unsigned char *encrypt_pin,unsigned char flag);
	void DSP_2_HEX(char *dsp,char *hex,int count);
	void HEX_2_DSP(char *hex,char *dsp,int count);
	int JL_3DES( uint8 input[8], uint8 output[8] ,int TYPE);
	void MY_set_3DESkey(unsigned char *key1);

public:
	static unsigned char C[17][28];
	static unsigned char D[17][28];
	static unsigned char K[17][48];
	static unsigned char DES3_keys[3][8];
	static unsigned char c;
	static unsigned char ch1;
	static uint32 SB1[64];
	static uint32 SB2[64];
	static uint32 SB3[64];
	static uint32 SB4[64];
	static uint32 SB5[64];
	static uint32 SB6[64];
	static uint32 SB7[64];
	static uint32 SB8[64];
	static uint32 LHs[16];
	static uint32 RHs[16];
    unsigned char key_3DES[16];
	
	
};

extern JLMAC gJLMac;

#endif // !defined(AFX_JLMAC_H__03B92500_9CB7_47D0_BC5D_0B2E5B05D1D8__INCLUDED_)
