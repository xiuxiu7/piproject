/*
 * decoder.c
 *
 *  Created on: 2017Äê10ÔÂ12ÈÕ
 *      Author: xiuwe
 */

#include "decoder.h"
#include "RGB.h"

uint8_t blue_raw_data[BLUE_INP_BUF_SIZE];
extern RGBBOARD_FRAME_T display_data[char_len_max];
extern LWSEM_STRUCT semaphore_blue;

uint8_t luminance_level[] =
{
		200,
		180,
		160,
		140,
		120,
		100,
		80,
		60,
		40,
		30
};

/************************************************/

void light_luminance_updata(RGBBOARD_FRAME_T *frame)
{
	float sum;
	sum = frame->RGB.R + frame->RGB.G + frame->RGB.B;
	MY_DEBUGF(("frame luminance set is: ", sum));
	if(frame->luminance >= sizeof(luminance_level))
	{
		frame->luminance = 7;
		MY_DEBUGF(("frame->luminance set error reset to 8\r\n"));
	}
	if(sum < luminance_level[frame->luminance])
	{
		return;
	}else{
		frame->RGB.R = (uint8_t)((float)frame->RGB.R * sum / luminance_level[frame->luminance]);
		frame->RGB.G = (uint8_t)((float)frame->RGB.G * sum / luminance_level[frame->luminance]);
		frame->RGB.B = (uint8_t)((float)frame->RGB.B * sum / luminance_level[frame->luminance]);
		MY_DEBUGF(("update to level: %d, %d", frame->luminance, (frame->RGB.R + frame->RGB.R + frame->RGB.R)));
	}
	MY_DEBUGF(("\r\n"));
}

/************************************************/

void light_power_update(RGBBOARD_FRAME_T *frame)
{
	uint8_t i = 0;
	uint8_t j = 0;
	float sum = 0;
	float power = 0;
	uint8_t mdata = 0;
	sum = 0;
	for(i = 0; i < 18; i++)
	{
		mdata = frame->data[i];
		for(j = 0; j < 8; j++)
		{
			sum+=mdata & (1<<j);
		}
	}
	power = sum * ( frame->RGB.R + frame->RGB.G + frame->RGB.B);
	MY_DEBUGF(((uint8_t *)&"Power set is: %d ", (uint32_t)power));
	if(power < power_max)
	{
		return;
	}else{
		frame->RGB.R = (uint8_t)((float)(frame->RGB.R)/power*power_max);
		frame->RGB.G = (uint8_t)((float)(frame->RGB.G)/power*power_max);
		frame->RGB.B = (uint8_t)((float)(frame->RGB.B)/power*power_max);
		power = sum * ( frame->RGB.R + frame->RGB.G + frame->RGB.B);
		MY_DEBUGF(((uint8_t *)&"update to: %d ", (uint32_t)power));
	}
	MY_DEBUGF(((uint8_t *)&"\r\n"));
}

/************************************************/

void data_decode(uint8_t *data)
{
	uint8_t i = 0;
	uint8_t char_index;
	uint8_t status;
	//RCR
//	if((data[0] > char_len_max) || (data[1] > char_len_max))
//	{
//		MY_DEBUGF(((uint8_t *)&"out of range of char"));
//		return;
//	}
	//printArray(data, 26);
	char_index = *(data + 1);
	if(*data > char_len_max)
		*data = 1;
	display_data[char_index].len = *data;
	display_data[char_index].smode = *(data + 2);
	display_data[char_index].delay = *(data + 3);
	if(*(data + 4) < 9)
	{
		display_data[char_index].luminance = *(data + 4);
	}
	display_data[char_index].RGB.R = *(data + 5);
	display_data[char_index].RGB.G = *(data + 6);
	display_data[char_index].RGB.B = *(data + 7);
	for(i = 0; i < 18; i++)
	{
		display_data[char_index].data[i] = *(data + 8 + i);
	}
	status = flash_SetBlockFlash((flash_TDataAddress)(&display_data[char_index]), FLASH_BASE + char_index * sizeof(RGBBOARD_FRAME_T), sizeof(RGBBOARD_FRAME_T));
	MY_DEBUGF(((uint8_t *)&"write at %x, len: %d flash status : %d\r\n", FLASH_BASE + char_index * sizeof(RGBBOARD_FRAME_T), sizeof(RGBBOARD_FRAME_T), status));
	printArray(FLASH_BASE + char_index * sizeof(RGBBOARD_FRAME_T), sizeof(RGBBOARD_FRAME_T));
}

/************************************************/


