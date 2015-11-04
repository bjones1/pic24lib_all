/// .. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
//    All rights reserved.
//    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
//    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
//    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
//
//    Permission to use, copy, modify, and distribute this software and its
//    documentation for any purpose, without fee, and without written agreement is
//    hereby granted, provided that the above copyright notice, the following
//    two paragraphs and the authors appear in all copies of this software.
//
//    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
//    DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
//    OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
//    HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
//    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
//    AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
//    ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
//    PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
//
//    Please maintain this header in its entirety when copying/modifying
//    these files.
//
// **********************************************************
// ecan_example_fifo_eid.c - Illustrate CAN transmit, receive
// **********************************************************
// Uses a FIFO for RX receive, and
// uses an extended data frame.

#include "pic24_all.h"
#include <stdio.h>

#define NUM_TX_BUFS  1   //reserve 1 for TX
#define NUM_BUFS    8   //make this a power of 2 for the alignment to work or enter alignment manually

#define MSG_ID 0x10B2ABC0    //arbitrary choice for extended messsage ID

#if defined(__PIC24H__) || defined (__dsPIC33F__)
ECANMSG msgBuf[NUM_BUFS] __attribute__((space(dma),aligned(NUM_BUFS*16)));

//configure DMA transmit buffer
void configDMA0(void) {
  DMACS0 = 0;
  _DMA0IF = 0;
  DMA0PAD = (unsigned int) &C1TXD;
  DMA0REQ = DMA_IRQ_ECAN1TX;
  DMA0STA = __builtin_dmaoffset(msgBuf);
  DMA0CNT =   sizeof(ECANMSG)/2 -1;  // == 7
  DMA0CON =   //configure and enable the module Module
    (DMA_MODULE_ON |
     DMA_SIZE_WORD |
     DMA_DIR_WRITE_PERIPHERAL |
     DMA_INTERRUPT_FULL |
     DMA_NULLW_OFF |
     DMA_AMODE_PERIPHERAL_INDIRECT |
     DMA_MODE_CONTINUOUS);
}

//configure DMA receive buffer
void configDMA1(void) {
  _DMA1IF = 0;
  DMA1PAD = (unsigned int) &C1RXD;
  DMA1REQ = DMA_IRQ_ECAN1RX;
  DMA1STA = __builtin_dmaoffset(msgBuf);
  DMA1CNT =  sizeof(ECANMSG)/2 -1;  // == 7
  DMA1CON =   //configure and enable the module Module
    (DMA_MODULE_ON |
     DMA_SIZE_WORD |
     DMA_DIR_READ_PERIPHERAL |
     DMA_INTERRUPT_FULL |
     DMA_NULLW_OFF |
     DMA_AMODE_PERIPHERAL_INDIRECT |
     DMA_MODE_CONTINUOUS);

}

#elif defined(__dsPIC33EP512GP806__)
// dsPIC33EP512GP806 must be handled differently than the rest of the family
// due to errata in the DMA subsystem (see document DS80000526E - silicon issue
// 15). DPRAM must be used to ensure that the DMA cannot be held in the "OFF"
// state by the system arbiter. [Ryan Taylor; November 2015]

__eds__ ECANMSG msgBuf[NUM_BUFS] __attribute__((space(dma),aligned(NUM_BUFS*16),eds));

//configure DMA transmit buffer
void configDMA0(void) {
  DMAPWC = 0; // Reset the DMA Peripheral Write Collision Status Register
  _DMA0IF = 0;
  DMA0PAD = (unsigned int) &C1TXD;
  DMA0REQ = DMA_IRQ_ECAN1TX;
  DMA0STAL = (unsigned long int) &msgBuf;
  DMA0STAH = 0;
  DMA0CNT =   sizeof(ECANMSG)/2 -1;  // == 7
  DMA0CON =   //configure and enable the module Module
    (DMA_MODULE_ON |
     DMA_SIZE_WORD |
     DMA_DIR_WRITE_PERIPHERAL |
     DMA_INTERRUPT_FULL |
     DMA_NULLW_OFF |
     DMA_AMODE_PERIPHERAL_INDIRECT |
     DMA_MODE_CONTINUOUS);
}

//configure DMA receive buffer
void configDMA1(void) {
  _DMA1IF = 0;
  DMA1PAD = (unsigned int) &C1RXD;
  DMA1REQ = DMA_IRQ_ECAN1RX;
  DMA1STAL = (unsigned long int) &msgBuf;
  DMA1STAH = 0;
  DMA1CNT =  sizeof(ECANMSG)/2 -1;  // == 7
  DMA1CON =   //configure and enable the module Module
    (DMA_MODULE_ON |
     DMA_SIZE_WORD |
     DMA_DIR_READ_PERIPHERAL |
     DMA_INTERRUPT_FULL |
     DMA_NULLW_OFF |
     DMA_AMODE_PERIPHERAL_INDIRECT |
     DMA_MODE_CONTINUOUS);
}

#elif defined(__dsPIC33E__)

ECANMSG msgBuf[NUM_BUFS] __attribute__((space(xmemory),aligned(NUM_BUFS*16)));

//configure DMA transmit buffer
void configDMA0(void) {
  DMAPWC = 0; // Reset the DMA Peripheral Write Collision Status Register
  _DMA0IF = 0;
  DMA0PAD = (unsigned int) &C1TXD;
  DMA0REQ = DMA_IRQ_ECAN1TX;
  DMA0STAL = (unsigned int) &msgBuf;
  DMA0STAH = 0;
  DMA0CNT =   sizeof(ECANMSG)/2 -1;  // == 7
  DMA0CON =   //configure and enable the module Module
    (DMA_MODULE_ON |
     DMA_SIZE_WORD |
     DMA_DIR_WRITE_PERIPHERAL |
     DMA_INTERRUPT_FULL |
     DMA_NULLW_OFF |
     DMA_AMODE_PERIPHERAL_INDIRECT |
     DMA_MODE_CONTINUOUS);
}

//configure DMA receive buffer
void configDMA1(void) {
  _DMA1IF = 0;
  DMA1PAD = (unsigned int) &C1RXD;
  DMA1REQ = DMA_IRQ_ECAN1RX;
  DMA1STAL = (unsigned int) &msgBuf;
  DMA1STAH = 0;
  DMA1CNT =  sizeof(ECANMSG)/2 -1;  // == 7
  DMA1CON =   //configure and enable the module Module
    (DMA_MODULE_ON |
     DMA_SIZE_WORD |
     DMA_DIR_READ_PERIPHERAL |
     DMA_INTERRUPT_FULL |
     DMA_NULLW_OFF |
     DMA_AMODE_PERIPHERAL_INDIRECT |
     DMA_MODE_CONTINUOUS);
}
#else
#error "Configure DMA for your chip here."
#endif

#define RX_BUFFER_ID  15  //a value of 15 means to use a FIFO for RX

void configECAN1() {
  uint8_t u8_i;
  CHANGE_MODE_ECAN1(ECAN_MODE_CONFIGURE);
  configBaudECAN1();
  C1FCTRL = ECAN_DMA_BUF_SIZE_8 | ECAN_FIFO_START_AREA_1;
//use Filter 0 with Mask 0
  configRxFilterECAN1(0, MSG_ID, ECAN_MATCH_EID, RX_BUFFER_ID, 0);
  configRxFilterECAN1(0, MSG_ID, ECAN_MATCH_EID, RX_BUFFER_ID, 0);
  configRxMaskECAN1(0, 0x1FFFFFFC, ECAN_MATCH_EID, 1);  //check all bits except last 2
  clrRxFullOvfFlagsECAN1();  //clear all RX full, overflow flags.

//first 8 buffs must be configured as either TX or TX
  for (u8_i = 0; u8_i<8; u8_i++) {
    if (u8_i < NUM_TX_BUFS)
      configTxRxBufferECAN1(u8_i,ECAN_TX_BUFF,3);
    else
      configTxRxBufferECAN1(u8_i,ECAN_RX_BUFF,3);
  }
  configDMA0();    //do DMA config after ECAN has been initialized
  configDMA1();
  CHANGE_MODE_ECAN1(ECAN_MODE_NORMAL);
}

uint32_t rrot32(uint32_t u32_x) {
  if (u32_x & 0x1) {
    u32_x = u32_x >> 1;
    u32_x = u32_x | 0x80000000;
  } else u32_x = u32_x >> 1;
  return u32_x;
}

int main (void) {
  uint32_t u32_out0, u32_out1, u32_in0, u32_in1;
  uint8_t rx_buff_id, u8_cnt;

  configBasic(HELLO_MSG);
  configECAN1();
  CHANGE_MODE_ECAN1(ECAN_MODE_LOOPBACK);  //loopback to ourself for a test.
  u32_out0 = 0xFEDCBA98;
  u32_out1 = 0x76543210;
  u8_cnt = 0;
  while (1) {
    DELAY_MS(500);
    msgBuf[0].data.u32[0] = u32_out0; //save in CAN message
    msgBuf[0].data.u32[1] = u32_out1;
    //format Buffer 0 for TX with SID=MSG_ID, data length = 8 bytes
    formatExtendedDataFrameECAN(&msgBuf[0], MSG_ID+u8_cnt, 8);
    startTxECAN1(0);  //start transmission of buffer 0
    while (getTxInProgressECAN1(0)) {
      doHeartbeat(); //wait for transmission to end.
    }
    _DMA0IF = 1;
    DELAY_MS(10);  //delay for reception
    if (!_DMA1IF) {
      printf("Message ID 0x%lX rejected by acceptance filter.\n",MSG_ID+u8_cnt);
    } else {
      _DMA1IF = 0;   //RX message accepted
      rx_buff_id = GET_FIFO_READBUFFER_ECAN1();
      u32_in0 = msgBuf[rx_buff_id].data.u32[0];
      u32_in1 = msgBuf[rx_buff_id].data.u32[1];
      printf("Rx Buff: %d. Msg ID: 0x%lX, Out: 0x%08lX%08lX, In: 0x%08lX%08lX\n",
             rx_buff_id, getIdExtendedDataFrameECAN (&msgBuf[rx_buff_id]),u32_out0, u32_out1, u32_in0, u32_in1 );
      clrRxFullFlagECAN1(rx_buff_id);
    }
    u32_out0 = rrot32(u32_out0);
    u32_out1 = rrot32(u32_out1);
    u8_cnt++;
    if (u8_cnt == 8) u8_cnt = 0;
  }//end while
}//end main
