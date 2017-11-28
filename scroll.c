#include <reg51.h>
#include"delay_ms.h"
#include"lcd8bit.h"
code char name[5]="amal";
void main()
{
	unsigned char i,j;
	lcd_init();
	lcd_cmd(0x0c);
	while(1)
	{
			j=4;
	for(i=0;i<16;i++)
	{
		lcd_cmd(0x01);
		if((i+j+1)>16)
		{
		   lcd_cmd(0x80);
			 lcd_string(name+j);
			j--;
		}
		lcd_cmd(0x80+i);		
		lcd_string(name);
		delay_ms(1000);
	}
  }
}