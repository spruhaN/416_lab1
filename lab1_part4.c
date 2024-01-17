#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


int main(void){
    init();
    char* scroll_value = "416";
    int lcd_x = 0;
    int lcd_y = 2;
        
    while(1){
        // getting ascceleiromeyter values
        int y_val = get_accel_y();
        int x_val = get_accel_x();

        if(x_val > 15 && x_val < 60){
            // go up
            lcd_x = 0;
        }
        else if(x_val < 235 && x_val > 190){
            // go down
            lcd_x = 1;
        }
        
        if(y_val > 15 && y_val < 60){
            // go left
            if (lcd_y > -2 && lcd_y <= 7){
                lcd_y--;
            }else{
                // if out of bounds sets to -2 
                lcd_y = -2;
            }
        }
        else if(y_val < 235 && y_val > 190){
            // go right
            if (lcd_y >= -2 && lcd_y < 7){
                lcd_y++;
            }else{
                // if out of bounds sets to 7
                lcd_y = 7;
            }
        }

        if(lcd_y < 0){
            // using the substring on the left side of the screen adds offset to 416
            lcd_cursor(0, lcd_x);
            print_string(scroll_value + (-1*lcd_y));   
        }
        else{
            // everything else
            lcd_cursor(lcd_y, lcd_x);
            print_string(scroll_value);
        }
        
        lcd_cursor(0,1);

        _delay_ms(300);
        clear_screen();
    }

    return 0;
}