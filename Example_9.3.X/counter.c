/*
 * File name            : counter.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.3 Interruption counter
 *                      : Created on January 30, 2014, 12:47 PM
 *                      : Counter function definitions source file
 */

/* __________________________Sequential counter function ____________________________________*/

void Seq_count(unsigned char*ptr1, unsigned char*ptr2, unsigned char*ptr3, unsigned char*ptr4)
{
 ++*ptr1;                                              /* Increments the value in the variable where ptr1 is pointing to            */
    if(*ptr1==10)                                      /* Testing the value in variable is 10 or not where ptr1 is pointing now     */
        {
        ++*ptr2;                                       /* Increments the value in the variable where ptr2 is pointing now           */
        *ptr1 = 0;                                     /* Resets the variable where ptr1 is pointing now                            */
            if(*ptr2 == 10)
               {
                 ++*ptr3;
                 *ptr2=0;
                        if(*ptr3 == 10)
                        {
                        ++*ptr4;
                        *ptr3=0;
                               if(*ptr4==10)
                               {
                               *ptr4=0;                /* Resets the variable where ptr4 is pointing now                            */
                               }

                        }

                }

        }

}
