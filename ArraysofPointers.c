#include <stdio.h>


// An array of pointers is an ordinary array variable 
// whose elements happen to be all pointers. 

/*
1. Create different pointers arrays to 4 different strings each 
2. Create the character string in flash(read only memory)  and initialize the 
array of pointers to point to these strings
3. Step through the code to access each of the characters in all four strings of each array

*/

// Generic loop variables are declared
unsigned char i=0,j=0,y;


// Create an array of pointers and initialize 4 different strings. 
/*
This declares an array of four constant pointers to characters. 
The pointers themselves are constant, which means you cannot 
change what memory addresses they point to. 
. In C, string literals are always treated as constant (read-only) 
arrays of characters. Even if you don't explicitly use the const keyword, 
string literals are by default considered as read-only,
 and you should not attempt to modify them.
*/
char* const p[4] = {"a01","b02","c03","d04"};

// create an array of pointers that reside in data memory 
/*
This declares an array of four pointers to constant characters. 
The pointers themselves are not constant, 
so you can change where they point to.
 However, you cannot modify the characters they point to. 
 The strings "e01", "f02", "g03", and "h04" are constant 
 and reside in read-only memory. 
 The pointers q[0], q[1], q[2], and q[3] point to the memory locations
  of these read-only strings. 
You cannot modify the characters within each string.
*/
const char* q[4]= {"e01","f02","g03","h04"};

int main() 
{

    while(1)
    {

        //Step through p[] pointer
        // loop variable i increment will move to the next string, 
        // while variable j increment will move to the next character in that string
        for(i=0;i<4;i++,j=0) 
        {
            do
            {
                y=*(p[i]+j);
                j++;
            } while (y!='\0');
            
        }

        // Step through q[] pointer
        for (i=0;i<4;i++,j=0)
        {
            do
            {
                y=*(q[i]+j);
                j++;
            } while (y!='\0');
            
        }

    }
return 0;
}
