/*
 * CAN_MSG_1840_0x730.c
 *
 *  Created on: Nov 20, 2013
 *      Author: andre_000
 */

#include "CAN.h"
#include "CAN_MSG_1840_0x730.h"
#include "Events.h"

CAN_MSG_1840_0x730_Type CAN_MSG_1840_0x730 = {
	.Factor.Signal_1 = 1,
	.Offset.Signal_1 = 0,
	.Factor.Signal_2 = 1,
	.Offset.Signal_2 = 0,
	.Factor.Signal_3 = 1,
	.Offset.Signal_3 = 0,
	.Factor.Signal_4 = 1,
	.Offset.Signal_4 = 0
};

void CAN_MSG_1840_0x730_Handler(CAN_Queue *QueueIn, LDD_CAN_TMBIndex BufferIdx) {
	LDD_CAN_TFrame CAN_MSG_1840_0x730_Frame = {
		.Data = (uint8_t*)&CAN_MSG_1840_0x730.Msg,
	};
	/* Receive message */
	CAN0_ReadFrame(QueueIn->Device, BufferIdx, &CAN_MSG_1840_0x730_Frame);
	CAN_MSG_1840_0x730_Pkt.Message.Signal_1 = ((CAN_MSG_1840_0x730.Msg.Signal_1*CAN_MSG_1840_0x730.Factor.Signal_1)+CAN_MSG_1840_0x730.Offset.Signal_1);
	CAN_MSG_1840_0x730_Pkt.Message.Signal_2 = ((CAN_MSG_1840_0x730.Msg.Signal_2*CAN_MSG_1840_0x730.Factor.Signal_2)+CAN_MSG_1840_0x730.Offset.Signal_2);
	CAN_MSG_1840_0x730_Pkt.Message.Signal_3 = ((CAN_MSG_1840_0x730.Msg.Signal_3*CAN_MSG_1840_0x730.Factor.Signal_3)+CAN_MSG_1840_0x730.Offset.Signal_3);
	CAN_MSG_1840_0x730_Pkt.Message.Signal_4 = ((CAN_MSG_1840_0x730.Msg.Signal_4*CAN_MSG_1840_0x730.Factor.Signal_4)+CAN_MSG_1840_0x730.Offset.Signal_4);
	CAN_MSG_1840_0x730_Pkt.ID = CAN_MSG_1840_0x730_Frame.MessageID;
	CAN_MSG_1840_0x730_Pkt.Length = CAN_MSG_1840_0x730_Frame.Length;
	LDD_TError Error;
	Error = UART0_SendBlock(UART0_DeviceData, &CAN_MSG_1840_0x730_Pkt , sizeof(CAN_MSG_1840_0x730_Pkt));
}
