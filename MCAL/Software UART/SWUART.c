
//############# SWUART.c ##############
#include "SWUART.h"

uint8_t parityState = PARITY_NOK;

float64_t bitTime = 0;
void SWUART_init(uint32_t baudrate)
{
	DIO_init(TX, UART_PORT, OUT);
	DIO_init(RX, UART_PORT, IN);
	DIO_write(TX, UART_PORT, HIGH);
	Timer0_init(NORMAL,clkI_No_DIVISON);
	bitTime = (float64_t)1/baudrate;
}


//1010111001
void SWUART_send(uint8_t data)
{
	//start bit
	DIO_write(TX, UART_PORT, LOW);
	Timer0_delay_ms(bitTime);
	//send data bits
	uint8_t parity = 0;
	for(uint8_t i = 0; i < 8;i++)
	{
		parity ^=getBit(data,7-i);
		DIO_write(TX, UART_PORT, getBit(data,7-i));
		Timer0_delay_ms(bitTime);
	}
	//send parity bit
	DIO_write(TX, UART_PORT, parity);
	Timer0_delay_ms(bitTime);
	//stop bit
	DIO_write(TX, UART_PORT, HIGH);
	Timer0_delay_ms(2*bitTime);
}


void SWUART_recieve(uint8_t *data)
{
	uint8_t bitValue = 0;
	*data = 0;
	uint8_t parity = 0;
	uint8_t parityRec = 0;
	
	
	//wait start bit
	do
	{
		DIO_read(RX,UART_PORT , &bitValue);
	}while(bitValue!=0);
	Timer0_delay_ms(bitTime);
	
	//recieve data bits
	for(uint8_t i = 0; i < 8;i++)
	{
		DIO_read(RX,UART_PORT , &bitValue);
		Timer0_delay_ms(bitTime);
		*data = (*data)<<i;
		*data |=bitValue;
		parity ^=bitValue;
	}
	//recieve parity bit
	DIO_read(RX,UART_PORT , &parityRec);
	Timer0_delay_ms(bitTime);
	
	//recieve stop bits
	DIO_read(RX,UART_PORT , &bitValue);
	Timer0_delay_ms(bitTime);
	DIO_read(RX,UART_PORT , &bitValue);
	Timer0_delay_ms(bitTime);
	
	if(parity == parityRec)
	{
		parityState = PARITY_OK;
	}
	else
	{
		parityState = PARITY_NOK;
	}
}


//////////////////////////////////////////////////////////