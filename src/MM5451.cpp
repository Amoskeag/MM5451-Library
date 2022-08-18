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

	//Initize so shifting works properly.
  	for( int i = 0; i < 35; i++ )
  	{
    	digitalWrite(DataPin, 0);
    	pulseCLK();
  	}

	_DataPin = DataPin;
	_CLK = CLK;
}

MM5451::getDataPin()
{
	//returns the assigned DataPin value.
	return _DataPin;
}

//Pulse the Clock of the MM5451
MM5451::pulseCLK()
{
	digitalWrite(_CLK, 1);
	digitalWrite(_CLK, 0);
}

//Shift Data to the Left. First element becomes last element.
MM5451::ShiftDataLeft(int (&data)[35])
{
	int temp = data[0]; //Hold First

    for (int i = 0; i < n - 1; i++)
    {
      data[i] = data[i + 1]; //move all element to the left except first one
    }

    data[n - 1] = temp;

  	return data;
}

//Shift data in the array to the next element to the right. Last element becomes the first element.
MM5451::ShiftDataRight(int (&data)[35])
{

	int temp = data[0]; //Hold First 
	
    for (int i = 0; i < 34; i++)
    {
      data[i + 1] = data[i]; //move all element to the Right except first one
    }

    data[34] = temp; //Set the held value to new position.

  	return data;
}

/**
 * @brief Scroll Data, d is a bool for direction, true is left, false is right. 
 * 
 * @param d 
 * @param data 
 */
MM5451::ScrollData(bool d, int(&data)[35])
{
	if(d)
	{
		int temp1 = data[0];
		int temp2 = data[7];
		int temp3 = data[14];
		int temp4 = data[21];
		int temp5 = data[28];
	
		for (int i = 0; i < n; i++)
		{
			data[i] = data[i + 1];
		}

		data[6] = temp1;
		data[13] = temp2;
		data[20] = temp3;
		data[27] = temp4;
		data[34] = temp5;
	}
	else
	{
		int temp1 = data[6]; //6
		int temp2 = data[13]; //13
		int temp3 = data[20];//20
		int temp4 = data[27];//27
		int temp5 = data[34];//34
	
		for (int i = n - 1; i >= 0; i--)
		{
			data[i + 1] = data[i];
		}

		data[0] = temp1;
		data[7] = temp2;
		data[14] = temp3;
		data[21]= temp4;
		data[28] = temp5;
	}

	return data;
	
}

/*address the pins of the selected 7 seg display.
*	*NEEDS WORK: I DONT HAVE A PLAN FOR THIS AT THE MOMENT.*
*/
MM5451::displaySSeg(bool b, int (&data)[35], int segArr[5])
{
	//Lookup table contains 0-F characters. 

	//create a temp array, assign it to data, return data.
	int temp[35] = {};

	//Update Data with segment characters. 
	if( b )
	{
		//CC, Logic 1 on. Read table directly
		//segArray has 5 slots, representing the max of 5, 7-seg displays.

		//Get the characters out
		for( int i = 0; i < 5; i++)
		{
			//fill the array.
			for( int j = 0; j < 35; j++)
			{
				
			}
			
			
		}
		

		
	}
	if(!b)
	{
		//CA, Logic 0 on. Invert Table readings

	}
	else
	{
		//Error
	}

	//SendData(data);


}

//SendData is given a 35 Bits
MM5451::SendData(int (&data)[35])
{
	//Prepare for Transmission
	digitalWrite(_DataPin, 1);
	pulseCLK();

	for (int i = 0; i < 35; i++)
	{
		if (array[i] == 1)
		{
			digitalWrite(_DataPin, 1);
		}
		else {
			digitalWrite(_DataPin, 0);
		}

		pulseCLK();
	}

}
