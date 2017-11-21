sbit  R1 = P2^0;
sbit  R2 = P2^1;
sbit  R3 = P2^2;
sbit  R4 = P2^3;
sbit  C1 = P2^4;
sbit  C2 = P2^5;
sbit  C3 = P2^6;
sbit  C4 = P2^7;

unsigned char keyscan(void)
{
 C1=1;
 C2=1;
 C3=1;
 C4=1;
 R1=0;
 R2=1;
 R3=1;
 R4=1;
 if(C1==0){delay_ms(100);while(C1==0);return 'A';}
 if(C2==0){delay_ms(100);while(C2==0);return 'B';}
 if(C3==0){delay_ms(100);while(C3==0);return 'C';}
 if(C4==0){delay_ms(100);while(C4==0);return '1';}
 R1=1;
 R2=0;
 R3=1;
 R4=1;
 if(C1==0){delay_ms(100);while(C1==0);return 'D';}
 if(C2==0){delay_ms(100);while(C2==0);return 'E';}
 if(C3==0){delay_ms(100);while(C3==0);return 'F';}
 if(C4==0){delay_ms(100);while(C4==0);return '2';}
 R1=1;
 R2=1;
 R3=0;
 R4=1;
 if(C1==0){delay_ms(100);while(C1==0);return 'G';}
 if(C2==0){delay_ms(100);while(C2==0);return 'H';}
 if(C3==0){delay_ms(100);while(C3==0);return 'I';}
 if(C4==0){delay_ms(100);while(C4==0);return '3';}
 R1=1;
 R2=1;
 R3=1;
 R4=0;
 if(C1==0){delay_ms(100);while(C1==0);return 'J';}
 if(C2==0){delay_ms(100);while(C2==0);return 'K';}
 if(C3==0){delay_ms(100);while(C3==0);return 'L';}
 if(C4==0){delay_ms(100);while(C4==0);return '=';}
 return 0 ;

}