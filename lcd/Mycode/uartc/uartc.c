#include "main.h"


void UART1_IRQHandler(void)//UART�жϺ���
{				
  //��ȡ�жϱ�־ ԭʼ�ж�״̬ �������жϱ�־		
  uint32_t flag = UARTIntStatus(UART1_BASE,1);
  //����жϱ�־	
  UARTIntClear(UART1_BASE,flag);
  //�ж�FIFO�Ƿ�������		
  while(UARTCharsAvail(UART1_BASE))		
  {			
//    char ch = UARTCharGet(UART1_BASE);
		UART1_CallBack();
//		UARTCharPut(UART1_BASE, 0x05);
  }
}



void UART2_IRQHandler(void)//UART�жϺ���
{				
  //��ȡ�жϱ�־ ԭʼ�ж�״̬ �������жϱ�־		
  uint32_t flag = UARTIntStatus(UART2_BASE,1);
	
  //����жϱ�־	
  UARTIntClear(UART2_BASE,flag);
  //�ж�FIFO�Ƿ�������		
  while(UARTCharsAvail(UART2_BASE))		
  {			
//    char ch = UARTCharGet(UART2_BASE);
		UART2_CallBack();
//    UARTCharPut(UART2_BASE, 0x05);
  }
}


static void Uart0_Init(void){
  
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);//ʹ��UART����
	
  GPIOPinConfigure(GPIO_PA0_U0RX);//GPIOģʽ���� PA0--RX PA1--TX 
  GPIOPinConfigure(GPIO_PA1_U0TX);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
	
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
											(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
											 UART_CONFIG_PAR_NONE));//UARTЭ������ ������115200 8λ 1ֹͣλ  ��У��λ	
}


static void Uart1_Init(void){

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);//ʹ��UART����
  GPIOPinConfigure(GPIO_PB0_U1RX);//GPIOģʽ���� PB0--RX PB1--TX 
  GPIOPinConfigure(GPIO_PB1_U1TX);
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO��UARTģʽ����
	
	UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 115200,
											(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
											 UART_CONFIG_PAR_NONE));//UARTЭ������ ������115200 8λ 1ֹͣλ  ��У��λ	
	
	
	UARTFIFODisable(UART1_BASE);//����FIFO Ĭ��FIFO LevelΪ4/8 �Ĵ�����8�ֽں�����жϣ����ú����1λ�Ͳ����ж�	
  UARTIntEnable(UART1_BASE,UART_INT_RX);//ʹ��UART�����ж�		
  UARTIntRegister(UART1_BASE,UART1_IRQHandler);//UART�жϵ�ַע��	
  IntPrioritySet(INT_UART1, USER_INT5);
}


static void Uart2_Init(void){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//ʹ��GPIO����		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);//ʹ��UART����
  
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;//����PD6
  HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;//ȷ��
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;//��������
  
  GPIOPinConfigure(GPIO_PD6_U2RX);//GPIOģʽ���� PD6--RX PD7--TX 
  GPIOPinConfigure(GPIO_PD7_U2TX);
  GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);//GPIO��UARTģʽ����
	
  UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 115200,
                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                       UART_CONFIG_PAR_NONE));
	
  UARTFIFODisable(UART2_BASE);//����FIFO Ĭ��FIFO LevelΪ4/8 �Ĵ�����8�ֽں�����жϣ����ú����1λ�Ͳ����ж�	
  UARTIntEnable(UART2_BASE,UART_INT_RX);//ʹ��UART�����ж�		
  UARTIntRegister(UART2_BASE,UART2_IRQHandler);//UART�жϵ�ַע��	
  IntPrioritySet(INT_UART2, USER_INT5);
}


Uart0_t Uart0 = {
	Uart0_Init
};
Uart1_t Uart1 = {
	Uart1_Init
};
Uart2_t Uart2 = {
	Uart2_Init
};


/************printf�ض������**************/
int fputc(int ch, FILE *f)
{
	UARTCharPut(UART0_BASE, ch);
  return ch;
}

int fgetc(FILE *f)
{
  uint8_t ch = 0;
  ch = UARTCharGet(UART0_BASE);
  return ch;
}

