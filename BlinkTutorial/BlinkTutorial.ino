/******************************************************************************/
/*                                                                            */
/*  Filename: BlinkTutorial.ino                                               */
/*  Description: This file contains the blink tutorial for Teensy 3.6 with    */
/*               some changes to play with the API for Teensy and its         */
/*               capabilities                                                 */
/*  Origin date: March 5th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#define LED            (13)    // Teensy 3.6 LED pin number
#define BAUDRATE    (38400)    // Teensy 3.6 baud rate
#define ONTIME       ( 200)    // miliseconds to keep LED on
#define OFFTIME      ( 200)    // miliseconds to keep LED off


int gCounter;                  // global variable for counter


/******************************************************************************/
/*  Function name: setup                                                      */
/*  Function description: setup routine to run once on startup                */
/*  Input Params:                                                             */
/*  Output Params:                                                            */
/******************************************************************************/
void setup()
{
    pinMode(LED, OUTPUT);   // set LED pin to 
    Serial.begin(BAUDRATE);
    gCounter = 0;
}

/******************************************************************************/
/*  Function name: loop                                                       */
/*  Function description: forever loop routing                                */
/*  Input Params:                                                             */
/*  Output Params:                                                            */
/******************************************************************************/
void loop()
{
    String locString;
    
    locString = "Turning LED on for ";
    locString += ONTIME;
    locString += "milisec. counter value: ";
    locString += gCounter;
    Serial.println(locString);
    digitalWrite(LED, HIGH);   // turn on the LED. HIGH is the voltage level
    delay(ONTIME);
    
    locString = "Turning LED off for ";
    locString += OFFTIME;
    locString += "milisec. counter value is yet: ";
    locString += gCounter;
    Serial.println(locString);
    digitalWrite(LED, LOW);   // turn off the LED. LOW is the voltage level
    delay(OFFTIME);
    
    gCounter++;
}

