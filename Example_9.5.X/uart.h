/*
 * File name            : uart_1.h
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.5 Timer
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : UART functions header file
 */
#ifndef UART_H
#define	UART_H

/*___________________________________UART configuration function header___________________________________*/

void UsartConfig(unsigned char config1, unsigned char config2);
/*
 * Include          :       uart_1.h
 * Description      :       Configure UART module with desired baud rate
 * Arguments        :       Configuraion data
 * Returns          :       None
 */


/*_____________________________________UART byte write function header_____________________________________*/

void Write(char data);
/*
 * Include          :       uart_1.h
 * Description      :       Writes a byte to UART
 * Arguments        :       character
 * Returns          :       None
 */


/*_____________________________________UART string write function header___________________________________*/

void Write_string(unsigned char *c);
/*
 * Include          :       uart_1.h
 * Description      :       Writes string data to UART
 * Arguments        :       Address of a string
 * Returns          :       None
 */


/*_____________________________________UART Byte read function header_______________________________________ */

unsigned char Read_char(void);
/*
 * Include          :       uart_1.h
 * Description      :       Reads a single byte from UART
 * Arguments        :       None
 * Returns          :       Character
 */



/*__________________________________________UART string read function header________________________________*/

void Read_string(unsigned char *str, unsigned char n);
/*
 * Include          :       uart_1.h
 * Description      :       Reads string data from UART
 * Arguments        :       Address of a string, string length
 * Returns          :       None
 */

#endif	/* UART_H */

