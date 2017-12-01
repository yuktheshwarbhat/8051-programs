#include<reg51.h>
#include "uart.h"

int digit(char * ,int);
void calculator(int,char,int);

void main()
{
	idata unsigned char buf[5],i,sign,temp,op;
	int a,b;
	uart_init();
  uart_string("\t\tCalculator\r\n");
	while(1)
	{
		sign=i=0;
	uart_string("\r\n");
	 if((temp=uart_rx())=='-')
		 sign=1;
	 else
		buf[i++]=temp;
	uart_tx(temp);
	while((temp=uart_rx())>=48 && temp<=57)
	{
		buf[i++]=temp;
		uart_tx(temp);
	}
	buf[i]='\0';
	
	a=digit(buf,sign);
	
	op = temp;
  uart_tx(temp);	
	i=0;
	if((temp=uart_rx())=='-')
  		sign=1;
 	else
 		buf[i++]=temp;
	uart_tx(temp);
	while((temp=uart_rx())>=48 && temp<=57)
	{
		buf[i++]=temp;
		uart_tx(temp);
	}
	buf[i]='\0';
	uart_tx('=');
	b=digit(buf,sign);
		
	calculator(a,op,b);
	
}

}

int digit(char *s,int sign)
{
	int dig=0;
	unsigned char i;
	for(i=0;s[i];i++)
		dig=dig*10+(s[i]-48);
	if(sign)
		dig=-dig;
	return dig;
}

void calculator(int a, char op,int b)
{
	switch(op)
	{
		case '+':uart_integer(a+b);
		         break;
		case '-':uart_integer(a-b);
		         break;
		case '*':uart_integer(a*b);
		         break;
		case '/':if(b==0)
								uart_string("xx");
          	 else
			          uart_float((float)a/b);
		         break;
		default:uart_string("Invalid operator");
	}
}