### Task 2 - VSDSquadron Mini Board Bring-Up, GPIO & UART Validation

In this implementation, a simple embedded firmware was developed for the VSDSquadron board to demonstrate basic GPIO and UART functionality. The firmware uses a modular structure where hardware control logic is separated into a dedicated firmware file, while the application logic resides in the main file. An LED connected to a GPIO pin is toggled periodically, and simple status messages are transmitted over UART to verify successful firmware execution and board bring-up.
