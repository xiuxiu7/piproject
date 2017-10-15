/*
 * cmd.h
 *
 *  Created on: 2017��8��22��
 *      Author: xiuwe
 */

#ifndef SOURCES_TASKS_CMD_H_
#define SOURCES_TASKS_CMD_H_

#include "mqx_tasks.h"
#include "task_template_list.h"

#include "ctype.h"
#include "../dev/print.h"
#include "string.h"
#include "../RGB.h"
#include "Cpu.h"
#include <stdio.h>

#define ARG_NUM     	30          	//����������Ĳ������
#define CMD_LEN     	10         		//������ռ�õ�����ַ��
#define CMD_BUF_LEN 	250         	//��������󳤶�

typedef struct {
	char const *cmd_name;                        //�����ַ�
 	int32_t max_args;                            //��������Ŀ
 	void (*handle)(int argc, void * cmd_arg);     //����ص�����
 	char  *help;                                 //������Ϣ
}cmd_list_struct;


typedef struct {
    char rec_buf[CMD_BUF_LEN];            //�����������
    char processed_buf[CMD_BUF_LEN];      //�洢�ӹ��������(ȥ������ַ�)
    int32_t cmd_arg[ARG_NUM];             //��������Ĳ���
}cmd_analyze_struct;


void vTaskCmdAnalyze();
void fill_rec_buf(char data);


#endif /* SOURCES_TASKS_CMD_H_ */
