/*
 * File name            : segment.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.3 Interruption counter
 *                      : Created on January 30, 2014, 03:50 PM
 *                      : Seven segment display function definitions source file
 */

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif


/*_______________________________Code for displying a digit with Decimal point____________________________________*/

#define OUTPUT0_DOT  PORTD = ((0b00111111) | (0b10000000))
#define OUTPUT1_DOT  PORTD = ((0b00000110) | (0b10000000))
#define OUTPUT2_DOT  PORTD = ((0b01011011) | (0b10000000))
#define OUTPUT3_DOT  PORTD = ((0b01001111) | (0b10000000))
#define OUTPUT4_DOT  PORTD = ((0b01100110) | (0b10000000))
#define OUTPUT5_DOT  PORTD = ((0b01101101) | (0b10000000))
#define OUTPUT6_DOT  PORTD = ((0b01111101) | (0b10000000))
#define OUTPUT7_DOT  PORTD = ((0b00000111) | (0b10000000))
#define OUTPUT8_DOT  PORTD = ((0b01111111) | (0b10000000))
#define OUTPUT9_DOT  PORTD = ((0b01101111) | (0b10000000))

/*_____________________________Code for displying a digit without Decimal point___________________________________*/

#define OUTPUT0  PORTD = 0b00111111
#define OUTPUT1  PORTD = 0b00000110
#define OUTPUT2  PORTD = 0b01011011
#define OUTPUT3  PORTD = 0b01001111
#define OUTPUT4  PORTD = 0b01100110
#define OUTPUT5  PORTD = 0b01101101
#define OUTPUT6  PORTD = 0b01111101
#define OUTPUT7  PORTD = 0b00000111
#define OUTPUT8  PORTD = 0b01111111
#define OUTPUT9  PORTD = 0b01101111

/*___________________________________ Module activation bits____________________________________________________ */

#define Segment_1 PORTAbits.RA0
#define Segment_2 PORTAbits.RA1
#define Segment_3 PORTAbits.RA2
#define Segment_4 PORTAbits.RA3
/* Segment direction bits*/
#define Segment_1_dir TRISAbits.TRISA0
#define Segment_2_dir TRISAbits.TRISA1
#define Segment_3_dir TRISAbits.TRISA2
#define Segment_4_dir TRISAbits.TRISA3

unsigned char dot = 0;

/*____________________________Seven segment display activating function_____________________________________________*/

void Segment_init(unsigned char Segment)
    {

    /*  Direction settings  */

    TRISD = 0x00;
    Segment_1_dir = 0;                                          /* Direction of segment 1 set as output                   */
    Segment_2_dir = 0;                                          /* Direction of segment 2 set as output                   */
    Segment_3_dir = 0;                                          /* Direction of segment 3 set as output                   */
    Segment_4_dir = 0;                                          /* Direction of segment 4 set as output                   */
    
    /*  7 segment Display module selection   */
     if(Segment == 1)
        Segment_1 = 1;                                          /* Segment 1 is activated                                 */
     else if(Segment == 2)
        Segment_2 = 1;                                          /* Segment 2 is activated                                 */
     else if(Segment== 3)
        Segment_3 = 1;                                          /* Segment 3 is activated                                 */
     else
        Segment_4 = 1;                                          /* Segment 4 is activated                                 */
    }

void DisplayValue(char Number)
{
    if(dot==1)
    {
    switch (Number)
    {
 case 0 :
                OUTPUT0_DOT;                                   /* Data out to data port of Seven Segment display with DP enabled */
                break;
 case 1  :
                OUTPUT1_DOT;
                break;
 case 2  :
                OUTPUT2_DOT;
                break;
 case 3  :
                OUTPUT3_DOT;
                break;
 case 4  :
                OUTPUT4_DOT;
                break;
 case 5  :
                OUTPUT5_DOT;
                break;
 case 6  :
                OUTPUT6_DOT;
                break;
 case 7  :
                OUTPUT7_DOT;
                break;
 case 8  :
                OUTPUT8_DOT;
                break;
 case 9  :
                OUTPUT9_DOT;
                break;
    }

    dot=0;
    }
    else
    {

switch (Number)
    {
 case 0 :
                OUTPUT0;                                        /* Data out to data port of Seven Segment display         */
                break;
 case 1  :
                OUTPUT1;
                break;
 case 2  :
                OUTPUT2;
                break;
 case 3  :
                OUTPUT3;
                break;
 case 4  :
                OUTPUT4;
                break;
 case 5  :
                OUTPUT5;
                break;
 case 6  :
                OUTPUT6;
                break;
 case 7  :
                OUTPUT7;
                break;
 case 8  :
                OUTPUT8;
                break;
 case 9  :
                OUTPUT9;
                break;
    }
  }
}

/* _______________________________Number displaying function________________________________________________________*/

void NumDisplay(char Number, unsigned char Segment )
{
 Segment_init(Segment);                                         /* Invoking function to segment initialization            */
 dot = 0;                                                       /* Display OFF DP (Decimal point)                         */
 DisplayValue(Number);                                          /* */
 }