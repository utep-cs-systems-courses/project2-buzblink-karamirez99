#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main(void) {
  configureClocks();
  buzzer_init();
  enableWDTInterrupts();

  or_sr(0x18);
}
