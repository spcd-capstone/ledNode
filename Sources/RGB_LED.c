/*
 * RGB_LED.c
 *
 *  Created on: Dec 5, 2015
 *      Author: Paul
 */

#include "LEDR.h"
#include "LEDG.h"
#include "LEDB.h"

void makeColor(unsigned int color)
{
	unsigned int mixTime;
	for (mixTime = 0; mixTime < 255; mixTime++)
	{
		//check for red
		if (((color & 0xFF0000) >> 16) > mixTime)
		{
			LEDR_Put(1);
		}
		else
		{
			LEDR_Put(0);
		}
		//check for green
		if (((color & 0xFF00) >> 8) > mixTime)
		{
			LEDG_Put(1);
		}
		else
		{
			LEDG_Put(0);
		}
		//check for blue
		if ((color & 0xFF) > mixTime)
		{
			LEDB_Put(1);
		}
		else
		{
			LEDB_Put(0);
		}
	}
}
