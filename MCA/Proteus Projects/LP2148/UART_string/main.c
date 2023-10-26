#include<lpc214x.h>
#include <stdlib.h>
#include <stdio.h>
#include"uart.h"
int main()
{
	int index = 0;
	int index1 = 0;
	unsigned char name[20];
	set_pll();
	UART0_init();
	while(1)
	{
		
		do
		{
			
			name[index]=UART0_RxChar();
				
		}while(index++<10);
		name[index] = '\n';
		index = 0;
		while(name[index]!='\n')
		{
				UART0_TxChar(name[index++]);
       // printf("hi %s",name);
		}
		index=0;
}
		
	
	
}