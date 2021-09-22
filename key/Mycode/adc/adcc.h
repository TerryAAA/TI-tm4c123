#ifndef __ADCC_H__
#define __ADCC_H__

#include "main.h"

typedef struct{
  void (* Init)	(void);
	uint32_t (* Get)	(uint8_t);
}Adc_t;

//void ADC_Init(void);   
//void Get_Battery_Voltage(void);
extern Adc_t Adc;
#endif
