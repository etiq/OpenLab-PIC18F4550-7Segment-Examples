/*
 * File name            : segment.h
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.4 Down Counter
 *                      : Created on January 23, 2013, 12:47 PM
 *                      : Seven segments functions header file
 */

#ifndef SEGMENT_H
#define	SEGMENT_H

/* ___________________________Number display functions header______________________________ */

void NumDisplay(char Number, unsigned char Segment );


/*
 * Include          :       segment.h
 * Description      :       Generates code
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

#endif	/* SEGMENT_H */