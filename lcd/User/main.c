#include "main.h"

uint8_t	SYS_Flag=0;

int main(void)
{
	FPULazyStackingEnable();//使能FPU浮点运算
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |//配置系统时钟，看芯片手册223页（Clock Control）
									 SYSCTL_OSC_MAIN);//SYSCTL_SYSDIV_2_5时80M
	
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
//		uint32_t clk = SysCtlClockGet();
//		Led.Light(1,0,0);
//		SysCtlDelay(10000000);//自己拿逻辑分析仪测的，大概900ms
//		Led.Light(-1,1,0);
//		SysCtlDelay(10000000);
//		Pwm.set(200,200,200,800);
//		int a=10;
//		printf("abc: %d\r\n",a);
//	LCD_ShowString(60 , 0 ,"Mode_Select:",MAGENTA);
//	LCD_ShowString(90 , 30 ,"Mode1",GREEN);
//	LCD_ShowString(90 ,50 ,"Mode2",GREEN);
//	LCD_ShowString(90 ,70 ,"Mode3",GREEN);
//	LCD_ShowString(90 ,90 ,"Mode4",GREEN);
//	LCD_ShowString(90 ,110 ,"Mode5",GREEN);
//	LCD_ShowString(90 ,130 ,"Mode6",GREEN);
//	LCD_ShowString(90 ,150 ,"Parameter1",GREEN);
//	LCD_ShowString(90 ,170 ,"Parameter2",GREEN);
//	LCD_ShowString(90 ,190 ,"Parameter3",GREEN);
//	
//	LCD_Fill(70,30,90,240 , BLACK);
//	LCD_ShowString(70,(2*20)+30, ">"  , YELLOW);
	}
}
