#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


int main(void){
    init();
    
    int old_x = get_accel_x();
    int old_y = get_accel_y();
    int lcd_x = 0;
    int lcd_y = 2;
    
    lcd_cursor(lcd_y, lcd_x);
    while(1){
        int new_x = get_accel_x();
        int new_y = get_accel_y();

        if((new_x+5 ) < old_x){
            //scroll down
            lcd_x = 0;

        }
        else if((new_x)> old_x){
            //scroll up
            lcd_x = 1;
        }
        old_x = new_x;

        if((new_y)< old_y){ // 255 - 
            //scroll right
            //print_num(new_y);
            if (lcd_y > 0 && lcd_y < 7){
                //print_string("right");
                lcd_y++;
            }
            

        }
        else if((new_y) > old_y){
            //scroll left
            //print_num(new_y);
            if (lcd_y > 0 && lcd_y < 7){
                //print_string("left");
                lcd_y--;
            }
        }
        old_y = new_y;

        lcd_cursor(lcd_y, lcd_x);
        print_string("416");

        _delay_ms(1000);
        clear_screen();
    }

    return 0;
}