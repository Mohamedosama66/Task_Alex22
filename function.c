/*
 * File:   function.c
 * Author: MaH MeD
 *
 * Created on September 25, 2021, 2:04 AM
 */



#include <avr/io.h>

#define led0 2
#define led1 7
#define led2 3
#define Relay 2
#define Buzzer 3
#define btn0 0
#define btn1 6 
#define btn2 2

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
