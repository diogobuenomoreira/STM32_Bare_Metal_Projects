/*
 * adc.h
 *
 *  Created on: Jun 15, 2025
 *      Author: moreirad
 */

#ifndef ADC_H_
#define ADC_H_

void ADC_Init(void);
void ADC_Start_Conversion(void);
uint32_t ADC_Read(void);

#endif /* ADC_H_ */
