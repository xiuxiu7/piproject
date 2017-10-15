/* ###################################################################
**     Filename    : mqx_tasks.h
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
** @file mqx_tasks.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup mqx_tasks_module mqx_tasks module documentation
**  @{
*/         

#ifndef __mqx_tasks_H
#define __mqx_tasks_H
/* MODULE mqx_tasks */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MQX1.h"
#include "SystemTimer1.h"
#include "LED.h"
#include "BitIoLdd1.h"
#include "UART_DEBUG.h"
#include "ASerialLdd1.h"
#include "BLUE.h"
#include "ASerialLdd2.h"
#include "CRC1.h"
#include "SM1.h"
#include "blue_delay.h"
#include "BitIoLdd2.h"
#include "blue_pwrc.h"
#include "BitIoLdd3.h"
#include "blue_at.h"
#include "BitIoLdd4.h"
#include "flash.h"
#include "IntFlashLdd1.h"
#include "led_output.h"
#include "BitIoLdd5.h"

#ifdef __cplusplus
extern "C" {
#endif 

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
void task_hb(uint32_t task_init_data);


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
void task_spi(uint32_t task_init_data);

/*
** ===================================================================
**     Event       :  task_flash (module mqx_tasks)
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
void task_flash(uint32_t task_init_data);

/*
** ===================================================================
**     Event       :  task_move (module mqx_tasks)
**
**     Component   :  Task4 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void task_move(uint32_t task_init_data);

/*
** ===================================================================
**     Event       :  task_com (module mqx_tasks)
**
**     Component   :  Task5 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void task_com(uint32_t task_init_data);

/*
** ===================================================================
**     Event       :  task_cmd (module mqx_tasks)
**
**     Component   :  Task6 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void task_cmd(uint32_t task_init_data);

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
void com_task(uint32_t task_init_data);

/* END mqx_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __mqx_tasks_H*/
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
