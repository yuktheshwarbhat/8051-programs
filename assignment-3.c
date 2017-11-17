#include<reg51.h>
#include"delay_ms.h"
#include"lcd8bit.h"
sbit sw1=P1^0;
sbit sw2=P1^1;
sbit sw3=P1^2;
unsigned char counter,status;

main()
{
	lcd_init();
	lcd_cmd(0x0c);
	counter=status=0;
	while(1)
	{
		
		if(sw1==0)
		{
			delay_ms(50);
			while(sw1==0);
			if(counter<60)
				counter++;
			status=0;
		}
		
		if(sw2==0)
		{
			delay_ms(50);
			while(sw2==0);
			if(counter>0)
				counter--;
			status=0;
		}
		
		if(sw3==0)
		{
			delay_ms(50);
			while(sw3==0);
			status=1;
		}
		
		if(status==1 && counter>0)
		{
			counter--;
			delay_ms(990);
		}
		
		lcd_cmd(0x80);
		lcd_integer(counter);
		
	}
	return 0;
}
		
	
