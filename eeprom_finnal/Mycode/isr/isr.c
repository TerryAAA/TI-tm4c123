#include "isr.h"
#include "scheduler.h"
#include "ui.h"
#include "main.h"



extern uint8_t Test5_Flag;
//extern uint8_t Key_Flag;
//extern ModeSelect_t Mode_Select;

void Timer_CallBack(void){
	if(SYS_Flag==1){
		Scheduler_Run();
	}
}



void UART1_CallBack(void){

	char ch = UARTCharGet(UART1_BASE);
}



void UART2_CallBack(void){

	char ch = UARTCharGet(UART2_BASE);
}



void UART3_CallBack(void){

	
}


void EncKey_CallBack(void){

	UI.Key();
}



void Key_CallBack(void){

	
	
}

