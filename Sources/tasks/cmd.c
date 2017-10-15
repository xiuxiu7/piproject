/*
 * cmd.c
 *
 *  Created on: 2017年8月22日
 *      Author: xiuwe
 */

#include "cmd.h"
#include "../dev/print.h"
#include "uart.h"

cmd_analyze_struct cmd_analyze;
LWSEM_STRUCT semaphore_uart;

void printf_cmd(int32_t argc, void *cmd_arg);

/*提供给串口中断服务程序，保存串口接收到的单个字符*/
void fill_rec_buf(char data)
{
    //接收数据
    static uint32_t rec_count=0;
    cmd_analyze.rec_buf[rec_count]=data;

    if(0x0A==cmd_analyze.rec_buf[rec_count] && 0x0D==cmd_analyze.rec_buf[rec_count-1])
    {
       rec_count=0;
       _lwsem_post(&semaphore_uart);
    }
    else if('d'==cmd_analyze.rec_buf[rec_count] && 'n'==cmd_analyze.rec_buf[rec_count-1] && 'e'==cmd_analyze.rec_buf[rec_count-2])
    {
    	cmd_analyze.rec_buf[rec_count - 0] = '\0';
		cmd_analyze.rec_buf[rec_count - 1] = 0x0A;
		cmd_analyze.rec_buf[rec_count - 2] = 0x0D;
		_lwsem_post(&semaphore_uart);
    	rec_count=0;
    }else
    {
       rec_count++;

       if(rec_count>=CMD_BUF_LEN)
       {
           rec_count=0;
       }
    }
}

static int32_t string_to_dec(uint8_t *buf, uint32_t len)
{
   uint32_t i=0;
   uint32_t base=10;       //基数
   int32_t  neg=1;         //表示正负,1=正数
   int32_t  result=0;

    if((buf[0]=='0')&&(buf[1]=='x'))
    {
       base=16;
       neg=1;
       i=2;
    }
    else if(buf[0]=='-')
    {
       base=10;
       neg=-1;
       i=1;
    }
    for(;i<len;i++)
    {
       if(buf[i]==0x20 || buf[i]==0x0D)    //为空格
       {
           break;
       }

       result *= base;
       if(isdigit(buf[i]))                 //是否为0~9
       {
           result += buf[i]-'0';
       }
       else if(isxdigit(buf[i]))           //是否为a~f或者A~F
       {
            result+=tolower(buf[i])-87;
       }
       else
       {
           result += buf[i]-'0';
       }
    }
   result *= neg;

    return result ;
}

static uint32_t get_true_char_stream(char *dest, const char *src)
{
   uint32_t dest_count=0;
   uint32_t src_count=0;

    while(src[src_count]!=0x0D && src[src_count+1]!=0x0A)
    {
       if(isprint(src[src_count]))
       {
           dest[dest_count++]=src[src_count++];
       }
       else
       {
           switch(src[src_count])
           {
                case    0x08:                          //退格键键值
                {
                    if(dest_count>0)
                    {
                        dest_count --;
                    }
                    src_count ++;
                }break;
                case    0x1B:
                {
                    if(src[src_count+1]==0x5B)
                    {
                        if(src[src_count+2]==0x41 || src[src_count+2]==0x42)
                        {
                            src_count +=3;              //上移和下移键键值
                        }
                        else if(src[src_count+2]==0x43)
                        {
                            dest_count++;               //右移键键值
                            src_count+=3;
                        }
                        else if(src[src_count+2]==0x44)
                        {
                            if(dest_count >0)           //左移键键值
                            {
                                dest_count --;
                            }
                           src_count +=3;
                        }
                        else
                        {
                            src_count +=3;
                        }
                    }
                    else
                    {
                        src_count ++;
                    }
                }break;
                default:
                {
                    src_count++;
                }break;
           }
       }
    }
    dest[dest_count++]=src[src_count++];
    dest[dest_count++]=src[src_count++];
    return dest_count;
}

static int32_t cmd_arg_analyze(char *rec_buf, unsigned int len)
{
	uint32_t i;
	uint32_t blank_space_flag=0;    //空格标志
	uint32_t arg_num=0;             //参数数目
	uint32_t index[ARG_NUM];        //有效参数首个数字的数组索引

    /*先做一遍分析,找出参数的数目,以及参数段的首个数字所在rec_buf数组中的下标*/
    for(i=0;i<len;i++)
    {
       if(rec_buf[i]==0x20)        //为空格
       {
           blank_space_flag=1;
           continue;
       }
        else if(rec_buf[i]==0x0D)   //换行
       {
           break;
       }
       else
       {
           if(blank_space_flag==1)
           {
                blank_space_flag=0;
                if(arg_num < ARG_NUM)
                {
                   index[arg_num]=i;
                    arg_num++;
                }
                else
                {
                    return -1;      //参数个数太多
                }
           }
       }
    }

    for(i=0;i<arg_num;i++)
    {
        cmd_analyze.cmd_arg[i]=string_to_dec((unsigned char *)(rec_buf+index[i]),len-index[i]);
    }
    return arg_num;
}

void printf_hello(int32_t argc, void *cmd_arg)
{
   MY_DEBUGF(("Hello world!\n"));
}

void SystemReset()
{
	Cpu_SystemReset();
}

extern bool flash_in_operation;

void rgb_e(int32_t argc, void *cmd_arg)
{
	uint32_t i = 0;
	uint8_t status = 0;
//	//MY_DEBUGF(((uint8_t *)&"flash Erasing\r\n"));
//	flash_in_operation = TRUE;
//	//flash_SetByteFlash();
//	//status = FLASH_Erase(FLASH_DeviceData, FLASH_USER_AREA0_flash1_ADDRESS, 300);
//	while((flash_in_operation == TRUE) && (i < 1000))
//	{
//		_time_delay_ticks(5);
//		i++;
//	}
	MY_DEBUGF(((uint8_t *)&"Erase status: %d\r\n", status));
}

extern RGBBOARD_FRAME_T PI;
void rgb_w(int32_t argc, void *cmd_arg)
{
	byte status;
	MY_DEBUGF(((uint8_t *)&"start write flash\r\n"));
	status = flash_SetBlockFlash((flash_TDataAddress)(&PI), 0x200, sizeof(RGBBOARD_FRAME_T));
	MY_DEBUGF(((uint8_t *)&"write flash : %d\r\n", status));
	printArray((flash_TDataAddress)(&PI), sizeof(RGBBOARD_FRAME_T));
}

void rgb_r(int32_t argc, void *cmd_arg)
{
	byte status;
	RGBBOARD_FRAME_T data;
	status = flash_GetBlockFlash(0x200, (flash_TDataAddress)(&data), sizeof(RGBBOARD_FRAME_T));
	MY_DEBUGF(((uint8_t *)&"read flash: %d\r\n", status));
	printArray((flash_TDataAddress)(&data), sizeof(RGBBOARD_FRAME_T));
}

extern RGBBOARD_FRAME_T PI;
void rgb_s(int32_t argc, void *cmd_arg)
{
	int32_t  *arg=(int32_t *)cmd_arg;
	if(argc == 3)
	{
		PI.rt_RGB.R = arg[0];
		PI.rt_RGB.G = arg[1];
		PI.rt_RGB.B = arg[2];
	}
	MY_DEBUGF(((uint8_t *)&"R: %d G: %d B: %d: %d\r\n", PI.rt_RGB.R, PI.rt_RGB.G, PI.rt_RGB.B));
}

uint_8 at_cmd_putvalue = 0;
void AT_CMD(int32_t argc, void *cmd_arg)
{
	at_cmd_putvalue = 1-at_cmd_putvalue;
	blue_at_PutVal(at_cmd_putvalue);
	MY_DEBUGF(((uint8_t *)&"at_cmd_putvalue: %d \r\n", at_cmd_putvalue));
}



const cmd_list_struct cmd_list[]={
/*命令    		参数数目   	 处理函数       			 帮助信息   		*/
{"cmd",   	0,      (void *)printf_cmd,   		"print cmds"},
{" ",		0,		(void *)printf_cmd,			"print cmds"},
{"reset",	0,      (void *)SystemReset,		"reset"},
{"flash-w",	1,		(void *)rgb_w,				"rgb"},
{"flash-r",	1,		(void *)rgb_r,				"rgb"},
{"flash-e",	0,		(void *)rgb_e,				"rgb"},
{"rgb-s",	3,		(void *)rgb_s,				"r,g,b"},
{"at-cmd", 	0,		(void *)AT_CMD,				"set value of at cmd port"},
{"start",	26,		(void *)blu_decode,			"decode"}
};

void printf_cmd(int32_t argc, void *cmd_arg)
{
	(void)argc;
	(void)cmd_arg;
	uint16_t cmd_len;
	uint16_t i = 0;
	cmd_len = sizeof(cmd_list)/sizeof(cmd_list[0]);
	for(i = 0; i < cmd_len; i++)
	{
		UARTprintf((uint8_t *)&"args: %d  cmd: %s      info: %s\r\n",
					cmd_list[i].max_args,
					cmd_list[i].cmd_name,
					cmd_list[i].help
					);
	}
}

void vTaskCmdAnalyze(void)
{
	uint32_t i;
   	int32_t rec_arg_num;
    char cmd_buf[CMD_LEN];
    _lwsem_create(&semaphore_uart, 0);
    while(1)
    {
       uint32_t rec_num;
       _lwsem_wait(&semaphore_uart);
       rec_num=get_true_char_stream(cmd_analyze.processed_buf, cmd_analyze.rec_buf);
       //printArray(cmd_analyze.processed_buf, rec_num);
       /*从接收数据中提取命令*/
       for(i=0;i<CMD_LEN;i++)
       {
           if((i>0)&&((cmd_analyze.processed_buf[i]==' ')||(cmd_analyze.processed_buf[i]==0x0D)))
           {
                cmd_buf[i]='\0';        //字符串结束符
                break;
           }
           else
           {
                cmd_buf[i]=cmd_analyze.processed_buf[i];
           }
       }

       rec_arg_num=cmd_arg_analyze(&cmd_analyze.processed_buf[i],rec_num);

       for(i=0;i<sizeof(cmd_list)/sizeof(cmd_list[0]);i++)
       {
           if(!strcmp(cmd_buf,cmd_list[i].cmd_name))       //字符串相等
           {
                if(rec_arg_num<0 || rec_arg_num>cmd_list[i].max_args)
                {
                    MY_DEBUGF(("too many args!\n"));
                }
                else
                {
                    cmd_list[i].handle(rec_arg_num, (void *)cmd_analyze.cmd_arg);
                }
                break;
           }

       }
       if(i>=sizeof(cmd_list)/sizeof(cmd_list[0]))
       {
           MY_DEBUGF(("not support cmd!\n"));
       }
    }
}




