#include "LS138.h"

//�������Ϊ�������ʾ������Ӧ�����飬����SEG_Write()��������ʾ��Ӧ�����ݣ�ÿһ�й�ʮ��Ԫ��
								  /*0    1    2    3     4    5    6    7    8    9 */
unsigned  char code  NixieTube[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,
								  /* A   B     C    D    E    F    H    L    N    P */
								   0x88,0x83,0xC6,0xA1,0x86,0x8E,0x89,0xC7,0xC8,0x8C,
								  /* U    -   ' ' */
								   0xC1,0xBF,0xFF};

unsigned char code NixieTube_Init[]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
//��ʱ��������ʱ2ms								   
static void Delay2ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 22;
	j = 128;
	do
	{
		while (--j);
	} while (--i);
}

static void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 13;
	j = 156;
	k = 83;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

//��ʼ��������
void LS138_Init(void)
{
	SEG_Write(NixieTube_Init);
    LED_Contrl(0);
    BEEP_Contrl(0);
    Relay_Control(0);
	LS138_A=LS138_B=LS138_C=0;
	P0 = 0xFF;
}
//���ls138��λѡ
void LS138_Clear(void)
{
	LS138_A=LS138_B=LS138_C=0;
	P0 = 0xFF;
}
//����ls138��λѡ,���������Data����������͵�ƽ�����������ΧΪ4~7��Ч
void LS138_Set(unsigned int Data)
{
	switch(Data)
	{
		case 0: LS138_A=LS138_B=LS138_C=0;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: LS138_A=0;LS138_B=0;LS138_C=1;
			break;
		case 5: LS138_A=1;LS138_B=0;LS138_C=1;
			break;
		case 6: LS138_A=0;LS138_B=1;LS138_C=1;
			break;
		case 7: LS138_A=1;LS138_B=1;LS138_C=1;
			break;
	}
}

//�����������ʾ��Ӧ�����֣���ʾ����Ϊ����p[i]��Ӧ��NixieTube[]�����е����ӻ�Ӣ���ַ���
//��ʾ����Ϊ����������ʾ��pΪ��������ĵ�ַ
//ԭ��ͼ�������Ϊ�����������
void SEG_Write(unsigned char* p)
{
	unsigned char i =0;
	for(i=0;i<8;i++)
	{
		LS138_Clear();
		LS138_Set(7);	//ls138������λѡΪ��������
		P0 = NixieTube[*(p+i)];
		LS138_Clear();
		LS138_Set(6);		//ls138������λѡΪ�ܽ�ѡ�񣬶�ӦλΪ1�����Ӧ�����������
		P0 = (unsigned char )0x01<<i;
		Delay2ms();
		P0=0xFF;
	}
}

//����LEDl��������д0Ϊ��д1����
void LED_Contrl(int Flag)
{
	if(Flag)
	{
		LS138_Clear();
		LS138_Set(4);
		P0 = 0x00;
	}
	else
	{
		LS138_Clear();
		LS138_Set(4);
		P0 = 0xFF;
	}
}

//LED��ˮ�ƺ�����д1ʱ��ʼ��ˮ�ƣ�д0ʱֹͣ��ˮ��
void LED_Run(int Flag)
{
	unsigned char i=0;
	LS138_Clear();
	if(Flag)
	{
		for(i=0;i<8;i++)
		{
		
		LS138_Set(4);
		P0 = ~(unsigned char )(0x01<<i);
		LS138_Clear();
		Delay300ms();
		}
	}
	else
	{
		LS138_Clear();
		LS138_Set(4);
		P0 = 0xFF;
	}
}

//���Ʒ������Ŀ��ء�д1ʱ�򿪣�д0ʱ�ر�
void BEEP_Contrl(int Flag)
{
	if(Flag)
	{
		LS138_Clear();
		LS138_Set(5);
		P0 |=  0x40;
		LS138_Clear();
	}
	else
	{
		LS138_Clear();
		LS138_Set(5);
		P0 = P0 & 0xBF;
		LS138_Clear();
	}
}

//���Ƽ̵����Ŀ��ء�д1ʱ�򿪣�д0ʱ�ر�
void Relay_Control(int Flag)
{
    if(Flag)
    {
        LS138_Clear();
        LS138_Set(5);
		P0 |=  0x10;
		LS138_Clear();
    }
    else
    {
        LS138_Clear();
		LS138_Set(5);
		P0 = P0 & 0xEF;
		LS138_Clear();
    }
}



