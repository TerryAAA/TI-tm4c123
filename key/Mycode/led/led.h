#ifndef __LED_H__
#define __LED_H__

#include "main.h"


typedef struct{
	
  void (* Init)	(void);
	void (* Light)	(int8_t, int8_t, int8_t);
}Led_t;

extern Led_t Led;



#endif

