/* ###################################################################
**     Filename    : mqx_tasks.c
**     Project     : RGB_LIGHT
**     Processor   : MKE06Z128VLD4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-08-22, 22:35, # CodeGen: 2
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         task_hb - void task_hb(uint32_t task_init_data);
**
** ###################################################################*/
/*!
** @file mqx_tasks.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup mqx_tasks_module mqx_tasks module documentation
**  @{
*/         
/* MODULE mqx_tasks */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"
#include "Init_Config.h"
#include "PDD_Includes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "dev/print.h"
#include "tasks/cmd.h"
#include "tasks/spi_output.h"
#include "dev/print.h"
#include "tasks/led_run.h"
#include "uart.h"
/*
** ===================================================================
**     Event       :  task_hb (module mqx_tasks)
**
**     Component   :  Task1 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/

void task_hb(uint32_t task_init_data)
{

	int counter = 0;
	word i = 0;
	MY_DEBUGF(((uint8_t *)&"hello, PI!\r\n"));
	//void push_led_data(PI);
	while(1) {
    counter++;
    vTaskCmdAnalyze();
  }
}

/*
** ===================================================================
**     Event       :  task_spi (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
extern RGBBOARD_FRAME_T PI;
extern uint8_t RGB_Buf[BufLength];
void task_spi(uint32_t task_init_data)
{
  memset(RGB_Buf, CodeZero, BufLength);
  SM1_SendBlock(SM1_DeviceData, RGB_Buf, BufLength);

#ifdef TEST_SCREEN

  led_test();

#else

  char_in(PI);
  _time_delay_ticks(20 * PI.delay);
  char_out(PI);

  led_run();

#endif
}


/*
** ===================================================================
**     Event       :  com_task (module mqx_tasks)
**
**     Component   :  Task3 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void com_task(uint32_t task_init_data)
{
	//uart_run();
	for(;;)
	{
		_time_delay_ticks(1000);
	}
}

/* END mqx_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
