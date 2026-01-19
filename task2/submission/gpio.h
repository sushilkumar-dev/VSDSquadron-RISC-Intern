#ifndef GPIO_H
#define GPIO_H

void gpio_init(void);
void gpio_set(void);
void gpio_clear(void);

void uart_init(void);
void uart_print(const char *msg);

#endif

