/*
 * Modul.h
 *
 *  Created on: 28.04.2015
 *      Author: nolfic
 */

#ifndef MODUL_H_
#define MODUL_H_

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


typedef struct {
	unsigned char deviceAddress;
	unsigned char setLayer;
	unsigned char lpduMaxLength;
	unsigned char auxiliaryControls;
	unsigned char dc24v;
	unsigned char chipID;
	unsigned int firmwareVersion0;
	unsigned int firmwareVersion1;
	unsigned char reserved;
	unsigned char cimiVersion;
	unsigned int cimiCapabilities0;
	unsigned int cimiCapabilities1;
}ModOut;

typedef struct {
	unsigned char deviceAddress;
	unsigned char setLayer;
	unsigned char lpduMaxLength;
	unsigned char auxiliaryControls;
	unsigned char dc24v;
	unsigned char chipID;
	unsigned int firmwareVersion0;
	unsigned int firmwareVersion1;
	unsigned char reserved;
	unsigned char cimiVersion;
	unsigned int cimiCapabilities0;
	unsigned int cimiCapabilities1;
}ModIn;

ModOut out;
ModIn in;

void prepareMessage(uint8_t *pointer, uint8_t length);



#endif /* MODUL_H_ */
