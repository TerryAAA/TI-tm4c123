#ifndef __PWMC_H__
#define __PWMC_H__

#include "main.h"


typedef struct{
	
  void (* Init)	(void);
	void (*set) (uint16_t ,uint16_t ,uint16_t ,uint16_t );
}Pwm_t;

extern Pwm_t Pwm;



#endif

