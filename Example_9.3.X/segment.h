/*
 * File name            : segment.h
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.3 Interruption counter
 *                      : Created on January 30, 2014, 10:42 AM
 *                      : Seven segments functions header file
 */

#ifndef SEGMENT_H
#define	SEGMENT_H

/* _________________________Decimal point display functions header______________________________ */

void NumDisplay(char Number, unsigned char Segment );


/*
 * Include          :       segment.h
 * Description      :       Test for segment number and sets or resets a flag for decimal point(DP) display
 * Arguments        :       Decimal numbers
 * Returns          :       None
 */

/* ______________________Segment initialization functions header______________________________ */

void Segment_init(unsigned char Segment);

/*
 * Include          :       segment.c
 * Description      :       Activates a specific seven segment
 * Arguments        :       Decimal number
 * Returns          :       None
 */

/* _____________________________Number display function headet__________________________________*/

void DisplayValue(char Number);

/*
 * Include          :       segment.h
 * Description      :       Generates binary code for each input argument to be displayed
 * Arguments        :       Decimal numbers
 * Returns          :       None
 */

#endif	/* SEGMENT_H */