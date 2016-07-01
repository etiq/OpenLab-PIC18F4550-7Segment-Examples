/*
 * File name            : display.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.3 Interruption counter
 *                      : Created on January 30, 2014, 12:47 PM
 *                      : Display functions source file
 */
#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(__18CXX)
#include "segment.h"
#include "delay.h"
#endif

#define OUT LATBbits.LATB0
extern unsigned char Num1, Num2, Num3, Num4;

void Display(void)
    {
    int x = 0;
    while(x<10)
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
    }

