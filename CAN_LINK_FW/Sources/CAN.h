/*
 * CAN.h
 *
 *  Created on: Nov 8, 2013
 *      Author: Andrew Westrick
 */

#ifndef CAN_H_
#define CAN_H_

#include "PE_Types.h"

#endif /* CAN_H_ */

/* ------------- Global Variables ------------------------------------------------------- */

#define CAN_TX_FAULT_TIME		250		/* Number of TX retries before dropping tx packet */
#define CAN_QUEUE_SIZE			256		/* Size of the tx queue buffer */

/* ------------- CAN0 Variables --------------------------------------------------------- */

/* Defines */
#define CAN0_RX_0x730			0		/* CAN0 RX buffer 0x21 */
#define CAN0_RX_0x7D0			1
#define CAN0_TX					2		/* CAN0 TX buffer */
#define CAN1_TX					1		/* CAN1 TX buffer */


/* ------------- CAN Structures --------------------------------------------------------- */

typedef word (*FPtr)();

/* Transmit Queue */
typedef struct {
	uint8 Front;
	uint8 Back;
	uint8 Size;
	uint8 Buffer;
	uint32 LostPacket;
	LDD_CAN_TStats Stats;
	LDD_CAN_TFrame Queue[256];
	LDD_TDeviceData *Device;
	LDD_CAN_TStats (*GetStats)();
	LDD_TError (*SendFrame)();
} CAN_Queue;

/* ------------- Queue Variables -------------------------------------------------------- */
CAN_Queue CAN0_Queue;

/*
** ===================================================================
**     Method      :  CAN_QueueInit (driver for CAN_LDD)
*/
/*!
**     @brief
**         Sets the queue variables to zero
**     @param
**         CAN_Queue 		-	CAN transmit queue        
*/
/* ===================================================================*/
void CAN_QueueInit(CAN_Queue *Queue);

/*
** ===================================================================
**     Method      :  CAN_QueueAdd (driver for CAN_LDD)
*/
/*!
**     @brief
**         Add a CAN message to the queue
**     @param
**         CAN_Queue 		-	CAN transmit queue
**     @param
**         LDD_CAN_TFrame 	-	Message frame to be added to the queue        
**     @return
**                         	-	0 if queue size is less
**                         		than max queue size
**                         		1 if queue is already full
*/
/* ===================================================================*/
uint8 CAN_QueueAdd(CAN_Queue* Queue, LDD_CAN_TFrame Frame);

/*
** ===================================================================
**     Method      :  CAN_QueueRemove (driver for CAN_LDD)
*/
/*!
**     @brief
**         Remove a CAN message from the back of the queue
**     @param
**         CAN_Queue 		-	CAN transmit queue     
**     @return
**                         	-	0 if there is a message in the queue
**                         		1 if the queue is already empty
*/
/* ===================================================================*/
uint8 CAN_QueueRemove(CAN_Queue* Queue);

/*
** ===================================================================
**     Method      :  CAN_QueueTransmit (driver for CAN_LDD)
*/
/*!
**     @brief
**         Transmit the messages in the CAN queue
**     @param
**         CAN_Queue 		-	CAN transmit queue     
**     @return
**                         	-	Number of elements left in the queue
**                         		or return 0 if queue is empty
*/
/* ===================================================================*/
uint8 CAN_QueueTransmit(CAN_Queue* Queue);

/*
** ===================================================================
**     Method      :  CAN_QueueEmpty (driver for CAN_LDD)
*/
/*!
**     @brief
**         Reset the front and back pointers and the queue size
**     @param
**         CAN_Queue 		-	CAN transmit queue     
*/
/* ===================================================================*/
void CAN_QueueEmpty(CAN_Queue *Queue);
