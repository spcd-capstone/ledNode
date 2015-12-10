/* ###################################################################
**     Filename    : main.c
**     Project     : themometerNode
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-11-15, 12:59, # CodeGen: 0
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
#include "CS1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "RGB_LED.h"
#include "UART.h"
#include "string.h"

parser commandParser;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  unsigned int color;
  char name[64];
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  InitParser(&commandParser);
  
  color = 0; //light starts off
  strcpy(name,"LED Node");
  
  while(1)
  {
	  //execute command if one is ready
	  if (commandParser.state == PS_READY)
	  {
		  if (commandParser.command == PC_GET)
		  {
			  if (strcmp("color", commandParser.key) == 0)
			  {
				  SendInteger(color);
			  }
			  else if (strcmp("name", commandParser.key) == 0)
			  {
				  SendString((unsigned char*)name);
			  }
			  else
			  {
				  SendError("Key Not Found");
			  }
		  }
		  else if (commandParser.command == PC_SET)
		  {
			  if ((strcmp("color", commandParser.key) == 0) && (commandParser.dataType == PDT_INTEGER))
			  {
				  color = commandParser.dataInt;
				  SendSuccess("Key Set Success");
			  }
			  else if ((strcmp("name", commandParser.key) == 0) && (commandParser.dataType == PDT_STRING))
			  {
				  strcpy(name,commandParser.dataString);
				  SendSuccess("Key Set Success");
			  }
			  else
			  {
				  SendError("Key Not Found");
			  }
		  }
		  commandParser.state = PS_COMMAND;
	  }
	  //normal operations
	  makeColor(color);
  }
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
