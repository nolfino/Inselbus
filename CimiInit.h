/*
 * CimiInit.h
 *
 *  Created on: 21.04.2015
 *      Author: nolfic
 */
#ifndef CIMIINIT_H_
#define CIMIINIT_H_


#include <stdint.h> 	//uint8_t etc.


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
}Host;

Host cimi;


void cimiInit(void);
void setDeviceAddress(uint8_t aAddress);
void setLayer(uint8_t aLayer);
void setLocalParam(void);



#endif /* CIMIINIT_H_ */


