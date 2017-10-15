/*
 * uart.c
 *
 *  Created on: 2017Äê10ÔÂ12ÈÕ
 *      Author: xiuwe
 */

#include "uart.h"
#include "print.h"
#include "string.h"
#include "cmd.h"

extern LWSEM_STRUCT semaphore_uart;
extern cmd_analyze_struct cmd_analyze;
uint16_t char_cnt = 0;
void uart_run(void)
{
	uint8_t data[200];
	word bytesRemain = 0;
	word bytesRecieved = 0;
	cmd_analyze.processed_buf[0]='\0';
	while(1) {
		_time_delay_ticks(50U);

		bytesRemain = 0;
		bytesRemain = BLUE_GetCharsInRxBuf();
		if(bytesRemain != 0)
		{
			MY_DEBUGF((" %d bytes in blue\r\n", bytesRemain));
			BLUE_RecvBlock(data, bytesRemain, &bytesRecieved);
			UART_DEBUG_SendBlock(data, bytesRemain, &bytesRecieved);
			MY_DEBUGF(("\r\n"));
			memcpy(cmd_analyze.processed_buf + char_cnt, data, bytesRemain);
			char_cnt += bytesRemain;
		}

		bytesRemain = 0;
		bytesRemain = UART_DEBUG_GetCharsInRxBuf();
		if(bytesRemain != 0)
		{
			MY_DEBUGF((" %d bytes in debug\r\n", bytesRemain));
			UART_DEBUG_RecvBlock(data, bytesRemain, &bytesRecieved);
			UART_DEBUG_SendBlock(data, bytesRemain, &bytesRecieved);
			MY_DEBUGF(("\r\n"));
			memcpy(cmd_analyze.processed_buf + char_cnt, data, bytesRemain);
			char_cnt += bytesRemain;
		}
		//bytesRemain = sizeof(cmd_analyze.processed_buf);
		if(char_cnt != 0)
		{
			MY_DEBUGF((" %d bytes in analyze buf\r\n", char_cnt));
			UART_DEBUG_SendBlock(cmd_analyze.processed_buf, char_cnt, &bytesRecieved);
			MY_DEBUGF(("\r\n"));
			if(cmd_analyze.processed_buf[char_cnt - 1] == 'd'
					&& cmd_analyze.processed_buf[char_cnt - 2] == 'n'
					&& cmd_analyze.processed_buf[char_cnt - 3] == 'e')
			{
				cmd_analyze.processed_buf[char_cnt - 2] = 0x0A;
				cmd_analyze.processed_buf[char_cnt - 3] = 0x0D;
				char_cnt = 0;
				_lwsem_post(&semaphore_uart);
			}else if(cmd_analyze.processed_buf[char_cnt-1] == 0x0A && cmd_analyze.processed_buf[char_cnt - 2] == 0x0D)
			{
				char_cnt = 0;
				_lwsem_post(&semaphore_uart);
			}else if(char_cnt > 200)
			{
				char_cnt = 0;
			}
		}
	}
}


void blu_decode(int32_t argc, void *cmd_arg)
{
	int* arg = cmd_arg;
	uint8_t i;
	uint8_t data[26];
	for(i = 0; i < argc; i++)
	{
		data[i] = (uint8_t)arg[i];
	}
	//printArray(data, 26);
	data_decode(data);
}

