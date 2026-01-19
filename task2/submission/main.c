#include "ch32v00x.h"
#include "gpio.h"

void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 8000; i++)
    {
        __asm volatile ("nop");
    }
}

int main(void)
{
    gpio_init();
    uart_init();

    uart_print("Hello from VSDSquadron!\r\n");

    while(1)
    {
        gpio_set();
        uart_print("LED_ON\r\n");
        delay_ms(500);

        gpio_clear();
        uart_print("LED_OFF\r\n");
        delay_ms(500);
    }
}

