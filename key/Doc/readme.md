## IO外部中断配置工程

几乎所有IO都可以有外部中断，相同端口共用一个中断号
开发板上有两个按键，PF4 --> SW1 , PF0 --> SW2

我又多加一个中断，PB2

写了一个解锁IO的东西，关于这部分，看芯片手册684-685页
这个锁确实烦人，芯片手册679页有需要解锁的说明
解锁程序借鉴gpio_jtag例程


---健宝
