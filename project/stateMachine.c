#include <msp430.h>
#include "stateMachine.h"
#include "led.h"

static char on_ratio = 0;
static char brightnessChange = 0;

char toggle_red(char value)
{
  if (on_ratio == 0) {        //on_ratio of 0 is just the led off
    red_on = 0;
    return 1;
  }
  
  if (value == 1) {           //the start of the led dim cycle is on
    red_on = 1;
    return 1;
  }

  if(value == on_ratio + 1){  //the end of the on_ratio cycle is an off led
    red_on = 0;
    return 1;
  }

  return 0;
}

void show_redLED() {
  static char count = -150;
  static char brightness_state = 0;
  static char brightnessChange = 0;
  char changed = 0;
 
  if (++count == 100) {
    brightnessChange = light_advance();
    count = 0;
  }
  if (count % 50 == 0){
    on_ratio += brightnessChange;
  }
  
  changed = toggle_red(brightness_state);
  led_changed |= changed;
  brightness_state = (brightness_state == 4) ? 1 : brightness_state + 1;
  led_update();
}

/*Composed of 3 states, off, increasing brightness and decreasing brightness */
char light_advance() {
  static char state = 0;
  char brightnessChange;
  
  switch(state) {
  case 0:
    state++;
    brightnessChange = 0;
    break;
  case 1:
    state++;
    brightnessChange = 1;
    break;
  case 2:
    state = 0;
    brightnessChange = -1;
    break;
  }

  return brightnessChange;
}
