#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

static int x;

void go_up() {
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
  
  x = 225;
}

void go_down() {
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
  
  x = -450;
}
  
void buzzer_advance()
{
  static short frequency = 500;

  frequency += x;
  buzzer_set_period(frequency);
}
  

void state_advance()		/* alternate between toggling red & green */
{
  static char current_state = 0;
  
  switch (current_state) {
  case 0:
    go_up();
    break;
  case 2:
    go_down();
    break;
  default:
    break;
  }

  current_state += 1;
  current_state %= 3;
 
}





