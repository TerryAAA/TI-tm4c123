#ifndef __UARTC_H__
#define __UARTC_H__

#include "main.h"


typedef struct{
  void (* Init)	(void);
}Uart0_t;


typedef struct{
  void (* Init)	(void);
}Uart1_t;


typedef struct{
  void (* Init)	(void);
}Uart2_t;


extern Uart0_t Uart0;
extern Uart1_t Uart1;
extern Uart2_t Uart2;


#endif

