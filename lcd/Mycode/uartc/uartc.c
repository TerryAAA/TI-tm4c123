#include "main.h"


void UART1_IRQHandler(void)//UART中断函数
{				
  //获取中断标志 原始中断状态 不屏蔽中断标志		
  uint32_t flag = UARTIntStatus(UART1_BASE,1);
  //清除中断标志	
  UARTIntClear(UART1_BASE,flag);
  //判断FIFO是否还有数据		
  while(UARTCharsAvail(UART1_BASE))		
  {			
//    char ch = UARTCharGet(UART1_BASE);
		UART1_CallBack();
//		UARTCharPut(UART1_BASE, 0x05);
  }
}



void UART2_IRQHandler(void)//UART中断函数
{				
  //获取中断标志 原始中断状态 不屏蔽中断标志		
  uint32_t flag = UARTIntStatus(UART2_BASE,1);
	
  //清除中断标志	
  UARTIntClear(UART2_BASE,flag);
  //判断FIFO是否还有数据		
  while(UARTCharsAvail(UART2_BASE))		
  {			
//    char ch = UARTCharGet(UART2_BASE);
		UART2_CallBack();
//    UARTCharPut(UART2_BASE, 0x05);
  }
}


static void Uart0_Init(void){
  
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);//使能GPIO外设		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);//使能UART外设
	
  GPIOPinConfigure(GPIO_PA0_U0RX);//GPIO模式配置 PA0--RX PA1--TX 
  GPIOPinConfigure(GPIO_PA1_U0TX);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO的UART模式配置
	
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
											(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
											 UART_CONFIG_PAR_NONE));//UART协议配置 波特率115200 8位 1停止位  无校验位	
}


static void Uart1_Init(void){

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//使能GPIO外设		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);//使能UART外设
  GPIOPinConfigure(GPIO_PB0_U1RX);//GPIO模式配置 PB0--RX PB1--TX 
  GPIOPinConfigure(GPIO_PB1_U1TX);
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);//GPIO的UART模式配置
	
	UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 115200,
											(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
											 UART_CONFIG_PAR_NONE));//UART协议配置 波特率115200 8位 1停止位  无校验位	
	
	
	UARTFIFODisable(UART1_BASE);//禁用FIFO 默认FIFO Level为4/8 寄存器满8字节后产生中断，禁用后接收1位就产生中断	
  UARTIntEnable(UART1_BASE,UART_INT_RX);//使能UART接收中断		
  UARTIntRegister(UART1_BASE,UART1_IRQHandler);//UART中断地址注册	
  IntPrioritySet(INT_UART1, USER_INT5);
}


static void Uart2_Init(void){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//使能GPIO外设		
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);//使能UART外设
  
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;//解锁PD6
  HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;//确认
  HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;//重新锁定
  
  GPIOPinConfigure(GPIO_PD6_U2RX);//GPIO模式配置 PD6--RX PD7--TX 
  GPIOPinConfigure(GPIO_PD7_U2TX);
  GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);//GPIO的UART模式配置
	
  UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 115200,
                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                       UART_CONFIG_PAR_NONE));
	
  UARTFIFODisable(UART2_BASE);//禁用FIFO 默认FIFO Level为4/8 寄存器满8字节后产生中断，禁用后接收1位就产生中断	
  UARTIntEnable(UART2_BASE,UART_INT_RX);//使能UART接收中断		
  UARTIntRegister(UART2_BASE,UART2_IRQHandler);//UART中断地址注册	
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


/************printf重定向相关**************/
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

