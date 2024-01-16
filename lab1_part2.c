#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int button_pressed(int time);

int main(void) {
   char* names[] = {"       Spruha Nayak", "       Sarah Hallam", "       Aiden Jacob"};
   int index = 0;

   init();
   init_lcd();
   clear_screen();

    while(1) {
      // gets current name 
      char* curr_name = names[index];
      int len = strlen(curr_name);
      int button_status = 0;

      for (int position = 0; position < len; position++) {     
         // if the button is not pressed scroll name
        lcd_cursor(0, 0);
        print_string(curr_name + position);
        // checks button status
        for(int i=0; i<300; i++){
            if (get_btn()){
                button_status = 1;
                lcd_cursor(0,1);
                print_num(i);
            }
            _delay_ms(1);
        }
        clear_screen();

      }
      if (button_status == 1){
        index = (index+1)%3;
      }
    }
    return 0;
} 


int button_pressed(int time){
    int res = 0;
    for(int i=0; i<time; i++){
        if (get_btn()){
            res = 1;
            lcd_cursor(0,1);
            print_num(i);
        }
        _delay_ms(1);
    }
    return res;
}