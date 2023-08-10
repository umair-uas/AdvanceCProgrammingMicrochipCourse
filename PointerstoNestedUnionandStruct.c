#include <stdio.h>


typedef union LED_ROTATE_Type
{
    
    unsigned long reg;
    struct {
        unsigned char u8rotateForwardSpeed;
        unsigned char u8rotateBackwardSpeed;
        unsigned char u8speedRateChange;
        unsigned char b1rotateStatusFlag: 2;
    } member;
}LED_ROTATE_Type;

typedef union {

    unsigned long reg;
    struct {
        unsigned short u16pwmLightIntensity;
        unsigned char u8breathSpeed;
        unsigned char b1breatheFlags: 2;

    }member;
}LED_BREATHE_Type;


typedef union {
    unsigned long reg;
    struct {
        unsigned char u8pattern[4];
    }member;
}LED_PATTERN_Type;

// Create  struct that holds all three unions
typedef struct {

    volatile LED_ROTATE_Type ledRotation;
    volatile LED_PATTERN_Type ledPattern;
    volatile LED_BREATHE_Type ledBreathe;
} STRUCT_LEDVariables;

//Create the instance of all unions and structures by creating the instance of STRUCT_LEDVariables

STRUCT_LEDVariables STRUCT_allLEDVariables;

//create a pointer to struct STRUCT_LEDVariables

STRUCT_LEDVariables *pSTRUCT_LEDVariables= &STRUCT_allLEDVariables;

int main() 
{

    while(1)
    {
       pSTRUCT_LEDVariables->ledRotation.reg=0xABCDECFF;
       pSTRUCT_LEDVariables->ledRotation.member.u8rotateForwardSpeed=0x11;
       pSTRUCT_LEDVariables->ledRotation.member.u8rotateBackwardSpeed=0x22;
       pSTRUCT_LEDVariables->ledRotation.member.u8speedRateChange=0x55;
       pSTRUCT_LEDVariables->ledRotation.member.b1rotateStatusFlag=1;//bottom 2 bits of AB-->11=0x3


       pSTRUCT_LEDVariables->ledPattern.reg=0x11111111;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[0]=0xAA;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[1]=0xBB;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[2]=0xCC;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[3]=0xDF;


       pSTRUCT_LEDVariables->ledBreathe.reg=0x12345678;
       pSTRUCT_LEDVariables->ledBreathe.member.u8breathSpeed=0x33;
       pSTRUCT_LEDVariables->ledBreathe.member.u16pwmLightIntensity=0xFEDC;
       pSTRUCT_LEDVariables->ledBreathe.member.b1breatheFlags=0b11;

    while(1);
    }
return 0;
}
