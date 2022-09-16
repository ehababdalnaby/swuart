Article type: Project
Software UART
Please Note
This project IS NOT A TAKE HOME TASK and it must be submitted during the assessment time.








#ifndef DIO_H_
#define DIO_H_


#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1

/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * direction: is an input argument that describes the data direction on a specific pin, IN or OUT
 */
 void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction);
 
 /*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * value: is an input argument that describes the value on a specific pin, LOW or HIGH
 */
 void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value);

/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * value: is an output argument that describes the value on a specific pin, LOW or HIGH
 */
 void DIO_read(uint8_t pinNumber, uint8_t port, uint8_t *value);
 
 
 #endif //DIO_H_