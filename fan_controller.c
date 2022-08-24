/*
 * fan_controller.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nourhan Ehab
 */
#include <string.h>
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "adc.h"

uint16 temprature=0;
char str1[20];
char str2[10];
ADC_ConfigType config_type ={INTERNAL_2_56V,F_CPU_8};

int main(void){
	ADC_init(&config_type);
	LCD_init();
	DCmotor_init();


	while(1){
		temprature = LM35_getTemperature();

		if (temprature <30){
			DCmotor_Rotate(STOP,0);
			LCD_moveCursor(0,1);
			strcpy(str1,"fan is off");
			strcpy(str2,"temp = ");
			LCD_displayString(str1);
			LCD_moveCursor(1,1);
			LCD_displayString(str2);
			LCD_intgerToString(temprature);
			LCD_displayCharacter('c');

		}
		else if((temprature >= 30) && (temprature <60)){
			DCmotor_Rotate(CW,64);
			LCD_moveCursor(0,1);
			strcpy(str1,"fan is ON ");
			strcpy(str2,"temp = ");
			LCD_displayString(str1);
			LCD_moveCursor(1,1);
			LCD_displayString(str2);
			LCD_intgerToString(temprature);
			LCD_displayCharacter('c');
		}
		else if((temprature >= 60) && (temprature <90)){
			DCmotor_Rotate(CW,128);
			LCD_moveCursor(0,1);
			strcpy(str1,"fan is ON ");
			strcpy(str2,"temp = ");
			LCD_displayString(str1);
			LCD_moveCursor(1,1);
			LCD_displayString(str2);
			LCD_intgerToString(temprature);
			LCD_displayCharacter('c');
	    }
		else if((temprature >= 90) && (temprature <120)){
		    DCmotor_Rotate(CW,192);
			LCD_moveCursor(0,1);
			strcpy(str1,"fan is ON ");
			strcpy(str2,"temp = ");
			LCD_displayString(str1);
			LCD_moveCursor(1,1);
			LCD_displayString(str2);
			LCD_intgerToString(temprature);
			LCD_displayCharacter('c');
		}
		else if(temprature >= 120){
			DCmotor_Rotate(CW,255);
			LCD_moveCursor(0,1);
			strcpy(str1,"fan is ON ");
			strcpy(str2,"temp = ");
			LCD_displayString(str1);
			LCD_moveCursor(1,1);
			LCD_displayString(str2);
			LCD_intgerToString(temprature);
			LCD_displayCharacter('c');
	}
 }
}


