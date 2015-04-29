/*
 * CimiInit.c
 *
 *  Created on: 21.04.2015
 *      Author: nolfic
 */



#include "CimiInit.h"
#include "Uart.h"


Host cimi;

void setLocalParam(void){
    uint8_t CimiGetLocalParam[21] = { 	0x7e,
    								  	0x03,
    									0x43,
										0xe4,
										0x00,
										cimi.deviceAddress,
										cimi.setLayer,
										cimi.lpduMaxLength,
										cimi.auxiliaryControls,
										cimi.dc24v,
										cimi.chipID,
										cimi.firmwareVersion0,
										cimi.firmwareVersion1,
										cimi.reserved,
										cimi.cimiVersion,
										cimi.cimiCapabilities1,
										cimi.cimiCapabilities0,
    									0x06,
										0x23,
										0x34,
										0x7e};

	sendUart(CimiGetLocalParam, 21);
};

void setDeviceAddress(uint8_t aAdress){
	cimi.deviceAddress = aAdress;
};

void setLayer(uint8_t aLayer){
};

void cimiInit(void){
	setLocalParam();
};




