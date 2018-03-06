/******************************************************************************/
/*                                                                            */
/*  Filename: BlinkTutorial.ino                                               */
/*  Description: This file contains the blink tutorial for Teensy 3.6 with    */
/*               some changes to play with the API for Teensy and its         */
/*               capabilities                                                 */
/*  Origin date: March 5th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#include "serialSupport.h"

#define BAUDRATE    (38400)    // Teensy 3.6 baud rate
#define LED            (13)    // Teensy 3.6 LED pin number
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
    setupLed(LED);
    gCounter = startSerial(BAUDRATE);
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
    
    while(gCounter >= 0 && gCounter < 200)
    {
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
}

