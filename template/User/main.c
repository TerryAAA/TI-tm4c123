#include "main.h"



int main(void)
{
	FPULazyStackingEnable();//ʹ��FPU��������
	SysCtlClockSet(SYSCTL_SYSDIV_2 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |//����ϵͳʱ�ӣ���оƬ�ֲ�223ҳ��Clock Control��
									 SYSCTL_OSC_MAIN);//SYSCTL_SYSDIV_2_5ʱ80M��ʵ��SYSCTL_SYSDIV_2ʱ��100M


	while(1)
	{
		
	}
}
