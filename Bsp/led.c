////Filename: led.c

//#include "includes.h" 

//void LEDInit(void)
//{
//	RCC->APB2ENR |=(1uL<<3) | (1uL<<6);
//	GPIOB->CRL |=(1uL<<20);
//	GPIOB->CRL &=~((1uL<<21) | (1uL<<22) | (1uL<<23));
//	
//	GPIOE->CRL |=(1uL<<20);
//	GPIOE->CRL &=~((1uL<<21) | (1uL<<22) | (1uL<<23));
//  }

//	void LED(Int08U w, LEDState s)
//	{
//		switch(w)
//		{
//			case 0:
//							if(s==LED_ON)
//									GPIOB->BRR = (1uL<<5);
//							else
//									GPIOB->BSRR = (1uL<<5);
//							break;
//			case 1:
//							if(s==LED_ON)
//									GPIOE->BRR = (1uL<<5);
//							else
//									GPIOE->BSRR = (1uL<<5);
//							break;
//				default:
//							break;
//	   }
//	}
//	
//	
//	
	//Filename:led.c

#include"includes.h"

void LEDInit(void)
{
GPIO_InitTypeDef g;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE,ENABLE);

g.GPIO_Pin=GPIO_Pin_5;
g.GPIO_Mode=GPIO_Mode_Out_PP; 
g.GPIO_Speed= GPIO_Speed_50MHz;
GPIO_Init(GPIOB,&g);

g.GPIO_Pin=GPIO_Pin_5;
g.GPIO_Mode = GPIO_Mode_Out_PP;
g.GPIO_Speed= GPIO_Speed_50MHz;
GPIO_Init(GPIOE,&g);
}
void LED(Int08U w, LEDState s)//w-which(1or2), s-state(LED_ONorLED_OFF)
{
switch(w)
{
case 0:
if(s==LED_ON)
GPIO_ResetBits(GPIOB,GPIO_Pin_5);
else
GPIO_SetBits(GPIOB,GPIO_Pin_5);
break;
case 1:
if(s==LED_ON)
GPIO_ResetBits(GPIOE,GPIO_Pin_5);
else
GPIO_SetBits(GPIOE,GPIO_Pin_5);
break;
default:
break;
}
}
