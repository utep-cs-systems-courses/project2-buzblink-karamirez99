//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include <stdio.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  // printf(BIT5);
  
  or_sr(0x18);		/* CPU off, GIE on */
}
