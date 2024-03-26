

#include <reg51.h>

void msdelay(unsigned int); // Function prototype declaration

void main(void)
{
    P0=0x55;
    P2=0x55;
    while (1)
    {
        P0=~P0;
        P2=P2^0xFF;
        msdelay(250);
    }
}

void msdelay(unsigned int time) // Function definition with a named parameter
{
    TMOD=0x00;
    TL0=0x00;
    TH0=0x35;
    TR0=1;
    while (TF0==0); // Wait until the timer overflows
    {
        TR0=0; // Stop Timer 0
        TF0=0; // Clear Timer 0 overflow flag
    }
}
