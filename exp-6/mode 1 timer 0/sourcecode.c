#include <reg51.h>

#define ON 1
#define OFF 0

sbit led = P2^0;
unsigned int i = 0;

void delay();

void main(void)
{
    while (1)
    {
      led = ON;
			
					delay();
				
      led = OFF;
				
					delay();
			
    }
}

void delay()
{
    TMOD = 0x01;
    TL0 = 0xFC;
    TH0 = 0x66;
    TR0 = 1;
    while (TF0 == 0)
    {
   
    }
    TR0 = 0;
    TF0 = 0;  
}
