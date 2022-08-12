/*
 * MM5451.h - Library for controlling the MM5451 LED Driver with your Arduino board.
 * Created by Arthur W. Aznive Jr., August 11 2022.
 * Released into the Public Domain.
 * 
 */
 
#ifndef MM5451_h
#define MM5451_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class MM5451
{
  public:
    //Constructor
    LED_Driver(int DataPin, int CLK);

    //Methods

    //returns the pin this Driver is using.
    getDataPin();

    //Scroll the data held in the 
    ScrollData();

  private:
    int _DataPin;
    int _CLK;
    
    //Sends 35 bits of data to the board to output
    /**
     * @brief Construct a new Send Data object
     * 
     * @param _array 
     */
    SendData(uint8_t _array[]);

    /**
     * @brief It just dootdoot
     * 
     */
    pulseCLK();
};


#endif
