/******************************************************************************/
/*                                                                            */
/*  Filename: RedAndGreen.ino                                                 */
/*  Description: This sketch fades in and out two leds, located on pins 3 & 4 */
/*               red led is assumed to be connected to pin 4, while green led */
/*               is assumed tp be connected to pin 3                          */
/*  Origin date: March 6th, 2018                                              */
/*                                                                            */
/******************************************************************************/

#define BUILTINLED     (13)    // Teensy 3.6 LED pin number
#define REDLED          (4)
#define GREENLED        (3)
#define BAUDRATE    (38400)    // Teensy 3.6 baud rate
#define FADERATE        (2)    // miliseconds to keep LED on

#define serialIf(cond, ...)    if(cond) { Serial.println(__VA_ARGS__); }

int gCounter;                  // global variable for counter
bool serialAvailable;

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
    digitalWrite(BUILTINLED, HIGH);   // turn on the LED. HIGH is the voltage level
    delay(duration);
    if(!keepOn)
    {
       digitalWrite(BUILTINLED, LOW);   // turn off the LED. LOW is the voltage level
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
    
    multiBlink(100, 100, 4);
    blinkOnce(100, true);
    Serial.begin(buadrate);
    while(!Serial && serialTimeOut<50)
    {
        // wait
        delay(100);
        serialTimeOut++;
    }
            
    return Serial;
    
}


/******************************************************************************/
/*  Function name: setup                                                      */
/*  Function description: setup routine to run once on startup                */
/*  Input Params:                                                             */
/*  Output Params:                                                            */
/******************************************************************************/
void setup()
{
    pinMode(BUILTINLED, OUTPUT);   // set LED pin to 
    pinMode(REDLED, OUTPUT);
    pinMode(GREENLED, OUTPUT);
    if(!(serialAvailable = startSerial(BAUDRATE)))
        digitalWrite(BUILTINLED, HIGH);   // turn on the LED. HIGH is the voltage level
    else
        multiBlink(100, 100, 10);

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
    int pwmCount;

    locString = "play RED  (";
    locString += gCounter;
    locString += ")";
    serialIf(serialAvailable, locString);
    for(pwmCount = 0 ; pwmCount < 256 ; pwmCount++)
    {
        analogWrite(REDLED, pwmCount);
        delay(FADERATE);
    }
    locString = "play GREEN  (";
    locString += gCounter;
    locString += ")";
    serialIf(serialAvailable, locString);
    for(pwmCount = 0 ; pwmCount < 256 ; pwmCount++)
    {
        analogWrite(REDLED, 255-pwmCount);
        analogWrite(GREENLED, pwmCount);
        delay(FADERATE);
    }
    for(pwmCount = 255 ; pwmCount >= 0 ; pwmCount--)
    {
        analogWrite(GREENLED, pwmCount);
        delay(FADERATE);
    }
    
    gCounter++;
}

