#include "main.h"

uint32_t adcval;
uint32_t adcval1;
uint32_t adcval2;

int main(void)
{
	FPULazyStackingEnable();//ʹ��FPU��������
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |//����ϵͳʱ�ӣ���оƬ�ֲ�223ҳ��Clock Control��
									 SYSCTL_OSC_MAIN);//SYSCTL_SYSDIV_2_5ʱ80M
	
	Adc.Init();
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
//		int a=10;
//		printf("abc: %d\r\n",a);
		adcval=Adc.Get(0);
		adcval1=Adc.Get(1);
		adcval2=Adc.Get(2);
	}
}
