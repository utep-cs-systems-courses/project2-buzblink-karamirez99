#include <msp430.h>
#include "song.h"
#include "stateMachine.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static unsigned char sixteenthCount = 0;

  show_redLED();
  if (++sixteenthCount == 50) {
    next_note();
    sixteenthCount = 0;
  }

}
