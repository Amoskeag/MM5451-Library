#include "MM5451.h"

/*
 * A LED Driver needs a Data pin, Clock pin, and Brightness control, for 35 outputs.
 */
MM5451::LED_Driver(int DataPin, int CLK)
{
	//Construct the object here.
	pinMode(DataPin, OUTPUT);
	pinMode(CLK, OUTPUT);

	//Write a 0 to start at a baseline.
	digitalWrite(CLK, 0);
	digitalWrite(DataPin, 0);

	_DataPin = DataPin;
	_CLK = CLK;
}

MM5451::getDataPin()
{
	//returns the assigned DataPin value.
	return _DataPin;
}

MM5451::pulseCLK()
{
	digitalWrite(_CLK, 1);
	digitalWrite(_CLK, 0);
}

MM5451::ShiftDataLeft(int (&data)[35])
{
	//Shift Data to the Left. First element becomes last "34th" element.

	int temp = data[0]; //Hold First

    for (int i = 0; i < n - 1; i++)
    {
      data[i] = data[i + 1]; //move all element to the left except first one
    }

    data[n - 1] = temp;

  	return data;
}

MM5451::ShiftDataRight(int (&data)[35])
{
	//Shift Data to the Right, Last element becomes the first "zero-th"  element.

	int temp = data[0]; //Hold First 
	
    for (int i = 0; i < 34; i++)
    {
      data[i + 1] = data[i]; //move all element to the Right except first one
    }

    data[34] = temp; //Set the held value to new position.

  	return data;
}

//address the pins of the selected 7 seg display.
MM5451::displaySSeg(Bool b, int (&data)[35])
{

	//Update Data and send it. 
	if( b )
	{
		//CC, Logic 1 on. Read table directly

		
	}
	if(!b)
	{
		//CA, Logic 0 on. Invert Table

	}
	else
	{
		//Error
	}

	//SendData(data);


}

//SendData is given a 35 Bits
MM5451::SendData(uint8_t array[])
{
	//Prepare for Transmission
	digitalWrite(_DataPin, 1);
	pulseCLK();

	for (int i = 0; i < 35; i++)
	{
		if (array[i] == 0x01)
		{
			digitalWrite(_DataPin, 1);
		}
		else {
			digitalWrite(_DataPin, 0);
		}

		pulseCLK();
	}

}
