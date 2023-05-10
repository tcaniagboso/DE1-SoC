#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include "DE1SoCfpga.h"

class LEDControl : public DE1SoCfpga{
public: 
        int previousButtonState;
        LEDControl();
       ~LEDControl();
       
       void Write1Led(int ledNum, int state);
       void WriteAllLeds(int value);
       int ReadAllSwitches();
       int Read1Switch(int switchNum);
       int PushButtonGet();        
};
#endif