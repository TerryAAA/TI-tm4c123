#include "main.h"



void ADC_Init(void)//ADC初始化配置   
{    
  SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);// Enable the ADC1 module.
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));// Wait for the ADC module to be ready.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);    
	
  GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
	GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2);
	GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_1);
	
  //ADCReferenceSet(ADC0_BASE, ADC_REF_EXT_3V);
  //Enable the first sample sequencer to capture the value of channel 0 when
  //the processor trigger occurs.  
  ADCSequenceConfigure(ADC0_BASE,0,ADC_TRIGGER_PROCESSOR, 0); 
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0 |ADC_CTL_END | ADC_CTL_IE); 
	ADCSequenceEnable(ADC0_BASE, 0);    
  ADCIntClear(ADC0_BASE, 0);
	
	ADCSequenceConfigure(ADC0_BASE,1,ADC_TRIGGER_PROCESSOR, 0); 
	ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH1 |ADC_CTL_END | ADC_CTL_IE); 
	ADCSequenceEnable(ADC0_BASE, 1);    
  ADCIntClear(ADC0_BASE, 1);
	
	ADCSequenceConfigure(ADC0_BASE,2,ADC_TRIGGER_PROCESSOR, 0); 
	ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_CH2 |ADC_CTL_END | ADC_CTL_IE); 
	ADCSequenceEnable(ADC0_BASE, 2);    
  ADCIntClear(ADC0_BASE, 2);
} 


//uint32_t value;
//uint32_t value1;
//uint32_t value2;
uint32_t ADC_Get(uint8_t ch)//ADC获取   
{
	uint32_t value;
	if(ch == 0){
		ADCProcessorTrigger(ADC0_BASE, 0);   
		while(!ADCIntStatus(ADC0_BASE, 0, false)) {;}
		ADCIntClear(ADC0_BASE, 0);	
		ADCSequenceDataGet(ADC0_BASE, 0, &value);   
	}

	if(ch == 1){
		ADCProcessorTrigger(ADC0_BASE, 1);   
		while(!ADCIntStatus(ADC0_BASE, 1, false)) {;}
		ADCIntClear(ADC0_BASE, 1);	
		ADCSequenceDataGet(ADC0_BASE, 1, &value); 
	}
	
	if(ch == 2){
		ADCProcessorTrigger(ADC0_BASE, 2);   
		while(!ADCIntStatus(ADC0_BASE, 2, false)) {;}
		ADCIntClear(ADC0_BASE, 2);	
		ADCSequenceDataGet(ADC0_BASE, 2, &value);			
	}
	
	return value;
}


Adc_t Adc = {
	ADC_Init,
	ADC_Get
};


