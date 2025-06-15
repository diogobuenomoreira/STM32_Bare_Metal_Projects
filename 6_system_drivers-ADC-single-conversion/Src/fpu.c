/*
 * fpu.c
 *
 *  Created on: Jun 9, 2025
 *      Author: moreirad
 */

#include "fpu.h"
#include "stm32l4xx.h"

void FPU_Enable(void)
{
	/* Enable floating point unit: Enable CP10 and CPU11 full access*/
	SCB->CPACR |= (1 << 20)|(1 << 21)|(1 << 22)|(1 << 23);

}
