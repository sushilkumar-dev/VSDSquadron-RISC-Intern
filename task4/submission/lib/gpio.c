#include "ch32v00x.h"
#include "gpio.h"

void gpio_init(int pin, int mode)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = pin;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOC, &gpio);
}

void gpio_set(int pin)
{
    GPIO_SetBits(GPIOC, pin);
}

void gpio_clear(int pin)
{
    GPIO_ResetBits(GPIOC, pin);
}

void gpio_toggle(int pin)
{
    if (GPIO_ReadOutputDataBit(GPIOC, pin))
        GPIO_ResetBits(GPIOC, pin);
    else
        GPIO_SetBits(GPIOC, pin);
}

