#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


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
            }
            _delay_ms(1);
        }
        clear_screen();

      }
      // final button check so only one increment can happen per scroll
      if (button_status == 1){
        index = (index+1)%3;
      }
    }
    return 0;
} 
