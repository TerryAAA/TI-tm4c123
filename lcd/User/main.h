#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>


#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_ints.h"
#include "debug.h"
#include "fpu.h"
#include "gpio.h"
#include "pin_map.h"
#include "pwm.h"
#include "rom.h"
#include "sysctl.h"
#include "uart.h"
#include "interrupt.h"
#include "timer.h"
#include "hw_gpio.h"
#include "eeprom.h"
#include "sysctl.h"


typedef   signed           char int8;
typedef unsigned           char u8;
typedef unsigned           char uint8;
typedef unsigned           char byte;
typedef   signed short     int int16;
typedef unsigned short     int uint16;
typedef unsigned short     int u16;
typedef unsigned long     int u32; 


#define ABS(X)  (((X)>0)?(X):-(X))
#define MAX(a,b)  ((a)>(b)?(a):(b))
#define MIN(a,b)  ((a)>(b)?(b):(a))




#define  USER_INT0  0x00
#define  USER_INT1  0x20
#define  USER_INT2  0x40
#define  USER_INT3  0x60
#define  USER_INT4  0x80
#define  USER_INT5  0xA0
#define  USER_INT6  0xC0
#define  USER_INT7  0xE0


#include "led.h"
#include "timerc.h"
#include "schedule.h"
#include "pwmc.h"
#include "uartc.h"
#include "lcdc.h"
#include "key.h"
#include "ui.h"
#include "isr.h"

extern uint8_t	SYS_Flag;
extern uint32_t UIcount1;
extern uint32_t UIcount2;
extern int32_t UIcount3;

#endif

