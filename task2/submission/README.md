# Task 2 - VSDSquadron Mini Board Bring-Up, GPIO & UART Validation

## 2.1 Overview 

In this implementation, a simple embedded firmware was developed for the VSDSquadron board to demonstrate basic GPIO and UART functionality. The firmware uses a modular structure where hardware control logic is separated into a dedicated firmware file, while the application logic resides in the main file. An LED connected to a GPIO pin is toggled periodically, and simple status messages are transmitted over UART to verify successful firmware execution and board bring-up.

## 2.2 GPIO pin chosen and why

GPIO Pins Used: PD6 and PD5 </br>
PD6 was used to control the onboard LED for visual GPIO validation, while PD5 was configured as the USART1 TX pin to transmit UART messages for firmware execution verification.

## 2.3 UART message description

UART was used to transmit simple status messages indicating firmware startup and LED state changes, allowing real-time verification of successful firmware execution through a serial terminal.

## 2.4 How to build and flash (short steps)

--> Navigate to the project directory in the terminal.</br>

--> Run pio run to build and generate the firmware binary.</br>

--> Run pio run -t upload to flash the firmware onto the board.</br>

--> Reset the board to start firmware execution.</br>

--> Verify output by printing texts in terminal (UART visible on /dev/ttyACM0)
