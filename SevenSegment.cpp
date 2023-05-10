#include "SevenSegment.h"
using namespace std;


const unsigned int bit_values[16] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7,0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

SevenSegment::SevenSegment(){

    reg0_hexValue = 0;
    reg1_hexValue = 0;
}

SevenSegment::~SevenSegment(){

     Hex_ClearAll();
}

void SevenSegment::Hex_ClearAll(){
  //cout << "hello again" << endl;
    RegisterWrite(HEX3_HEX0_OFFSET, 0);
    RegisterWrite(HEX5_HEX4_OFFSET, 0);
}

void SevenSegment::Hex_ClearSpecific(int index){
        //cout << "holle" << endl;
         //RegisterWrite(HEX3_HEX0_OFFSET+3, 0);    
        int val;          
            
        if (index >=0 && index <= 3){
            val = 127<<(index*8);
            val = ~val;
            reg0_hexValue = reg0_hexValue & val;
            RegisterWrite(HEX3_HEX0_OFFSET, reg0_hexValue);
            }
            
        else{
            val = 127<<((index-4)*8);
            val = ~val;
            reg1_hexValue = reg1_hexValue & val;
            RegisterWrite(HEX5_HEX4_OFFSET, reg1_hexValue);
                
            }

}
       
void SevenSegment::Hex_WriteSpecific(int index, int value){
//cout << "hello" << endl;
//RegisterWrite(HEX3_HEX0_OFFSET, bit_values[value]);
    if (value < -16 || value > 15){              
        cout<<"Cannot be displayed"<<endl;
    }  
    else{
        int val;
        if (value < 0){
                
            value += 16;
                
        }
                
        val = bit_values[value];
        Hex_ClearSpecific(index);
                
        if (index >= 0 && index <= 3){

            val = val<<(index*8);
            reg0_hexValue = val | reg0_hexValue;
            RegisterWrite(HEX3_HEX0_OFFSET, reg0_hexValue);
                    
        }
                    
        else{

            val = val<<((index - 4)*8);
            reg1_hexValue = val | reg1_hexValue;
            RegisterWrite(HEX5_HEX4_OFFSET, reg1_hexValue);
                    
        }
        }

}
       
void SevenSegment::Hex_WriteNumber(int number){

    Hex_ClearAll();
    int digit;
            
    if (number < 0){
                
        number += 16777216; //0xFFFFFF
    }

    for (int i = 0; i < 6; i++){
                
        digit = number % 16;
        Hex_WriteSpecific(i, digit);
        number = (number-digit) /16;
    }
           
    reg0_hexValue = RegisterRead(HEX3_HEX0_OFFSET);
    reg1_hexValue = RegisterRead(HEX5_HEX4_OFFSET);


}