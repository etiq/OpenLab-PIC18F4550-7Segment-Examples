/*
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.1 Seven segment disply
 *                      : Created on November 2, 2013, 2:30 PM
 *                      : Displaying digits in seven segment display and counting sequentially.
 */

/*
 * Microcontroller executes to count the decimal digit starts from 0 to 9 in a segment. After completing
 * one cycle in a segment it shifts into next segment and repeats the count. After finishing display in
 * 4 segments, again repeats counting from first segment.
 
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
#include "segment.h"
#endif

int main()

{
    unsigned char a = 0b00000001;
    TRISD = 0x00;
    TRISA  = 0x00;

    while(1)
    {


        0b00000001;
        LATA = 0x01;
        while(a!=0x00)
        {
        Delay_s(1);
        LATD = a<<1;
        a = a<<1;
        }
        
        LATA = 0x02;
        a = 0b00000001;
        while(a!=0x00)
        {
        Delay_s(1);
        LATD = a<<1;
        a = a<<1;
        }


        LATA = 0x04;
        a = 0b00000001;
        while(a!=0x00)
        {
        Delay_s(1);
        LATD = a<<1;
        a = a<<1;
        }


        LATA = 0x08;
        a = 0b00000001;
        while(a!=0x00)
        {
        Delay_s(1);
        LATD = a<<1;
        a = a<<1;
        }

    }






//  while(1)
//    {
//    char Number = 0;                                                   /* Setting initial counting digit to 0                       */
//    unsigned char Segment = 1;                                         /* Selecting first segment                                   */
//    do{
//        do
//        {
//        NumDisplay(Number, Segment);                                   /* Invoking function to disply a digit in desired segment    */
//        Delay_s(2);                                                    /* 2seconds Delay                                            */
//        Number++;                                                      /* Incrementing digit to count once                          */
//        }while(Number <= 9);                                           /* checking whether counting sequence reached greater than 9 */
//        Segment++;                                                     /* Incrementing the segment to the next left                 */
//        Number = 0;                                                    /* Reseting the counting sequence                            */
//      }while(Segment <= 4);                                            /* Checking whether the value in Segment is reached 4 or not */
//    }                                                                  /* If reached 4 then resetting Number and selecting          */
    return (0);
}