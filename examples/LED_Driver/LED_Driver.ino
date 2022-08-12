/*
 * Arthur W. Aznive Jr.
 * MM5451 LED Driver Sketch
 * For controlling a 5x7 LED Matrix
 * Based upon the LAI Stacker Entertainment Machine.
 * 
 * 8/11/2022
 * 
 */
//#include MM5451.cpp
#define CLK 8     //Connect to pin 21 on the MM5451
#define DATAPIN 9 //Connect to pin 22 on the MM5451
//#define BTN 2     //Button to cycle through LEDs

byte LED = 0b00000001;

void setup()
{
  Serial.begin(9600);
  //Set Arduino pin modes to OUTPUT
  pinMode(CLK, OUTPUT);
  pinMode(DATAPIN, OUTPUT);
//  pinMode(BTN, INPUT_PULLUP);
  
  //Write a 0 to start at a baseline.
  digitalWrite(CLK, 0);
  digitalWrite(DATAPIN, 0);
  
}//End Setup

//Loop this forever! Or until you stop it. or the Heat Death of the Universe, your call~
void loop()
{
  for (int myCount = 0; myCount <= 255; myCount++)   {
    // start bit
    digitalWrite(DATAPIN, 1);
    pulseCLK();
    // the "+ 0x80" turns on DP
    ssrWriteLSB(LED); // MOD myCount = 0-9
    zeroWrite(21); // pad remaining bits with 0s
    delay(500);
  }
}//End Loop

// LSB out first!
void ssrWriteLSB(byte value)   
{
  for(int x =0; x < 8; x++)   
  {
    byte temp = value & 0x01;
    
    if (temp == 0x01)   
    {
      digitalWrite(DATAPIN, 1); // data bit HIGH
    }
    else
    {
      digitalWrite(DATAPIN, 0); // data bit LOW
    }
      
    pulseCLK();
    value = value >> 0x01; // shift left
  }
}
//Pulse the Clock
void pulseCLK()
{
  digitalWrite(CLK, 1);
  digitalWrite(CLK, 0);
}

void zeroWrite(byte num1)
{
  digitalWrite(DATAPIN, 0);     // data bit LOW
  for(int x = 0; x < num1; x++) 
  {
    pulseCLK();
  }
}

byte cycleLED(byte LED)
{
  //  LED = LED >> 0x01;
  //  return LED;
  Serial.println("Here");
}
 
