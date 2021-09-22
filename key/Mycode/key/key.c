#include "main.h"

void gpio_unlock(uint32_t ui32Port, uint8_t ui8Pins){
  HWREG(ui32Port + GPIO_O_LOCK) = GPIO_LOCK_KEY; // Unlock the commit register
  HWREG(ui32Port + GPIO_O_CR) |= 0x01 << ui8Pins;// Write 0x01 to the corresponding bit in commit register
  HWREG(ui32Port + GPIO_O_LOCK) = 0;//��������
}

int a=0;
void PortFIntHandler(void)//�жϳ���
{
	SysCtlDelay(100000);
  GPIOIntClear(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4);//����жϱ�־	
	if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0) == 0){
//		a++;
	}
	if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4) == 0){
//		a++;
	}
}


void PortBIntHandler(void)//�жϳ���
{
	SysCtlDelay(100000);
  GPIOIntClear(GPIO_PORTB_BASE, GPIO_PIN_2);//����жϱ�־	
	if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_2) == 0){
		a++;
	}
}



void KEY_Init(void)
{    
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//ʹ��GPIO����
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//ʹ��GPIO����
	
	gpio_unlock(GPIO_PORTF_BASE, 0);
	gpio_unlock(GPIO_PORTF_BASE, 4);
	gpio_unlock(GPIO_PORTB_BASE, 2);
	
  GPIOIntRegister(GPIO_PORTF_BASE, PortFIntHandler);//GPIOע���ж�
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);//�ж�����Դ
  GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//����Ϊ����
  GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4 , GPIO_BOTH_EDGES);//�жϴ�������Ϊ�½��ش���
  GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);//ʹ���ж�
  IntPrioritySet(INT_GPIOF,USER_INT7);
	
  GPIOIntRegister(GPIO_PORTB_BASE, PortBIntHandler);//GPIOע���ж�
  GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_2);//�ж�����Դ
  GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD);//����Ϊ����
  GPIOIntTypeSet(GPIO_PORTB_BASE, GPIO_PIN_2 , GPIO_BOTH_EDGES);//�жϴ�������Ϊ�½��ش���
  GPIOIntEnable(GPIO_PORTB_BASE, GPIO_PIN_2);//ʹ���ж�
  IntPrioritySet(INT_GPIOB,USER_INT7);
} 


Key_t Key = {
	KEY_Init,
};


