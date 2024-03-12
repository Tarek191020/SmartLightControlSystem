/*
 * main.c
 *
 * Created: 3/11/2024 4:54:49 AM
 *  Author: Tarek Alaa
 */ 

#include <xc.h>
#define F_CPU 16000000UL
#include <util/delay.h>
//include MCAL layer
#include "DIO_interface.h"
#include "ADC_interface.h"
//include HAL layer
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "LDR_interface.h"
#include "LED_interface.h"

int main(void)
{
	//initialize peripherals
	LCD_voidInit();
	LDR_voidInit();
	LED_voidInit();
	KEYPAD_voidInit();
	
	u8 str[]="light percentage: ";
	u8 str1[]="threshold: ";
	u8 str2[]="enter threshold";
	
	//variables
	u16 lightPercentage = 0;
	u8 threshold[2]={NOTPRESSED,NOTPRESSED};
	u8 num=0;
	LCD_voidWriteString(str2);
	LCD_voidGoToXY(1,0);
	//enter threshold
	while (threshold[0]==NOTPRESSED)
	{
		KEYPAD_voidGetbutton(&threshold[0]);
	}
	LCD_voidWriteData(threshold[0]);
	while (threshold[1]==NOTPRESSED)
	{
		KEYPAD_voidGetbutton(&threshold[1]);
	}
	LCD_voidWriteData(threshold[1]);
	num=((threshold[0]-48)*10)+(threshold[1]-48);
	_delay_ms(500);
	while(1)
    {
		//read LDR value
		LDR_voidGetLightIntinsity(&lightPercentage);
		LCD_voidClear();
		//display light percentage
		LCD_voidWriteString(str);
		LCD_voidWriteNumber(lightPercentage);
		//display threshold
		LCD_voidGoToXY(1,0);
		LCD_voidWriteString(str1);
		LCD_voidWriteNumber(num);
		
		if (lightPercentage>num)
		{
			LED_voidTurnOff();
		}
		else
		{
			LED_voidTurnOn();
		}
		_delay_ms(1000);
		
    }
}