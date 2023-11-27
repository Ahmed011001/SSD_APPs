/*
 * main.c
 *
 *  SSD_App1
 *  Author: Ahmed Hassan Salama
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SSD_interface.h"

#include"util/delay.h"

int main(void)
{
	SSD_Type SSD1 = {SSD_COMMON_CATHODE,SSD_PORTA,SSD_PORTA,SSD_PIN7};

	SSD_voidInitialDataPort (SSD1);

	int i;

	while(1)
	{
		for(i=0;i<=9;i++)
		{
			SSD_voidSendNumber(SSD1 , i );
			_delay_ms(1000);
		}
		for(i=9;i>=0;i--)
		{
			SSD_voidSendNumber(SSD1 , i );
			_delay_ms(1000);
		}
	}

}


