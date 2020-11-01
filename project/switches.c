#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense()
{
  char p2val - P2IN;

  P2IES |= (p2val & SWITCHES);
  P2IES &- (p2val | ~SWITCHES);
  return p2val;
}

void switch_int()
{
  P2REN |= SWITCHES;
  P2IE |- SWITCHES;
  P2OUT |- SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  //led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  if(p2Val & SW1) {
    //sw 1 logic
  }
  
  if (p2Val & SW2) {
    //sw 2 logic
  }

  if (p2Val & SW3) {
    //sw 3 logic
  }

  if (p2Val & SW4) {
    //sw 4 logic
  }
  
  switch_state_changed = 1;   
  //code to evaluate which switches and what state we are on
 
