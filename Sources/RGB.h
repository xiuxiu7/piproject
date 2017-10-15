/*
 * RGB.h
 *
 *  Created on: 2017Äê8ÔÂ22ÈÕ
 *      Author: xiuwe
 */

#ifndef SOURCES_RGB_H_
#define SOURCES_RGB_H_

#include "psptypes.h"
#define CodeOne  	0x00
#define CodeZero	0x0F

#define FLASH_BASE 	0x200

#define char_len_max	10

#define PixelNum  	12*12

#define BufLength 	PixelNum*24

#define power_max  	200000

//#define TEST_SCREEN

typedef struct
{
	uint_8 R;
	uint_8 G;
	uint_8 B;
}RGB_t;

typedef struct
{
	uint8_t len;
	uint8_t index;
	uint8_t smode;
	uint8_t delay;     //x100ms
	uint8_t luminance;
	RGB_t RGB;
	RGB_t rt_RGB;
	uint8_t data[18];
}RGBBOARD_FRAME_T;


#endif /* SOURCES_RGB_H_ */
