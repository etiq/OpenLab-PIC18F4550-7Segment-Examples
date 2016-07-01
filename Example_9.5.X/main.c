/*
 * File name            : main.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.5 Timer
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : Timed external power control with preset option.
 */

/*__________________________________TIMER EXAMPLE__________________________________________________________*/

/*
 * The TIMER designed for 1hr time running with option to set the Time IN and Time OUT for controlling
 * an external power device. Counting starts from the pre-set value 0000. Before counting starts, user
 * has an option to set the Power Time IN and Power Time OUT values. When the running time reaches, the
 * Time IN value then Power ON the external device. similarly when running time reaches, the Time OUT
 * preset value, then Power OFF the device.
 *
 * Connections
 * -----------
 * Control port             -   PORTA
 * Data port                -   PORTD
 * Status LED               -   RB1
 * Power device connection  -   Relay Terminals (J1- 1,2)
*/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
    #include <plib\usart.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <usart.h>
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
#include "timer.h"
#include "uart.h"
#endif

#define Fosc 20000000                                                 /* External crystal frequency                              */
#define baud 9600                                                     /* UART baud rate                                          */
#define config2 ((Fosc/baud/64)-1)                                    /* */

unsigned char array[8];
unsigned char Num1=0, Num2=0, Num3=0, Num4=0;                         /* Setting initial counting digit of all segments to 0       */
unsigned char str1[39] = "Enter Power Time IN MMSS format", str2[38] = "Enter Power Time OUT MMSS format";
unsigned char str[10];
unsigned char config1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;




/**/

#pragma interrupt_level 0 @0x0018
void interrupt Rx_isr()                                          /* Interrupt service routine for USART receive interrupt  */
{
    if(PIR1bits.RCIF == 1)
    {
        Read_BUF();
        Reset_TIME();
        Switch_Relay(0);
        Set_TIME(str);
        PIR1bits.RCIF = 0;                                        /* clearing USART receive flag                            */
    }
}

/*______________________________________________________Main function_______________________________________________*/

void main(void)
{
     TRISBbits.TRISB0=0;                                          /* Direction of RB0 as output                              */
     TRISBbits.TRISB1=0;                                          /* Direction of RB1 as output                              */
     UsartConfig(config1, config2);                               /* UART configuration function call                        */
     Switch_Relay(0);                                             /* Function call to switch OFF the relay                   */
     Set_TIME(str);                                               /* Time IN and Time OUT settings                           */
     Config_Interrupt();                                          /* UART receive interrupt Configuration function call      */
 while(1)
    {  
    Display();                                                   /* 7 segment display function call                          */
    Seq_count(&Num1, &Num2, &Num3, &Num4);                       /* Function call for sequential count                       */
    if(LATB0==1)                                                 /* Testing whether bit RB0 is set or not                    */
    Blink();                                                     /* Status LED blink function call                           */
    }
}