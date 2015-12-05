/*
 * RGB_LED.c
 *
 *  Created on: Dec 5, 2015
 *      Author: Paul
 */

#include "LEDR.h"
#include "LEDG.h"
#include "LEDB.h"

/*
void makeColor(unsigned char color)
{
	unsigned char mixTime;
	for (mixTime = 0; mixTime < 255; mixTime++)
	{
		//check for red
		if (((color & 0xE0) >> 5) > mixTime)
		{
			LEDR_Put(1);
		}
		else
		{
			LEDR_Put(0);
		}
		//check for green
		if (((color & 0x1C) >> 2) > mixTime)
		{
			LEDG_Put(1);
		}
		else
		{
			LEDG_Put(0);
		}
		//check for blue
		if ((color & 0x03) > mixTime)
		{
			LEDB_Put(1);
		}
		else
		{
			LEDB_Put(0);
		}
	}
}
*/

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

/*
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
*/

/*
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
*/

/*
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
*/
