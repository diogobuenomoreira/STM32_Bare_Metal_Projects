/*
 * timebase.c
 *
 *  Created on: Jun 14, 2025
 *      Author: moreirad
 */

#include "stm32l4xx.h"
#include "timebase.h"

#define CTRL_ENABLE		(1U << 0U)
#define CTRL_TICKINT	(1U << 1U)
#define CTRL_CLKSRC		(1U << 2U)
#define CTRL_COUNTFLAG	(1U << 16U)

#define ONE_SEC_LOAD	4000000 // 4Mhz

#define MAX_DELAY		0XFFFFFFFF
#define TICK_FREQ		1U

static void Tick_Increment(void);

static volatile uint32_t g_current_tick;
static volatile uint32_t g_current_tick_p;


/* Delay in seconds */
void Delay(uint32_t delay)
{
	uint32_t tick_start = Get_Tick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY)
	{
		wait += (uint32_t)TICK_FREQ;
	}

	while((Get_Tick() - tick_start) < wait );
}

uint32_t Get_Tick(void)
{
	__disable_irq();
	g_current_tick_p = g_current_tick;
	__enable_irq();

	return g_current_tick_p;
}

static void Tick_Increment(void)
{
	g_current_tick += TICK_FREQ;
}

void Timebase_Init(void)
{
	/* Disable global interrupts */
	__disable_irq();

	/* Load the timer with number of clock cycles per second */
	SysTick->LOAD = ONE_SEC_LOAD - 1; // -1 because we count from zero

	/* Clear systick current value register */
	SysTick->VAL = 0;

	/* Select internal clock source */
	SysTick->CTRL |= CTRL_CLKSRC;

	/* Enable interrupt */
	SysTick->CTRL |= CTRL_TICKINT;

	/* Enable systick */
	SysTick->CTRL |= CTRL_ENABLE;

	/* Enable global interrupt */
	__enable_irq();
}

void SysTick_Handler(void)
{
	Tick_Increment();
}
