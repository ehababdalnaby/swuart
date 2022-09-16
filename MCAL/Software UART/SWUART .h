




#ifndef SWUART_H_
#define SWUART_H_

#include"Dio.h"
#include "Timer_0.h"



#define TX 0
#define RX 1
#define UART_PORT A


/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate);

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data);
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data);
 
 #endif //SWUART_H_