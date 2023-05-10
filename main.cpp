#include "SevenSegment.h"
#include "DE1SoCfpga.h"
#include "LEDControl.h"


int main(void)
{

 LEDControl fpga;
 SevenSegment display;

  // test LED and switch functions
  int LEDVAL = fpga.ReadAllSwitches();
  fpga.WriteAllLeds(LEDVAL);
  display.Hex_WriteNumber(LEDVAL);

  for (int i = 0; i < 10; i++) {
   cout << "Switch " << i << " is " << fpga.Read1Switch(i) << endl;
    }

   while (true) {
      int buttonValue = fpga. PushButtonGet();
       int ledValue = fpga.RegisterRead(LEDR_OFFSET);
      if (buttonValue == 1) { // KEY0 pressed
         ledValue++;
        fpga. WriteAllLeds(ledValue);
     }
      else if (buttonValue == 2) { // KEY1 pressed
         ledValue--;
        fpga.WriteAllLeds(ledValue);
     }
      else if (buttonValue == 3) { // KEY2 pressed
        ledValue >>= 1;
        fpga.WriteAllLeds(ledValue);
     }
     else if (buttonValue == 4) { // KEY3 pressed
        ledValue <<= 1;
        fpga.WriteAllLeds(ledValue);
     }
     
     usleep(10000); // sleep for 10 ms to prevent busy waiting
     display.Hex_WriteNumber(ledValue);
   }


//display->Hex_WriteNumber(hex_value); // display value
cout << "Terminating...!" << endl;
return 0;
}