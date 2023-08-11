#include <stdio.h>


/* 
1. Create an array of pointers to initialized strings
2. Create a double pointer to the array of pointers.
3. Use the dereferenced double pointer to access the string characters

*/

const char* p[4] = {"ALARM","FAULT","SENSOR","UNLOCK"};
const char **pp=&p[0]; // const char **pp=p;
unsigned char y;

// Function protoype
void string_access(const char** message_pointer);

int main() 
{
 /*
 Step through the following code and watch 'y' variables. THis code will separately access each string
 in the array.This code will pass the pointer address to the strings to the function. 
 It will also increment double pointer to point to the next string. 
 This demonstrate how to pass pointer to function. 
 */
    while(1)
    {
        // Access "ALARM"
        pp=&p[0];
        string_access(&*pp);

        // Access "FAULT"
        pp++;
        string_access(&*pp);


        // Access "SENSOR"
        pp++;
        string_access(&*pp);

        // Access "UNLOCK"
        pp++;
        string_access(&*pp);
        //string_access(p);
    

        while(1);
    }
    return 0;
}

/*
This function receives the address of array pointer to the text strings.
The double pointer allows us to pass the address of pointers to functions.
The function will access each character in the string. 
*/
void string_access(const char** message_pointer)
{

    unsigned char i;
    do
    {
        y=*(*message_pointer+i);
       /*  if(y !='\0'){
            printf("%c",y);
        } */
        i++;
    } while (y!='\0');
    

}