#include <reg51.h>
#include "delay_ms.h"
#include "lcd8bit.h"
#include "keypad.h"

code unsigned char psswd[5]="ABCD";

main()
{
	unsigned char temp,i,v;
	lcd_init();
	while(1)
	{
		lcd_cmd(0x80);
		lcd_string("Enter password");
		lcd_cmd(0xc0);
    //lcd_cmd(0x0f);
		temp=0;
		for(i=0;i<4;i++)
		{
			while(!(v=keyscan()));
			if(v!=psswd[i])
				  temp++;
			lcd_data('*');
			delay_ms(1000);
		}
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		if(temp==0)
		{	lcd_string("Access Granded");
		}
		else{
			lcd_string("Access Denied");
		}	
		delay_ms(2000);
	}
}	
