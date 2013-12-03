/*
 * CAN.c
 *
 *  Created on: Nov 8, 2013
 *      Author: Andrew Westrick
 */

#include <string.h>
#include "CAN.h"
#include "Events.h"
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
void CAN_QueueInit(CAN_Queue *Queue) {
	Queue->Front = 0;
	Queue->Back = 0;
	Queue->Size = 0;
	Queue->LostPacket = 0;
}

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
uint8 CAN_QueueAdd(CAN_Queue* Queue, LDD_CAN_TFrame Frame) {
	if ((Queue->Size) < CAN_QUEUE_SIZE) {
		memcpy(&(Queue->Queue[Queue->Back]),&Frame,sizeof(Queue->Queue[Queue->Back])); 	/* Copy contents of message to the back of the CAN queue */
		Queue->Back++;																	/* Increment back pointer of the queue */
		Queue->Size++;																	/* and increase its size by 1 */
		return 0;
	}
	else {
		return 1;
	}
}

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
uint8 CAN_QueueRemove(CAN_Queue* Queue) {
	if ((Queue->Size) > 0) {
		Queue->Back--;
		Queue->Size--;
		return 0;
	}
	else { 
		return 1;
	}
}

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
uint8 CAN_QueueTransmit(CAN_Queue* Queue) {
	if ((Queue->Size) > 0) {
		int BusyCnt=0;
		while(Queue->SendFrame(Queue->Device, Queue->Buffer, &(Queue->Queue[Queue->Front]))==ERR_BUSY){	/* Attempt to retransmit while bus is busy */
			BusyCnt++;
			if (BusyCnt>CAN_TX_FAULT_TIME) {														/* If bus busy count > TX fault time then drop message */
				Queue->LostPacket++;																/* and increment lost packet count */
				break;
			}
		}
		Queue->Front++;																				/* Remove message from queue */
		Queue->Size--;																				/* Decrease queue size */
		return Queue->Size;
	}
	else {
		CAN_QueueEmpty(Queue);																		/* Empty the queue */
		Queue->Stats=Queue->GetStats(Queue->Device);												/* Get CAN0 communication statistics */
		return 0;
	}
}

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
void CAN_QueueEmpty(CAN_Queue *Queue) {
	Queue->Front = 0;
	Queue->Back = 0;
	Queue->Size = 0;
}
