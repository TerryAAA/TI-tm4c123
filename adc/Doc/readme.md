## ADC配置工程

芯片手册799页Analog-to-Digital Converter (ADC)
有三个ADC模块，12个ADC引脚
ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0 |ADC_CTL_END | ADC_CTL_IE)里的ADC_CTL_CH0代表引脚
第二个参数ui32SequenceNum可以看芯片手册799的图，据我理解就是不同通道用不同的ui32SequenceNum
第三个参数ui32Step据我理解就是触发到来时候的采集顺序（这个不清楚）

PE3 --> AIN0
PE2 --> AIN1
PE1 --> AIN2


---健宝
