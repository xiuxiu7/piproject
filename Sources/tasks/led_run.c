/*
 * led_run.c
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: xiuwe
 */

#include "led_run.h"
#include "flash.h"
#include "print.h"
#include "RGB.h"
#include "led_output.h"

extern RGBBOARD_FRAME_T PI;

RGBBOARD_FRAME_T display_data[char_len_max];


void led_get(void)
{
	uint16_t i;
	uint32_t add_offset;
	uint8_t status;
	RGBBOARD_FRAME_T led_data;
	display_data[0] = PI;
	add_offset = 0;
	if((*(uint8_t*)FLASH_BASE) > 0 && (*(uint8_t*)FLASH_BASE) < 10)
	{
		for(i = 0; i < *(uint8_t*)FLASH_BASE; i++)
		{
			memcpy(&led_data, FLASH_BASE + add_offset, sizeof(RGBBOARD_FRAME_T));
			printArray(FLASH_BASE + add_offset, sizeof(RGBBOARD_FRAME_T));
			add_offset += sizeof(RGBBOARD_FRAME_T);
			if((led_data.len < 1) || (led_data.len > char_len_max) || (led_data.len <= led_data.index))
			{
				MY_DEBUGF(((uint8_t *)&"No data or data error!\r\n"));
				break;
			}else{
				display_data[i] = led_data;
				printArray((flash_TDataAddress)(&led_data), sizeof(RGBBOARD_FRAME_T));
			}
		}
	}

//	do
//	{
//		//status = flash_GetBlockFlash(FLASH_BASE + i * sizeof(RGBBOARD_FRAME_T), (flash_TDataAddress)(&led_data), sizeof(RGBBOARD_FRAME_T));
//		memcpy(&led_data, FLASH_BASE + i * sizeof(RGBBOARD_FRAME_T), sizeof(RGBBOARD_FRAME_T));
//		MY_DEBUGF(((uint8_t *)&"read flash: %d\r\n", status));
//		printArray(led_data, sizeof(RGBBOARD_FRAME_T));
//		if((led_data.len < 1) || (led_data.len > char_len_max) || (led_data.len <= led_data.index))
//		{
//			MY_DEBUGF(((uint8_t *)&"No data or data error!\r\n"));
//			break;
//		}else{
//			display_data[i] = led_data;
//			printArray((flash_TDataAddress)(&led_data), sizeof(RGBBOARD_FRAME_T));
//		}
//		i++;
//		if(i == char_len_max)
//		{
//			break;
//		}
//	}
//	while(led_data.len == (led_data.index + 1));
}


void led_run(void)
{
	uint8_t i = 0;
	led_get();
	while(1)
	{
		for(i = 0; i < display_data[0].len; i++)
		{
			char_in(display_data[i]);
			_time_delay_ticks(20 * display_data[i].delay);
			char_out(display_data[i]);
		}
		MY_DEBUGF(((uint8_t*)"char len = %d\r\n", display_data[0].len));
		for(i = 0; i < display_data[0].len; i++)
		{
			MY_DEBUGF(((uint8_t*)"char %d\r\n", i));
			printArray((flash_TDataAddress)(&display_data[i]), sizeof(RGBBOARD_FRAME_T));
		}
	}
}

