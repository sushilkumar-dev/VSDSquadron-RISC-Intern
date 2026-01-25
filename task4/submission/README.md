# UART-Controlled Mode Machine

## Project Description:

This project implements a UART-controlled mode machine on the VSDSquadron Mini board, where multiple operating modes such as LED blink, breathe effect, pattern generation, and a simple reaction game can be selected dynamically through UART commands. The system allows mode switching without resetting the board and provides a UART help menu for user interaction, demonstrating clean integration of UART, GPIO, and timing logic using a modular and readable firmware design.

## Drivers Used:

This project uses the GPIO driver for LED control, the UART driver for mode selection and user interaction, and a Timer (software delay) for controlling timing behaviors such as blink and pattern modes. PWM is optional and not used in the current implementation.

## API Summary (Key Functions):

--> gpio_init() – Configures a GPIO pin as input or output.

--> gpio_set() – Sets the selected GPIO pin to HIGH.

--> gpio_clear() – Sets the selected GPIO pin to LOW.

--> gpio_toggle() – Toggles the current state of the GPIO pin.

--> uart_init() – Initializes UART with the required baud rate and settings.

--> uart_print() – Sends text messages over UART to the serial terminal.

--> uart_read_char() – Reads a character received through UART for command input.

## Build + Flash Steps:

--> Open a terminal and navigate to the desired project directory.


<img width="692" height="405" alt="1" src="https://github.com/user-attachments/assets/dab0a3e9-2a54-4774-b598-0d00af47b1d8" /></br>

</br>

--> Initialize the PlatformIO project using</br>

        pio project init --board vsdsquadronMini


<img width="692" height="405" alt="2" src="https://github.com/user-attachments/assets/6df32935-fdea-46d7-964a-afc6195a61cb" /></br>

</br>

--> Place all source files inside the **src** folder


<img width="692" height="405" alt="3" src="https://github.com/user-attachments/assets/86876e06-8ca4-431c-9753-5545ca5bd9ae" /></br>

</br>

--> Run ***pio run*** to build the firmware.

        pio run

<img width="692" height="405" alt="4" src="https://github.com/user-attachments/assets/f089dcd1-e6df-43ae-a122-4a4129e638fa" /></br>

</br>

--> Connect the VSDSquadron board and run ***pio run -t upload*** to flash the firmware.

          pio run -t upload

<img width="692" height="405" alt="5" src="https://github.com/user-attachments/assets/8ad5d621-f321-4caf-b430-245fa2b09c59" /></br>


## UART settings (baud, port)

--> Open terminal and type 

        minicom -b 9600 -o -D /dev/ttyACM0



<img width="492" height="405" alt="6" src="https://github.com/user-attachments/assets/d454e258-57a7-4a23-acf2-187e326860c0" />










