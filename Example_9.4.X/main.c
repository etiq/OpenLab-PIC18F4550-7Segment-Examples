/*
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.4 Down Counter
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : Displaying 4 digit down counting sequence in seven segment display.
 */

/*__________________________________DIGITAL COUNTER EXAMPLE__________________________________________*/

/*
 * The counter designed for 4 digits down counting. Counting starts from the pre-set value 9999. Digit
 * in a specific segment counts down once, when its right digit counts down 10 times. Counter will set
 * to 9999 when it reaches its minimum value 0000. The status of each segment is continuously displayed
 * with time duration of the order of milli seconds.
 *
 * Control port     -   PORTA
 * Data port        -   PORTD
*/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)
    #include <stdint.h>        /* For uint8_t definition */
    #include <stdbool.h>       /* For true/false definition */
#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "delay.h"
#include "Segment.h"
#include "counter.h"
#endif

signed char Num1=9, Num2=9, Num3=9, Num4=9;                   /* Setting initial counting digit of all segments to 0       */

/*_______________________________Main function_______________________________________________*/

void main(void)
{

 while(1)
 {  
    int x = 0;
    while(x<=10)
    {
    NumDisplay(Num1, 1);                                        /* Invoking function to disply a digit in  segment 1         */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(Num2, 2);                                        /* Invoking function to disply a digit in  segment 2         */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(Num3, 3);                                        /* Invoking function to disply a digit in  segment 3         */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(Num4, 4);                                        /* Invoking function to disply a digit in  segment 4         */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    x++;
    }
   Seq_count(&Num1, &Num2, &Num3, &Num4);                       /* Function call for sequential count                        */
 }
} 