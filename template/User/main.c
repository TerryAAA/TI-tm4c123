#include "main.h"



int main(void)
{
	FPULazyStackingEnable();//使能FPU浮点运算
	SysCtlClockSet(SYSCTL_SYSDIV_2 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |//配置系统时钟，看芯片手册223页（Clock Control）
									 SYSCTL_OSC_MAIN);//SYSCTL_SYSDIV_2_5时80M，实际SYSCTL_SYSDIV_2时有100M


	while(1)
	{
		
	}
}
