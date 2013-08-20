/*
 * "Copyright (c) 2013 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 *
 */


/**
 * \addtogroup ESOS_Task_Mail_Service
 * @{
 */


/** \file
 *  This file contains macros, prototypes, and definitions for
 *  mail services for ESOS tasks.
 *
    \note For now, these routines are safe from data corruption
    because mailboxes are modified only in the task context.
 */


#ifndef		ESOS_MAIL_H
#define	ESOS_MAIL_H

/* I N C L U D E S **********************************************************/
#include    "esos.h"
#include		"esos_cb.h"

/* D E F I N E S ************************************************************/
// DEFINEs user can NOT change
#define	__MAIL_MSG_HEADER_LEN    	8			// verify this against the MAILMESSAGE struct below
#define __MAIL_MSG_MAX_DATA_LEN		16		// can be no BIGGER than 16
#define __MAIL_MSG_MAX_LEN				(__MAIL_MSG_HEADER_LEN+__MAIL_MSG_MAX_DATA_LEN)


// size of each task's mailbox (in bytes)
//#define	MAX_SIZE_TASK_MAILBOX		    16
#define	MAX_SIZE_TASK_MAILBOX		  5*__MAIL_MSG_MAX_LEN


// TODO  we have included esos.h but for some reason the MAX_NUM_USER_TASKS
//  define is not being found in the declaration of mailboxes below??????

/* S T R U C T U R E S ******************************************************/

/**
* structure to contain a set of descriptors about the buffers used
* to implement ESOS task mailboxes
**/
typedef struct __stMAILBOX {
	CBUFFER*					pst_CBuffer;											// ptr to structure that describes mailbox circular buffer
  struct stTask*		pst_Task;													// ptr to ESOS_TASK_HANDLE that owns mailbox
} MAILBOX;

/**
* structure to contain a mail message "envelope" -- a set of descriptors
* about a mail message and the contents within
**/
typedef struct __stMAILMSG {
  uint16_t    u16_Header;				// bits F-C RESERVED; bits B-4 fromTaskHash?; bits 3-0 payload length 
  uint32_t		u32_Postmark;			// ESOS tick timestamp
  uint8_t 		au8_Contents[__MAIL_MSG_MAX_LEN]; // data storage	
}  MAILMSG;

typedef struct __stMAILMESSAGE {
	uint8_t									u8_flags;					// various bits to help us decode message
	uint16_t								u16_FromTaskID;		// task that sent message
	uint8_t									u8_DataLength;		// how many bytes in data payload
  uint32_t								u32_Postmark;			// ESOS tick timestamp on message
  union {
    uint8_t 					au8_Contents[16]; 		// message contents
    uint16_t 					au16_Contents[8]; 		// message contents
		uint32_t					au32_Contents[4];			// message contents
		char					 	  ach_Contents[16];			// message contents
  };
}  MAILMESSAGE;

#define	ESOS_MAILMESSAGE_STRING					0x0
#define	ESOS_MAILMESSAGE_UINT8					0x1
#define	ESOS_MAILMESSAGE_UINT16					0x2
#define	ESOS_MAILMESSAGE_UINT32					0x4
#define	ESOS_MAILMESSAGE_REQUEST_ACK		0x8


/* M A C R O S ************************************************************/

/**
 * Determines if a task has mail ready to be read/consumed. 
 *
 * \param TaskHandle The \ref ESOS_TASK_HANDLE of the task being queried
 * \sa ESOS_TASK_GET_TASK_HANDLE
 * \hideinitializer
 */
#define ESOS_TASK_HAS_MAIL(pstTask)   									(__ESOS_CB_IS_NOT_EMPTY((pstTask)->pst_Mailbox->pst_CBuffer))

/**
 * Determines if a task is waiting on an acknowledgment from another task
 * reading its mail... a.k.a. "signature confirmation" or "delivery confirmation" 
 *
 * \param TaskHandle The \ref ESOS_TASK_HANDLE of the task being queried
 * \sa ESOS_TASK_GET_TASK_HANDLE
 * \hideinitializer
 */
#define   ESOS_TASK_IS_WAITING_MAIL_DELIVERY(TaskHandle)             IS_BIT_SET_MASK((TaskHandle)->flags, __TASK_MAILNACK_MASK)

/**
 * Determines if the current task has mail to be read
 *
 * Returns TRUE if the current task has mail ready to be read.
 * else it returns FALSE.
 *
 * \sa ESOS_TASK_HAS_MAIL
 *
 * \hideinitializer
 */
#define ESOS_TASK_IVE_GOT_MAIL()               ESOS_TASK_HAS_MAIL(__pstSelf)

/**
 * Blocks the current task until a mailbox message has arrived
 *
 * This function blocks and waits until the task has a message in its mailbox.
 *
 * \hideinitializer
 */
#define ESOS_TASK_WAIT_FOR_MAIL()							ESOS_TASK_WAIT_UNTIL(ESOS_TASK_IVE_GOT_MAIL())


/**
* Evaluates to the booelan to determine if the specified task's mailbox
* has <em>at least</em> x bytes available for holding messages
*
* \param pstTask	pointer to task structure (ESOS_TASK_HANDLE) 
* \param x    number of bytes to check for
* \retval TRUE   if task's mailbox has  x bytes <em>or more</em>
* \retval FALSE   otherwise
*
* \hideinitializer
*/
#define ESOS_TASK_WAIT_ON_TASKS_MAILBOX_HAS_AT_LEAST(pstTask, x)		   ESOS_TASK_WAIT_UNTIL(ESOS_TASK_MAILBOX_GOT_AT_LEAST_DATA_BYTES((pstTask), (x)))

/**
* Evaluates to the number of bytes available in the mailbox association
* with an arbitrary task pstTask
* \param pstTask	pointer to task structure
* \retval N   number of bytes available for writing in task's mailbox
* \hideinitializer
*/
#define ESOS_TASK_MAILBOX_GET_AVAILABLE_LEN(pstTask)   					__ESOS_CB_GET_AVAILABLE((pstTask)->pst_Mailbox->pst_CBuffer)
/**
* Evaluates to the booelan to determine if the specified task's mailbox
* has  <em>exactly</em> x bytes available for holding messages
*
* \param pstTask	pointer to task structure (ESOS_TASK_HANDLE) 
* \param x    number of bytes to check for
* \retval TRUE   if task's mailbox has <em>exactly</em> x bytes
* \retval FALSE   otherwise
*
* \hideinitializer
*/
#define ESOS_TASK_MAILBOX_GOT_EXACTLY_DATA_BYTES(pstTask,x)				(ESOS_TASK_MAILBOX_GET_AVAILABLE_LEN((pstTask)) == x)

/**
* Evaluates to the booelan to determine if the specified task's mailbox
* has <em>at least</em> x bytes available for holding messages
*
* \param pstTask	pointer to task structure (ESOS_TASK_HANDLE) 
* \param x    number of bytes to check for
* \retval TRUE   if task's mailbox has  x bytes <em>or more</em>
* \retval FALSE   otherwise
*
* \hideinitializer
*/
#define ESOS_TASK_MAILBOX_GOT_AT_LEAST_DATA_BYTES(pstTask, x)			(ESOS_TASK_MAILBOX_GET_AVAILABLE_LEN((pstTask)) >= x)

/**
* Flushes the specified task's mailbox contents.  All unread data in the mailbox
* will be lost.
*
* \param pstTask	pointer to task structure (ESOS_TASK_HANDLE) whose mailbox will be flushed
* \note Use this function only if you want to reset some task's mailbox back
* to its empty state.
* \note Not really sure why any task would call this except possibly on its own mailbox, e.g.
* the argument <em>pstTask</em> would be __pstSelf.
*
* \hideinitializer
*/
#define ESOS_TASK_FLUSH_TASK_MAILBOX(pstTask)						  __ESOS_CB_FLUSH((pstTask)->pst_Mailbox->pst_CBuffer)

#define ESOS_TASK_SEND_MESSAGE(pstTask, pstMsg)										__esos_SendMailMessage( pstTask, pstMsg )

#define ESOS_TASK_SEND_MESSAGE_WAIT_DELIVERY(pstTask, pstMsg)												\
		do {																																						\
				ESOS_TASK_SEND_MESSAGE((pstTask),(pstMsg));																	\
				__ESOS_SET_TASK_MAILNACK_FLAG((__pstSelf));																	\
				ESOS_TASK_WAIT_WHILE( ESOS_TASK_IS_WAITING_MAIL_DELIVERY( __pstSelf ) );		\
		} while(0)

/********************
*** QUICKIE MACROS
********************/
#define ESOS_SET_MSG_FLAG(stMsg, flags)						stMsg.u8_flags=(flags)
#define ESOS_SET_MSG_FROM_TASK(stMsg, fromTask)		stMsg.u16_FromTaskID=(fromTask)
#define ESOS_SET_MSG_DATA_LENGTH(stMsg, len)			stMsg.u8_DataLength=(len)
#define ESOS_GET_MSG_FLAG(stMsg)									(stMsg.u8_flags)
#define ESOS_GET_MSG_FROM_TASK(stMsg)							(stMsg.u16_FromTaskID)
#define ESOS_GET_MSG_DATA_LENGTH(stMsg)						(stMsg.u8_DataLength)
#define ESOS_GET_MSG_POSTMARK(stMsg)				  		(stMsg.u32_Postmark)

#define ESOS_SET_PMSG_FLAG(pstMsg, flags)						pstMsg->u8_flags=(flags)
#define ESOS_SET_PMSG_FROM_TASK(pstMsg, fromTask)		pstMsg->u16_FromTaskID=(fromTask)
#define ESOS_SET_PMSG_DATA_LENGTH(pstMsg, len)			pstMsg->u8_DataLength=(len)
#define ESOS_GET_PMSG_FLAG(pstMsg)									(pstMsg->u8_flags)
#define ESOS_GET_PMSG_FROM_TASK(pstMsg)							(pstMsg->u16_FromTaskID)
#define ESOS_GET_PMSG_DATA_LENGTH(pstMsg)						(pstMsg->u8_DataLength)
#define ESOS_GET_PMSG_POSTMARK(pstMsg)				  		(pstMsg->u32_Postmark)

#define ESOS_TASK_MAKE_MSG_UINT8(stMsg, u8x)								\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT8);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 1);										\
	   stMsg.au8_Contents[0] = u8x;														\
	} while(0)

#define ESOS_TASK_MAKE_MSG_UINT8_X2(stMsg, u8x0, u8x1)			\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT8);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 2);										\
	   stMsg.au8_Contents[0] = u8x0;													\
	   stMsg.au8_Contents[1] = u8x1;													\
	} while(0)

#define ESOS_TASK_MAKE_MSG_AUINT8(stMsg, pau8x, len)				\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT8);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 1);										\
	   for (__u8_esos_mail_routines_dummy_uint8=0; __u8_esos_mail_routines_dummy_uint8<len; __u8_esos_mail_routines_dummy_uint8++) {			\
	     stMsg.au8_Contents[__u8_esos_mail_routines_dummy_uint] = pau8x[__u8_esos_mail_routines_dummy_uint8];															\
	   }																											\
	} while(0)

#define ESOS_TASK_MAKE_MSG_UINT16(stMsg, u16x)							\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT16);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 1);										\
	   stMsg.au16_Contents[0] = u16x;													\
	} while(0)

#define ESOS_TASK_MAKE_MSG_UINT16_X2(stMsg, u16x0, u16x1)		\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT16);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 2);										\
	   stMsg.au16_Contents[0] = u16x0;												\
	   stMsg.au16_Contents[1] = u16x1;												\
	} while(0)

#define ESOS_TASK_MAKE_MSG_UINT32(stMsg, u32x)							\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT32);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 1);										\
	   stMsg.au32_Contents[0] = u32x;													\
	} while(0)

#define ESOS_TASK_MAKE_MSG_UINT32_X2(stMsg, u32x0, u32x1)		\
	do{																												\
	   ESOS_SET_MSG_FLAG(stMsg, ESOS_MAILMESSAGE_UINT32);			\
	   ESOS_SET_MSG_FROM_TASK(stMsg, __pstSelf->u16_taskID);	\
	   ESOS_SET_MSG_DATA_LENGTH(stMsg, 2);										\
	   stMsg.au32_Contents[0] = u32x0;												\
	   stMsg.au32_Contents[1] = u32x1;												\
	} while(0)


#define PRINTF_MESSAGE(stMsg)															\
	do{																											\
	  printf("MESSAGE u8_flags =            %d\n",ESOS_GET_MSG_FLAG(stMsg) );	\
	  printf("        u16_FromTaskID =      %d\n",ESOS_SET_MSG_FROM_TASK(stMsg) ); \
	  printf("        u8_DataLength =       %d\n",ESOS_SET_MSG_DATA_LENGTH(stMsg) );	\
	  printf("        u32_PostMark =        %d\n",ESOS_GET_MSG_DATA_LENGTH(stMsg) ); \
	  printf("          first byte  =       %d\n",stMsg.au8_Contents[0]); \
	} while(0) 

/* E X T E R N S ************************************************************/
//extern 		MAILBOX				__astMailbox;
//extern 		uint8_t				__au8_MBData;
extern		MAILBOX					__astMailbox[MAX_NUM_USER_TASKS];
extern		uint8_t					__au8_MBData[MAX_NUM_USER_TASKS][MAX_SIZE_TASK_MAILBOX];
extern		uint8_t					__u8_esos_mail_routines_dummy_uint8;

/* P U B L I C  P R O T O T Y P E S *****************************************/

/* P R I V A T E    P R O T O T Y P E S ***********************************/

/**
*
*/
void __esos_InitMailbox(MAILBOX* pst_Mailbox, uint8_t* pau8_ptr);

//void __esos_WriteMailboxUINT8(MAILBOX* pst_Mailbox, uint8_t u8_x );
#define __esos_WriteMailboxUINT8(pstMB, u8x)					__esos_CB_WriteUINT8((pstMB)->pst_CBuffer, (u8x) )

//uint8_t __esos_ReadMailboxUINT8(MAILBOX* pst_Mailbox );
#define __esos_ReadMailboxUINT8(pstMB, u8x)					__esos_CB_ReadUINT8((pstMB)->pst_CBuffer )

/**
* Writes a mail message into some task's mailbox
* \param	pst_Task		handle tretval verNum   Version number.  Exact value and meaning depends on hardware
* \hideinitializer
*/
void __esos_SendMailUint8(struct stTask* pst_Task, MAILBOX* pst_Mailbox, uint8_t* pau8_data, uint8_t u8_len );


/** @} */

#endif		// ESOS_MAIL_H