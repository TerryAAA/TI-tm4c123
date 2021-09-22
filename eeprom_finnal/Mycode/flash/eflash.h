#ifndef __EFLASH_H__
#define __EFLASH_H__
#include "main.h"


typedef struct{

	void (* Init)(void);
	void (* Write)(void);
	void (* Read)	(void);
}Flash_t;

extern Flash_t Flash;




#endif

















