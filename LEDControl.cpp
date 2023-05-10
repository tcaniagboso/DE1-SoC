#include "LEDControl.h"


using namespace std;



LEDControl::LEDControl(){
    previousButtonState = 0;   
}

LEDControl::~LEDControl(){

}

void LEDControl::Write1Led(int ledNum, int state){

   int ledValue = RegisterRead(LEDR_OFFSET);

   if (state == 1) {
     ledValue |= (1 << ledNum);
    } else {
        ledValue &= ~(1 << ledNum);
    }

   RegisterWrite(LEDR_OFFSET, ledValue);
}

void LEDControl::WriteAllLeds(int value){
     RegisterWrite(LEDR_OFFSET, value);
}
       
int LEDControl::ReadAllSwitches(){
   return RegisterRead(SW_OFFSET);
}
       
int LEDControl::Read1Switch(int num){

   int switchValue = RegisterRead(SW_OFFSET);

   if (switchValue & (1 << switchNum)) {
      return 1;
   } else {
       return 0;
   }


}
    
int LEDControl::PushButtonGet(){

    int current_button_state = RegisterRead(KEY_OFFSET);

    if (current_button_state != previousButtonState) {
        // If a change in button state is detected, debounce
        usleep(1000); // Wait for 1ms
        current_button_state = RegisterRead(KEY_OFFSET);

        if (current_button_state != previousButtonState) {
            // If the button state is still different, return the new state
            previousButtonState = current_button_state;

            if (current_button_state & 0x1) {
                // KEY0 is pressed
                return 1;
            } else if (current_button_state & 0x2) {
                // KEY1 is pressed
                return 2;
            } else if (current_button_state & 0x4) {
                // KEY2 is pressed
                return 3;
            } else if (current_button_state & 0x8) {
                // KEY3 is pressed
                return 4;
            }
        }
    }

    return 0;
 }
