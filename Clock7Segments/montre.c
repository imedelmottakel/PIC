/* copyright/ Imed Elmottakel
* Year 2018
* This code is provided free of charge for any non-commercial use.
* The code is provided as is, with no warranties or guarantees, and the user assumes all responsibility 
* for any damages or losses resulting from its use. The user is also required to include this copyright disclaimer 
* in any copies or derivative works of the code.
* Any commercial use of this code is prohibited without the express written permission of the copyright holder.
*/
#include <16F877.h> // include the PIC16F877A microcontroller library
#device adc=10 // set the ADC to 10-bit resolution
#fuses NOWDT, XT, PUT, NOPROTECT // set the fuses for the microcontroller
#use delay(clock=20000000) // set the clock speed to 20MHz

// define the pin connections for the RTC module
#define RTC_SCLK PIN_C1            // clock pin
#define RTC_IO   PIN_C2             // data pin
#define RTC_RST  PIN_C0            // reset pin
#include <ds1302.c> // include the library for the DS1302 RTC module

// variables to hold the date and time information
byte day=1,mth=1,year=18,dow=1,hour=0,min=0,sec=0;

// => Les fonctions disponibles pour manipuler l'horloge DS1302
////  rtc_init()                                   Call after power up////
////                                                                  ////
////  rtc_set_datetime(day,mth,year,dow,hour,min)  Set the date/time  ////
////                                                                  ////
////  rtc_get_date(day,mth,year,dow)               Get the date       ////
////                                                                  ////
////  rtc_get_time(hr,min,sec)                     Get the time       ////
////                                                                  ////

void main()
{
    output_b(0); // set all output pins to 0
    output_d(0);

    rtc_init(); // initialize the RTC module

    // if the E0 pin is high, set the date and time on the RTC module
    // the date and time is set to the values of the variables: day, mth, year, dow, hour, min, sec
    // default time = 00:00:00 01/01/2018
    // you can change this time by modifying the variables
    if(input(pin_e0)){
        rtc_set_datetime(day,mth,year,dow,hour,min); 
    }

    while(1){
        rtc_get_time(hour,min,sec)  ; // read the time from the RTC module and store in the variables

        // display the time on the 7-segment display
        // the least significant digit is displayed on the first 7-segment display
        // the next digit is displayed on the next 7-segment display, and so on
        output_d(1);
        output_b(sec%10);
        output_d(2);
        output_b(sec/10);
        output_d(4);
        output_b(min%10);
        output_d(8);
        output_b(min/10);
        output_d(16);
        output_b(hour%10);
        output_d(32);
        output_b(hour/10);

        delay_ms(20); // delay for 20ms before updating the display again
    }

}
