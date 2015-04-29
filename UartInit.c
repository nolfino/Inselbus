/*
 * InitUart.c
 *
 *  Created on: 21.04.2015
 *      Author: nolfic
 */




#include "UartInit.h"



// System clock rate in Hz.

uint32_t g_ui32SysClock;



// The error routine that is called if the driver library encounters an error.
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif






void initUart(void){

	    // Set the clocking to run directly from the crystal at 120MHz.
	    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
	                                             SYSCTL_OSC_MAIN |
	                                             SYSCTL_USE_PLL |
	                                             SYSCTL_CFG_VCO_480), 120000000);

	    // Enable the peripherals used by this example.
	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	    // Enable processor interrupts.
	    ROM_IntMasterEnable();

	    // Set GPIO A0 and A1 as UART pins.
	    GPIOPinConfigure(GPIO_PA0_U0RX);
	    GPIOPinConfigure(GPIO_PA1_U0TX);
	    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	    // Configure the UART for 115,200, 8-N-1 operation.
	    ROM_UARTConfigSetExpClk(UART0_BASE, g_ui32SysClock, 115200,
	                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
	                             UART_CONFIG_PAR_NONE));

	    // Enable the UART interrupt.
	    ROM_IntEnable(INT_UART0);
	    ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
};





