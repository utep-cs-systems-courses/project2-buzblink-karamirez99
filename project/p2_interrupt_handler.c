#include <msp430.h>
#include "switches.h"

/* Our switches connecting to P2 */
void _interrupt_vect(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
}
