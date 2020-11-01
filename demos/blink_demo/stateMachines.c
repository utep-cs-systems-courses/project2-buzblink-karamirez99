#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char on_ratio = 1;

char toggle_red(char current_state)		/* always toggle! */
{
  
  if(current_state == 1) {
    red_on = 1;
    return 1;
  }
  
  if(current_state == on_ratio + 1){
    red_on = 0;
    return 1;
  }

  return 0;
}

//char toggle_green()	/* only toggle green if red is on!  */
//{
//  char changed = 0;
//  if (red_on) {
//    green_on ^= 1;
//    changed = 1;
//  }
//  return
//}

void change_brightness()
{
  static char state = 0;
  
  switch (state){
    case 0:
      state++;
      on_ratio = 1;
      break;
    case 1:
      state++;
      on_ratio = 2;
      break;
    case 2:
      state++;
      on_ratio = 3;
      break;
    case 3:
      state = 0;
      on_ratio = 4;
      break;
  }

}

//char toggle_green()	/* only toggle green if red is on!  */
//{
//  char changed = 0;
//  if (red_on) {
//    green_on ^= 1;
//    changed = 1;
//  }
//  return
//}

void show_redLED() {
  static char current_state = 1;
  char changed = 0;

  changed = toggle_red(current_state);
  led_changed = changed;
  current_state = (current_state == 4) ? 1 : current_state + 1;
  led_update();
  
}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  // static enum {R=0, G=1} color = G;
  // switch (color) {
  // case R: changed = toggle_red(); color = G; break;
  // case G: changed = toggle_green(); color = R; break;
  // }

  change_brightness();
}



