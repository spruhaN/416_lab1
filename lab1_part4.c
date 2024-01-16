#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
    init();

    while(1){
        int x = get_accel_x();
        int y = get_accel_y();
        lcd_cursor(0,0);
        print_num(x);
        lcd_cursor(0,1);
        print_num(y);
    }

    return 0;
}