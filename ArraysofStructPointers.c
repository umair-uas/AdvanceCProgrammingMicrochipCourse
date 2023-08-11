#include <stdio.h>

// An array of pointers is an ordinary array variable
// whose elements happen to be all pointers.

/*
1. Create Typedef structure
2. Create instances of structure
3. Step through the code to access the structure using struct pointers
4. Analyze the operation of a function that receives the address of the array of structure pointers
*/

// Create a typedef struct

typedef struct struct_alarm_type
{
    unsigned char u8alarmTimeSeconds;
    unsigned char u8alarmTimeMinutes;
    unsigned char u8alarmTimeHours;
} STRUCT_ALARM_Type;

// Create 5 of such ALARM_Type structs;
STRUCT_ALARM_Type STRUCT_alarmDescriptor[5];

// Create  array of pointers to point to 5 instances of STRUCT_ALARM_Type
STRUCT_ALARM_Type *p_STRUCT_alarmDescriptor[5] = {&STRUCT_alarmDescriptor[0], &STRUCT_alarmDescriptor[1],
                                                  &STRUCT_alarmDescriptor[2], &STRUCT_alarmDescriptor[3], &STRUCT_alarmDescriptor[4]};

// Create a single pointer to show how a single pointer can be used here as well
STRUCT_ALARM_Type *p_STRUCT_singlePointer = &STRUCT_alarmDescriptor[0];

// function prototype for passing single pointer

void load_alarm_data_using_pointer(STRUCT_ALARM_Type *p_structure, unsigned char seconds,
                                   unsigned char minutes, unsigned char hours);

// function protoype for passing array of pointers

void load_alarm_data_using_pointer_array(STRUCT_ALARM_Type *p_structure[], unsigned char seconds,
                                         unsigned char minutes, unsigned char hours);

int main()
{

    unsigned char i;
    for(i=0;i<5;i++)
    {
        // Load values directory with pointer
        p_STRUCT_alarmDescriptor[i]->u8alarmTimeHours=3;
        p_STRUCT_alarmDescriptor[i]->u8alarmTimeSeconds=13;
        p_STRUCT_alarmDescriptor[i]->u8alarmTimeMinutes=39;
    
    // Pass the address to change the actual alarmDescriptor location 
    load_alarm_data_using_pointer(&STRUCT_alarmDescriptor[i],4,5,7);

    // pass the address using pointer

    load_alarm_data_using_pointer(p_STRUCT_alarmDescriptor[i],7,4,5);

   // set the structure values using a single pointer
   load_alarm_data_using_pointer(p_STRUCT_singlePointer,0xA,0xB,0xC);

   // increment the single pointer
   p_STRUCT_singlePointer++; 
    
    }

    // pass array of pointers to function 
    load_alarm_data_using_pointer_array(&p_STRUCT_alarmDescriptor[0],66,55,44);
    while (1);
   
    return 0;
}

// Receive one pointer and act on that location
void load_alarm_data_using_pointer(STRUCT_ALARM_Type *p_structure, unsigned char seconds,
                                   unsigned char minutes, unsigned char hours)
{
    if(p_structure){
    p_structure->u8alarmTimeSeconds = seconds;
    p_structure->u8alarmTimeMinutes = minutes;
    p_structure->u8alarmTimeHours = hours;
}

}


// function protoype for passing array of pointers

void load_alarm_data_using_pointer_array(STRUCT_ALARM_Type *p_structure[], unsigned char seconds,
                                         unsigned char minutes, unsigned char hours)
{

    unsigned char j;

    for (j = 0; j < 5; j++)
    {
        p_structure[j]->u8alarmTimeHours=hours;
        p_structure[j]->u8alarmTimeMinutes=minutes;
        p_structure[j]->u8alarmTimeSeconds=seconds;
    }
    
}