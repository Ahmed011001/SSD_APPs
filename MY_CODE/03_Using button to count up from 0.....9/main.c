/*
 * main.c
 *
 * Using button to count up from 0.....9
 *  Author: Ahmed Hassan Salama
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_Interface.h"
#include "SSD_Interface.h"
#include "SW_Interface.h"

#include <util/delay.h>


SSD_Type SSD1 = {SSD_COMMON_CATHODE,SSD_PORTC ,SSD_PORTC ,SSD_PIN7};
SW_Type SW1 = {DIO_PORTA ,DIO_PIN0 ,SW_Int_PULL_UP};





void main (void )
{

	SSD_voidInitialDataPort(SSD1) ;
	SSD_voidEnable(SSD1) ;
	SW_voidInit(SW1) ;


	while(1)
	{

		    SSD_voidInitialDataPort(SSD1);
			SSD_voidEnable         (SSD1);
			SW_voidInit            (SW1) ;

			u8 count = 0;
			while (1)
			{
				while (count != 10) {

					if (SW_u8GetPressed (SW1)) {

						while (SW_u8GetPressed (SW1)) {
							SSD_voidSendNumber     (SSD1, count);
						}

						count++;
					}
				}

				count = 0;
			}

	}
}
