/*
 * main.c
 *
 *  SSD_App3
 *  Author: Ahmed Hassan Salama
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SSD_private.h"
#include "SSD_interface.h"

#include "DIO_interface.h"

#include "util/delay.h"


SSD_Type SSD={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};


int main()
{

	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable         (SSD);

		while (1)
		{
			SSD_voidMakeAnimation (SSD, 0, 200);
		}
}
