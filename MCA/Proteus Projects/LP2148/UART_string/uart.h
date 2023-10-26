#ifndef _UART_H_
#define _UART_H_

void set_pll(void);
void UART0_init(void);
unsigned char UART0_RxChar(void);
void UART0_TxChar(char);
#endif