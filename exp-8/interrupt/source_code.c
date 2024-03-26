#include<reg51.h>
sbit SWAVE=P1^5;
void timer0(void) interrupt 1{
SWAVE=~SWAVE;
TH0=0x4B;
TL0=0xFD;
}
void main(void)
{
IE=0x82;
TMOD=0x01;
TH0=0x4B;
TL0=0xFD;
TR0=1;
while(1);
}