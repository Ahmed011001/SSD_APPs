/*
*-------------------------------------------------------------------------------------------*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*
*-------------------------------------------------------------------------------------------*
*
* Author  : Ahmed Hassan Salama
* Layer  : MCAL
* SWC   : DIO/GPIO
*
*/ 

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"DIO_private.h"
#include"DIO_config.h"

//------------------------------------------------------------------------------------------------------------------------------//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   IO Pins   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
//------------------------------------------------------------------------------------------------------------------------------//
/*
 * Breif : This Function set the direction of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */


DIO_ErrorStatus DIO_enumSetPinDirection (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	//Make sure that the Port ID and Pin ID are in the valid range
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		//Check on the Pin Direction
		if (Copy_u8Direction == DIO_PIN_OUTPUT)
		{
			//Check on the Required PORT Number
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : SET_BIT(DDRA,Copy_u8PIN);break;
			case DIO_PORTB : SET_BIT(DDRB,Copy_u8PIN);break;
			case DIO_PORTC : SET_BIT(DDRC,Copy_u8PIN);break;
			case DIO_PORTD : SET_BIT(DDRD,Copy_u8PIN);break;		
			}
		}
		//Check on the Pin Direction
		else if (Copy_u8Direction == DIO_PIN_INPUT)
		{
			//Check on the Required PORT Number
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : CLR_BIT(DDRA,Copy_u8PIN);break;
			case DIO_PORTB : CLR_BIT(DDRB,Copy_u8PIN);break;
			case DIO_PORTC : CLR_BIT(DDRC,Copy_u8PIN);break;
			case DIO_PORTD : CLR_BIT(DDRD,Copy_u8PIN);break;		
			}
		}	
		else
		{
			//in case of error in the Pin ID or PORT ID
			LOC_enumState = DIO_NOK ;
		}	
		
	}
	else
	{
		//in case of error in the Pin ID or PORT ID
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}
//-----------------------------------------------------------------------------//
/*
 * Breif : This Function set the Value of the Pin  (HIGH || LOW)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Value --> Pin Direction [ DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	//Make sure that the Port ID and Pin ID are in the valid range
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		//Check on the Pin Option Value
		if (Copy_u8Value == DIO_PIN_HIGH)
		{
			//Check on the Required PORT Number
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : SET_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB : SET_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC : SET_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD : SET_BIT(PORTD,Copy_u8PIN);break;		
			}
		}
		//Check on the Pin Option Value
		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			//Check on the Required PORT Number
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : CLR_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB : CLR_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC : CLR_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD : CLR_BIT(PORTD,Copy_u8PIN);break;		
			}
		}
		else
			{
				//in case of error in the Pin ID or PORT ID
				LOC_enumState = DIO_NOK ;
			}
	}

	else
	{
		//in case of error in the Pin ID or PORT ID
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}
//-----------------------------------------------------------------------------//
/*
 * Breif : This Function Get the Value of the Pin
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  => *Copy_PtrData  --> pointer to recieve the pin value
 * return : its status and recieve Pin Value in pointer
 */

DIO_ErrorStatus DIO_enumGetPinValue (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData   )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;
    //Make sure that the Port ID and Pin ID are in the valid range
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		//Check on the Required PORT Number
		switch (Copy_u8PORT)
	    {
		case DIO_PORTA : * Copy_PtrData=GET_BIT(PINA,Copy_u8PIN);break;
		case DIO_PORTB : * Copy_PtrData=GET_BIT(PINB,Copy_u8PIN);break;
		case DIO_PORTC : * Copy_PtrData=GET_BIT(PINC,Copy_u8PIN);break;
		case DIO_PORTD : * Copy_PtrData=GET_BIT(PIND,Copy_u8PIN);break;		
		}
	}
	else
	{
		//in case of error in the Pin ID or PORT ID
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;	
}
//----------------------------------------------------------------------------//
/*
 * Breif : This Function Toggle the Value of the Pin
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumTogglePinValue  ( u8 Copy_u8PORT, u8 Copy_u8PIN )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	//Make sure that the Port ID and Pin ID are in the valid range
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		//Check on the Required PORT Number
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : TOG_BIT(PORTA,Copy_u8PIN);
		break ;
		case DIO_PORTB : TOG_BIT(PORTB,Copy_u8PIN);
		break ;
		case DIO_PORTC : TOG_BIT(PORTC,Copy_u8PIN);
		break ;
		case DIO_PORTD : TOG_BIT(PORTD,Copy_u8PIN);
		break ;
		}

	}
	else
	{
		//in case of error in the Pin ID or PORT ID 
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}

//------------------------------------------------------------------------------------------------------------------------------//
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   IO Ports   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
//------------------------------------------------------------------------------------------------------------------------------//
/*
 * Breif : This Function Set the direction of the port (INPUT / OUTPUT)
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Direction  --> Port direction [ DIO_PORT_OUTPUT , DIO_PORT_INPUT ]
 * return :  its status
 */
DIO_ErrorStatus DIO_enumSetPortDirection  (u8 Copy_u8PORT , u8 Copy_u8Direction ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;
    
	//Make sure that the Port ID is in the valid range
	if ( (Copy_u8PORT <= DIO_PORTD) )
	{
		//Check on the Required PORT Number 
		switch (Copy_u8PORT)
		{
		case DIO_PORTA: DDRA = Copy_u8Direction; break;
		case DIO_PORTB: DDRB = Copy_u8Direction; break;
		case DIO_PORTC: DDRC = Copy_u8Direction; break;
		case DIO_PORTD: DDRD = Copy_u8Direction; break;
		default       : LOC_enumState = DIO_NOK; break;
		}	
	}
	else
	{
		//in case of error in the PORT ID 
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

//---------------------------------------------------------------------------//
/*
 * Breif : This Function Set value on Port
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Value  --> The Value  [DIO_PORT_HIGH , DIO_PORT_LOW , Another Value]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPortValue  (u8 Copy_u8PORT , u8 Copy_u8Value )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;
    
	//Make sure that the Port ID is in the valid range and the Value is Valid
	if ( (Copy_u8PORT <= DIO_PORTD) && ( (Copy_u8Value<=255) || (Copy_u8Value==DIO_PORT_LOW) || (Copy_u8Value==DIO_PORT_HIGH) ) )
	{
		//Check on the Required PORT Number 
		switch (Copy_u8PORT)
		{
		case DIO_PORTA: PORTA = Copy_u8Value; break;
		case DIO_PORTB: PORTB = Copy_u8Value; break;
		case DIO_PORTC: PORTC = Copy_u8Value; break;
		case DIO_PORTD: PORTD = Copy_u8Value; break;
		default       : LOC_enumState = DIO_NOK; break;
		}	
	}
	else
	{
		//in case of error in the PORT ID 
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}
//---------------------------------------------------------------------------//
/*
 * Breif : This Function GET value on Port
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  => *Copy_PtrData  --> pointer to recieve the port value
 * return : its status and recieve Port Value in pointer
 */
DIO_ErrorStatus   DIO_enumGetPortValue  ( u8 Copy_u8PORT  , u8 * Copy_PtrData )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

    //Make sure that the Port ID is in the valid range
	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		//Check on the Required PORT Number 
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : *Copy_PtrData = PINA ;break ;
		    case DIO_PORTB : *Copy_PtrData = PINB ;break ;
		    case DIO_PORTC : *Copy_PtrData = PINC ;break ;
	        case DIO_PORTD : *Copy_PtrData = PIND ;break ;
		    default        : LOC_enumState = DIO_NOK; break ;
		}
	}
	else
	{
		//in case of error in the PORT ID 
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;
}

//---------------------------------------------------------------------------//
/*
 * Breif : This Function Toggle value on Port
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumTogglePortValue      (u8 Copy_u8PORT                       )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;
	
    //Make sure that the Port ID is in the valid range
	if (Copy_u8PORT <= DIO_PORTD)
	{
		//Check on the Required PORT Number 
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : PORTA = ~PORTA ;break ;
		case DIO_PORTB : PORTB = ~PORTB ;break ;
		case DIO_PORTC : PORTC = ~PORTC ;break ;
		case DIO_PORTD : PORTD = ~PORTD ;break ;
		}
	}
	else
	{
		//in case of error in the PORT ID 
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

