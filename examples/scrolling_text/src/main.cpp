/*
 * Arthur W. Aznive Jr.
 * MM5451 LED Driver Sketch
 * For controlling the 5x7 LED Matrix
 * Based upon the LAI Stacker Entertainment Machine.
 *
 * 8/16/2022
 *
 */

#include <Arduino.h>
#include "MM5451.h"

#define CLK 8	  // Connect to pin 21 on the MM5451
#define DATAPIN 9 // Connect to pin 22 on the MM5451

// Example text matrix
uint16_t matrix[35] = {
	1, 0, 1, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 0, 1,
	0, 1, 0, 1, 0, 1, 1,
	0, 1, 0, 1, 0, 0, 1,
	1, 0, 1, 1, 0, 1, 0};

// Prototypes
void shiftMatrix(uint16_t (&data)[35]);
void pulseCLK();

void setup()
{
	Serial.begin(9600);

	// Set Arduino pin modes to OUTPUT
	pinMode(CLK, OUTPUT);
	pinMode(DATAPIN, OUTPUT);

	// Write a 0 to start.
	digitalWrite(CLK, 0);
	digitalWrite(DATAPIN, 0);
}

// Loop this forever! Or until you stop it. or the Heat Death of the Universe, your call~
void loop()
{
	for (uint16_t myCount = 0; myCount <= 35; myCount++)
	{
		// Start Bit
		digitalWrite(DATAPIN, 1);
		pulseCLK();

		for (uint16_t i = 0; i < 35; i++)
		{
			digitalWrite(DATAPIN, matrix[i]);
			pulseCLK();
		}
	}
	// shift to scroll image

	// short delay
	delay(100);
	shiftMatrix(matrix);
}

void shiftMatrix(uint16_t (&data)[35])
{
	uint16_t temp = data[0];

	for (uint16_t i = 0; i < 34; i++)
	{
		data[i] = data[i + 1];
	}
	data[34] = temp;

	return data;
}

// Pulse the Clock
void pulseCLK()
{
	digitalWrite(CLK, 1);
	digitalWrite(CLK, 0);
}
