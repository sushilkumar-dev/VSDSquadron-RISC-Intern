#ifndef UART_H
#define UART_H

void uart_init(void);
void uart_print(const char *msg);
char uart_read_char(void);

#endif

