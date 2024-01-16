#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int button_pressed(int time);

int main(void) {
   char* names[] = {"       Spruha Nayak", "       Sarah Hellman", "       Aiden Jacob"};
   int index = 0;

   init();
   init_lcd();
   clear_screen();

    while(1) {
      // gets current name 
      char* curr_name = names[index];
      int len = strlen(curr_name);

      for (int position = 0; position < len; position++) {     
         // if the button is not pressed scroll name
        lcd_cursor(0, 0);
        print_string(curr_name + position);
        // checks button status
        int button_status = button_pressed(300);
        if(button_status){
            // if button is pressed change name 0 index ++ %3
            if (index == 2){
                index = 0;
            }else{
                index++;
            }
        }
        clear_screen();

      }
    }
    return 0;
} 


int button_pressed(int time){
    
    for(int i=0; i<time; i++){
        if (get_btn()){
            return 1;
        }
        _delay_ms(1);
    }
    return 0;
}