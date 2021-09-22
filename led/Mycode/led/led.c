#include "main.h"

static void Led_Init(void){

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);//��ɫ
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);//��ɫ
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);//��ɫ
}


static void Led_Light(int8_t R, int8_t G, int8_t B){
	
	if(R > 0){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
	}else if(R == 0){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
	}else{
		//���������в���
	}
	
	if(G > 0){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
	}else if(G == 0){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
	}else{
		//���������в���
	}
	
	if(B > 0){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
	}else if(B == 0){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
	}else{
		//���������в���
	}
}


Led_t Led = {
	Led_Init,
	Led_Light
};


