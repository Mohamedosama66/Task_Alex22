/*
 * File:   main1.c
 * Author: MaH MeD
 *
 * Created on September 25, 2021, 12:09 AM
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>


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


void init_leds();
void init_Relay();
void init_Buzzer();
void init_Buttons();

void set_led(int led_number,int status);
void set_Relay(int status);
void set_Buzzer(int status);
int isPressed_B (int Button_number);

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


void init_leds(){
    DDRC |=(1<<led0)|(1<<led1);
    DDRD |=(1<<led2);
}
void init_Relay(){
    DDRA |=(1<<Relay);
}
void init_Buzzer(){
    DDRA |=(1<<Buzzer);
}
void init_Buttons(){
    DDRB &=~(1<<btn0);
    DDRD &=~((1<<btn1)|(1<<btn2));    
}

void set_led(int led_number,int status){
    
    if(status){
        switch (led_number){
            case led0:
                PORTC |=(1<<led0);
                break;
            case led1:
                PORTC |=(1<<led1);
                break;
            case led2:
                PORTD |=(1<<led2);
                break;
        }
    }else{
        switch (led_number){
            case led0:
                PORTC &=~(1<<led0);
                break;
            case led1:
                PORTC &=~(1<<led1);
                break;
            case led2:
                PORTD &=~(1<<led2);
                break;
        
    }
}
}

void set_Relay(int status){
    
    if(status){
        PORTA |=(1<<Relay);
    }else{
        PORTA &=~(1<<Relay);
    }
}

void set_Buzzer(int status){
    
    if(status){
        PORTA |=(1<<Buzzer);
    }else{
        PORTA &=~(1<<Buzzer);
    }
}
int isPressed_B(int Button_number){
    int z=0;
    switch(Button_number){
        case btn0:
            z=(PINB &(1<<btn0))? 1:0 ;
            break;
        case btn1:
            z=(PIND &(1<<btn1))? 1:0 ;
            break;
        case btn2:
            z=(PIND &(1<<btn2))? 1:0 ;
            break;
    }
    return z;
        
}
