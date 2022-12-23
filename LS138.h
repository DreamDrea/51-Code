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


//延时函数，延时2ms   @11.0592MHz
static void Delay2ms();

//延时函数，延时300ms   @11.0592MHz
static void Delay300ms();		

//初始化函数，默认为设置数码管全亮
void LS138_Init(void);

//清除ls138的位选
void LS138_Clear(void);

//设置ls138的位选,控制Data号引脚输出低电平，输入参数范围为4~7有效
void LS138_Set(unsigned int Data);

//在数码管上显示对应的数字，显示内容为数组p[i]对应到NixieTube[]数组中的数子或英文字符，
//显示方向为从左向右显示，p为传入数组的地址，
//原理图上数码管为共阴极数码管
void SEG_Write(unsigned char* p);

//控制LED的亮和灭，写0为灭，写1亮。
void LED_Contrl(int Flag);

//LED流水灯函数，写1时开始流水灯，写0时停止流水灯
void LED_Run(int Flag);

//控制蜂鸣器的开关。写1时打开，写0时关闭
void BEEP_Contrl(int Flag);

//控制继电器的开关。写1时打开，写0时关闭
void Relay_Control(int Flag);
#endif  /*__LS138_H_*/