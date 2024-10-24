#include "delaytime10us.h"

void Delay10us()		//@11.0592MHz
{
	unsigned char i;

	i = 2;
	while (--i);
}

void Delay(unsigned int  time)//—” ±time*10 us
{
	while(time--)
	{Delay10us();}
}
