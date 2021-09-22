#ifndef __UI_H__
#define __UI_H__


#include "main.h"



typedef enum
{
	None_mode = 0U,
	Mode1 = 1U,
	Mode2 = 2U,
	Mode3 = 3u,
	Mode4 = 4U,
	Mode5 = 5U,
	Mode6 = 6U,
	Parameter1 = 7u,
	Parameter2 = 8U,
	Parameter3 = 9U,
}ModeSelect_t;


typedef enum
{
	P_None = 0U,
	P1 = 1U,
	P2 = 2U,
	P3 = 3U,
	P4 = 4u,
	P5 = 5U,
	P6 = 6U,
	P7 = 7U,
	P8 = 8u,
	P9 = 9U,
	P10= 10U,
	P11= 11U,
	P12= 12U,
	P13= 13U,
	P14= 14U,
	P15= 15U,
	P16= 16U,
	P17= 17U,
	P18= 18U,
	Parameter_Save= 19U,
	BACK= 20U,
}ParameterAdj_t;





void UI_Mode(void);



typedef struct{

	void (* ModeSelect)(void);
	void (* InMode)(void);
	void (* ParameterAdj)(void);
	void (* Main)(void);
	void (* Key)(void);
}UI_t;

extern UI_t UI;




#endif

























