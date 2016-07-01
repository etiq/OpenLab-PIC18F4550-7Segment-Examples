
/*
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.2 Digital counter_1
 *                      : Created on November 2, 2013, 2:30 PM
 *                      : Displaying 4 digit counting sequence in seven segment display.
 */


/*__________________________________DIGITAL COUNTER EXAMPLE__________________________________________*/

/*
 * The counter designed for 4 digits counting. Counting starts from the pre-set value 0000. At any
 * stage, a digit in a specific segment counts up once, when its right digit counts 10 times. Counter
 * will reset when it reaches its maximum value 9999. The status of each segment is displayed with time
 * duration of the order of milli seconds. Control port and Data port are PORTA and PORTD respectively.
 *
 * Connections
 * -----------
 * Control port             -   PORTA
 * Data port                -   PORTD
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

unsigned char Num1=0, Num2=0, Num3=0, Num4=0;                   /* Setting initial counting digit of all segments to 0       */

void main(void)
{
 while(1)
 {  
    int x = 0;
    while(x<=10)
    {
    NumDisplay(Num1, 1);                                        /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(Num2, 2);                                        /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(Num3, 3);                                        /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(Num4, 4);                                        /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    x++;
    }
   Seq_count(&Num1, &Num2, &Num3, &Num4);                       /* Function call for sequential count                        */
 }

}
 