/* ###################################################################
**     Filename    : main.c
**     Project     : ledNode
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-26, 19:39, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LEDR.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LEDG.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "LEDB.h"
#include "LEDpin3.h"
#include "BitIoLdd3.h"
#include "WAIT1.h"
#include "AS1.h"
#include "IFsh1.h"
#include "IntFlashLdd1.h"
#include "RxBuf.h"
#include "CS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
void makeColor(int red, int green, int blue);
void colorWheel(void);
void breathingColor(int red, int green, int blue, int time, int repetitions);

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
	/* Write your local variable definition here */

	/*** Processor Expert internal initialisation. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialisation.                    ***/

	/* Write your code here */
	colorWheel();
	breathingColor(1,0,0,5,2);
	breathingColor(1,1,0,5,2);
	breathingColor(0,1,0,5,2);
	breathingColor(0,1,1,5,2);
	breathingColor(0,0,1,5,2);
	breathingColor(1,0,1,5,2);
	breathingColor(1,1,1,5,-1);
	/* For example: for(;;) { } */
  
	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

void makeColor(int red, int green, int blue)
{
	int mixTime;
	for (mixTime = 0; mixTime < 255; mixTime++)
	{
		//check for red
		if (red > mixTime)
		{
			LEDR_Put(1);
		}
		else
		{
			LEDR_Put(0);
		}
		//check for green
		if (green > mixTime)
		{
			LEDG_Put(1);
		}
		else
		{
			LEDG_Put(0);
		}
		//check for blue
		if (blue > mixTime)
		{
			LEDB_Put(1);
		}
		else
		{
			LEDB_Put(0);
		}
	}
}

void colorWheel(void)
{
	int r, g, b;
	int i;
	
	int sameColorTime = 20;
	int colorBits = 255;
	
	//red to yellow
	r = colorBits;
	b = 0;
	for (g = 0; g < colorBits; g++)
	{
		for (i = 0; i < sameColorTime; i++)
		{
			makeColor(r,g,b);
		}
	}
	//yellow to green
	for (r = colorBits; r > 0; r--)
	{
		for (i = 0; i < sameColorTime; i++)
		{
			makeColor(r,g,b);
		}
	}
	//green to cyan
	for (b = 0; b < colorBits; b++)
	{
		for (i = 0; i < sameColorTime; i++)
		{
			makeColor(r,g,b);
		}
	}
	//cyan to blue
	for (g = colorBits; g > 0; g--)
	{
		for (i = 0; i < sameColorTime; i++)
		{
			makeColor(r,g,b);
		}
	}
	//blue to magenta
	for (r = 0; r < colorBits; r++)
	{
		for (i = 0; i < sameColorTime; i++)
		{
			makeColor(r,g,b);
		}
	}
	//magenta to red
	for (b = colorBits; b > 0; b--)
	{
		for (i = 0; i < sameColorTime; i++)
		{
			makeColor(r,g,b);
		}
	}
}

void breathingColor(int red, int green, int blue, int time, int repetitions)
{
	int i, n;
	int breathingDirection = 1;
	
	int r = (red != 0);
	int g = (green != 0);
	int b = (blue != 0);
	
	i = 0;
	
	while (i < repetitions || repetitions == -1)
	{
		for (n = 0; n < time; n++)
		{
			makeColor(red, green, blue);
		}
		
		//shift to next brightness
		if (r)
		{
			red += breathingDirection;
		}
		if (g)
		{
			green += breathingDirection;
		}
		if (b)
		{
			blue += breathingDirection;
		}
		
		if (red > 255 || green > 255 || blue > 255)
		{
			breathingDirection = -1;
		}
		else if ((r && red < 1) || (g && green < 1) || (b && blue < 1))
		{
			breathingDirection = 1;
			i++;
		}
	}
}
