
#include "stm32l4xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>
#include "timebase.h"
#include "bsp.h"


int main(void)
{
	/* Enable FPU */
	FPU_Enable();

	/* Initialize UART */
	Debug_UART_Init();

	/* Initialize Timebase */
	Timebase_Init();

	/* Initialize LED */
	LED_Init();

	/* Initialize button */
	Button_Init();

	while(1)
	{
		LED_On();
		if(Get_Button_State())
		{
			LED_Off();
		}
		Delay(1);
	}
}
