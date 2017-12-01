#include<reg51.h>
#include"uart.h"

void main()
{
	uart_init();
	uart_integer(205);
	uart_string("\r\n");
	uart_integer(2234);
	uart_string("\r\n");
	uart_integer(2089);
	uart_string("\r\n");
	
	uart_integer(20512);
	uart_string("\r\n");
	uart_float(208.225f);
	uart_string("\r\n");
	uart_float(2051.325f);
	while(1);
}
	
