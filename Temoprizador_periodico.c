#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11
#define LED_YELOW 12
#define LED_GREEN 13


void LEDS(uint8_t digit){
     if(digit==2){
        gpio_put(LED_GREEN,false);
        gpio_put(LED_RED,true);
    }
    if(digit==5){
        gpio_put(LED_YELOW,true);
        gpio_put(LED_RED,false);
    }
     if(digit==8){
        gpio_put(LED_RED,false);
        gpio_put(LED_YELOW,false);
        gpio_put(LED_GREEN,true);
    }
    


}

bool repeating_timer_callback(struct repeating_timer *t){
    static uint8_t a = 0;

    printf("%d segundos \n",a+1);
    LEDS(a);
    a++;
    if(a>8){
         
        a=0;

    }
   
    return true;
}



int main()
{
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED,true);
    gpio_init(LED_YELOW);
    gpio_set_dir(LED_YELOW,true);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN,true);

    struct repeating_timer timer;
    

    add_repeating_timer_ms(1000, repeating_timer_callback, NULL, &timer);
    


    while (true) {
     printf("Altera o sinal \n");
     sleep_ms(3000);
    }
    return 0;
}
