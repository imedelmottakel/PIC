This project is designed to control and display the time on a 7-segment display using a PIC16F877A microcontroller and a DS1302 real-time clock (RTC) module.

The PIC16F877A microcontroller is configured to communicate with the DS1302 RTC module using the clock (SCLK), data (IO), and reset (RST) pins. The microcontroller uses the rtc_init(), rtc_set_datetime(), rtc_get_date(), and rtc_get_time() functions from the ds1302.c library to initialize and interact with the RTC module.

When the project is powered on, the microcontroller initializes the RTC module and checks the state of the E0 pin. If the E0 pin is high, the microcontroller sets the date and time on the RTC module using the values of the day, mth, year, dow, hour, min, and sec variables. If the E0 pin is low, the microcontroller continues to the main loop.

In the main loop, the microcontroller reads the current time from the RTC module and stores the hour, minute, and second values in the hour, min, and sec variables respectively. It then uses the output_d() and output_b() functions to display the current time on a 7-segment display. The least significant digit is displayed on the first 7-segment display, the next digit is displayed on the next 7-segment display, and so on. Finally, the microcontroller waits for 20ms before updating the display again.

This project allows the user to easily set and read the time on the RTC module, and display it on a 7-segment display. Additionally, the user can change the date and time by modifying the values of the day, mth, year, dow, hour, min, and sec variables, and power on the board while the E0 pin is high.



