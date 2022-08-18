/*
 * MM5451.h - Library for controlling the MM5451 LED Driver with your Arduino board.
 * Created by Arthur W. Aznive Jr., August 11 2022.
 * Released into the Public Domain.
 *
 */

#ifndef MM5451_h
#define MM5451_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class MM5451
{
public:
	// Constructor
	MM5451(int DataPin, int CLK);

	/*
	 * 	METHODS
	 */

	// returns the pin value this Driver is using. Returns int.
	int getDataPin();

	// Scroll the data held in the Array Left. Returns array.
	void ShiftDataLeft(int (&data)[35]);

	// Scroll the data held in the Array Right. Returns array.
	void ShiftDataRight(int (&data)[35]);

	// Scroll the data across the screen to the left or right.
	void ScrollData(bool d, int (&data)[35]);

	/*Displays Characters on a 7 segment display. Boolean defines
	 * if you are using Common Cathode or Common Annode (True CC, False CA).
	 */
	void displaySSeg(bool b, int (&data)[35], int segArr[5]);

private:
	int _DataPin;
	int _CLK;
	int _size;

	/**
	 * @brief Look up table for 7-Seg Displays
	 *
	 * 	Each MM5451 can support 4 - 5, 7 Seg Displays
	 *	Display 1 = Bits 1 - 7
	 *	Display 2 = Bits 8 - 14
	 * 	Display 3 = Bits 15 - 21
	 *	Display 4 = Bits 22 - 28
	 *	Display 5 = Bits 29 - 35
	 */

	uint8_t lookUpTable[16] = {
		0b1111110, // 0
		0b1100000, // 1
		0b1101101, // 2
		0b1111001, // 3
		0b0110011, // 4
		0b1011011, // 5
		0b1011111, // 6
		0b1110000, // 7
		0b1111111, // 8
		0b1111011, // 9
		0b1110111, // A
		0b0011111, // B
		0b1001110, // C
		0b0111101, // D
		0b1001111, // E
		0b1000111  // F
	};

	// Sends 35 bits of data to the board to output
	/**
	 * @brief Construct a new Send Data object
	 *
	 * @param _array
	 */
	void SendData(int (&data)[35]);

	/**
	 * @brief It just dootdoot
	 *
	 */
	void pulseCLK();
};

#endif
