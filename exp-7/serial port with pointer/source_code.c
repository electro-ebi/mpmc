#include<reg51.h>
char tx='A';
char *txp=&tx;
void transmit(char *tx)
{
SBUF=*tx;
while(TI==0);
TI=0;
}
void main()
{
TMOD=0x20;
TH1=0xFD;
SCON=0x50;
TR1=1;
while(1)
{
transmit(txp);
}}