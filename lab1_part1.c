#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


int main(void) {
   int start = 250;
   init();  //initialize board hardware
   // changes the led
   while(1){
    for (int led = 1; led >= 0;led --){
        // makes it brighter
        for (int x = 0; x < start; x++){
            led_on(led); 
            //time on
            for (int i = 0;i<x;i++){
                _delay_us(20);
            }
            led_off(led); 
            //time off
            for (int i = start;i>x;i--){
                _delay_us(20);
            }
        }
        // makes it fade inverse to previous 
        for (int x = 0; x < start; x++){
            led_off(led); 
            for (int i = 0;i<x;i++){
                _delay_us(20);
            }
            led_on(led); 
            for (int i = start;i>x;i--){
                _delay_us(20);
            }
        }
    led_off(led);
    _delay_ms(20);
    }
   }
   
   
   return 0;
}