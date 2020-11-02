#include <msp430.h>
#include "song.h"
#include "stateMachine.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static unsigned char sixteenthCount = 0;

  
  if (playing){
    
    show_redLED();
    if (++sixteenthCount == 50) {
      next_note();
      sixteenthCount = 0;
    }
  }

}
