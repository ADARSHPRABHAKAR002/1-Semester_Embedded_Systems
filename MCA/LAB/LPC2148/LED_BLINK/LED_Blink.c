#include<lpc214x.h>
int i,j;
int delay(int);

int main()
{
	
	IO0DIR=0xFFFFFFFF;
	while(1)
	{
		IOSET1=0x55;
		delay(5000);
		IOCLR1=0x55;
		delay(5000);
	}
}
int delay(int k)
{
	for(i=0;i<k;i++);
}