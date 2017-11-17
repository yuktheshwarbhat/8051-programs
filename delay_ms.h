void delay_ms(unsigned int n)
{
	unsigned char i;
	for(;n>0;n--)
	{
		for(i=250;i>0;i--);//501 mc
		for(i=247;i>0;i--);//495 mc
	}
}
