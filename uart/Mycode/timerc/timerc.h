#ifndef __TIMERC_H__
#define __TIMERC_H__

#include "main.h"


typedef struct{
	
  void (* Init)	(void);
}Timer_t;

extern Timer_t Timer;



#endif

