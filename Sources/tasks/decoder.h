/*
 * decoder.h
 *
 *  Created on: 2017Äê10ÔÂ12ÈÕ
 *      Author: xiuwe
 */

#ifndef SOURCES_TASKS_DECODER_H_
#define SOURCES_TASKS_DECODER_H_

#include "BLUE.h"
#include "RGB.h"
#include "mqx_tasks.h"
#include "print.h"
#include "string.h"

void light_luminance_updata(RGBBOARD_FRAME_T *frame);
void light_power_update(RGBBOARD_FRAME_T *frame);
void data_decode(uint8_t *data);



#endif /* SOURCES_TASKS_DECODER_H_ */
