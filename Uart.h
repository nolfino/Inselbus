/*
 * Uart.h
 *
 *  Created on: 21.04.2015
 *      Author: nolfic
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h> 	//uint8_t etc.
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"


void sendUart(uint8_t * pMessage, uint8_t legth);
void UARTSendChar(const uint8_t *pui8Buffer, uint32_t ui32Cout);



#endif /* UART_H_ */
