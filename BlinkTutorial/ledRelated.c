/******************************************************************************/
/*                                                                            */
/*  Filename: ledRelated.c                                                    */
/*  Description: LED related functions                                        */
/*  Origin date: March 5th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#include "ledRelated.h"
int gLedPin;

/******************************************************************************/ 
/*  Function name: setupLed                                                   */
/*  Function description: setup the LED pin                                   */
/*  Input Params: int LED pin number                                          */
/*  Output Params:                                                            */
/*  Return value:                                                             */
/******************************************************************************/
void setupLed(int pinNum)
{
    gLedPin = pinNum;
    pinMode(gLedPin, OUTPUT);   // set LED pin to 
}

/******************************************************************************/ 
/*  Function name: blinkOnce                                                  */
/*  Function description: makes the LED blink once, assuming that the LED pin */
/*                        is already set to OUTPUT mode                       */
/*  Input Params: int duration in miliseconds                                 */
/*  Output Params:                                                            */
/*  Return value:                                                             */
/******************************************************************************/
void blinkOnce(int duration, byte keepOn)
{
    digitalWrite(gLedPin, HIGH);   // turn on the LED. HIGH is the voltage level
    delay(duration);
    if(!keepOn)
    {
       digitalWrite(gLedPin, LOW);   // turn off the LED. LOW is the voltage level
    }
}

/******************************************************************************/ 
/*  Function name: multiBlink                                                 */
/*  Function description: makes the LED blink multiple times, according the   */
/*                        given number of times                               */
/*                        This function assumes the LED pinmode is set to OUT */
/*  Input Params: int duration in miliseconds for both on and off time        */
/*                int number of times to blink                                */
/*  Output Params:                                                            */
/*  Return value:                                                             */
/******************************************************************************/
void multiBlink(int durationOn, int durationOff, int times)
{
    int loopCounter;
    
    for(loopCounter = 0 ; loopCounter < times ; loopCounter++)
    {
        blinkOnce(durationOn, false);
        delay(durationOff);
    }
}
