#include<lpc214x.h>
#include"uart.h"

void set_pll(void)
{
  PLL0CON=0x01;             // PPLE=1 & PPLC=0 so it will be enabled  but not connected after FEED sequence
  PLL0CFG=0x24;          // set the multipler to 5 (i.e actually 4) i.e 12x5 = 60 Mhz (M - 1 = 4), Set P=2 since we want FCCO in range So , Assign PSEL =01 in PLL0CFG as per the table.
  PLL0FEED=0XAA;          //feed
  PLL0FEED=0X55;
  while((PLL0STAT&(1<<10))==0);      // check whether PLL has locked on to the  desired freq by reading the lock bit in the PPL0STAT register
  PLL0CON=0x03;          //enable & connect pll
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  VPBDIV = 0x01;          // PCLK is same as CCLK i.e 60Mhz
}

void UART0_init(void)
{
	PINSEL0 = PINSEL0 | 0x00000005;	/* Enable UART0 Rx0 and Tx0 pins of UART0 */
	U0LCR = 0x83;	 /* DLAB = 1, 1 stop bit, 8-bit character length */
	U0DLM = 0x01;	/* For baud rate of 9600 with Pclk = 15MHz */
	U0DLL = 0x87;		/* We get these values of U0DLL and U0DLM from formula */
	U0LCR = 0x03; 	/* DLAB = 0 */
}

unsigned char UART0_RxChar(void) /*A function to receive a byte on UART0 */
{
	while( (U0LSR & 0x01) == 0);	/*Wait till RDR bit becomes 1 which tells that receiver contains valid data */
		return U0RBR;
}

void UART0_TxChar(char ch) /*A function to send a byte on UART0 */
{
	while( (U0LSR & 0x40) == 0 );	/* Wait till THRE bit becomes 1 which tells that transmission is completed */
	U0THR = ch;
}
