#include "main.h"



int main(void)
{
	FPULazyStackingEnable();//ʹ��FPU��������
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |//����ϵͳʱ�ӣ���оƬ�ֲ�223ҳ��Clock Control��
									 SYSCTL_OSC_MAIN);//SYSCTL_SYSDIV_2_5ʱ80M
	Uart0.Init();
	Uart1.Init();
	Uart2.Init();
	Timer.Init();
	Led.Init();
	Pwm.Init();
	Scheduler_Init();
	
	Led.Light(1,1,1);
	while(1)
	{
//		uint32_t clk = SysCtlClockGet();
//		Led.Light(1,0,0);
//		SysCtlDelay(10000000);//�Լ����߼������ǲ�ģ����900ms
//		Led.Light(-1,1,0);
		SysCtlDelay(10000000);
//		Pwm.set(200,200,200,800);
		int a=10;
		printf("abc: %d\r\n",a);
	}
}
