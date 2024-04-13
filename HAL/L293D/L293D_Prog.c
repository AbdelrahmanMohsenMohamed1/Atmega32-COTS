/*
 * L293D_Prog.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Abdelrahman
 */
#include"STD.h"
#include"DIO_Interface.h"
#include"TIMER0_int.h"
#include"L293D_Private.h"
#include"L293D_Config.h"
#include"L293D_Interface.h"



void H_L293D_Void_L293DMotor1CW(void)
{
	//M_DIO_Void_SetPinDirection(EN1_PORT,EN1_PIN,OUTPUT);
	//M_DIO_Void_SetPinValue(EN1_PORT,EN1_PIN,HIGH);
	M_DIO_Void_SetPinDirection(IN1_PORT,IN1_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(IN1_PORT,IN1_PIN,HIGH);
	M_DIO_Void_SetPinDirection(IN2_PORT,IN2_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(IN2_PORT,IN2_PIN,LOW);
}
void H_L293D_Void_L293DMotor1ACW(void)
{
	//M_DIO_Void_SetPinDirection(EN1_PORT,EN1_PIN,OUTPUT);
	//M_DIO_Void_SetPinValue(EN1_PORT,EN1_PIN,HIGH);
	M_DIO_Void_SetPinDirection(IN2_PORT,IN2_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(IN2_PORT,IN2_PIN,HIGH);
	M_DIO_Void_SetPinDirection(IN1_PORT,IN1_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(IN1_PORT,IN1_PIN,LOW);
}
void H_L293D_Void_L293DMotor1Stop(void)
{

}


void H_L293D_Void_L293DMotor2CW(void)
{
	M_DIO_Void_SetPinDirection(EN2_PORT,EN2_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(EN2_PORT,EN2_PIN,HIGH);
	M_DIO_Void_SetPinDirection(IN3_PORT,IN3_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(IN3_PORT,IN3_PIN,HIGH);
}
void H_L293D_Void_L293DMotor2ACW(void)
{
	M_DIO_Void_SetPinDirection(EN2_PORT,EN2_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(EN2_PORT,EN2_PIN,HIGH);
	M_DIO_Void_SetPinDirection(IN4_PORT,IN4_PIN,OUTPUT);
	M_DIO_Void_SetPinValue(IN4_PORT,IN4_PIN,HIGH);
}

void H_L293D_Void_L293DMotor1PWM(u8 Copy_u8PWM)
{
	// step1 : config OC0 pin as output
	M_DIO_Void_SetPinDirection(DIO_PORTB, DIO_PIN3 , OUTPUT);
	// step 2 : Init Timer in PWM mode
	M_TIMER0_void_Init();
	// step 3 : start time
	M_TIMER0_void_TimerStart();

	M_TIMER0_void_setFastPWM(Copy_u8PWM);
}
void H_L293D_Void_L293DMotor2PWM(u8 Copy_u8PWM)
{
	// step1 : config OC0 pin as output
	M_DIO_Void_SetPinDirection(DIO_PORTB, DIO_PIN3 , OUTPUT);
	// step 2 : Init Timer in PWM mode
	M_TIMER0_void_Init();
	// step 3 : start time
	M_TIMER0_void_TimerStart();
	M_TIMER0_void_setFastPWM(Copy_u8PWM);

}
