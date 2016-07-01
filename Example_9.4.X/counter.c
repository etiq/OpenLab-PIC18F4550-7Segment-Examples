/*
 * File name            : counter.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.4 Down Counter
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : Counter function definitions source file
 */

void Seq_count(unsigned char*ptr1, unsigned char*ptr2, unsigned char*ptr3, unsigned char*ptr4)
{
 --*ptr1;                                                         /* */
    if(*ptr1==0xFF)                                     /* Test for value in Num1 has reached 0xFF or not. ptr1 is now pointing to   */
        {                                               /* Num1. If condition is true then Num2 decrementing once and Num1 seting    */
        --*ptr2;                                        /* again to 9                                                                */
        *ptr1 = 9;
            if(*ptr2==0xFF)
               {
                 --*ptr3;
                 *ptr2=9;
                        if(*ptr3==0xFF)
                        {
                        --*ptr4;
                        *ptr3=9;
                               if(*ptr4==0xFF)
                               {
                               *ptr4=9;
                               }

                        }

                }

        }

}
