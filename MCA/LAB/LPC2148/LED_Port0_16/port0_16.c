#include "lpc214x.h"
int main()
{
	IO0DIR=(1<<16);
	while(1)
	{
		if(IO0SET==(1<<16))
		{
			IO0SET|=(1<<16);
		}
	else
	{
		IO0CLR|=(1<<16);
	}
}
	return 0;
}
