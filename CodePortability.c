#include <stdint.h>


/*
1. Create three functions each for two RAM buffers:
    * initialize
    * read
    * write
2. Create a struct of function pointers.
3. Create an array of structure that contains function pointers. 
4. Create an enum to select between the two buffers. 
5. Access both buffers using a common interface. 
*/

// Variable declarations

unsigned short u16buffer1[16];
unsigned short u16buffer2[16];
unsigned short u16dataBufferRead;

// enum for two buffers

typedef enum {BUFFER1, BUFFER2}buffer_configurations_t;

// Function prototypes
void BUFFER1_Initialize(unsigned short u16bufferFill);
unsigned short BUFFER1_Read(unsigned char u8index);
void BUFFER1_Write(unsigned char u8index, unsigned short u16value);
void BUFFER2_Initialize(unsigned short u16bufferFill);
unsigned short BUFFER2_Read(unsigned char u8index);
void BUFFER2_Write(unsigned char u8index, unsigned short u16value);

// Create three function pointers within a typedef struct , 
// THe three functions will initialize,read and write the two buffers.

typedef struct {
    void (*DataInit)(unsigned short bufferFill);
    void (*DataWrite)(unsigned char index,unsigned short value);
    unsigned short  (*DataRead)(unsigned char index);
}buffer_functions_t;


// The buffer_access[]   array contains the address for both of the buffer
// initialize,read and write functions. This array is place inread only memory(flash)
const buffer_functions_t buffer_access[] = {
    {BUFFER1_Initialize, BUFFER1_Write,BUFFER1_Read},
    {BUFFER2_Initialize,BUFFER2_Write,BUFFER2_Read}
};


int main() 

{

    // Initialize both buffers
    buffer_access[BUFFER1].DataInit(0x55);
    buffer_access[BUFFER2].DataInit(0xAA);

    while (1)
    {
        //Access the functions for each buffer using the buffer_access[]array
        buffer_access[BUFFER1].DataWrite(4,0x4321);
        u16dataBufferRead=buffer_access[BUFFER1].DataRead(4);

        buffer_access[BUFFER2].DataWrite(7,0x7896);
       u16dataBufferRead= buffer_access[BUFFER2].DataRead(7);

        while(1);
    }
     

    return 0;
}


// Write 16 integer values to BUFFER1 
void BUFFER1_Initialize(unsigned short u16bufferFill)
{
    unsigned char i;
    for(i=0;i<=15;i++)
    {
        u16buffer1[i]=u16bufferFill;
    }
}

// Read a 16bit value from BUFFER1 at the index specified by u8index

unsigned short BUFFER1_Read(unsigned char u8index)
{
    return u16buffer1[u8index];
}

// Write one 16bit value to BUFFER1 at the address specified by u8index

void BUFFER1_Write(unsigned char u8index,unsigned short u16value)
{
    u16buffer1[u8index]=u16value;
}

// Write 16 integer values to BUFFER2 
void BUFFER2_Initialize(unsigned short u16bufferFill)
{
    unsigned char i;
    for(i=0;i<=15;i++)
    {
        u16buffer2[i]=u16bufferFill;
    }
}

// Read a 16bit value from BUFFER2 at the index specified by u8index

unsigned short BUFFER2_Read(unsigned char u8index)
{
    return u16buffer2[u8index];
}

// Write one 16bit value to BUFFER2 at the address specified by u8index

void BUFFER2_Write(unsigned char u8index,unsigned short u16value)
{
    u16buffer2[u8index]=u16value;
}