#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "../blink_demo/led.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
    led_init()
    buzzer_init();
    // buzzer_set_period(4545);	/* start buzzing!!! */

    or_sr(0x18);          // CPU off, GIE on
}
