/*
 * EEPROM_prg.c
 *
 *  Created on: Sep 28, 2022
 *      Author: Abdelrahman
 */
 
#include "STD.h"
#include "TWI_int.h"
#include "EEPROM_priv.h"
#include "EEPROM_config.h"
#include "EEPROM_int.h"

void H_EEPROM_void_Init(void)
{
   M_TWI_void_Init();
}
u8 H_EEPROM_u8_writeByte(u16  copy_u16add,u8 copy_u8data)
{
	u8 _3MSB ;
	// step 1 : send start
   M_TWI_void_sendStart();
   // step 2 : check status
   if(! (M_TWI_u8_getStatus() == TWI_MT_START_SUCCESS)  )
   {
	   return 0;
   }
   // step 3 : send SLA + W  (0xA0 + A10 + A9 + A8)
   _3MSB  = (u8)  ((copy_u16add & 0700) >> 7);// 0000 A10 A9 A8 R/W
   M_TWI_void_sendByte( _3MSB |0xA0);
   // step 4 : check status
   if(! (M_TWI_u8_getStatus() == TWI_MT_SLA_W_ACK)  )
  {
   return 0;
  }
   // step 5 : send the rest of the address (A7  .... A0)
   M_TWI_void_sendByte((u8)copy_u16add);
   // step 4 : check status
     if(! (M_TWI_u8_getStatus() == TWI_MT_DATA_ACK)  )
    {
     return 0;
    }
    // step 6 : send data to be written
     M_TWI_void_sendByte(copy_u8data);
   // step 7 : check status
	 if(! (M_TWI_u8_getStatus() == TWI_MT_DATA_ACK)  )
	{
	 return 0;
	}
	 // step 8 : send stop
	 M_TWI_void_sendStop();
	 return 1 ;
}
u8 H_EEPROM_u8_readByte(u16  copy_u16add,u8 * ptr_data)
{
	u8 _3MSB ;
	// step 1 : send start
   M_TWI_void_sendStart();
   // step 2 : check status
   if(! (M_TWI_u8_getStatus() == TWI_MT_START_SUCCESS)  )
   {
	   return 0;
   }
   // step 3 : send SLA + W  (0xA0 + A10 + A9 + A8)
   _3MSB  = (u8)  ((copy_u16add & 0700) >> 7);// 0000 A10 A9 A8 R/W
   M_TWI_void_sendByte( _3MSB |0xA0);
   // step 4 : check status
   if(! (M_TWI_u8_getStatus() == TWI_MT_SLA_W_ACK)  )
  {
   return 0;
  }
   // step 5 : send the rest of the address (A7  .... A0)
   M_TWI_void_sendByte((u8)copy_u16add);
   // step 6 : check status
     if(! (M_TWI_u8_getStatus() == TWI_MT_DATA_ACK)  )
    {
     return 0;
    }
     // step 7 : send repeated start
     M_TWI_void_sendStart();
     // step 8 : check status
   if(! (M_TWI_u8_getStatus() == TWI_MR_REPEATED_START_SUCCESS)  )
   {
	   return 0;
   }
   // step 9 : send SLA + R  (0xA0)
   M_TWI_void_sendByte(0xA0| 1); // fixed address + R  => R = 1

   //step 10 : check status
   if(! (M_TWI_u8_getStatus() == TWI_MR_SLA_R_ACK)  )
      {
   	   return 0;
      }
   // step 11 : read data
   M_TWI_void_receiveByte_ACK(ptr_data);
   // step 12 : check status
   if(! (M_TWI_u8_getStatus() ==  TWI_MR_DATA_ACK)  )
	 {
	   return 0;
	 }
   //  step 13 :
   M_TWI_void_sendStop();
  	 return 1 ;
}
