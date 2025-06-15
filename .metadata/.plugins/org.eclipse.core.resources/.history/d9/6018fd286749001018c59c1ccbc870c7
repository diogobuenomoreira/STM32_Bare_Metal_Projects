
#include "stm32l4xx.h"
#include "fpu.h"
#include "uart.h"
#include <stdio.h>


int main(void)
{
	/* Enable FPU */
	FPU_Enable();

	/* Initialize UART */
	Debug_UART_Init();

	while(1)
	{
		printf("Hello from STM32\r\n");
		for(int i = 0; i < 9000; i++);
	}
}
