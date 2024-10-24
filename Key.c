#include <REGX52.H>
#include "delaytime10us.h"
#include "key.h"

unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(P1_0==0){Delay(1000);while(P1_0==0);Delay(1000);KeyNumber=1;}
	if(P1_1==0){Delay(1000);while(P1_1==0);Delay(1000);KeyNumber=2;}
	if(P1_2==0){Delay(1000);while(P1_2==0);Delay(1000);KeyNumber=3;}
	if(P1_3==0){Delay(1000);while(P1_3==0);Delay(1000);KeyNumber=4;}
	if(P3_0==0){Delay(1000);while(P3_0==0);Delay(1000);KeyNumber=5;}
	
	return KeyNumber;
}
