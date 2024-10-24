#include <REGX52.H>
#include "MotorRun.h"
#include "delaytime10us.h"

sbit MA=P2^4;
sbit MB=P2^5;
sbit MC=P2^6;
sbit MD=P2^7;


/*
dir����ת����		ö������
speed��ת��
*/
//�ٶȿ���:
void stepper(unsigned int dir, unsigned int speed)
{
	if(dir == 0)
	{
		//step1:
		IN1_HIGH;
		IN2_LOW;
		IN3_LOW;
		IN4_LOW;
		Delay(speed);
		
		//step2:	
		IN1_HIGH;
		IN2_HIGH;
		IN3_LOW;
		IN4_LOW;
		Delay(speed);

		//step3:		
		IN1_LOW;
		IN2_HIGH;
		IN3_LOW;
		IN4_LOW;
		Delay(speed);

		//step4:
		IN1_LOW;
		IN2_HIGH;
		IN3_HIGH;
		IN4_LOW;
		Delay(speed);

		//step5:
		IN1_LOW;
		IN2_LOW;
		IN3_HIGH;
		IN4_LOW;
		Delay(speed);

		//step6:
		IN1_LOW;
		IN2_LOW;
		IN3_HIGH;
		IN4_HIGH;
		Delay(speed);

		//step7:
		IN1_LOW;
		IN2_LOW;
		IN3_LOW;
		IN4_HIGH;
		Delay(speed);

		//step8:
		IN1_HIGH;
		IN2_LOW;
		IN3_LOW;
		IN4_HIGH;
		Delay(speed);
	}
	else if(dir == 1)
	{
		//step1:
		IN1_HIGH;
		IN2_LOW;
		IN3_LOW;
		IN4_HIGH;
		Delay(speed);

		//step2:		
		IN1_LOW;
		IN2_LOW;
		IN3_LOW;
		IN4_HIGH;
		Delay(speed);

		//step3:		
		IN1_LOW;
		IN2_LOW;
		IN3_HIGH;
		IN4_HIGH;
		Delay(speed);

		//step4:
		IN1_LOW;
		IN2_LOW;
		IN3_HIGH;
		IN4_LOW;
		Delay(speed);

		//step5:
		IN1_LOW;
		IN2_HIGH;
		IN3_HIGH;
		IN4_LOW;
		Delay(speed);

		//step6:
		IN1_LOW;
		IN2_HIGH;
		IN3_LOW;
		IN4_LOW;
		Delay(speed);

		//step7:
		IN1_HIGH;
		IN2_HIGH;
		IN3_LOW;
		IN4_LOW;
		Delay(speed);

		//step8:
		IN1_HIGH;
		IN2_LOW;
		IN3_LOW;
		IN4_LOW;
		Delay(speed);
	}
}

//�Ƕȿ��ƣ�
void angle_control(unsigned int dir, double angle, unsigned int speed)
{
	int i;

	for(i = 0; i < angle / STEPPER_ANGLE; i++)
		stepper(dir, speed);
	Motor_Stop();
}

//���ֹͣ��
void Motor_Stop()
{
		IN1_HIGH;
		IN2_HIGH;
		IN3_HIGH;
		IN4_HIGH;
}
