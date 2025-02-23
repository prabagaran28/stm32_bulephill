#include "gpio.h"

    

void set_led(gpio_t* gpiox ,uint16_t gpio_pin,gpio_state pinstate)
{
     if(pinstate == RESET)
     {
          gpiox->odr &= ~(1 << gpio_pin);
     }
     else
     {
          gpiox->odr |= (1 <<gpio_pin);
     }
}