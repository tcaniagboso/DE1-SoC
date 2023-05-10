#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include "DE1SoCfpga.h"

class SevenSegment : public DE1SoCfpga{

    public: 
    
        SevenSegment();
       ~SevenSegment();
       
       void Hex_ClearAll();
       void Hex_ClearSpecific(int index);
       void Hex_WriteSpecific(int index, int value);
       void Hex_WriteNumber(int number);
       
       
     private: 
        
        unsigned int reg0_hexValue;
        unsigned int reg1_hexValue;
        
};
#endif
