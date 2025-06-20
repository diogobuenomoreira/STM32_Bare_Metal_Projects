/*
 * bsp.c
 *
 *  Created on: Jun 15, 2025
 *      Author: moreirad
 */

#include "stm32l4xx.h"
#include "bsp.h"

#define GPIOAEN		(1U << 0U)
#define GPIOCEN		(1U << 2U)
#define PIN5		(1U << 5U)
#define LED_PIN		PIN5
#define	PIN13		(1U << 13U)
#define BUTTON_PIN	PIN13

void LED_Init(void)
{
	/* Enable clock access to GPIOA */
	RCC->AHB2ENR |= GPIOAEN;

	/* Set PA5 mode to output mode */
	GPIOA->MODER |= (1U << 10U);
	GPIOA->MODER &= ~(1U << 11U);
}

void LED_On(void)
{
	/* Set PA5 high */
	GPIOA->ODR |= LED_PIN;
}

void LED_Off(void)
{
	/* Set PA5 low */
	GPIOA->ODR &= ~LED_PIN;
}

void Button_Init(void)
{
	/* Enable clock access to PORTC */
	RCC->AHB2ENR |= GPIOCEN;

	/* Set PC13 as an input pin */
	GPIOC->MODER &= ~(1U << 26U);
	GPIOC->MODER &= ~(1U << 27U);
}

bool Get_Button_State(void)
{
	/*Note: Button is active low */
	/* Check if the button is pressed */
	if(GPIOC->IDR & BUTTON_PIN)
	{
		return false;
	}

	return true;
}
