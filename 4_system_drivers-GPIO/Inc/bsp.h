/*
 * bsp.h
 *
 *  Created on: Jun 15, 2025
 *      Author: moreirad
 */

#ifndef BSP_H_
#define BSP_H_

#include <stdbool.h>

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void Button_Init(void);
bool Get_Button_State(void);


#endif /* BSP_H_ */
