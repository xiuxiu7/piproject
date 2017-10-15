/*
 * spi_output.c
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: xiuwe
 */

#include "spi_output.h"
#include "mqxlite.h"
#include "string.h"
#include "led_output.h"

uint8_t RGB_Buf[BufLength];

uint32_t RGB_Index = 0;
#define breath_delay_in	40
#define breath_delay_out 20

RGBBOARD_FRAME_T PI =
		{
		1,
		0,
		0,
		20,
		8,
		{20, 20, 20},
		{20, 20, 20},
		{0xff, 0xff, 0xff, 0xff, 0xe0, 0x1c, 0x03, 0x80, 0x77, 0x0e, 0x71, 0xc7, 0x38, 0x77, 0x07, 0xe0, 0x7c, 0x07}
		};

// 1 1 0 0 0 0 0 0 0 0 1 1
// 1 1 1 0 0 0 0 0 0 1 1 1
// 0 1 1 1 0 0 0 0 1 1 1 0
// 0 0 1 1 1 0 0 1 1 1 0 0
// 0 0 0 1 1 1 1 1 1 0 0 0
// 0 0 0 0 1 1 1 1 0 0 0 0
// 0 0 0 0 1 1 1 1 0 0 0 0
// 0 0 0 1 1 1 1 1 1 0 0 0
// 0 0 1 1 1 0 0 1 1 1 0 0
// 0 1 1 1 0 0 0 0 1 1 1 0
// 1 1 1 0 0 0 0 0 0 1 1 1
// 1 1 0 0 0 0 0 0 0 0 1 1


/*-------------------------------------------*/

void SetBit(uint8_t data)
{
	uint8_t i;
	for(i=0; i<8; i++)
	{
		if((data & 0x80)==0x80)
		{
			RGB_Buf[RGB_Index] = CodeOne;
		}
		else
		{
			RGB_Buf[RGB_Index] = CodeZero;
		}
		RGB_Index++;
		data=data<<1;
	}
}

/*-------------------------------------------*/

void AddPixel(RGB_t RGB)
{
	SetBit(RGB.G);
	SetBit(RGB.R);
	SetBit(RGB.B);
}


void push_led_data(RGBBOARD_FRAME_T frame)
{
	uint32 i,j;
	uint8_t data_index = 0;
	uint8_t datas;
	RGB_t RGB0={0,0,0};

	RGB_Index = 0;
	for(i = 0; i < 18; i++)
	{
		datas = frame.data[i];
		for(j=0; j<8; j++)
		{
			if((datas & 0x80) == 0x80)
			{
				AddPixel(frame.rt_RGB);
			}else{
				AddPixel(RGB0);
			}
			datas = datas << 1;
		}
	}
}


void char_in(RGBBOARD_FRAME_T frame)
{
	uint32_t i = 0;
	uint32_t j = 0;
	switch (frame.smode)
	{
		case 0:
			for(i = 0; i < breath_delay_in; i++)
			{
				frame.rt_RGB.R = (uint8_t)(((float)frame.RGB.R*i)/breath_delay_in);
				frame.rt_RGB.G = (uint8_t)(((float)frame.RGB.G*i)/breath_delay_in);
				frame.rt_RGB.B = (uint8_t)(((float)frame.RGB.B*i)/breath_delay_in);
				push_led_data(frame);
				SM1_SendBlock(SM1_DeviceData, RGB_Buf, BufLength);
				_time_delay_ticks(2U);
			}
			return;
		case 1:
			frame.rt_RGB.R = frame.RGB.R;
			frame.rt_RGB.G = frame.RGB.G;
			frame.rt_RGB.B = frame.RGB.B;
			push_led_data(frame);
			SM1_SendBlock(SM1_DeviceData, RGB_Buf, BufLength);
		default:
			return;
	}
}

void char_out(RGBBOARD_FRAME_T frame)
{
	uint32_t j = 0;
	uint32_t i = 0;
	switch (frame.smode)
	{
		case 0:
			for(i = 0; i < breath_delay_out; i++)
				{
					frame.rt_RGB.R = (uint8_t)(((float)frame.RGB.R*(breath_delay_out-1-i))/breath_delay_out);
					frame.rt_RGB.G = (uint8_t)(((float)frame.RGB.G*(breath_delay_out-1-i))/breath_delay_out);
					frame.rt_RGB.B = (uint8_t)(((float)frame.RGB.B*(breath_delay_out-1-i))/breath_delay_out);
					push_led_data(frame);
					SM1_SendBlock(SM1_DeviceData, RGB_Buf, BufLength);
					//spi_send(RGB_Buf);
					_time_delay_ticks(2U);
				}
			return;
		case 1:
			memset(RGB_Buf, CodeZero, BufLength);
			SM1_SendBlock(SM1_DeviceData, RGB_Buf, BufLength);
			_time_delay_ticks(2U);
		default:
			return;
	}
}

void led_test(void)
{
	uint8_t i;
	for(i = 0; i < 18; i++)
	{
	  PI.data[i] = 0xff;
	}
	while(1) {
		PI.RGB.R = 20;
		PI.RGB.G = 0;
		PI.RGB.B = 0;
		PI.delay = 0;
		char_in(PI);
		char_out(PI);
		PI.RGB.R = 0;
		PI.RGB.G = 20;
		PI.RGB.B = 0;
		char_in(PI);
		char_out(PI);
		PI.RGB.R = 0;
		PI.RGB.G = 0;
		PI.RGB.B = 255;
		char_in(PI);
		char_out(PI);
	}
}
