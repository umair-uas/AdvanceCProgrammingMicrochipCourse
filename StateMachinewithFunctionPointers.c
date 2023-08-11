#include <stdio.h>

/*
1. Create three functions
2. Create an array of function pointers 
to point to these three functions.
3. Use the created functions pointers as states in state machine. 
4. Step through the code to access the structure using struct pointers
*/

// an enum for system states

typedef enum {
    STATE0=0,
    STATE1,
    STATE2
}SYSTEM_STATE;

SYSTEM_STATE gSystemState;

// These functions are called indirectly through a function pointer. 
// They are passed a value by RunStateMachine function and return either the inputBits values 
// that is passed or a literal value. 
// Each function also increments the state machine. 

unsigned int function1(unsigned int InputBits,SYSTEM_STATE *state);
unsigned int function2(unsigned int InputBits,SYSTEM_STATE *state);
unsigned int function3(unsigned int InputBits,SYSTEM_STATE *state);

/*
    Array of function pointers to function of form 
    'unsigned (int fName[])(unsigned int, *SYSTEM_STATE)'

*/

unsigned int (*pStateFunction[])(unsigned int InputBits,SYSTEM_STATE* state)={
    function1,
    function2,
    function3
};

// FUnction that is called to run state machine. Called by main() program and it calls the proper
// function based on the state variable

unsigned int RunStateMachine(unsigned int InputBits);

int main () {

    volatile unsigned int result1,result2,result3;
    while (1)
    {
        gSystemState=STATE0;
        result1=RunStateMachine(1);
        

        // gSystemState should be increment by the function 
        result2=RunStateMachine(2);

        // gSystemState should be increment by the function 
        result3=RunStateMachine(3);
    }
    
    return 0;
}

unsigned int RunStateMachine(unsigned int InputBits)
{

    return (*pStateFunction[gSystemState])(InputBits,&gSystemState);

}
unsigned int function1(unsigned int InputBits,SYSTEM_STATE *state)
{
    (*state)++;
    if (InputBits ==0 && *state >1)
    {
        return InputBits;
    }
    else return 99;
       
}
unsigned int function2(unsigned int InputBits,SYSTEM_STATE *state)
{

    (*state)++;
    if (InputBits ==2 && *state >1)
    {
        return InputBits*InputBits;
    }
    else return 88;

}
unsigned int function3(unsigned int InputBits,SYSTEM_STATE *state)
{

    (*state)++;
    if (InputBits >=2 && *state >1)
    {
        return InputBits*InputBits*InputBits;
    }
    else return 77;
}