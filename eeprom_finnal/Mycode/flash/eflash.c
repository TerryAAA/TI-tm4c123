#include "eflash.h"


#define myEEPROM_BASE 0x0000 	//EEPROM的起始地址
uint32_t Parameter_Buffer[18]={0};




void EEPROM_Init(void)
{
  /* EEPROM SETTINGS */
  SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0); // EEPROM activate
  EEPROMInit(); // EEPROM start
}

void EEPROM_Write(void)	
{ 
  EEPROMProgram(Parameter_Buffer,myEEPROM_BASE,18*4);
}

void EEPROM_Read(void)   	
{
  EEPROMRead(Parameter_Buffer,myEEPROM_BASE,18*4);
}







Flash_t Flash = {
	
	EEPROM_Init,
	EEPROM_Write,
	EEPROM_Read,
};
