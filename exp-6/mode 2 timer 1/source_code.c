#include <reg51.h>

sbit freq = P3^4;

void delay();

void main(void) {
    while (1) {
        freq = ~freq;
        delay();
    }
}

void delay() {
    TMOD = 0x20;   // Initialize Timer 1 in mode 2
    TH1 = 0x3C;    // Set initial value for 1 ms delay (assuming 11.0592 MHz crystal)
    TL1 = 0x3C;    // Set initial value for 1 ms delay (assuming 11.0592 MHz crystal)
    TR1 = 1;       // Start Timer 1

    while (TF1 == 0); // Wait for Timer 1 overflow
    TF1 = 0;           // Clear Timer 1 overflow flag
    TR1 = 0;           // Stop Timer 1
}
