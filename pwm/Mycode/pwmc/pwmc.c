#include "main.h"



static void PWM_Output(uint16_t width1,uint16_t width2,uint16_t width3,uint16_t width4)
{
//  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_6,width);//PC4 
//  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_7,width);//PC5 
//  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_5,width);//PE5
//  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_4,width);//PE4
  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_0,width1);//PB6
  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_1,width2);//PB7
  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_2,width3);//PB4
  PWMPulseWidthSet(PWM0_BASE,PWM_OUT_3,width4);//PB5
}


static void Pwm_Init(void){
	
  SysCtlPWMClockSet(SYSCTL_PWMDIV_8); // Set divider to 80M/64=10M=0.1us
  SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); // Enable PWM peripheral
  SysCtlDelay(2); // Insert a few cycles after enabling the peripheral to allow the clock to be fully activated
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // Enable GPIOB peripheral
//  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC); // Enable GPIOC peripheral
//  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE); // Enable GPIOE peripheral
  SysCtlDelay(2); // Insert a few cycles after enabling the peripheral to allow the clock to be fully activated
  // Use alternate function
  GPIOPinConfigure(GPIO_PB6_M0PWM0);
  GPIOPinConfigure(GPIO_PB7_M0PWM1);
  GPIOPinConfigure(GPIO_PB4_M0PWM2);
  GPIOPinConfigure(GPIO_PB5_M0PWM3);
	
  
//  GPIOPinConfigure(GPIO_PE4_M0PWM4);
//  GPIOPinConfigure(GPIO_PE5_M0PWM5);
//  GPIOPinConfigure(GPIO_PC4_M0PWM6);
//  GPIOPinConfigure(GPIO_PC5_M0PWM7);
  // Use pin with PWM peripheral
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);//M0PWM0
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);//M0PWM1
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);//M0PWM2
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);//M0PWM3
  
//  GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4);//M0PWM4
//  GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5);//M0PWM5
//  GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);//M0PWM6
//  GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);//M0PWM7
  // Configure the PWM generator for count down mode with immediate updates to the parameters
  PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
  PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
  
//  PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
//  PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
  // The period set
  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 1000); // Set the period
  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 1000);
  
//  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, period); // Set the period
//  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, period);
  // Start the timers in generator 0 and 1
  PWMGenEnable(PWM0_BASE, PWM_GEN_0);
  PWMGenEnable(PWM0_BASE, PWM_GEN_1);
  
//  PWMGenEnable(PWM0_BASE, PWM_GEN_2);
//  PWMGenEnable(PWM0_BASE, PWM_GEN_3);
  // Enable the outputs
  PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT, true);
  //PWM_Output(0,0,0,0);
}





Pwm_t Pwm = {
	Pwm_Init,
	PWM_Output
};


