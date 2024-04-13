/*
 * L293D_Interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Abdelrahman
 */

#ifndef L293D_L293D_INTERFACE_H_
#define L293D_L293D_INTERFACE_H_

//void H_L293D_Void_L293DMotor1Init(void);
//void H_L293D_Void_L293DMotor2Init(void);
void H_L293D_Void_L293DMotor1CW(void);
void H_L293D_Void_L293DMotor1ACW(void);
void H_L293D_Void_L293DMotor1Stop(void);
void H_L293D_Void_L293DMotor2CW(void);
void H_L293D_Void_L293DMotor2ACW(void);
//void H_L293D_Void_L293DMotor2Stop(void);
void H_L293D_Void_L293DMotor1PWM(u8 Copy_u8PWM);
void H_L293D_Void_L293DMotor2PWM(u8 Copy_u8PWM);



#endif /* L293D_L293D_INTERFACE_H_ */
