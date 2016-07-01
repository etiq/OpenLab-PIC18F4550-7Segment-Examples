/*
 * File name            : timer.h
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.5 Timer
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : Timer functions header file
 */
#ifndef TIMER_H
#define	TIMER_H

/* _________________________UART buffer register clearing function header________________________________*/

void Read_BUF(void);

/*
 * Include          :       timer.h
 * Description      :       Clears the UART buffer register
 * Arguments        :       None
 * Returns          :       None
 */

/* ______________________Character to Decimal digit converting function header___________________________*/

void Format_DEC(unsigned char *p, unsigned char *q);

/*
 * Include          :       timer.h
 * Description      :       Converts a number in character data type into decimal format and stores into an array
 * Arguments        :       Address of a string variable and array variable
 * Returns          :       None
 */

/* ___________________________________Relay switching function header____________________________________*/

void Switch_Relay(unsigned char sw);

/*
 * Include          :       timer.h
 * Description      :       Switch ON or OFF the Relay depending on input parameter
 * Arguments        :       Decimal number
 * Returns          :       None
 */

/* ______________________________________7 segment display function header________________________________*/

void Display(void);

/*
 * Include          :       timer.h
 * Description      :       Function displays 4 digits in 4 segments continuously.
 * Arguments        :       None
 * Returns          :       None
 */

/* ______________________________________Time reset function header_______________________________________*/

void Reset_TIME(void);

/*
 * Include          :       timer.h
 * Description      :       Resets the time to 00:00 (MM:SS)
 * Arguments        :       None
 * Returns          :       None
 */

/* ______________________________________Time setting function header________________________________*/

void Set_TIME(unsigned char *str);

/*
 * Include          :       timer.h
 * Description      :       Function sets TIME-IN and TIME-OUT values
 * Arguments        :       Address of a String variable
 * Returns          :       None
 */

/* ______________________________________Interrupt configuration function header________________________________*/

void Config_Interrupt(void);

/*
 * Include          :       timer.h
 * Description      :       Configures and enables the UART receive interrupt
 * Arguments        :       None
 * Returns          :       None
 */

/* ______________________________________LED status displaying function header_________________________________*/

void Blink(void);

/*
 * Include          :       timer.h
 * Description      :       Generates a square wave out in bit RB1
 * Arguments        :       None
 * Returns          :       None
 */


#endif	/* TIMER_H */

