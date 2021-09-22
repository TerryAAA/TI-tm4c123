#include "main.h"

uint8_t	SYS_Flag=0;

int main(void)
{
	FPULazyStackingEnable();//使能FPU浮点运算
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |//配置系统时钟，看芯片手册223页（Clock Control）
									 SYSCTL_OSC_MAIN);//SYSCTL_SYSDIV_2_5时80M
	
	Flash.Init();
//	Parameter_Buffer[1]=90;
//	Flash.Write();
	Flash.Read();
	Lcd_Init();			//初始化OLED  
	LCD_Clear(BLACK);
	BACK_COLOR=BLACK;
	Key.Init();
	Uart0.Init();
	Uart1.Init();
	Uart2.Init();
	Timer.Init();
	Led.Init();
	Pwm.Init();
	Scheduler_Init();
	
	Led.Light(1,1,1);
	SYS_Flag=1;
	
	while(1)
	{
		UI.Main();
		if(P_Flag==1){
			Flash.Write();
			P_Flag=0;
		}
	}
}
