#include <stdio.h>

// An array of pointers is an ordinary array variable
// whose elements happen to be all pointers.

/*
1. Create three functions
2. Create an array of function pointers in both data memory and flash memory
to point to these three functions.
3. Step through the code to access the structure using struct pointers
*/

// variable declarations

unsigned char functionState=0;
unsigned int functionResult=0;

//function prototypes

int function1(int x);
int function2(int y);
int function3(int z);
int functionHalf(int x);

// function pointer declarations and initializations. 

int (*funPtr[3])(int a) = {&function1,&function2,&function3};

// place function pointer in read only memory ??

int (*const funPtrFlash[3])(int a)= {&function1,&function2,&function3};

int main()
{
    // The functionState variable is incremented afer each indirect function call so the next function is called

    while (1)
    {
        functionState=0;
        functionResult=funPtr[functionState](2);

         // calls function2 
        functionState++;
        functionResult=funPtr[functionState](2);
        
        //calls function3
        functionState++;
        functionResult=funPtr[functionState](2);

        functionState=0;

        funPtr[2]=&functionHalf;
        functionResult=funPtr[2](2);

        // now use function pointer in program memory 
        
        // call function1 
        functionState=0;
        functionResult=funPtrFlash[functionState](3);

        // call function2 
        functionState++;
        functionResult=funPtrFlash[functionState](3);

        //call function 3 
        functionState++;
        functionResult=funPtrFlash[functionState](3);

       // funPtrFlash[functionState]=functionHalf;// illegal

       functionState=0;
    }
    

return 0;
}
int function1(int x) { return x;}
int function2(int y) { return y*y;}
int function3(int z) { return z*z*z;}
int functionHalf(int x) {return x/2;}