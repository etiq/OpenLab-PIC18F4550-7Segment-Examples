/*
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.3 Interruption counter
 *                      : Created on January 30, 2014, 03:04 PM
 *                      : External interruption counter.
 */

/*__________________________________TIMER EXAMPLE__________________________________________________________*/

/*
 * The Interruption counter counts number of interruptions detected and displays the total count in 7 segment
 * display. Counting starts from the pre-set value 0000. Upto 9999 number of interruption counts are possible.
 * If the count value exceeds 9999 then counter resets to 0000.
 *
 * Connections
 * -----------
 * Control port             -   PORTA
 * Data port                -   PORTD
 * Status LED               -   RB1
*/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File 		*/
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File 	*/
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File 		*/
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition 		*/
#include <stdbool.h>       /* For true/false definition 	*/
#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "delay.h"
#include "Segment.h"
#include "counter.h"
#include "display.h"
#endif

#define Fosc 20000000                                                 /* External crystal frequency                              */
#define baud 9600                                                     /* UART baud rate                                          */
#define config2 ((Fosc/baud/64)-1)                                    /* Baud rate setting */

unsigned char Num1=0, Num2=0, Num3=0, Num4=0;                         /* Setting initial counting digit of all segments to 0       */

void Config_Interrupt(void)
    {
   INT0IE  = 1;                                                /* External interrupt enable                                */
    INT0IF  = 0;                                                /* Reset external interrupt flag bit                        */
    PEIE = 1;                                                   /* Peripheral Interrupt Enable                              */
    INTEDG0 = 1;                                                /* External interrupt on rising edge                        */
    ei();                                                       /* Global interrupt enable                                  */
    }
#pragma interrupt Ext_isr
#pragma interrupt_level 0 @0x0018
 void Ext_isr()                                           /* Interrupt service routine for external interrupt            */
    {
     if(INTCONbits.INT0IF)                                          /* Testing if external interrupt flag is set or not            */
    {
    Seq_count(&Num1, &Num2, &Num3, &Num4);                          /* Function call for sequential count                          */
        {
        LATBbits.LATB1 = ~LATBbits.LATB1;                           /* Logical NOT operation on bit RB1                            */                                                /* Delay function call                                         */
        }
    Display();                                                      /* 7 segment display function call                             */
    INTCONbits.INT0IF =0;                                           /* Reset external interrupt flag bit                           */
    }
    }

/*______________________________________________________Main function_______________________________________________*/

void main(void)
{
     TRISBbits.TRISB1=0;                                          /* Direction of RB1 as output                              */
     Config_Interrupt();                                          /* External interrupt Configuration function call          */
 while(1)
    {  
     LATBbits.LATB1 = 0;                                          /* Clearing bit RB1                                        */
     Display();                                                   /* 7 segment display function call                         */
    }
}