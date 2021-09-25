/* 
 * File:   newmain2.h
 * Author: MaH MeD
 *
 * Created on September 25, 2021, 4:45 AM
 */

#ifndef NEWMAIN2_H
#define	NEWMAIN2_H
void init_leds();
void init_Relay();
void init_Buzzer();
void init_Buttons();

void set_led(int led_number,int status);
void set_Relay(int status);
void set_Buzzer(int status);
int isPressed_B (int Button_number);
#ifdef	__cplusplus
extern "C" {
   
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NEWMAIN2_H */

