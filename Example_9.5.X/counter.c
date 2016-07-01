/*
 * File name            : counter.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.5 Timer
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : Counter function definitions source file
 */

void Seq_count(unsigned char*ptr1, unsigned char*ptr2, unsigned char*ptr3, unsigned char*ptr4)
{
 ++*ptr1;                                               /* Increments the value in the variable where ptr1 is pointing to            */
    if(*ptr1==10)                                       /* Testing the value in variable is 10 or not where ptr1 is pointing now     */
        {                                               
        ++*ptr2;                                        /* Increments the value in the variable where ptr2 is pointing now           */
        *ptr1 = 0;                                      /* Resets the variable where ptr1 is pointing now                            */
            if(*ptr2==6)                                /* Testing the value in variable is 6 or not where ptr2 is pointing now      */
               {
                 ++*ptr3;                               /* Increments the value in the variable where ptr3 is pointing now           */
                 *ptr2=0;                               /* Resets the variable where ptr2 is pointing now                            */
                        if(*ptr3==10)                   /* Testing the value in variable is 10 or not where ptr3 is pointing now     */
                        {
                        ++*ptr4;                        /* Increments the value in the variable where ptr4 is pointing now           */
                        *ptr3=0;                        /* Resets the variable where ptr3 is pointing now                            */
                               if(*ptr4==6)             /* Testing the value in variable is 6 or not where ptr4 is pointing now      */
                               {
                               *ptr4=0;                 /* Resets the variable where ptr4 is pointing now                            */
                               }

                        }

                }

        }

}
