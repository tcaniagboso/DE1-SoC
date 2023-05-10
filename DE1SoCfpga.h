#ifndef DE1SOCFGPA_H
#define DE1SOCFGPA_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using namespace std;

const unsigned int LW_BRIDGE_BASE = 0xFF200000; // Base offset
// Physical final address of FPGA Devices
const unsigned int FINAL_PHYSICAL_ADDRESS = 0xFFFEC700; // Final offset
// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN = FINAL_PHYSICAL_ADDRESS - LW_BRIDGE_BASE;
//0x00DEC700; // Address map size
// Cyclone V FPGA device addresses
const unsigned int LEDR_OFFSET = 0;//Physical ADDRESS of RED LED - LW_BRIDGE_BASE ;
//Write the value in Hex here
const unsigned int SW_OFFSET = 0x40;//Physical ADDRESS of SWITCH - LW_BRIDGE_BASE ;
//Write the value in Hex here
const unsigned int KEY_OFFSET = 0x50;//Physical ADDRESS of PUSH BUTTON - LW_BRIDGE_BASE; Write the value in Hex here
const unsigned int HEX3_HEX0_OFFSET = 0x20;
const unsigned int HEX5_HEX4_OFFSET = 0x30;

class DE1SoCfpga
{
    public: 
    
    char *pBase;
    int fd;
    DE1SoCfpga();
    ~DE1SoCfpga();
    void RegisterWrite(unsigned int reg_offset, int value);
    int RegisterRead(unsigned int reg_offset); 
       
};
#endif
