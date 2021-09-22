#include "main.h"


void TIMER0A_Handler(void){

	Timer_CallBack();
	TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
}



static void Timer_Init(void){

  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);							//定时器0使能				
  TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC);						//32位周期定时器				
  TimerLoadSet(TIMER0_BASE,TIMER_A,SysCtlClockGet()/1000);	//设定装载值,（80M/1000）*1/80M=1ms				
  IntEnable(INT_TIMER0A);																		//总中断使能				
  TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT); 					//中断输出, 设置模式;			
  TimerIntRegister(TIMER0_BASE,TIMER_A,TIMER0A_Handler);		//中断函数注册
  TimerEnable(TIMER0_BASE,TIMER_A); 												//定时器使能开始计数
  IntPrioritySet(INT_TIMER0A,USER_INT7);
}




Timer_t Timer = {
	Timer_Init
};


