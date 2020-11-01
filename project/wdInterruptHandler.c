#include <msp430.h>
#include "song.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char eigthCount = 0;

  if (++eigthCount == 162) {
    //next_note();
    buzzer_set_period(0);
    eigthCount = 0;
  }

}
