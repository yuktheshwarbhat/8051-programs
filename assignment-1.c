#include<reg51.h>

void delay_ms(unsigned int);
sbit sw=0x90^0;
sfr port2=0xA0;

unsigned char a;
unsigned int delay;

void main()
{
unsigned char i;
while(1)
{ 
	a=0;
	delay=1000;
	while(a<3)
	{
		for(i=0;i<8;i++)
		{
			port2=(1<<i)^0x0f;
			delay_ms(delay);
			if(sw==0)
		  {
				 while(sw==0);
				 a++;
			   if(a==0)
					  delay=1000;
				 else if(a==1)
					  delay=500;
				 else
					  delay=100;
         break;
	   	}
		}
	}
}
} 
void delay_ms(unsigned int n)
{
	unsigned int k;
	unsigned char j;
	for(k=0;k<n;k++)
	{
		for(j=0;j<247;j++);
		for(j=0;j<250;j++);
	}	
}