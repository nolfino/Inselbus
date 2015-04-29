/*
 * Uart.c
 *
 *  Created on: 21.04.2015
 *      Author: nolfic
 */

#include "Uart.h"






void sendUart(uint8_t *pMessage, uint8_t length){
	unsigned char ucData;

	//Loop while send
	while(length--){
		ucData =*pMessage++;
		UARTCharPut( UART0_BASE, ucData);
	};
};



void UARTSendChar(const uint8_t *pui8Buffer, uint32_t ui32Cout){
	unsigned char ucData;
	//Loop while send
	while(ui32Cout--){
		ucData =*pui8Buffer++;
		//UARTCharPut( UART0_BASE, ucData);
	};
};






