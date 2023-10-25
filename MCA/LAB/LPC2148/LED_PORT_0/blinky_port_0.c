#include "lpc214x.h"
unsigned int i;
int delay(int);
int main()
{
	IO0DIR=0xFFFFFFFF;

	while(1)
	{
		IO0SET=0xFFFFFFFF;
		delay(1000);
		IO0CLR=0xFFFFFFFF;
		delay(1000);
	}
}
int delay(int time)
{
	for(i=0;i>time;i++);
	return ;
}
