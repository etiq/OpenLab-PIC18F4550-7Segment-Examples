#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#include "segment.h"
#include "delay.h"
#include "uart.h"

#define OUT LATBbits.LATB0
extern unsigned char Num1, Num2, Num3, Num4, array[], str1[], str2[], str[];

/* ____________________________________UART buffer register clearing function___________________________________________*/

void Read_BUF(void)
    {
    unsigned char c;
    c = RCREG;                                                  /* Reading UART buffer register                               */
    c = RCREG;
    }

void Format_DEC(unsigned char *p, unsigned char *q)
    {
    *q = (*p-'0');                                              /* Converting a character to decimal and storing into an array  */
    p++;                                                        /* Incrementing the address of the pointer                      */
    q++;
    *q = (*p-'0');
    p++;
    q++;
    *q = (*p-'0');
    p++;
    q++;
    *q = (*p-'0');
    }
void Switch_Relay(unsigned char sw)
    {                                                 
    switch(sw)
        {
        case 1   :  OUT = 1;                                   /* Switch ON relay  RB0 = 1                                      */
                    break;
        case 0   :  OUT = 0;                                   /* Switch OFF relay RB0 = 0                                      */
                    LATBbits.LATB1 = 0;
                    break;
        }
    }
void Display(void)
    {
    unsigned char *ptr = array;
    if((Num4==*ptr)&&(Num3== *(ptr+1))&&(Num2==*(ptr+2))&&(Num1==*(ptr+3)))
        {
        Switch_Relay(1);
        }
    else if((Num4==*(ptr+4))&&(Num3==*(ptr+5))&&(Num2==*(ptr+6))&&(Num1==*(ptr+7)))
        {
        Switch_Relay(0);
        }
    int x = 0;
    while(x<63)
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
void Reset_TIME(void)
    {
    Num1=0;Num2=0; Num3=0; Num4=0;                              /* Time rest                                                */
    Display();                                                  /* Time display function call                               */
    }
void Set_TIME(unsigned char *str)
    {
    Write_string(str1);                                         /* Writing a string to serial port                          */
    Read_BUF();                                                 /* UART Buffer register clearing function call              */
    Read_string(str, 4);                                        /* Read an Input string of length 4 from serial port        */
    Read_BUF();                                                 /* UART Buffer register clearing function call              */
    Format_DEC(str, array);                                     /* Charcter to decimal number conversion                    */
    Write_string(str2);                                         /* Writing a string to serial port                          */
    Read_BUF();                                                 /* UART Buffer register clearing function call              */
    Read_string(str, 4);                                        /* Read an Input string of length 4 from serial port        */
    Read_BUF();                                                 /* UART Buffer register clearing function call              */
    Format_DEC(str, array+4);                                   /* Charcter to decimal number conversion                    */
    }
void Config_Interrupt(void)
    {
    RCIF = 0;                                                   /* Reset UART Receive Interrupt Flag                    */
    RCIP = 0;                                                   /* Low priority for EUSART Receive Interrupt            */
    RCIE = 1;                                                   /* RX interrupt Enable                                  */
    PEIE = 1;                                                   /* Peripheral Interrupt Enable                          */
    ei();                                                       /* Global interrupt enable                              */
    }
 void Blink(void)
    {
     LATBbits.LATB1= ~LATBbits.LATB1;                           /* Logical NOT operation on bit RB1                     */
    }

