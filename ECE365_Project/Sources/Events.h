/* ###################################################################
**     Filename    : Events.h
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
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MQX1.h"
#include "SystemTimer1.h"
#include "UART0.h"
#include "T10ms.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "CAN0.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK21FN1M0LQ12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


/*
** ===================================================================
**     Event       :  UART0_OnBlockReceived (module Events)
**
**     Component   :  UART0 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void UART0_OnBlockReceived(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  UART0_OnBlockSent (module Events)
**
**     Component   :  UART0 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void UART0_OnBlockSent(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  UART0_OnTxComplete (module Events)
**
**     Component   :  UART0 [Serial_LDD]
*/
/*!
**     @brief
**         This event indicates that the transmitter is finished
**         transmitting all data, preamble, and break characters and is
**         idle. It can be used to determine when it is safe to switch
**         a line driver (e.g. in RS-485 applications).
**         The event is available only when both <Interrupt
**         service/event> and <Transmitter> properties are enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void UART0_OnTxComplete(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  UART0_OnError (module Events)
**
**     Component   :  UART0 [Serial_LDD]
*/
/*!
**     @brief
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void UART0_OnError(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  T10ms_OnInterrupt (module Events)
**
**     Component   :  T10ms [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void T10ms_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  CAN0_OnFreeTx (module Events)
**
**     Component   :  CAN0 [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the buffer is empty after a
**         successful transmit of a message. This event is available
**         only if method SendFrame is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     @param
**         BufferIdx       - Receive message buffer index.
*/
/* ===================================================================*/
void CAN0_OnFreeTx(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx);

/*
** ===================================================================
**     Event       :  CAN0_OnFullRx (module Events)
**
**     Component   :  CAN0 [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the buffer is full after a
**         successful receive a message. This event is available only
**         if method ReadFrame or SetRxBufferState is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     @param
**         BufferIdx       - Transmit buffer index.
*/
/* ===================================================================*/
void CAN0_OnFullRx(LDD_TUserData *UserDataPtr, LDD_CAN_TMBIndex BufferIdx);

/*
** ===================================================================
**     Event       :  CAN0_OnTransmitWarning (module Events)
**
**     Component   :  CAN0 [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the CAN controller goes into
**         warning status due to the transmit error counter exceeding
**         96 and neither an error status nor a BusOff status are
**         present. This event is available only if method SendFrame is
**         enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void CAN0_OnTransmitWarning(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Event       :  CAN0_OnReceiveWarning (module Events)
**
**     Component   :  CAN0 [CAN_LDD]
*/
/*!
**     @brief
**         This event is called when the CAN controller goes into a
**         warning status due to the receive error counter exceeding 96
**         and neither an error status nor a BusOff status are present.
**         The event is available only if Interrupt service/event is
**         enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void CAN0_OnReceiveWarning(LDD_TUserData *UserDataPtr);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
