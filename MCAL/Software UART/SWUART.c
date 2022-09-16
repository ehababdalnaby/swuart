

#include "SWUART.h"




float64_t bitTime = 0;
void SWUART_init(uint32_t baudrate)
{
	DIO_init(TX, UART_PORT, OUT);
	DIO_init(RX, UART_PORT, IN);
	DIO_write(TX, UART_PORT, HIGH);
	Timer0_init(NORMAL,clkI_No_DIVISON);
	bitTime = (float64_t)1/baudrate;
}



void SWUART_send(uint8_t data)
{
	//start bit
	DIO_write(TX, UART_PORT, LOW);
	Timer0_delay_ms(bitTime);
	//send data bits
	for(uint8_t i = 0; i < 8;i++)
	{
		DIO_write(TX, UART_PORT, getBit(data,7-i));
		Timer0_delay_ms(bitTime);
	}
	//stop bit
	DIO_write(TX, UART_PORT, HIGH);
	Timer0_delay_ms(2*bitTime);
}
