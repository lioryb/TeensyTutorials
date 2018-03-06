/******************************************************************************/
/*                                                                            */
/*  Filename: serialSupport.c                                                 */
/*  Description: Serial related functions                                     */
/*  Origin date: March 5th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#include "serialSupport.h"
#include "ledRelated.h"
#include "Arduino.h"

/******************************************************************************/
/*  Function name: startSerial                                                */
/*  Function description: starts the serial port and waits for it             */
/*  Input Params: int baudrate                                                */
/*  Output Params:                                                            */
/*  Return value: int - 0 for success / (-1) for failure                      */
/******************************************************************************/
int startSerial(int buadrate)
{
    int serialTimeOut = 0;
    int returnValue = -1;
    
    multiBlink(100, 100, 4);
    blinkOnce(100, true);
    Serial.begin(buadrate);
    while(!Serial && serialTimeOut<50)
    {
        // wait
        delay(100);
        serialTimeOut++;
    }
    
    if(Serial)
        returnValue = 0;
    else
        multiBlink(200, 200, 2);

        
    return returnValue;
    
}