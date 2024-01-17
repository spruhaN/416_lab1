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
    int delay_ms = 2000;
    init();
    
    // set pins
    for(int i = 0; i< 5; i++){
        digital_dir(i, 1);
    }
    
    // start game
    while(delay_ms){        
        
        // go right (middle pins)
        for(int pin=3; pin>0; pin--){
            digital_out(pin, 1);
            if(button_pressed(delay_ms)){ // middle behavior if the button is pressed game over
                game_finish(delay_ms);
                return 0;
            }
            
            digital_out(pin, 0);
        }
            
        // go left
        for(int pin=0; pin<5; pin++){

            // turns pin on and off and looks for button status
            digital_out(pin, 1);
            int btn = button_pressed(delay_ms);
            digital_out(pin, 0);

            if(!btn && (pin == 0 || pin==4)){ // end behavior if the button is not pressed game over
                game_finish(delay_ms);
                return 0;
            }
            else if(btn && (pin>0 && pin<4)){ // middle behavior if the button is pressed game over
                game_finish(delay_ms);
                return 0;
            }

            
        }
        if (delay_ms > 1){
            delay_ms = delay_ms/2;
        }
    }
    
   return 0;
}


int button_pressed(int time){
    // loops over a very small interval in total of time so it can catch any button press
    int end = 0;
    for(int i=0; i<time; i++){
        if (get_btn()){
            end = 1;
        }
        _delay_ms(1);
    }
    return end;
}

void game_finish(int delay){
    // turn on lights
    for(int i = 0; i< 5; i++){
        digital_out(i, 1);
    }
    
    // print delay
    print_num(delay);
    _delay_ms(600);
}