# UART-Controlled Mode Machine

## Project Description:

This project implements a UART-controlled mode machine on the VSDSquadron Mini board, where multiple operating modes such as LED blink, breathe effect, pattern generation, and a simple reaction game can be selected dynamically through UART commands. The system allows mode switching without resetting the board and provides a UART help menu for user interaction, demonstrating clean integration of UART, GPIO, and timing logic using a modular and readable firmware design.

## Target Hardware:
VSDSquadron Mini (CH32V RISC-V based development board)

## Drivers Used:
This project uses the GPIO driver for LED control, the UART driver for mode selection and user interaction, and a Timer (software delay) for controlling timing behaviors such as blink and pattern modes. PWM is optional and not used in the current implementation.

## Folder structure

![Untitled drawing](https://github.com/user-attachments/assets/8e555304-4128-4eee-a363-5bf67917664b)

## Quick Start

1. Create a new project using pio project init --board vsdsquadronMini.

2. Copy all source files (main.c, gpio.c/h, uart.c/h) into the src folder.

3. Connect the VSDSquadron Mini board to the system via USB.

4. Build the firmware by running pio run.

5. Flash the firmware onto the board using pio run -t upload.

