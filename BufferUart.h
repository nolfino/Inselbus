/*
 * BufferUart.h
 *
 *  Created on: 27.04.2015
 *      Author: nolfic
 */

#ifndef BUFFERUART_H_
#define BUFFERUART_H_

#include <stdint.h>
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

void bufferInit(void);
int bufferSend (unsigned char c);
unsigned char bufferReceive (void);

#endif /* BUFFERUART_H_ */
