#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* lab1_part1.c */
int main(void){
   init();
   while(1){
      print_num(get_accel_y());
      _delay_ms(300);
      clear_screen();
   }
   
}
