#include <reg51.h>
#include"delay_ms.h"
#include"lcd8bit.h"
void lcd_scrol(unsigned char *s)
{
    unsigned char name[20]="";
	unsigned char i=0,j=0;
	while(*s)
	 {
	 j++;
	 name[i]=*s++;
	 i++;
	 }
	lcd_init();
	lcd_cmd(0x0c);//lcd cursor off
	while(1)
	{
	for(i=0;i<16;i++)
	{
		lcd_cmd(0x01);//clear lcd screen
		if((i+j+1)>16)  //To check whether name exceeds first line
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

