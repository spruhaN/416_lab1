#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* lab1_part1.c */

/*
int main(void) {
   int start = 250;
   init();  //initialize board hardware
   // changes the led
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
   print_num(led);
   }
   
   
   return 0;
}
*/

/* lab1_part2.c */

void scrollName(char* name);

int main(void) {
   char* names[] = {"       Spruha Nayak", "       Sarah Hellman", "       Aiden Jacob"};
   int index = 0;
   bool buttonPreviouslyPressed = false;

   init();
   init_lcd();
   clear_screen();

    while(1) {
      // gets current name 
      char* curr_name = names[index];
      int len = strlen(curr_name);

      for (int position = 0; position < len; position++) {     
         // if the button is not pressed scroll name
         if (!get_btn()){   
            lcd_cursor(0, 0);
            print_string(curr_name + position);
            _delay_ms(300);
            clear_screen();
         }else{
            // if button is pressed then change name
            index = (index + 1)%3;
         }
      }
    }
    return 0;
}

void scrollName(char* name) {
    int len;
    char* buffer = "";
    strcat(buffer, name);
    len = strlen(name);
    for (int position = 0; position < len; position++) {        
        lcd_cursor(0, 0);
        print_string(name + position);
        _delay_ms(300);
        clear_screen();
    }
}

/* lab1_part3.c */

