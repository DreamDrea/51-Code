#ifndef __LS138_H_
#define __LS138_H_
#include <STC15F2K60S2.H>
#include <INTRINS.h>

//#define SEG_Number_ON  7
//#define SEG_Com_ON     6
//#define BUZZER_ON      5
//#define RELAY_ON       5
//#define LED_ON         4
sbit LS138_A = P2^5;
sbit LS138_B = P2^6;
sbit LS138_C = P2^7;


//��ʱ��������ʱ2ms   @11.0592MHz
static void Delay2ms();

//��ʱ��������ʱ300ms   @11.0592MHz
static void Delay300ms();		

//��ʼ��������Ĭ��Ϊ���������ȫ��
void LS138_Init(void);

//���ls138��λѡ
void LS138_Clear(void);

//����ls138��λѡ,����Data����������͵�ƽ�����������ΧΪ4~7��Ч
void LS138_Set(unsigned int Data);

//�����������ʾ��Ӧ�����֣���ʾ����Ϊ����p[i]��Ӧ��NixieTube[]�����е����ӻ�Ӣ���ַ���
//��ʾ����Ϊ����������ʾ��pΪ��������ĵ�ַ��
//ԭ��ͼ�������Ϊ�����������
void SEG_Write(unsigned char* p);

//����LED��������д0Ϊ��д1����
void LED_Contrl(int Flag);

//LED��ˮ�ƺ�����д1ʱ��ʼ��ˮ�ƣ�д0ʱֹͣ��ˮ��
void LED_Run(int Flag);

//���Ʒ������Ŀ��ء�д1ʱ�򿪣�д0ʱ�ر�
void BEEP_Contrl(int Flag);

//���Ƽ̵����Ŀ��ء�д1ʱ�򿪣�д0ʱ�ر�
void Relay_Control(int Flag);
#endif  /*__LS138_H_*/