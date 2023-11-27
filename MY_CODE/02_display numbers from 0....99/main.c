/*
 * main.c
 *
 *  SSD_App2
 *  Author: Ahmed Hassan Salama
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_interface.h"

#include "util/delay.h"

int main(void) {
	SSD_Type SSD1 = {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};
	SSD_Type SSD2 = {SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTD,SSD_PIN7};


    SSD_voidInitialDataPort(SSD1);
    SSD_voidInitialDataPort(SSD2);

    while (1) {
        for (int i = 0; i < 100; i++) {
            int tens = i / 10;  // Extract tens digit
            int ones = i % 10;  // Extract ones digit

            SSD_voidSendNumber(SSD1, tens);
            SSD_voidSendNumber(SSD2, ones);

            _delay_ms(250);  // Display each number for 1 second
        }
    }
}


