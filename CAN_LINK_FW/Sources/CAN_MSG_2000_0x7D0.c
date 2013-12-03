/*
 * CAN_MSG_2000_0x7D0.c
 *
 *  Created on: Nov 20, 2013
 *      Author: andre_000
 */

#include "CAN.h"
#include "CAN_MSG_2000_0x7D0.h"
#include "Events.h"

CAN_MSG_2000_0x7D0_Type CAN_MSG_2000_0x7D0 = {
	.Factor.Signal_1 = 1,
	.Offset.Signal_1 = 0,
	.Factor.Signal_2 = 1,
	.Offset.Signal_2 = 0,
	.Factor.Signal_3 = 1,
	.Offset.Signal_3 = 0,
	.Factor.Signal_4 = 1,
	.Offset.Signal_4 = 0
};

void CAN_MSG_2000_0x7D0_Handler(CAN_Queue *QueueIn, LDD_CAN_TMBIndex BufferIdx) {
	LDD_CAN_TFrame CAN_MSG_2000_0x7D0_Frame = {
		.Data = (uint8_t*)&CAN_MSG_2000_0x7D0.Msg,
	};
	/* Receive message */
	CAN0_ReadFrame(QueueIn->Device, BufferIdx, &CAN_MSG_2000_0x7D0_Frame);
	CAN_MSG_2000_0x7D0_Pkt.Message.Signal_1 = ((CAN_MSG_2000_0x7D0.Msg.Signal_1*CAN_MSG_2000_0x7D0.Factor.Signal_1)+CAN_MSG_2000_0x7D0.Offset.Signal_1);
	CAN_MSG_2000_0x7D0_Pkt.Message.Signal_2 = ((CAN_MSG_2000_0x7D0.Msg.Signal_2*CAN_MSG_2000_0x7D0.Factor.Signal_2)+CAN_MSG_2000_0x7D0.Offset.Signal_2);
	CAN_MSG_2000_0x7D0_Pkt.Message.Signal_3 = ((CAN_MSG_2000_0x7D0.Msg.Signal_3*CAN_MSG_2000_0x7D0.Factor.Signal_3)+CAN_MSG_2000_0x7D0.Offset.Signal_3);
	CAN_MSG_2000_0x7D0_Pkt.Message.Signal_4 = ((CAN_MSG_2000_0x7D0.Msg.Signal_4*CAN_MSG_2000_0x7D0.Factor.Signal_4)+CAN_MSG_2000_0x7D0.Offset.Signal_4);
	CAN_MSG_2000_0x7D0_Pkt.ID = CAN_MSG_2000_0x7D0_Frame.MessageID;
	CAN_MSG_2000_0x7D0_Pkt.Length = CAN_MSG_2000_0x7D0_Frame.Length;
	LDD_TError Error;
	Error = UART0_SendBlock(UART0_DeviceData, &CAN_MSG_2000_0x7D0_Pkt , sizeof(CAN_MSG_2000_0x7D0_Pkt));
}
