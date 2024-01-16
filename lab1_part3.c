#include "globals.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int button_pressed(int time);
void game_finish(int delay);

int main(void) {
    
    // PART 2
    init();
    
    // initialize variables
    int loop_n = 20;
    
    // set pins
    digital_dir(0, 1);
    digital_dir(1, 1);
    digital_dir(2, 1);
    
    // define pin arrays
    while(1){
        int delay_ms = 2000;
        
        // go right (middle pins)
        for(int pin=1; pin>0; pin--){
            print_num(pin);
            digital_out(pin, 1);
            if(button_pressed(delay_ms)){ // middle behavior
                //game_finish(7);
                print_num(7);
                //return 0;
            }
            
            digital_out(pin, 0);
        }
            
        // go left
        for(int pin=0; pin<3; pin++){
            print_num(pin);
            digital_out(pin, 1);
            
            int btn = button_pressed(delay_ms);
        
            if(btn && (pin>0 && pin<2)){ // middle behavior
                //game_finish(7);
                print_num(8);
                //return 0;
            }
        
            if(!btn && (pin == 0 || pin==2)){ // end behavior
                //game_finish(7);
                print_num(9);
                //return 0;
            }
            digital_out(pin, 0);
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

void game_finish(int delay){
    // turn on lights
    digital_out(0, 1);
    digital_out(1, 1);
    digital_out(2, 1);
    
    // print delay
    //print_num(delay);
    
    _delay_ms(600);
}