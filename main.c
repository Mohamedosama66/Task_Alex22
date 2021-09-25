/*
 * File:   main1.c
 * Author: MaH MeD
 *
 * Created on September 25, 2021, 12:09 AM
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "function.h"


#define led0 2
#define led1 7
#define led2 3
#define Relay 2
#define Buzzer 3
#define btn0 0
#define btn1 6 
#define btn2 2
#define ON 1
#define OFF 0
#define Delay 200


int main(void) {
    
    // Intialization....
    
    init_leds();
    init_Relay();
    init_Buzzer();
    
    // Set leds states....
    /* 
    set_led(led0,ON);
    set_led(led1,ON);
    set_led(led2,ON);
    set_Relay(ON);
    set_Buzzer(ON);

    _delay_ms(Delay);

    set_led(led0,OFF);
    set_led(led1,OFF);
    set_led(led2,OFF);
    set_Relay(OFF);
    set_Buzzer(OFF);
        
    _delay_ms(Delay);
     */
    
    while (1) {
        
        if(isPressed_B(btn0)){
            set_led(led0,ON);
            set_led(led1,ON);
            set_led(led2,ON);   
        }else{
            set_led(led0,OFF);
            set_led(led1,OFF);
            set_led(led2,OFF);
        }
        if(isPressed_B(btn1)){
            set_Relay(ON);   
        }else{
            set_Relay(OFF);
        }
        if(isPressed_B(btn2)){
            set_Buzzer(ON);   
        }else{
            set_Buzzer(OFF);
        }
        }
}

