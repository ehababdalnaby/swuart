


//############# main.c ##############


#include "SWUART.h"
int main()
{
	SWUART_init(9600);
	uint8_t data = 0;
	while(1)
	{
		SWUART_recieve(&data);
		SWUART_send(data);
	}
	
	
	return 0;
}


//////////////////////////////////////////////////////////