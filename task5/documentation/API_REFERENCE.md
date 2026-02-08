# API Reference — Driver Documentation

## 1.GPIO Driver APIs

        void gpio_init(int pin, int mode);

## Purpose:

Configures the specified GPIO pin as either input or output.

## Parameters:

--> pin – GPIO pin to configure

--> mode – Direction of the pin (input or output)

## Return Value:

None

## Constraints / Notes:

--> GPIO port clock must be enabled internally

--> Pin must belong to the supported GPIO port

## Example Usage:

        gpio_init(GPIO_Pin_6, GPIO_OUTPUT);


