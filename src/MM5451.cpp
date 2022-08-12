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

MM5451::pulseCLK()
{
  digitalWrite(_CLK, 1);
  digitalWrite(_CLK, 0);
}

//SendData is given a 35 Bits
MM5451::SendData(uint8_t array[])
{
  //Prepare for Transmission
  digitalWrite(_DataPin, 1);
  pulseCLK();

  for( int i = 0; i < 35; i++ )
  {
    if(array[i] == 0x01)
    {
      digitalWrite(_DataPin, 1);
    }
    else{
      digitalWrite(_DataPin, 0);
    }

    pulseCLK();
  }
  
}
