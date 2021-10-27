//Filename: key.c

#include "includes.h"

void KEYInit(void)
{
	GPIO_InitTypeDef g;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO,ENABLE);
	
	g.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	g.GPIO_Mode = GPIO_Mode_IPU;
	g.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOE, &g);
	
	GPIO_SetBits(GPIOE,GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4);
}
