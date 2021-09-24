## uart配置工程

串口0的接收端不能用，串口1正常，串口2也不正常，涉及到芯片部分IO解锁的东西



开发板上PA0与PA1莫得，是跟调试引脚搞出来的，看下原理图就知道在哪里
PB0 --> UART1_RX;
PB1 --> UART1_TX;
PD6 --> UART2_RX;
PD7 --> UART2_TX;

接受UARTCharGet
发送UARTCharPut


---健宝
