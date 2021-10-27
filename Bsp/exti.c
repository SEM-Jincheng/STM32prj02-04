//Filename: exti.c

#include "includes.h"

void EXTIKeyInit(void)
{
	EXTI_InitTypeDef e;
		
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
	e.EXTI_Line = EXTI_Line2 | EXTI_Line3 | EXTI_Line4;
	e.EXTI_Mode = EXTI_Mode_Interrupt;
	e.EXTI_Trigger = EXTI_Trigger_Falling;
	e.EXTI_LineCmd = ENABLE;
	EXTI_Init(&e);
	
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_SetPriority(EXTI2_IRQn,5);
	NVIC_SetPriority(EXTI3_IRQn,6);	
	NVIC_SetPriority(EXTI4_IRQn,7);
}

void EXTI2_IRQHandler()
{
	LED(0,LED_OFF);
	EXTI_ClearFlag(EXTI_Line2);
	NVIC_ClearPendingIRQ(EXTI2_IRQn);
}

void EXTI3_IRQHandler()
{
	LED(0,LED_OFF);
	EXTI_ClearFlag(EXTI_Line3);
	NVIC_ClearPendingIRQ(EXTI3_IRQn);
}

void EXTI4_IRQHandler()
{
	BEEP();
	EXTI_ClearFlag(EXTI_Line4);
	NVIC_ClearPendingIRQ(EXTI4_IRQn);
}
