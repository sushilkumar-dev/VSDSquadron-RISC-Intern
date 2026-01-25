#include "ch32v00x.h"
#include "gpio.h"
#include "uart.h"

#define LED_PIN     GPIO_Pin_6   // PC6 LED
#define BUTTON_PIN  GPIO_Pin_7   // PC7 Button

void delay_ms(int ms)
{
    for (int i = 0; i < ms * 8000; i++)
        __asm volatile ("nop");
}

int main(void)
{
    gpio_init(LED_PIN, GPIO_OUTPUT);
    gpio_init(BUTTON_PIN, GPIO_INPUT);

    uart_init();
    uart_print("System started\r\n");


    while (1)
    {
        int current_state = gpio_read(BUTTON_PIN);

        if (current_state == 0)
        {
            gpio_toggle(LED_PIN);
            uart_print("Button pressed\r\n");
            delay_ms(300);   // simple delay
        }
        else if(current_state == 1)
        {
            gpio_clear(LED_PIN);
        }

    }
}

