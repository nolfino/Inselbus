/*
 * BufferUart.c
 *
 *  Created on: 27.04.2015
 *
 */

#include "BufferUart.h"

//Defines
#define BUFLEN 128

//Varibles
unsigned char rxBuf[BUFLEN], txBuf[BUFLEN];
int rxBuf_in, rxBuf_out, txBuf_in, txBuf_out;



void bufferInit(void){

	//Sets the FIFO level at which interrupts are generated to one
//	UARTFIFOLevelSet(UART0_BASE,UART_FIFO_TX1_8, UART_FIFO_RX1_8);

	rxBuf_in = 0;
	rxBuf_out = 0;
	txBuf_in = 0;
	txBuf_out = 0;
}



void UARTIntHandler(void){
    uint32_t ui32Status;
    // Get the interrrupt status.
    ui32Status = ROM_UARTIntStatus(UART0_BASE, true);

    //Interrup UartSend
    if (ui32Status & UART_INT_TX){

    	UARTCharPut(UART0_BASE, txBuf[txBuf_out++]);          // Zeichen aus Tx-Buffer ins Sende-Register legen
		if (txBuf_out >= BUFLEN)              // Index nachführen...
		{
		  txBuf_out = 0;                      // ... und evtl zurücksetzen
		}
		if (txBuf_in == txBuf_out)            // Ist Tx-Buffer leer?
		{
			//IE1 &= ~UTXIE0;                     // ... Dann Tx-Interrupt ausschalten
			ROM_UARTIntDisable(UART0_BASE, UART_INT_TX);
		}
    }

    //Interrupt UartReceive
    if(ui32Status & UART_INT_RX){
		signed int length;

		length = rxBuf_in - rxBuf_out;        // Länge berechnen
		if (length < 0){                       // Falls ein negativer Wert...
			length += BUFLEN;                   // ... Bufferlänge dazu addieren
		}
		if (length < (BUFLEN-1)){              // Wenn Rx-Buffer noch nicht voll...
			rxBuf[rxBuf_in++] = UARTCharGet(UART0_BASE);         // Zeichen in Ringbuffer einfügen
			if (rxBuf_in >= BUFLEN){             // Index nachführen...
				rxBuf_in = 0;                     // ... und evtl zurücksetzen
		    }
	    }
    }
}



unsigned char bufferReceive (void)
{
	unsigned char c;
	if (rxBuf_in != rxBuf_out){            // Ist Rx-Buffer nicht leer?
		c = rxBuf[rxBuf_out++];             // Zeichen aus Rx-Buffer holen
		if (rxBuf_out >= BUFLEN){            // Index nachführen...
		  rxBuf_out = 0;                    // ... und evtl. zurücksetzen
		}
		return c;                           // Zeichen als return-Wert
	}
	return 0;	                            // Signalisieren, dass kein Zeichen gelesen wurde
}


int bufferSend (unsigned char c){
	signed int length;

	length = txBuf_in - txBuf_out;        // Länge berechnen
		if (length < 0){                       // Falls ein negativer Wert...
			length += BUFLEN;                   // ... Bufferlänge dazu addieren
		}
		if (length < (BUFLEN -1)){             // wenn Tx-Buffer noch nicht voll
			txBuf[txBuf_in++] = c;              // Zeichen einfügen in Ringbuffer
			if (txBuf_in >= BUFLEN) {            // Index nachführen...
				txBuf_in = 0;                     // ... und evtl. zurücksetzen
			}
// 		IE1 |= UTXIE0;                      // Enable USART0 TX interrupt
		ROM_UARTIntEnable(UART0_BASE, UART_INT_TX);
		return 1;                           // return Wert: alles OK, Zeichen einfgefügt
		}
//  IE1 |= UTXIE0;                        // Enable USART0 TX interrupt
	ROM_UARTIntEnable(UART0_BASE, UART_INT_TX);
	return 0;                             // return Wert: Fehler, Zeichen nicht eingefügt
}
