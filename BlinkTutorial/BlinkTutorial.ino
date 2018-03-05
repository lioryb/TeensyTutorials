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
/*  Function name: blinkOnce                                                  */
/*  Function description: makes the LED blink once, assuming that the LED pin */
/*                        is already set to OUTPUT mode                       */
/*  Input Params: int duration in miliseconds                                 */
/*  Output Params:                                                            */
/*  Return value:                                                             */
/******************************************************************************/
void blinkOnce(int duration, bool keepOn)
{
    digitalWrite(LED, HIGH);   // turn on the LED. HIGH is the voltage level
    delay(duration);
    if(!keepOn)
    {
       digitalWrite(LED, LOW);   // turn off the LED. LOW is the voltage level
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


/******************************************************************************/
/*  Function name: startSerial                                                */
/*  Function description: starts the serial port and waits for it             */
/*  Input Params: int baudrate                                                */
/*  Output Params:                                                            */
/*  Return value: boolean for success                                         */
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


/******************************************************************************/
/*  Function name: setup                                                      */
/*  Function description: setup routine to run once on startup                */
/*  Input Params:                                                             */
/*  Output Params:                                                            */
/******************************************************************************/
void setup()
{
    pinMode(LED, OUTPUT);   // set LED pin to 
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

