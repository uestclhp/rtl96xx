/*
=============================================================================
     Header Name: opl_driver.h

     General Description:
===============================================================================
                         Opulan Confidential Proprietary                     
                  ID and version: xxxxxxxxxxxxxx  Version 1.00
                  (c) Copyright Opulan XXXX - XXXX, All Rights Reserved
     

Revision History:
Author                Date              Description of Changes
----------------   ------------  ----------------------------------------------
 zzhu 				   2007/10/10		Initial Version	
----------------   ------------  ----------------------------------------------
*/
#ifndef OPL_DRIVER_H
#define	OPL_DRIVER_H

#include <linux/string.h>
#include <linux/slab.h>



#ifndef OPCONN_BIG_ENDIAN
#define  OPCONN_BIG_ENDIAN 1
#endif
//#define  OPL_DRV_DEBUG    0


#ifndef _TYPE_DEF
#define _TYPE_DEF

typedef unsigned long long UINT64;
typedef unsigned 	int  		UINT32;
typedef unsigned 	short 	UINT16;
typedef unsigned 	char  	UINT8;

typedef signed 	 	int  		INT32;
typedef signed 		short 	INT16;
typedef signed 		char  	INT8;

#endif /* _TYPE_DEF */

typedef UINT8 		      		BOOL_T;
typedef int					    	OPL_BOOL;
typedef int							OPL_STATUS;
//typedef float						FLOAT32;

#define OPL_INT_BIT(x)  (1<<(x))
#define WIDTHMASK(n)  ((n) == 32)?0xffffffff:(~(0xffffffff<<(n)))

#define OPL_OK					0
#define OPL_ERROR				(-1)
#define OPL_BAD_PARA            (-2)   /* Illegal parameter in function called  */
#define OPL_NOT_SUPPORTED       (-3)   /* This request is not support           */
#define OPL_EXIST               (-4)   /* Tried to create existing item         */
#define OPL_NOT_EXIST           (-5)   /* Tried to create existing item         */
#define OPL_FAIL                (-6) /* Operation failed                      */
#define OPL_BAD_VALUE           (-7)   /* Illegal value (general)               */
#define OPL_NO_MEMORY           (-8)   /* Out of memory               */
#define OPL_NOT_FOUND           (-10)   /* Item not found                        */
#define OPL_NO_MORE             (-11)   /* No more items found                   */
#define OPL_NO_SUCH             (-12)   /* No such item                          */
#define OPL_TIMEOUT             (-13)   /* Time Out                              */
#define OPL_FULL                (-13)   /* full                              */

#define OPL_ZERO				0

#define OPL_NULL 				((void *) 0) 	/* a null pointer */

#define OPL_TRUE				1
#define OPL_FALSE				0

#define OPL_ENABLE			1
#define OPL_DISABLE			0
#define OPL_VALID				1
#define OPL_INVALID			0
#define OPL_USED				1
#define OPL_UNUSED			0

		/* register related constants */

#define OPL_REG_BIT0		(0x1 << 0)
#define OPL_REG_BIT1		(0x1 << 1)
#define OPL_REG_BIT2		(0x1 << 2)
#define OPL_REG_BIT3		(0x1 << 3)
#define OPL_REG_BIT4		(0x1 << 4)
#define OPL_REG_BIT5		(0x1 << 5)
#define OPL_REG_BIT6		(0x1 << 6)
#define OPL_REG_BIT7		(0x1 << 7)
#define OPL_REG_BIT8		(0x1 << 8)
#define OPL_REG_BIT9		(0x1 << 9)
#define OPL_REG_BIT10		(0x1 << 10)
#define OPL_REG_BIT11		(0x1 << 11)
#define OPL_REG_BIT12		(0x1 << 12)
#define OPL_REG_BIT13		(0x1 << 13)
#define OPL_REG_BIT14		(0x1 << 14)
#define OPL_REG_BIT15		(0x1 << 15)
#define OPL_REG_BIT16		(0x1 << 16)
#define OPL_REG_BIT17		(0x1 << 17)
#define OPL_REG_BIT18		(0x1 << 18)
#define OPL_REG_BIT19		(0x1 << 19)
#define OPL_REG_BIT20		(0x1 << 20)
#define OPL_REG_BIT21		(0x1 << 21)
#define OPL_REG_BIT22		(0x1 << 22)
#define OPL_REG_BIT23		(0x1 << 23)
#define OPL_REG_BIT24		(0x1 << 24)
#define OPL_REG_BIT25		(0x1 << 25)
#define OPL_REG_BIT26		(0x1 << 26)
#define OPL_REG_BIT27		(0x1 << 27)
#define OPL_REG_BIT28		(0x1 << 28)
#define OPL_REG_BIT29		(0x1 << 29)
#define OPL_REG_BIT30		(0x1 << 30)
#define OPL_REG_BIT31		(0x1 << 31)

#define OPL_MEMCPY				memcpy
#define OPL_MEMSET				memset
#define OPL_MALLOC(size) 		kmalloc(size, GFP_KERNEL)
#define OPL_STRCPY				strcpy
#define OPL_STRCMP				strcmp
#define OPL_STRLEN				strlen
#define OPL_FREE   				kfree
#define OPL_MEMCMP				memcmp

#define OPL_DRV_DEBUG_ENABLE    0
#define OPL_DAL_DEBUG_ENABLE    0

#define OPL_DRV_PRINTF_ERR(x)	printk x
#define OPL_DRV_PRINTF(x)		if(OPL_DRV_DEBUG_ENABLE)printk x
#define OPL_DAL_PRINTF(x)       if(OPL_DAL_DEBUG_ENABLE)printk x
#define OPL_DRV_PRINTK(x)       printk x

#define OPL_DRV_SHOW_PRINTF(x)  printk x

#define OPL_BZERO(pcBaseAddr, nBytes)     		memset((void *)(pcBaseAddr), 0, (nBytes))

#define OPL_ERR_NO(errorno)				    				(errorno)
#define OPL_ERR_MEMORY_BASE								(OPL_ERROR - 0x2400)  /* = -0x2401,! */
#define OPL_ERR_MEM_ALLOCATION_FAILURE		(OPL_ERR_MEMORY_BASE - 0)
#define OPL_ERR_UNKNOWN_MEM_REGION			(OPL_ERR_MEMORY_BASE - 1)

#define IS_NULL_POINTER(p)  ((p)?0:1)

#define MAC_STRING_LENG   17
#define MAC_LENGTH            6
#define IPVERSION4_LENGTH     4


#define ONU_OPCONN					0x1
#define ONU_NEEDLETAIL				0x2	

extern UINT32 gChipRevision;

#define IS_ONU_RESPIN (gChipRevision == ONU_NEEDLETAIL)
#define IS_ONU_OPCONN (gChipRevision == ONU_OPCONN)

#define PON_MAC_MTU ((IS_ONU_RESPIN)?2047:1536) 

typedef  int (*ioctlfunc)(unsigned int );

#define USR2KRN( dst, src ) \
  if( usr2krn( &(dst), src, sizeof(dst)) ) return OPL_ERR_INVALID_PARAMETERS

#define KRN2USR( dst, src ) \
  if( krn2usr( dst, &(src), sizeof(src)) ) return OPL_ERR_INVALID_PARAMETERS


int krn2usr( void *dst, void *src, UINT32 size );
int usr2krn( void *dst, void *src, UINT32 size );


enum 
{
	OPL_NOT_FIND,
	OPL_FIND
};

#endif
