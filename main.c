#include <REGX52.H>
#include "delaytime10us.h"
#include "motorrun.h"
#include "key.h"


bit flag=0;
bit dir=1;
unsigned char KeyNum;	//����ֵ
unsigned int speed=0;		//����ֵ


void main()
{
	
	while(1)
	{
		stepper(dir, speed);
		
		KeyNum=Key();
		
		if(KeyNum==1)//����ת		K1
		{
	   dir = ~dir;
		}
		if(KeyNum==2)//���� 		K2
		{
		 speed-=30;
	   if(speed <= 70)speed = 70;
		}
		if(KeyNum==3)//����			K3
		{
	   speed+=30;
		 if(speed >= 340)speed = 340;
		}
		if(KeyNum==4)//��ͣ			K4
		{
			flag=~flag;
			if(flag==0)speed=0;
			else speed=190;
		}
		if(KeyNum==5)//ת��ָ���Ƕ�		K5
		{	
			angle_control(dir, 90, 150);//������90��������Ƕ�
		}
	}
}
