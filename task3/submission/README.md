# Advanced GPIO Library + Application

## Library Implemented

A simple GPIO library was implemented to abstract basic input and output operations such as initialization, read, set, clear, and toggle. This library hides hardware-specific details from the application layer.

## API List

The GPIO APIs include functions to initialize a pin as input or output, set or clear an output pin, toggle its state, and read the status of an input pin. These APIs provide a clean interface for GPIO control.

## Demo Application

The demo application reads a button input and toggles an LED whenever the button is pressed. UART messages are printed to indicate button press events and confirm firmware execution.

## Build and Flash

The firmware is built using PlatformIO by running pio run, which compiles the source code into a firmware binary. The binary is flashed onto the board using pio run -t upload.

## UART Configuration

UART communication is configured using USART1 with a baud rate of 9600. The TX pin (PD5) is connected to a USB-to-TTL converter to view messages on a serial terminal.
