unsigned char buf[10];
void uart_init()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=TL1=-3;
	TR1=1;
}

void uart_tx(unsigned char n)
{
	SBUF=n;
	while(TI==0);
	TI=0;
}

unsigned char uart_rx()
{
	while(RI==0);
	RI=0;
	return SBUF;
}

void uart_string(char *s)
{
	while(*s)
		uart_tx(*s++);
}

void uart_integer(long int n)
{
	
	char i;
	if(n<0)
	{
		n=-n;
		uart_tx('-');
	}
	for(i=0;n;n/=10,i++)
  	buf[i]=n%10;
	for(i-=1;i>=0;i--)
	  uart_tx(buf[i]+48);
}

void uart_float(float n)
{
	int d,p;
	d=(int)n;
	n-=d;
  n*=10000;
  uart_integer(d);
	uart_tx('.');
  if(n<0)
  n=-n;
  uart_integer(n);
}	