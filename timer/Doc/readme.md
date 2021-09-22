## 定时器定时中断工程

这个芯片定时器有16/32/64几种模式，一个定时器包含A\B两个子定时器
有6个这样子的定时器t0~t5，不过t4和t5两个定时器的IO是调试引脚
具体看芯片手册704页（General-Purpose Timers）

关于优先级，值越大优先级越低，因此级别0是最高的中断优先级
每个中断的可编程优先级有0-7共八个
我也没弄明白，看例程来的，定义在了main.h里，USER_INT0~USER_INT7
具体看芯片手册124页（Nested Vectored Interrupt Controller (NVIC)）和164页（ Interrupt Priority Levels）

---健宝
