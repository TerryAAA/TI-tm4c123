#include "main.h"


void TIMER0A_Handler(void){

	Timer_CallBack();
	TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
}



static void Timer_Init(void){

  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);							//��ʱ��0ʹ��				
  TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC);						//32λ���ڶ�ʱ��				
  TimerLoadSet(TIMER0_BASE,TIMER_A,SysCtlClockGet()/1000);	//�趨װ��ֵ,��80M/1000��*1/80M=1ms				
  IntEnable(INT_TIMER0A);																		//���ж�ʹ��				
  TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT); 					//�ж����, ����ģʽ;			
  TimerIntRegister(TIMER0_BASE,TIMER_A,TIMER0A_Handler);		//�жϺ���ע��
  TimerEnable(TIMER0_BASE,TIMER_A); 												//��ʱ��ʹ�ܿ�ʼ����
  IntPrioritySet(INT_TIMER0A,USER_INT7);
}




Timer_t Timer = {
	Timer_Init
};


