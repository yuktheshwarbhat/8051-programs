void delay_ms(unsigned int n)
{
	unsigned int i;
	unsigned char j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<247;j++);
		for(j=0;j<250;j++);
	}	
}