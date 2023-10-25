#include <lpc214x.h>
#include "Timer_h.h"

void delay_ms(uint32_t ms)
{
	T0CTCR = 0x00;
	T0TCR = 0x00;
	T0TC = 0;
	T0PC = 0;
	T0TCR = 0x02;
	T0PR = 59999;
	T0TCR = 0x01;
	while(T0TC<ms);
	T0TCR = 0x00;
}
void delay_us(uint32_t us)
{
	T0CTCR = 0x00;
	T0TCR = 0x00;
	T0TC = 0;
	T0PC = 0;
	T0TCR = 0x02;
	T0PR = 599;
	T0TCR = 0x01;
	while(T0TC<us);
	T0TCR = 0x00;
}	

