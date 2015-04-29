/*
 * main.c
 * includein Project Properties
 * 		in Build, ARM Linker, FileSearchPatch "d:ti/tivaware/drivelib/css/debug/driverlib"
 * 		unter Build, ARM compiler, advanced, predefined Symbols "TARGET_IS_TM4C129_RA0"
 */

#include <stdint.h> 	//uint8_t etc.
#include <stdio.h>
#include <string.h>
#include "Uart.h"
#include "buttons.h"

#include "CimiInit.h"
#include "BufferUart.h"
#include "UartInit.h"


uint8_t schliesseRelais [18] =	{0x7e,0x03,0x52,0xc6,0x00,0x61,0x09,0x05,0xc0,0x60,0x01,0x14,0x44,0x01,0x06,0x07,0xf7,0x7e};
uint8_t offeRelais [18] =			{0x7e,0x03,0x53,0xc6,0x00,0x61,0x09,0x05,0xc0,0x60,0x01,0x14,0x44,0x00,0x06,0x72,0xeb,0x7e};

int main(void) {
	
	//Initialisation
	initUart();
	bufferInit();
    ButtonsInit();

	//CimiInit
	setDeviceAddress(0xc2);
	setLayer(0xD0);
	cimiInit();


    uint8_t Data = 0;
    uint8_t temp =3;

	int i = 0;
	while (1){

	    // Grab the current, debounced state of the buttons.
	    Data = (ROM_GPIOPinRead(BUTTONS_GPIO_BASE, ALL_BUTTONS));

	    if (Data != 3){
	    	if (temp != Data){
				if (Data >1){
					sendUart(schliesseRelais,18);
				}
				else{
					sendUart(offeRelais,18);
				}
	    	}
	    temp = Data;
	    }

	}
}

