#include "main.h"


uint32_t enc1=0;
uint32_t UIcount1=0;
uint32_t UIcount2=0;
int32_t UIcount3=0;

void gpio_unlock(uint32_t ui32Port, uint8_t ui8Pins){
  HWREG(ui32Port + GPIO_O_LOCK) = GPIO_LOCK_KEY; // Unlock the commit register
  HWREG(ui32Port + GPIO_O_CR) |= 0x01 << ui8Pins;// Write 0x01 to the corresponding bit in commit register
  HWREG(ui32Port + GPIO_O_LOCK) = 0;//重新锁定
}


void PortFIntHandler(void)//中断程序
{
	SysCtlDelay(100000);
  GPIOIntClear(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4);//清除中断标志	
	if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0) == 0){
//		a++;
		Key_CallBack();
	}
	if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4) == 0){
//		a++;
		EncKey_CallBack();
	}
}


void PortBIntHandler(void)//中断程序
{
	SysCtlDelay(100000);
  GPIOIntClear(GPIO_PORTB_BASE, GPIO_PIN_2);//清除中断标志	
	if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_2) == 0){
		enc1++;
		UIcount1=enc1%9;
		UIcount2=enc1%20;
		UIcount3=UIcount2-10;
		
	}
}



void KEY_Init(void)
{    
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//使能GPIO外设
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//使能GPIO外设
	
	gpio_unlock(GPIO_PORTF_BASE, 0);
	gpio_unlock(GPIO_PORTF_BASE, 4);
	gpio_unlock(GPIO_PORTB_BASE, 2);
	
  GPIOIntRegister(GPIO_PORTF_BASE, PortFIntHandler);//GPIO注册中断
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);//中断输入源
  GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//配置为上拉
  GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4 , GPIO_BOTH_EDGES);//中断触发类型为下降沿触发
  GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);//使能中断
  IntPrioritySet(INT_GPIOF,USER_INT7);
	
  GPIOIntRegister(GPIO_PORTB_BASE, PortBIntHandler);//GPIO注册中断
  GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_2);//中断输入源
  GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD);//配置为上拉
  GPIOIntTypeSet(GPIO_PORTB_BASE, GPIO_PIN_2 , GPIO_BOTH_EDGES);//中断触发类型为下降沿触发
  GPIOIntEnable(GPIO_PORTB_BASE, GPIO_PIN_2);//使能中断
  IntPrioritySet(INT_GPIOB,USER_INT7);
} 


Key_t Key = {
	KEY_Init,
};


