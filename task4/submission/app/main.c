#include "ch32v00x.h"
#include "gpio.h"
#include "uart.h"

#define LED_PIN GPIO_Pin_6   // PC6 LED

int mode = 0;


void delay_ms(int ms)
{
    for (int i = 0; i < ms * 8000; i++)
        __asm volatile ("nop");
}


void print_help(void)
{
    uart_print("\r\n=== UART MODE MACHINE ===\r\n");
    uart_print("0 : LED OFF\r\n");
    uart_print("1 : Blink\r\n");
    uart_print("2 : Breathe\r\n");
    uart_print("3 : Pattern\r\n");
    uart_print("4 : Game\r\n");
    uart_print("h : Help\r\n");
}



void mode_blink(void)
{
    gpio_toggle(LED_PIN);
    delay_ms(500);
}

void mode_breathe(void)
{
   
    for (int i = 0; i < 50; i++)
    {
        gpio_set(LED_PIN);
        delay_ms(i);
        gpio_clear(LED_PIN);
        delay_ms(50 - i);
    }
}

void mode_pattern(void)
{
    gpio_set(LED_PIN);
    delay_ms(100);
    gpio_clear(LED_PIN);
    delay_ms(100);

    gpio_set(LED_PIN);
    delay_ms(300);
    gpio_clear(LED_PIN);
    delay_ms(300);
}

void mode_game(void)
{
    uart_print("GAME: Press 't' fast!\r\n");

    delay_ms(2000);          
    gpio_set(LED_PIN);      

    while (1)
    {
        if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE))
        {
            char c = uart_read_char();
            if (c == 't')
            {
                gpio_clear(LED_PIN);
                uart_print("Good reaction!\r\n");
                mode = 0;    // back to OFF
                return;
            }
        }
    }
}

int main(void)
{
    gpio_init(LED_PIN, GPIO_OUTPUT);
    uart_init();

    print_help();

    while (1)
    {
    
        if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE))
        {
            char cmd = uart_read_char();

            if (cmd >= '0' && cmd <= '4')
            {
                mode = cmd - '0';
                uart_print("Mode changed\r\n");
            }
            else if (cmd == 'h')
            {
                print_help();
            }
        }

      
        if (mode == 0)
        {
            gpio_clear(LED_PIN);
        }
        else if (mode == 1)
        {
            mode_blink();
        }
        else if (mode == 2)
        {
            mode_breathe();
        }
        else if (mode == 3)
        {
            mode_pattern();
        }
        else if (mode == 4)
        {
            mode_game();
        }
    }
}

