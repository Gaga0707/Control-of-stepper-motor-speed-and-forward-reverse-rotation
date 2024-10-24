#include <REGX52.H>
#include "delaytime10us.h"
#include "motorrun.h"
#include "key.h"


bit flag=0;
bit dir=1;
unsigned char KeyNum;	//按键值
unsigned int speed=0;		//赋初值


void main()
{
	
	while(1)
	{
		stepper(dir, speed);
		
		KeyNum=Key();
		
		if(KeyNum==1)//正反转		K1
		{
	   dir = ~dir;
		}
		if(KeyNum==2)//加速 		K2
		{
		 speed-=30;
	   if(speed <= 70)speed = 70;
		}
		if(KeyNum==3)//减速			K3
		{
	   speed+=30;
		 if(speed >= 340)speed = 340;
		}
		if(KeyNum==4)//启停			K4
		{
			flag=~flag;
			if(flag==0)speed=0;
			else speed=190;
		}
		if(KeyNum==5)//转动指定角度		K5
		{	
			angle_control(dir, 90, 150);//参数“90”：代表角度
		}
	}
}
