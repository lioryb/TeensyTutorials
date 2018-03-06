/******************************************************************************/
/*                                                                            */
/*  Filename: ledRelated.h                                                    */
/*  Description: Header file for general LED functions                        */
/*  Origin date: March 5th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#include "WProgram.h"
#include "WConstants.h"

#pragma once

#if 0
class cLed
{
    private:
        int ledPin;
        
    
}
#endif

/******************************************************************************/ 
/*  Function name: setupLed                                                   */
/*  Function description: setup the LED pin                                   */
/*  Input Params: int LED pin number                                          */
/*  Output Params:                                                            */
/*  Return value:                                                             */
/******************************************************************************/
void setupLed(int pinNum);

/******************************************************************************/ 
/*  Function name: blinkOnce                                                  */
/*  Function description: makes the LED blink once, assuming that the LED pin */
/*                        is already set to OUTPUT mode                       */
/*  Input Params: int duration in miliseconds                                 */
/*  Output Params:                                                            */
/*  Return value:                                                             */
/******************************************************************************/
void blinkOnce(int duration, byte keepOn);


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
void multiBlink(int durationOn, int durationOff, int times);