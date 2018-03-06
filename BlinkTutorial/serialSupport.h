/******************************************************************************/
/*                                                                            */
/*  Filename: serialSupport.h                                                 */
/*  Description: Header file for Serial related functions                     */
/*  Origin date: March 5th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#include "WProgram.h"
#include "WConstants.h"
#include "HardwareSerial.h"
#include "wiring.h"


#pragma once

/******************************************************************************/
/*  Function name: startSerial                                                */
/*  Function description: starts the serial port and waits for it             */
/*  Input Params: int baudrate                                                */
/*  Output Params:                                                            */
/*  Return value: int - 0 for success / (-1) for failure                      */
/******************************************************************************/
int startSerial(int buadrate);


