## PWM生成工程

芯片有两个PWM模块
总共可以产生16路PWM，一个PWM模块8路
一个PWM模块有四个发生器，一个发生器可以产生两路PWM
同一个发生器的产生的PWM频率是一样的

关于频率和占空比，就是计数
主频设置为80M，然后SysCtlPWMClockSet(SYSCTL_PWMDIV_8)分8频，也就得到计数一次需要1/(80M/8)s = 0.1us
所以此时我将PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, period)中period设置为1000就是10KHZ
占空间PWMPulseWidthSet(PWM0_BASE,PWM_OUT_1,width1)中width1设置为500就是50%占空比
0占空比默认是高电平，挺奇怪


PB6 --> PWM0;
PB7 --> PWM1;
PB4 --> PWM2;
PB5 --> PWM3;
开发板上PB7与PD1相连，PB6与PD0相连

具体看芯片手册1230页（Pulse Width Modulator (PWM)）


---健宝
