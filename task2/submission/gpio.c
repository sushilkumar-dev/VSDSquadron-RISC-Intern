#include "ch32v00x.h"
#include "gpio.h"

/* -------- UART LOW LEVEL -------- */
static void uart_send_char(char c)
{
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, c);
}

/* UART init: USART1 TX on PD5 */
void uart_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD |
                           RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef gpio;

    /* PD5 -> USART1 TX */
    gpio.GPIO_Pin = GPIO_Pin_5;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    USART_InitTypeDef uart;
    uart.USART_BaudRate = 9600;
    uart.USART_WordLength = USART_WordLength_8b;
    uart.USART_StopBits = USART_StopBits_1;
    uart.USART_Parity = USART_Parity_No;
    uart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart.USART_Mode = USART_Mode_Tx;

    USART_Init(USART1, &uart);
    USART_Cmd(USART1, ENABLE);
}

/* Print string */
void uart_print(const char *msg)
{
    while(*msg)
    {
        uart_send_char(*msg++);
    }
}

/* -------- GPIO (LED) -------- */
void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_6;          
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOD, &gpio);
}

void gpio_set(void)
{
    GPIO_SetBits(GPIOD, GPIO_Pin_6);
}

void gpio_clear(void)
{
    GPIO_ResetBits(GPIOD, GPIO_Pin_6);
}

