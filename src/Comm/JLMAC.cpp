// JLMAC.cpp: implementation of the JLMAC class.
//
//////////////////////////////////////////////////////////////////////

#pragma comment( lib,"jlcrypt.lib" )

#include "../stdafx.h"
#include "../CResponseServer.h"
#include "JLMAC.h"
#include "Function.h"
#include <jlcrypt.h>
#include <string.h>

#include <exception>
#include <STRING>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

JLMAC gJLMac;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define GET_UINT32(n,b,i)                       \
{                                               \
    (n) = ( (uint32) (b)[(i)    ] << 24 )       \
        | ( (uint32) (b)[(i) + 1] << 16 )       \
        | ( (uint32) (b)[(i) + 2] <<  8 )       \
        | ( (uint32) (b)[(i) + 3]       );      \
}

#define PUT_UINT32(n,b,i)                       \
{                                               \
    (b)[(i)    ] = (uint8) ( (n) >> 24 );       \
    (b)[(i) + 1] = (uint8) ( (n) >> 16 );       \
    (b)[(i) + 2] = (uint8) ( (n) >>  8 );       \
    (b)[(i) + 3] = (uint8) ( (n)       );       \
}

/* Initial Permutation macro */

#define DES_IP(X,Y)                                             \
{                                                               \
    T = ((X >>  4) ^ Y) & 0x0F0F0F0F; Y ^= T; X ^= (T <<  4);   \
    T = ((X >> 16) ^ Y) & 0x0000FFFF; Y ^= T; X ^= (T << 16);   \
    T = ((Y >>  2) ^ X) & 0x33333333; X ^= T; Y ^= (T <<  2);   \
    T = ((Y >>  8) ^ X) & 0x00FF00FF; X ^= T; Y ^= (T <<  8);   \
    Y = ((Y << 1) | (Y >> 31)) & 0xFFFFFFFF;                    \
    T = (X ^ Y) & 0xAAAAAAAA; Y ^= T; X ^= T;                   \
    X = ((X << 1) | (X >> 31)) & 0xFFFFFFFF;                    \
}

/* Final Permutation macro */

#define DES_FP(X,Y)                                             \
{                                                               \
    X = ((X << 31) | (X >> 1)) & 0xFFFFFFFF;                    \
    T = (X ^ Y) & 0xAAAAAAAA; X ^= T; Y ^= T;                   \
    Y = ((Y << 31) | (Y >> 1)) & 0xFFFFFFFF;                    \
    T = ((Y >>  8) ^ X) & 0x00FF00FF; X ^= T; Y ^= (T <<  8);   \
    T = ((Y >>  2) ^ X) & 0x33333333; X ^= T; Y ^= (T <<  2);   \
    T = ((X >> 16) ^ Y) & 0x0000FFFF; Y ^= T; X ^= (T << 16);   \
    T = ((X >>  4) ^ Y) & 0x0F0F0F0F; Y ^= T; X ^= (T <<  4);   \
}

/* DES round macro */

#define DES_ROUND(X,Y)                          \
{                                               \
    T = *SK++ ^ X;                              \
    Y ^= SB8[ (T      ) & 0x3F ] ^              \
         SB6[ (T >>  8) & 0x3F ] ^              \
         SB4[ (T >> 16) & 0x3F ] ^              \
         SB2[ (T >> 24) & 0x3F ];               \
                                                \
    T = *SK++ ^ ((X << 28) | (X >> 4));         \
    Y ^= SB7[ (T      ) & 0x3F ] ^              \
         SB5[ (T >>  8) & 0x3F ] ^              \
         SB3[ (T >> 16) & 0x3F ] ^              \
         SB1[ (T >> 24) & 0x3F ];               \
}

unsigned char JLMAC::C[17][28]={0};
unsigned char JLMAC::D[17][28]={0};
unsigned char JLMAC::K[17][48]={0};
unsigned char JLMAC::DES3_keys[3][8] =
{
    { 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31 },
    { 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32 },
    { 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30 },

};
uint32 JLMAC:: SB1[64] =
{
    0x01010400, 0x00000000, 0x00010000, 0x01010404,
    0x01010004, 0x00010404, 0x00000004, 0x00010000,
    0x00000400, 0x01010400, 0x01010404, 0x00000400,
    0x01000404, 0x01010004, 0x01000000, 0x00000004,
    0x00000404, 0x01000400, 0x01000400, 0x00010400,
    0x00010400, 0x01010000, 0x01010000, 0x01000404,
    0x00010004, 0x01000004, 0x01000004, 0x00010004,
    0x00000000, 0x00000404, 0x00010404, 0x01000000,
    0x00010000, 0x01010404, 0x00000004, 0x01010000,
    0x01010400, 0x01000000, 0x01000000, 0x00000400,
    0x01010004, 0x00010000, 0x00010400, 0x01000004,
    0x00000400, 0x00000004, 0x01000404, 0x00010404,
    0x01010404, 0x00010004, 0x01010000, 0x01000404,
    0x01000004, 0x00000404, 0x00010404, 0x01010400,
    0x00000404, 0x01000400, 0x01000400, 0x00000000,
    0x00010004, 0x00010400, 0x00000000, 0x01010004
};

uint32 JLMAC::SB2[64] =
{
    0x80108020, 0x80008000, 0x00008000, 0x00108020,
    0x00100000, 0x00000020, 0x80100020, 0x80008020,
    0x80000020, 0x80108020, 0x80108000, 0x80000000,
    0x80008000, 0x00100000, 0x00000020, 0x80100020,
    0x00108000, 0x00100020, 0x80008020, 0x00000000,
    0x80000000, 0x00008000, 0x00108020, 0x80100000,
    0x00100020, 0x80000020, 0x00000000, 0x00108000,
    0x00008020, 0x80108000, 0x80100000, 0x00008020,
    0x00000000, 0x00108020, 0x80100020, 0x00100000,
    0x80008020, 0x80100000, 0x80108000, 0x00008000,
    0x80100000, 0x80008000, 0x00000020, 0x80108020,
    0x00108020, 0x00000020, 0x00008000, 0x80000000,
    0x00008020, 0x80108000, 0x00100000, 0x80000020,
    0x00100020, 0x80008020, 0x80000020, 0x00100020,
    0x00108000, 0x00000000, 0x80008000, 0x00008020,
    0x80000000, 0x80100020, 0x80108020, 0x00108000
};

uint32 JLMAC::SB3[64] =
{
    0x00000208, 0x08020200, 0x00000000, 0x08020008,
    0x08000200, 0x00000000, 0x00020208, 0x08000200,
    0x00020008, 0x08000008, 0x08000008, 0x00020000,
    0x08020208, 0x00020008, 0x08020000, 0x00000208,
    0x08000000, 0x00000008, 0x08020200, 0x00000200,
    0x00020200, 0x08020000, 0x08020008, 0x00020208,
    0x08000208, 0x00020200, 0x00020000, 0x08000208,
    0x00000008, 0x08020208, 0x00000200, 0x08000000,
    0x08020200, 0x08000000, 0x00020008, 0x00000208,
    0x00020000, 0x08020200, 0x08000200, 0x00000000,
    0x00000200, 0x00020008, 0x08020208, 0x08000200,
    0x08000008, 0x00000200, 0x00000000, 0x08020008,
    0x08000208, 0x00020000, 0x08000000, 0x08020208,
    0x00000008, 0x00020208, 0x00020200, 0x08000008,
    0x08020000, 0x08000208, 0x00000208, 0x08020000,
    0x00020208, 0x00000008, 0x08020008, 0x00020200
};

uint32 JLMAC::SB4[64] =
{
    0x00802001, 0x00002081, 0x00002081, 0x00000080,
    0x00802080, 0x00800081, 0x00800001, 0x00002001,
    0x00000000, 0x00802000, 0x00802000, 0x00802081,
    0x00000081, 0x00000000, 0x00800080, 0x00800001,
    0x00000001, 0x00002000, 0x00800000, 0x00802001,
    0x00000080, 0x00800000, 0x00002001, 0x00002080,
    0x00800081, 0x00000001, 0x00002080, 0x00800080,
    0x00002000, 0x00802080, 0x00802081, 0x00000081,
    0x00800080, 0x00800001, 0x00802000, 0x00802081,
    0x00000081, 0x00000000, 0x00000000, 0x00802000,
    0x00002080, 0x00800080, 0x00800081, 0x00000001,
    0x00802001, 0x00002081, 0x00002081, 0x00000080,
    0x00802081, 0x00000081, 0x00000001, 0x00002000,
    0x00800001, 0x00002001, 0x00802080, 0x00800081,
    0x00002001, 0x00002080, 0x00800000, 0x00802001,
    0x00000080, 0x00800000, 0x00002000, 0x00802080
};

uint32 JLMAC:: SB5[64] =
{
    0x00000100, 0x02080100, 0x02080000, 0x42000100,
    0x00080000, 0x00000100, 0x40000000, 0x02080000,
    0x40080100, 0x00080000, 0x02000100, 0x40080100,
    0x42000100, 0x42080000, 0x00080100, 0x40000000,
    0x02000000, 0x40080000, 0x40080000, 0x00000000,
    0x40000100, 0x42080100, 0x42080100, 0x02000100,
    0x42080000, 0x40000100, 0x00000000, 0x42000000,
    0x02080100, 0x02000000, 0x42000000, 0x00080100,
    0x00080000, 0x42000100, 0x00000100, 0x02000000,
    0x40000000, 0x02080000, 0x42000100, 0x40080100,
    0x02000100, 0x40000000, 0x42080000, 0x02080100,
    0x40080100, 0x00000100, 0x02000000, 0x42080000,
    0x42080100, 0x00080100, 0x42000000, 0x42080100,
    0x02080000, 0x00000000, 0x40080000, 0x42000000,
    0x00080100, 0x02000100, 0x40000100, 0x00080000,
    0x00000000, 0x40080000, 0x02080100, 0x40000100
};

uint32 JLMAC::SB6[64] =
{
    0x20000010, 0x20400000, 0x00004000, 0x20404010,
    0x20400000, 0x00000010, 0x20404010, 0x00400000,
    0x20004000, 0x00404010, 0x00400000, 0x20000010,
    0x00400010, 0x20004000, 0x20000000, 0x00004010,
    0x00000000, 0x00400010, 0x20004010, 0x00004000,
    0x00404000, 0x20004010, 0x00000010, 0x20400010,
    0x20400010, 0x00000000, 0x00404010, 0x20404000,
    0x00004010, 0x00404000, 0x20404000, 0x20000000,
    0x20004000, 0x00000010, 0x20400010, 0x00404000,
    0x20404010, 0x00400000, 0x00004010, 0x20000010,
    0x00400000, 0x20004000, 0x20000000, 0x00004010,
    0x20000010, 0x20404010, 0x00404000, 0x20400000,
    0x00404010, 0x20404000, 0x00000000, 0x20400010,
    0x00000010, 0x00004000, 0x20400000, 0x00404010,
    0x00004000, 0x00400010, 0x20004010, 0x00000000,
    0x20404000, 0x20000000, 0x00400010, 0x20004010
};

uint32 JLMAC:: SB7[64] =
{
    0x00200000, 0x04200002, 0x04000802, 0x00000000,
    0x00000800, 0x04000802, 0x00200802, 0x04200800,
    0x04200802, 0x00200000, 0x00000000, 0x04000002,
    0x00000002, 0x04000000, 0x04200002, 0x00000802,
    0x04000800, 0x00200802, 0x00200002, 0x04000800,
    0x04000002, 0x04200000, 0x04200800, 0x00200002,
    0x04200000, 0x00000800, 0x00000802, 0x04200802,
    0x00200800, 0x00000002, 0x04000000, 0x00200800,
    0x04000000, 0x00200800, 0x00200000, 0x04000802,
    0x04000802, 0x04200002, 0x04200002, 0x00000002,
    0x00200002, 0x04000000, 0x04000800, 0x00200000,
    0x04200800, 0x00000802, 0x00200802, 0x04200800,
    0x00000802, 0x04000002, 0x04200802, 0x04200000,
    0x00200800, 0x00000000, 0x00000002, 0x04200802,
    0x00000000, 0x00200802, 0x04200000, 0x00000800,
    0x04000002, 0x04000800, 0x00000800, 0x00200002
};

uint32 JLMAC:: SB8[64] =
{
    0x10001040, 0x00001000, 0x00040000, 0x10041040,
    0x10000000, 0x10001040, 0x00000040, 0x10000000,
    0x00040040, 0x10040000, 0x10041040, 0x00041000,
    0x10041000, 0x00041040, 0x00001000, 0x00000040,
    0x10040000, 0x10000040, 0x10001000, 0x00001040,
    0x00041000, 0x00040040, 0x10040040, 0x10041000,
    0x00001040, 0x00000000, 0x00000000, 0x10040040,
    0x10000040, 0x10001000, 0x00041040, 0x00040000,
    0x00041040, 0x00040000, 0x10041000, 0x00001000,
    0x00000040, 0x10040040, 0x00001000, 0x00041040,
    0x10001000, 0x00000040, 0x10000040, 0x10040000,
    0x10040040, 0x10000000, 0x00040000, 0x10001040,
    0x00000000, 0x10041040, 0x00040040, 0x10000040,
    0x10040000, 0x10001000, 0x10001040, 0x00000000,
    0x10041040, 0x00041000, 0x00041000, 0x00001040,
    0x00001040, 0x00040040, 0x10000000, 0x10041000
};

/* PC1: left and right halves bit-swap */

uint32 JLMAC:: LHs[16] =
{
    0x00000000, 0x00000001, 0x00000100, 0x00000101,
    0x00010000, 0x00010001, 0x00010100, 0x00010101,
    0x01000000, 0x01000001, 0x01000100, 0x01000101,
    0x01010000, 0x01010001, 0x01010100, 0x01010101
};

uint32 JLMAC:: RHs[16] =
{
    0x00000000, 0x01000000, 0x00010000, 0x01010000,
    0x00000100, 0x01000100, 0x00010100, 0x01010100,
    0x00000001, 0x01000001, 0x00010001, 0x01010001,
    0x00000101, 0x01000101, 0x00010101, 0x01010101,
};


JLMAC::JLMAC()
{

}

JLMAC::~JLMAC()
{

}

// This is an example of an exported variable
int nJL_MAC=0;

// This is an example of an exported function.
int fnJL_MAC(void)
{
	return 42;
}
void JLMAC::DES(unsigned char *source,unsigned char *dest,unsigned char *key,unsigned char flag)
{
        unsigned char tmp[64];
        expand0(key, (char *)tmp);
        setkeystar(tmp);
	if( flag == ENCRYPT || flag == 'e' || flag == 'E' )
            encrypt0(source, dest);
        else
            discrypt0(source, dest);
}
 void JLMAC:: Do_XOR(unsigned char *dest,unsigned char *source,int size)
{
   int i;
   for(i=0; i<size; i++)
       dest[i] ^= source[i];
}

int JLMAC:: GetMAC(unsigned char *packet,int packet_size,unsigned char * mac_value,unsigned char * key,unsigned char mode)
{
  int size=0;

   memset(mac_value, 0, 8);

   while( packet_size > size)
   {
	if( (packet_size - size) <= 8 )
	{
	  Do_XOR(mac_value, &packet[size], packet_size - size);
	  DES(mac_value, mac_value, key, ENCRYPT);
	  return 0;
	}
	Do_XOR(mac_value, &packet[size], 8);
	if( mode == STAND )
	      DES(mac_value, mac_value, key, ENCRYPT);
	size += 8;
   }
   return 0;
}

void JLMAC::HostDes(unsigned char *card_no,unsigned char *work_key,unsigned char *pin,unsigned char *encrypt_pin,unsigned char flag)
{
   unsigned char  card_buf[16], pin_buf[17], enpin_buf[8];
   unsigned char  key_buf[8];
   int   i, ii;

   DSP_2_HEX((char *)work_key,(char *)key_buf, 8);

   memset(card_buf, 'F', sizeof(card_buf));
   memcpy(card_buf, card_no+1, 15);
   DSP_2_HEX((char *)card_buf,(char *)card_buf, 8);
   card_buf[0] = 0;

   if(flag == 'e' || flag == 'E' || flag == ENCRYPT)
   {
       enpin_buf[0] = strlen((const char *)pin);
       memcpy(pin_buf, pin, strlen((const char *)pin));
       ii = strlen((const char *)pin);
       for(i = ii; i<17; i++)
       {
	  pin_buf[i] = 'F';
       }
       DSP_2_HEX((char *)pin_buf, (char *)pin_buf, 8);

       Do_XOR(card_buf, pin_buf, 7);

       memcpy(enpin_buf+1, card_buf, 7);

       DES(enpin_buf, encrypt_pin, key_buf, ENCRYPT);

       return;
   }

   if(flag == 'd' || flag == 'D' || flag == DECRYPT)
   {
       DES(encrypt_pin, pin_buf, key_buf, DECRYPT);

       Do_XOR(pin_buf+1, card_buf, 7);

       HEX_2_DSP((char *)(pin_buf+1), (char *)pin, 7);

       pin[pin_buf[0]&0x0f] = 0;

       return;
   }
}

void JLMAC::DSP_2_HEX(char *dsp,char *hex,int count)
{
    int i;
    for(i = 0; i < count; i++)
    {
	hex[i]=((dsp[i*2]<=0x39)?dsp[i*2]-0x30:dsp[i*2]-0x41+10);
        hex[i]=hex[i]<<4;
	hex[i]+=((dsp[i*2+1]<=0x39)?dsp[i*2+1]-0x30:dsp[i*2+1]-0x41+10);
    }
} 

void JLMAC::HEX_2_DSP(char *hex,char *dsp,int count)
{
    int i;
    char ch;
    for(i = 0; i < count; i++)
    {
        ch=(hex[i]&0xf0)>>4;
        dsp[i*2]=(ch>9)?ch+0x41-10:ch+0x30;
        ch=hex[i]&0xf;
        dsp[i*2+1]=(ch>9)?ch+0x41-10:ch+0x30;
    }
} 


void JLMAC:: encrypt0(unsigned char *text,unsigned char *mtext)
{
	char ll[64],rr[64],LL[64],RR[64];
	char tmp[64];
	int i,j;
	ip(text,ll,rr);

	for (i=1;i<17;i++)
	{
		F(i,ll,rr,LL,RR);
		for (j=0;j<32;j++)
		{
			ll[j]=LL[j];
			rr[j]=RR[j];
		}
	}

	_ip((unsigned char *)tmp,rr,ll);

	compress0(tmp,mtext);
}

void JLMAC::discrypt0(unsigned char *mtext,unsigned char *text)
{
	char ll[64],rr[64],LL[64],RR[64];
	char tmp[64];
	int i,j;
	ip(mtext,ll,rr);

	for (i=16;i>0;i--)
	{
		F(i,ll,rr,LL,RR);
		for (j=0;j<32;j++)
		{
			ll[j]=LL[j];
			rr[j]=RR[j];
		}
	}

	_ip((unsigned char *)tmp,rr,ll);

	compress0(tmp,text);
}

void JLMAC:: expand0(unsigned char *in,char *out)
{
	int divide;
	int i,j;

	for (i=0;i<8;i++)
	{
		divide=0x80;
		for (j=0;j<8;j++)
		{
			*out++=(in[i]/divide)&1;
			divide/=2;
		}
	}
}


void JLMAC::compress0(char *out,unsigned char *in)
{
	int times;
	int i,j;

	for (i=0;i<8;i++)
	{
		times=0x80;
		in[i]=0;
		for (j=0;j<8;j++)
		{
			in[i]+=(*out++)*times;
			times/=2;
		}
	}
}

void JLMAC::compress016(char *out,unsigned char *in)
{
	int times;
	int i,j;

	for (i=0;i<16;i++)
	{
		times=0x8;
		in[i]='0';
		for (j=0;j<4;j++)
		{
			in[i]+=(*out++)*times;
			times/=2;
		}
	}
}


int pc_1_c[28]={
	57,49,41,33,25,17,9
	,1,58,50,42,34,26,18
	,10,2,59,51,43,35,27
	,19,11,3,60,52,44,36};
static int pc_1_d[28]={
	63,55,47,39,31,23,15
	,7,62,54,46,38,30,22
	,14,6,61,53,45,37,29
	,21,13,5,28,20,12,4};
static int pc_2[48]={
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32};
static int ls_count[16]={
	1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

void JLMAC::setkeystar(unsigned char bits[64])
{
	int i,j;

	for (i=0;i<28;i++)
		C[0][i]=bits[pc_1_c[i]-1];
	for (i=0;i<28;i++)
		D[0][i]=bits[pc_1_d[i]-1];
	for (j=0;j<16;j++)
	{
		LS((char *)(C[j]),(char *)(C[j+1]),ls_count[j]);
		LS((char *)(D[j]),(char *)(D[j+1]),ls_count[j]);
		son((char *)(C[j+1]),(char *)(D[j+1]),(char *)(K[j+1]));
	}
}


void JLMAC:: LS(char *bits,char *buffer,int count)
{
	int i;
	for (i=0;i<28;i++)
	{
		buffer[i]=bits[(i+count)%28];
	}
}

void JLMAC::son(char *cc,char *dd,char *kk)
{
	int i;
	char buffer[56];
	for (i=0;i<28;i++)
		buffer[i] = *cc++;

	for (i=28;i<56;i++)
		buffer[i] = *dd++;

	for (i=0;i<48;i++)
		*kk++=buffer[pc_2[i]-1];
}

static int ip_tab[64]={
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7};
static int _ip_tab[64]={
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25};

void JLMAC::ip(unsigned char *text,char *ll,char *rr)
{
	int i;
	char buffer[64];
	expand0(text,buffer);

	for (i=0;i<32;i++)
		ll[i]=buffer[ip_tab[i]-1];

	for (i=0;i<32;i++)
		rr[i]=buffer[ip_tab[i+32]-1];
}

void JLMAC:: _ip(unsigned char *text,char *ll,char *rr)
{
	int i;
	char tmp[64];
	for (i=0;i<32;i++)
		tmp[i]=ll[i];
	for (i=32;i<64;i++)
		tmp[i]=rr[i-32];
	for (i=0;i<64;i++)
		text[i]=tmp[_ip_tab[i]-1];
}


static int e_r[48]={
	32,1,2,3,4,5,4,5,6,7,8,9,
	8,9,10,11,12,13,12,13,14,15,16,17,
	16,17,18,19,20,21,20,21,22,23,24,25,
	24,25,26,27,28,29,28,29,30,31,32,1};

static int P[32]={
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25};
static int SSS[16][4][16]={
	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,/* err on */
	4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13,

	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
	3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
	0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
	13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9,

	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
	13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
	13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
	1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12,

	7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
	13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
	10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
	3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14, /* err on */

	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
	14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, /* err on */
	4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
	11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,

	12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
	10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
	9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
	4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13,

	4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
	13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
	1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
	6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12,

	13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
	1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
	7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
	2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11};

void JLMAC:: F(int n,char *ll,char *rr,char *LL,char *RR)
{
	int i;
	char buffer[64],tmp[64];
	for (i=0;i<48;i++)
		buffer[i]=rr[e_r[i]-1];
	for (i=0;i<48;i++)
		buffer[i]=(buffer[i]+K[n][i])&1;

	s_box(buffer,tmp);

	for (i=0;i<32;i++)
		buffer[i]=tmp[P[i]-1];

	for (i=0;i<32;i++)
		RR[i]=(buffer[i]+ll[i])&1;

	for (i=0;i<32;i++)
		LL[i]=rr[i];
}

void JLMAC::s_box(char *aa,char *bb)
{
	int i,j,k,m;
	int y,z;
	char ss[8];
	m=0;
	for (i=0;i<8;i++)
	{
		j=6*i;
		y=aa[j]*2+aa[j+5];
		z=aa[j+1]*8+aa[j+2]*4+aa[j+3]*2+aa[j+4];
		ss[i]=SSS[i][y][z];
		y=0x08;
		for (k=0;k<4;k++)
		{
			bb[m++]=(ss[i]/y)&1;
			y/=2;
		}

	}
}

int JLMAC:: des_set_key( des_context *ctx, uint8 key[8] )
{
    int i;

    /* setup encryption subkeys */

    des_main_ks( ctx->esk, key );

    /* setup decryption subkeys */

    for( i = 0; i < 32; i += 2 )
    {
        ctx->dsk[i    ] = ctx->esk[30 - i];
        ctx->dsk[i + 1] = ctx->esk[31 - i];
    }

    return( 0 );
}

void JLMAC:: des_crypt( uint32 SK[32], uint8 input[8], uint8 output[8] )
{
    uint32 X, Y, T;

    GET_UINT32( X, input, 0 );
    GET_UINT32( Y, input, 4 );

    DES_IP( X, Y );

    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );

    DES_FP( Y, X );

    PUT_UINT32( Y, output, 0 );
    PUT_UINT32( X, output, 4 );
}

void JLMAC:: des_encrypt( des_context *ctx, uint8 input[8], uint8 output[8] )
{
    des_crypt( ctx->esk, input, output );
}

void JLMAC:: des_decrypt( des_context *ctx, uint8 input[8], uint8 output[8] )
{
    des_crypt( ctx->dsk, input, output );
}

int JLMAC:: des3_set_2keys( des3_context *ctx, uint8 key1[8], uint8 key2[8] )
{
    int i;

    des_main_ks( ctx->esk     , key1 );
    des_main_ks( ctx->dsk + 32, key2 );

    for( i = 0; i < 32; i += 2 )
    {
        ctx->dsk[i     ] = ctx->esk[30 - i];
        ctx->dsk[i +  1] = ctx->esk[31 - i];

        ctx->esk[i + 32] = ctx->dsk[62 - i];
        ctx->esk[i + 33] = ctx->dsk[63 - i];

        ctx->esk[i + 64] = ctx->esk[     i];
        ctx->esk[i + 65] = ctx->esk[ 1 + i];

        ctx->dsk[i + 64] = ctx->dsk[     i];
        ctx->dsk[i + 65] = ctx->dsk[ 1 + i];
    }

    return( 0 );
}

int JLMAC:: des3_set_3keys( des3_context *ctx, uint8 key1[8], uint8 key2[8],
                                       uint8 key3[8] )
{
    int i;

    des_main_ks( ctx->esk     , key1 );
    des_main_ks( ctx->dsk + 32, key2 );
    des_main_ks( ctx->esk + 64, key3 );

    for( i = 0; i < 32; i += 2 )
    {
        ctx->dsk[i     ] = ctx->esk[94 - i];
        ctx->dsk[i +  1] = ctx->esk[95 - i];

        ctx->esk[i + 32] = ctx->dsk[62 - i];
        ctx->esk[i + 33] = ctx->dsk[63 - i];

        ctx->dsk[i + 64] = ctx->esk[30 - i];
        ctx->dsk[i + 65] = ctx->esk[31 - i];
    }

    return( 0 );
}

void JLMAC:: des3_crypt( uint32 SK[96], uint8 input[8], uint8 output[8] )
{
    uint32 X, Y, T;

    GET_UINT32( X, input, 0 );
    GET_UINT32( Y, input, 4 );

    DES_IP( X, Y );

    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );

    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );
    DES_ROUND( X, Y );  DES_ROUND( Y, X );

    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );

    DES_FP( Y, X );

    PUT_UINT32( Y, output, 0 );
    PUT_UINT32( X, output, 4 );
}

void JLMAC:: des3_encrypt( des3_context *ctx, uint8 input[8], uint8 output[8] )
{
    des3_crypt( ctx->esk, input, output );
}

void JLMAC:: des3_decrypt( des3_context *ctx, uint8 input[8], uint8 output[8] )
{
    des3_crypt( ctx->dsk, input, output );
}
void JLMAC:: MY_set_key(unsigned char *key1, unsigned char *key2)
{

	memcpy(DES3_keys[0],key1,8);
	memcpy(DES3_keys[1],key2,8);
	
}
int JLMAC:: MY_3des( uint8 input[8], uint8 output[8] ,int TYPE) 
{
	des_context ctx1,ctx2;

	des_set_key( &ctx1, DES3_keys[0] );
	des_set_key( &ctx2, DES3_keys[1] );

	switch(TYPE){
	case 0:			/*  加密  */
		des_encrypt( &ctx1, input , output );
		des_decrypt( &ctx2, output, output );
		des_encrypt( &ctx1, output, output );
		break;
	case 1:			/*  解密  */
		des_decrypt( &ctx1, input, output );
		des_encrypt( &ctx2, output, output );
		des_decrypt( &ctx1, output, output );
		break;
	default:
		return(1);
	}

	return(0);
}

void JLMAC:: MY_set_3DESkey(unsigned char *key1)
{

	memcpy(key_3DES,key1,16);	
}

int JLMAC:: JL_3DES( uint8 input[8], uint8 output[8] ,int TYPE) 
{
	des3_context ctx1;

	des3_set_2keys( &ctx1, key_3DES , key_3DES+8);

	switch(TYPE){
	case 0:			/*  加密  */
		des3_encrypt( &ctx1, input , output );
		break;
	case 1:			/*  解密  */
		des3_decrypt( &ctx1, input, output );
		break;
	default:
		return(1);
	}

	return(0);
}

void JLMAC::Stgstr( uint8 input1[8], uint8 input2[8], uint8 output[8] )
{
	int	i;

	for( i=0;i<8;i++ ){
		output[i]=input1[i] ^ input2[i];
	}
}

void JLMAC:: GetDesMAC( unsigned char *pack, unsigned char *mac, int len, unsigned char *key )
{
/*	unsigned char	*str;
	int 		num, i;


	if ( len%8 ) num=len/8 + 1;
	else num=len/8;
	str=malloc( num*8);//, sizeof( unsigned char ) 
	memset( str, 0x00, sizeof( str ) );
	memcpy( str, pack, len );

	memcpy( mac, str, 8 );
	MY_set_key( key, key );
	for ( i=1; i<num; i++ ){
		MY_des( mac, mac, 0 );
		str=str + 8;
		Stgstr( mac, str, mac );
	}
	MY_des( mac, mac, 0 );
	
	free( str-(--num)*8 );
*/	
}
int JLMAC::MY_des( uint8 input[8], uint8 output[8] ,int TYPE) 
{
	des_context ctx;

	des_set_key( &ctx, DES3_keys[0] );
	switch(TYPE){
	case 0:			/*  加密  */
		des_encrypt( &ctx, input , output );
		break;
	case 1:			/*  解密  */
		des_decrypt( &ctx, input, output );
		break;
	default:
		return(1);
	}

	return(0);
}

void JLMAC:: Get3DesMAC( unsigned char *packet, unsigned char *mac_value, int packet_size, 
	       unsigned char *key1, unsigned char *key2 )
{
	int size=0;
	memset(mac_value, 0, 8);
	int 		num;
	if ( packet_size%8 ) 
	{
		num=packet_size/8 + 1;
		memset(packet+packet_size,0x00,num*8 - packet_size);
	}
	else num=packet_size/8;
	unsigned char buffer[1024] ;
	memcpy(buffer,packet,num*8);


	//MY_set_key( key1, key2 );
	memcpy(DES3_keys[0],key1,8);
	while( packet_size > size)
	{
		if( (packet_size - size) > 0/*<= 8*/ )
		{
		  Do_XOR(mac_value, &packet[size], 8/*packet_size - size*/);
		  //MY_3des(mac_value, mac_value, ENCRYPT);
		  MY_des(mac_value,mac_value,0);
		  memcpy(DES3_keys[0],key2,8);
		  MY_des(mac_value,mac_value,1);
		  memcpy(DES3_keys[0],key1,8);
		  MY_des(mac_value,mac_value,0);
		  //return 0;
		  size += 8;
		  //return;
		}
		else
		{
			return;
		}
	//	Do_XOR(mac_value, &packet[size], 8);
		//if(mode == STAND )
		//MY_3des(mac_value, mac_value, ENCRYPT);
	//	MY_des(mac_value,mac_value,0);
	//	size += 8;
	}
	
}
void JLMAC::MakeXorOpration(UCHAR *pInput1 , UCHAR *pInput2, int length, UCHAR *pOutput)
{
	if((!pInput1) ||(!pInput2)||(!pOutput))
		return ;
	for(int i=0; i<length ; i++)
	{
		(*pOutput) = (*pInput1) ^ (*pInput2);
		pInput1++;
		pInput2++;
		pOutput++;
	}
}
int JLMAC::des_main_ks( uint32 SK[32], uint8 key[8] )
{
    int i;
    uint32 X, Y, T;

    GET_UINT32( X, key, 0 );
    GET_UINT32( Y, key, 4 );

    /* Permuted Choice 1 */

    T =  ((Y >>  4) ^ X) & 0x0F0F0F0F;  X ^= T; Y ^= (T <<  4);
    T =  ((Y      ) ^ X) & 0x10101010;  X ^= T; Y ^= (T      );

    X =   (LHs[ (X      ) & 0xF] << 3) | (LHs[ (X >>  8) & 0xF ] << 2)
        | (LHs[ (X >> 16) & 0xF] << 1) | (LHs[ (X >> 24) & 0xF ]     )
        | (LHs[ (X >>  5) & 0xF] << 7) | (LHs[ (X >> 13) & 0xF ] << 6)
        | (LHs[ (X >> 21) & 0xF] << 5) | (LHs[ (X >> 29) & 0xF ] << 4);

    Y =   (RHs[ (Y >>  1) & 0xF] << 3) | (RHs[ (Y >>  9) & 0xF ] << 2)
        | (RHs[ (Y >> 17) & 0xF] << 1) | (RHs[ (Y >> 25) & 0xF ]     )
        | (RHs[ (Y >>  4) & 0xF] << 7) | (RHs[ (Y >> 12) & 0xF ] << 6)
        | (RHs[ (Y >> 20) & 0xF] << 5) | (RHs[ (Y >> 28) & 0xF ] << 4);

    X &= 0x0FFFFFFF;
    Y &= 0x0FFFFFFF;

    /* calculate subkeys */

    for( i = 0; i < 16; i++ )
    {
        if( i < 2 || i == 8 || i == 15 )
        {
            X = ((X <<  1) | (X >> 27)) & 0x0FFFFFFF;
            Y = ((Y <<  1) | (Y >> 27)) & 0x0FFFFFFF;
        }
        else
        {
            X = ((X <<  2) | (X >> 26)) & 0x0FFFFFFF;
            Y = ((Y <<  2) | (Y >> 26)) & 0x0FFFFFFF;
        }

        *SK++ =   ((X <<  4) & 0x24000000) | ((X << 28) & 0x10000000)
                | ((X << 14) & 0x08000000) | ((X << 18) & 0x02080000)
                | ((X <<  6) & 0x01000000) | ((X <<  9) & 0x00200000)
                | ((X >>  1) & 0x00100000) | ((X << 10) & 0x00040000)
                | ((X <<  2) & 0x00020000) | ((X >> 10) & 0x00010000)
                | ((Y >> 13) & 0x00002000) | ((Y >>  4) & 0x00001000)
                | ((Y <<  6) & 0x00000800) | ((Y >>  1) & 0x00000400)
                | ((Y >> 14) & 0x00000200) | ((Y      ) & 0x00000100)
                | ((Y >>  5) & 0x00000020) | ((Y >> 10) & 0x00000010)
                | ((Y >>  3) & 0x00000008) | ((Y >> 18) & 0x00000004)
                | ((Y >> 26) & 0x00000002) | ((Y >> 24) & 0x00000001);

        *SK++ =   ((X << 15) & 0x20000000) | ((X << 17) & 0x10000000)
                | ((X << 10) & 0x08000000) | ((X << 22) & 0x04000000)
                | ((X >>  2) & 0x02000000) | ((X <<  1) & 0x01000000)
                | ((X << 16) & 0x00200000) | ((X << 11) & 0x00100000)
                | ((X <<  3) & 0x00080000) | ((X >>  6) & 0x00040000)
                | ((X << 15) & 0x00020000) | ((X >>  4) & 0x00010000)
                | ((Y >>  2) & 0x00002000) | ((Y <<  8) & 0x00001000)
                | ((Y >> 14) & 0x00000808) | ((Y >>  9) & 0x00000400)
                | ((Y      ) & 0x00000200) | ((Y <<  7) & 0x00000100)
                | ((Y >>  7) & 0x00000020) | ((Y >>  3) & 0x00000011)
                | ((Y <<  2) & 0x00000004) | ((Y >> 21) & 0x00000002);
    }

    return( 0 );
}

void JLMAC::EncryptSM4( char* pszOutBuf, const unsigned int ulOutBufLen, const char* pszMainKey, const char* pszWorkingKey, const char* pszIV, bool bIsUseBCD, bool bbIsUseBCD2 )
{
	unsigned char lszMainKey[33] = { 0 };
	unsigned char lszWorkKey[33] = { 0 };
	
	if ( bIsUseBCD == true )
	{
		BCDToASC( (unsigned char*)pszMainKey,		lszMainKey, 32 );
		BCDToASC( (unsigned char*)pszWorkingKey,	lszWorkKey, 32 );
	}
	else
	{
		memcpy(lszMainKey, pszMainKey, 32);
		memcpy(lszWorkKey, pszWorkingKey, 32);
	}
	
	// 原有加密算法
	// 	unsigned char lszPinKey1[9] = { 0 };
	// 	unsigned char lszPinKey2[9] = { 0 };
	// 	memcpy(lszPinKey1, lszMainKey, 8);
	// 	memcpy(lszPinKey2, lszMainKey + 8, 8);
	// 	
	// 	unsigned char lszTempKey1[33] = { 0 };
	// 	gJLMac.MY_set_key(lszPinKey1, lszPinKey2);
	// 	gJLMac.MY_3des(lszWorkKey, lszTempKey1, 0);
	// 	gJLMac.MY_3des(lszWorkKey + 8, lszTempKey1 + 8, 0);
	
	// 使用国密
	unsigned char lszTempKey1[128] = { 0 };
	try{
		::Sm4( "ECB", 1, (char*)lszMainKey, (char*)pszIV, (char*)lszWorkKey, (char*)lszTempKey1 );
	}catch( ... )
	{
	}
	
	unsigned char lszTempKey2[33] = { 0 };
	if ( bbIsUseBCD2 == true )
	{
		ASCToBCD( lszTempKey1, lszTempKey2, 32 );
	}
	else
	{
		memcpy(lszTempKey2, lszTempKey1, 32);
		
	}

	memcpy(pszOutBuf, lszTempKey2, ulOutBufLen);
}

void JLMAC::AuthenticSM4( char* pszOutBuf, const unsigned int ulOutBufLen, const char* pszWorkKey, const char* pszIV, bool bIsUseBCD, bool bIsUseBCD2 )
{
	std::string lstrWorkKey = pszWorkKey;
	unsigned char lszWorkKey[33] = { 0 };
	if ( bIsUseBCD == true )
	{
		BCDToASC( (unsigned char*)pszWorkKey, lszWorkKey, 32 );
	}
	else
	{
		memcpy(lszWorkKey, lstrWorkKey.c_str(), 32);
	}
	
	// 使用国密
	unsigned char lszNullString[17] = { 0 };
	unsigned char lszOutBuf[128] = { 0 };
	try{
		::Sm4( "ECB", 1, (char*)lszWorkKey, (char*)pszIV, "00", (char*)lszOutBuf );
	}catch( ... )
	{
	}
	
	unsigned char lszAuthenticString[33] = { 0 };
	if ( bIsUseBCD2 == true )
	{
		ASCToBCD( lszOutBuf, lszAuthenticString, 32 );
	}
	else
	{
		memcpy( lszAuthenticString, lszOutBuf, ulOutBufLen);
	}
	
	memcpy( pszOutBuf, lszAuthenticString, ulOutBufLen );
}

unsigned int JLMAC::GetMacSM4( PBYTE pMacString, UINT iMacStringLen, const char* pszMackey, const char* pszIV, PBYTE pszMacValue, UINT iMacLen )
{
	int size=0;
	unsigned char lszMacValue[17] = {0};
	unsigned char lszBuf[33] = {0};
	unsigned char lszOutBuf[33] = {0};
	
	while( iMacStringLen > size)
	{
		if( (iMacStringLen - size) <= 16 )
		{
			Do_XOR(lszMacValue, &pMacString[size], iMacStringLen - size);
			BCDToASC(lszMacValue, lszBuf, 32 );
			::Sm4( "ECB", 1, (char*)pszMackey, (char*)pszIV, (char*)lszBuf, (char*)lszOutBuf  );
			break;
		}
		Do_XOR(lszMacValue, &pMacString[size], 16);
		BCDToASC( lszMacValue, lszBuf, 32 );
		::Sm4( "ECB", 1, (char*)pszMackey, (char*)pszIV, (char*)lszBuf, (char*)lszOutBuf );
		ASCToBCD(lszOutBuf, lszMacValue,32);
		
		size += 16;
	}
	
	memcpy( pszMacValue, lszOutBuf, iMacLen );
	
	return iMacLen;
}
