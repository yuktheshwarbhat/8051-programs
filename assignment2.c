#include<reg51.h>
#include"delay_ms.h"
#include"led8bit.h"
sbit sw=P1^0;
unsigned char a;

main()
{
	lcd_init();
	lcd_cmd(0x0c);
	while(1)
	{
		a=0;
		lcd_cmd(0x80);
		lcd_integer(a);
		lcd_cmd(0x88);
		lcd_hex(a);
		lcd_cmd(0xc0);
		lcd_bin(a);
		while(a<60)
		{
	if(sw==0)
	{
		a++;
		delay_ms(100);
		while(sw==0);
		lcd_cmd(0x80);
		lcd_integer(a);
		lcd_cmd(0x88);
		lcd_hex(a);
		lcd_cmd(0xc0);
		lcd_bin(a);
	}
  }
}
}
	