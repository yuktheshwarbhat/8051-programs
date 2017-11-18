sbit  r0 = P2^0;
sbit  r1 = P2^1;
sbit  r2 = P2^2;
sbit  r3 = P2^3;
sbit  c0 = P1^0;
sbit  c1 = P1^1;
sbit  c2 = P1^2;
sbit  c3 = P1^3;

unsigned char lup[4][4]={{'A','B','C','1'},{'D','E','F','2'},{'G','H','I','3'},{'J','K','L','='}};

unsigned char keyscan(void)
{
	unsigned char row,col;
	row=0;col=0;
	r0=r1=r2=r3=0;
	c0=c1=c2=c3=1;
	while(c0&c1&c2&c3==1);
	delay_ms(20);
	
	r0=0;
	r1=r2=r3=1;
	if(c0&c1&c2&c3==0)
	{
		row=0;
		goto colcheck;
	}
	
	r1=0;
	r0=r2=r3=1;
	
	if(c0&c1&c2&c3==0)
	{
		row=1;
		goto colcheck;
	}
	r2=0;
	r0=r1=r3=1;
	if(c0&c1&c2&c3==0)
	{
		row=2;
		goto colcheck;
	}
	
	r3=0;
	r0=r1=r2=1;
	if(c0&c1&c2&c3==0)
	{
		row=3;
		goto colcheck;
	}
 
	colcheck:

	if(c0==0)
		col=0;
	else if(c1==0)
		col=1;
	else if(c2==0)
		col=2;
	else if(c3==0)
		col=3;
	while(c0&c1&c2&c3==0);
	return(lup[row][col]);
}
