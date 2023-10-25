#include<lpc214x.h>
#include "Timer_h.h"
#include "pll_init.h"
int main(void)
{
	PLL_Config();
	PINSEL0 = 0;
	IO0DIR |= 0x01;
	while(1)
	{
		IO0SET |=0x01;
		delay_ms(10);
		IO0CLR |=0x01;
		delay_ms(10);
	}
	return 0;
}
