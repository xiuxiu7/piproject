/*
 * spi_output.h
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: xiuwe
 */

#ifndef SOURCES_TASKS_SPI_OUTPUT_H_
#define SOURCES_TASKS_SPI_OUTPUT_H_

#include "SM1.h"
#include "../RGB.h"

void push_led_data(RGBBOARD_FRAME_T frame);
void char_in(RGBBOARD_FRAME_T frame);
void char_out(RGBBOARD_FRAME_T frame);
void led_test(void);

#endif /* SOURCES_TASKS_SPI_OUTPUT_H_ */
