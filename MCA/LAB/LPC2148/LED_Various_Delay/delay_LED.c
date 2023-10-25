#include "lpc214x.h"
unsigned int i,j;
void delay(int time)
{
	for(j=0;j<time;j++);
	
}
int main()
{
	IO0DIR=0xFFFFFFFF;
	
	while(1)
	{
		for(i=0;i<32;i++)
		{
			IO0SET|=(1<<i);
			delay(1000);
			IO0CLR|=(1<<i);
			delay(1000);
		}
	}
}

		
