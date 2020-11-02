#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

int main(void) {
  configureClocks();
  buzzer_init();
  led_init();
  switch_init();
  enableWDTInterrupts();

  or_sr(0x18);
}
