# System Architecture — Project-11
**Overview**

The system is designed using a layered firmware architecture, where low-level hardware control is separated from application logic. This structure improves readability, maintainability, and scalability while following embedded firmware best practices.


![Untitled drawing(2)](https://github.com/user-attachments/assets/ab854322-2ca0-443a-9445-c7cc563df54e)

***

# Separation of Responsibilities
**Drivers**

The driver layer contains all hardware-specific code, including GPIO control for LEDs, UART communication for user interaction, and timing logic using software delays. Drivers expose clean APIs and directly interact with hardware registers.

**Application**

The application layer (main.c) implements the UART-controlled mode machine. It selects and executes different modes such as blink, breathe, pattern, and game using only driver APIs, without direct hardware access.

**Scheduler / Event System**

No RTOS or scheduler is used in this project. Mode execution and UART command handling are managed using a simple main loop with polling, which is sufficient for the project’s scope.

***

# Data Flow and Control Flow

--> User sends commands via UART from a serial terminal

--> UART driver receives input and passes it to the application

--> Application updates the current mode based on the command

--> Application invokes GPIO and timing APIs to execute the selected mode

--> Status messages are sent back to the user via UART


# Architecture Rationale

This architecture was chosen to enforce clean separation between hardware control and application logic, making the firmware easy to understand, debug, and extend. It mirrors industry-standard embedded design practices and allows future enhancements such as hardware timers, PWM, or an RTOS without major restructuring.














