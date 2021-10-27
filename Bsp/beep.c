//filename: beep.c

#include "includes.h"

void BEEPInit(void)
{
	GPIO_InitTypeDef g;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	g.GPIO_Pin = GPIO_Pin_8;
	g.GPIO_Mode = GPIO_Mode_Out_PP;
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &g);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}

void BEEP(void)
{
	Int08U v;
	v=GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8);
	if(v==1)
			GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	else 
			GPIO_SetBits(GPIOB,GPIO_Pin_8);
}
