/*
 * InitUart.h
 *
 *  Created on: 21.04.2015
 *      Author: nolfic
 */

#ifndef UARTINIT_H_
#define UARTINIT_H_

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



//Functions
void initUart(void);
unsigned char receive (void);


#endif /* UARTINIT_H_ */
