/* ###################################################################
**     Filename    : mqx_tasks.c
**     Project     : ProcessorExpert
**     Processor   : MK21FN1M0VLQ12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-12-02, 10:59, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task1_task - void Task1_task(uint32_t task_init_data);
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
#include "CAN.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Task1_task (module mqx_tasks)
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
void Task1_task(uint32_t task_init_data)
{
	CAN_QueueInit(&CAN0_Queue);
	CAN0_Queue.Buffer = CAN0_TX;
	CAN0_Queue.Device = CAN0_DeviceData;
	CAN0_Queue.GetStats = &CAN0_GetStats;
	CAN0_Queue.SendFrame = &CAN0_SendFrame;
	CAN0_Enable(CAN0_DeviceData);
	while(1) {
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
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
