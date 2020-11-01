#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static count = 0;

  count++;

  if (count % 25 == 0) buzzer_advance();
  if (count ==  250){
    state_advance();
    count = 0;
  }
}
