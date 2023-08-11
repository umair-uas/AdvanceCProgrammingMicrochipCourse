#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1. Create three functions
2. Create an array of function pointers 
to point to these three functions.
3. Use the created functions pointers as states in state machine. 
4. Step through the code to access the structure using struct pointers
*/

// an enum for system states

typedef enum {
    STATE_RED=0,
    STATE_YELLOW,
    STATE_GREEN,
    NUM_STATES
}SYSTEM_STATE;

SYSTEM_STATE gSystemState = STATE_RED;

const char* stateNames[NUM_STATES]= {
    "RED","YELLOW","GREEN"};

// These functions are called indirectly through a function pointer. 
// They are passed a value by RunStateMachine function and return either the inputBits values 
// that is passed or a literal value. 
// Each function also increments the state machine. 

void stateRed(void);
void stateGreen(void);
void stateYellow(void);

/*
    Array of function pointers to function of form 
    'unsigned (int fName[])(unsigned int, *SYSTEM_STATE)'

*/
void  (*pStateFunction[NUM_STATES])(void)={
    stateRed,
    stateGreen,
    stateYellow
};


// state transition function 
void transitionToNextState(void) {

    gSystemState=(gSystemState +1) % NUM_STATES;
}

void  RunStateMachine(void)
{
    struct timespec delayTime; 
    while (1)
    {
        struct timespec currentTime;
        clock_gettime(CLOCK_REALTIME,&currentTime);
        char timestamp[20];
        strftime(timestamp,sizeof(timestamp),"%H:%M:%S",localtime(&currentTime.tv_sec));
        printf(" %s - ",timestamp);
        pStateFunction[gSystemState]();
    // delay between 1 and 5 seconds
        int delaySeconds= rand() %5+1 ; 
        delayTime.tv_nsec=0;
        delayTime.tv_sec=delaySeconds;
        // use clock_nanoslepp to introduce the delay
        clock_nanosleep(CLOCK_MONOTONIC,0,&delayTime,NULL);
        transitionToNextState();
    }
    
}

int main () {

    srand(time(NULL));
    RunStateMachine();
    
    return 0;
}

void stateRed(void) { printf( "Traffice Light: %s \n",stateNames[gSystemState]);}
void stateGreen(void) { printf( "Traffice Light: %s \n",stateNames[gSystemState]);}
void stateYellow(void) { printf( "Traffice Light: %s \n",stateNames[gSystemState]);}