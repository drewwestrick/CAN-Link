/*
 * CAN_MSG_2000_0x7D0.h
 *
 *  Created on: Nov 20, 2013
 *      Author: andre_000
 */

#ifndef CAN_MSG_2000_0x7D0_H_
#define CAN_MSG_2000_0x7D0_H_

#endif /* CAN_MSG_2000_0x7D0_H_ */

typedef struct {
	float Signal_1;
	float Signal_2;
	float Signal_3;
	float Signal_4;
} CAN_MSG_2000_0x7D0_ProcessType;
typedef struct {
	uint8_t Signal_1;
	uint8_t Signal_2;
	uint8_t Signal_3;
	uint8_t Signal_4;
} CAN_MSG_2000_0x7D0_ProcessTypeInt;

typedef struct {
	struct {
		unsigned long long	Signal_1: 		8;	/* S:0   L:16  */
		unsigned long long 	Signal_2: 		8;	/* S:16  L:16  */
		unsigned long long	Signal_3: 		8;	/* S:32  L:16  */
		unsigned long long	Signal_4: 		8;	/* S:48  L:16 */
	} Msg;
	CAN_MSG_2000_0x7D0_ProcessType Factor;
	CAN_MSG_2000_0x7D0_ProcessType Offset;
	CAN_MSG_2000_0x7D0_ProcessTypeInt Value;
} CAN_MSG_2000_0x7D0_Type;

typedef struct {
	uint16_t ID;
	uint8_t Length;
	CAN_MSG_2000_0x7D0_ProcessTypeInt Message;
} CAN_MSG_2000_0x7D0_PktType;

CAN_MSG_2000_0x7D0_Type CAN_MSG_2000_0x7D0;
CAN_MSG_2000_0x7D0_PktType CAN_MSG_2000_0x7D0_Pkt;
void CAN_MSG_2000_0x7D0_Handler(CAN_Queue *QueueIn, LDD_CAN_TMBIndex BufferIdx);
