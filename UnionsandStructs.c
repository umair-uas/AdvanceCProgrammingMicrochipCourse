#include <stdio.h>
/*
******************************************************************************
 *                             Union Example                                 *
 ******************************************************************************
 
 * Key Concepts:
 * --------------
 * 1. Union: A union is a composite data type that allows different members to share
 *    the same memory location. It enables us to access the same memory block through
 *    different data types, which is useful for interpreting raw data in various ways.
 * 
 * 2. A/D Conversion: The code simulates an A/D conversion result using constants
 *    ADRESH and ADRESL, representing the high and low bytes of the conversion result.
 * 
 * 3. Bit Fields: The union contains a structure with bit fields. Bit fields allow us
 *    to define how the bits of a data member are used, which is especially helpful
 *    when working with registers.
 * 
 * Usage:
 * ------
 * 1. The code creates a union named UNION_ADRead that contains an unsigned integer
 *    u16ADRead and a structure STRUCT_ADReadMembers. The structure has two unsigned
 *    char members: u8ADReadLow and u8ADReadHigh.
 * 
 * 2. The high and low bytes of the A/D conversion result are stored in
 *    UNION_ADRead.STRUCT_ADReadMembers.u8ADReadHigh and
 *    UNION_ADRead.STRUCT_ADReadMembers.u8ADReadLow, respectively.
 * 
 * 3. The printf function is used to display the full 16-bit A/D conversion result in
 *    hexadecimal format, stored in UNION_ADRead.u16ADRead.
 * 
 ******************************************************************************
 *
 *                             Struct Example                                *
 ******************************************************************************

 * 
 * Key Concepts:
 * --------------
 * 1. Struct: A struct is a composite data type that groups together variables of
 *    different data types under a single name. Bit fields are used to allocate a
 *    specific number of bits for each member of the struct.
 * 
 * 2. Bit Fields: Bit fields allow us to allocate a specific number of bits for a
 *    variable, enabling efficient storage of data with limited range.
 * 
 * Usage:
 * ------
 * 1. The code defines a struct named STRUCT_sensor, which contains multiple bit
 *    fields representing different sensor readings, such as volts, amps, humidity,
 *    temperature, and tachometer.
 * 
 * 2. An instance of STRUCT_sensor, named 'y', is declared and its individual bit
 *    fields are set to represent specific sensor readings.
 * 
 * 3. The values of individual bit fields within the 'y' instance are printed using
 *    printf statements.
 * 
 *****************************************
*/
#define ADRESH 0xDF
#define ADRESL 0x23
typedef struct byteBits
{
    unsigned int b1volts: 1;
    unsigned int b1amps: 1;
    unsigned int b1humid: 2;
    unsigned int b1temp: 1;
    unsigned int b1tach: 3;
}STRUCT_sensor;

int main() {
    union {
        unsigned int u16ADRead;
        struct {
            unsigned char u8ADReadLow;
            unsigned char u8ADReadHigh;
        } STRUCT_ADReadMembers;
    } UNION_ADRead;

    // For A/D Reading in two separate registers:
    UNION_ADRead.STRUCT_ADReadMembers.u8ADReadHigh = (unsigned char)ADRESH;
    UNION_ADRead.STRUCT_ADReadMembers.u8ADReadLow = (unsigned char)ADRESL;

   
    // Now u16ADRead contains the full 16-bit A/D conversion result
    printf("Full 16-bit result: %04X\n", UNION_ADRead.u16ADRead);
STRUCT_sensor y;
y.b1volts=1;
y.b1amps=0;
y.b1humid=0b10;
y.b1temp=0x0;
y.b1tach=7;
printf("struct y: %02X \n",y);// incorrect due to bitfields
printf ("y.b1volts= %02X\n",y.b1volts);
printf ("y.b1amps= %02X\n",y.b1amps);
printf ("y.b1humid= %02X\n",y.b1humid);
printf ("y.b1temp= %02X\n",y.b1temp);
printf ("y.b1tach= %02X\n",y.b1tach);
    return 0;
}
