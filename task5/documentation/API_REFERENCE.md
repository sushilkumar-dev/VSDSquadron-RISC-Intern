# API Reference — Driver Documentation

## GPIO Driver APIs

    void gpio_init(int pin, int mode);

### Purpose:

Configures the specified GPIO pin as either input or output.

### Parameters:

--> pin – GPIO pin to configure

--> mode – Direction of the pin (input or output)

### Return Value:

None

### Constraints / Notes:

--> GPIO port clock must be enabled internally

--> Pin must belong to the supported GPIO port

### Example Usage:

    gpio_init(GPIO_Pin_6, GPIO_OUTPUT);

***

### gpio_set()

    void gpio_set(int pin);

### Purpose:

Drives the selected GPIO pin to logic HIGH.

Example Usage:

    gpio_set(GPIO_Pin_6);


***

### gpio_clear()

    void gpio_clear(int pin);

### Purpose:
Drives the selected GPIO pin to logic LOW.

### Example Usage:

    gpio_clear(GPIO_Pin_6);


***

### gpio_toggle()

    void gpio_toggle(int pin);

### Purpose:
Changes the GPIO pin state from HIGH to LOW or LOW to HIGH.

### Example Usage:

    gpio_toggle(GPIO_Pin_6);

***


## UART Driver APIs

### uart_init()

    void uart_init(void);

### Purpose:

Initializes UART for serial communication with a host system.

### Constraints / Notes:

--> Uses USART1

--> TX pin: PD5

--> Baud rate fixed at 9600

### Example Usage:

    uart_init();


***

## uart_print()

    void uart_print(const char *msg);

### Purpose:
Sends text messages over UART for logging and user interaction.

### Example Usage:

    uart_print("Mode changed\r\n");

***

## uart_read_char()

    char uart_read_char(void);


### Purpose:
Reads a single character from UART input, typically used for command parsing.

### Constraints / Notes:

--> Blocking function

--> Should be used carefully inside loops

### Example Usage:

    char cmd = uart_read_char();


***

## Timer / Delay Utility

### delay_ms()

    void delay_ms(int ms);

### Purpose:
Creates a simple time delay used for blink, pattern, and breathe modes.

### Constraints / Notes:

--> Blocking delay

--> Not suitable for power-efficient or real-time applications

### Example Usage:

    delay_ms(500);














































