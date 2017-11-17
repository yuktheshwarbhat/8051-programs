sfr LCD_PORT = 0x80;
sbit RS=P3^4;
sbit RW=P3^5;
sbit EN = P3^6;

void lcd_cmd(unsigned char c)
{
 LCD_PORT=c;
 RS=0;
 RW=0;
 EN=1;
 delay_ms(2);
 EN=0;
 }
 
 void lcd_data(unsigned char c)
 {
 LCD_PORT=c;
 RS=1;
 RW=0;
 EN=1;
 delay_ms(2);
 EN=0;
 }
 
 void lcd_init()
 {
  lcd_cmd(0x02);
  lcd_cmd(0x38);
  lcd_cmd(0x06);
  lcd_cmd(0x0e);
  lcd_cmd(0x01);
  }
  
  void lcd_string(char *s)
  {
    while(*s)
	  lcd_data(*s++); 
}