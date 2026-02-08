# Application Guide — How the App Works

## Overview

The application implements a UART-controlled mode machine that allows the user to switch between multiple LED behaviors at runtime without resetting the system. The application logic runs inside a single main loop and coordinates GPIO, UART, and timing through driver APIs.


## Application States / Modes

The application operates in one of the following modes, selected via UART input:

-> Mode 0 – OFF: LED remains turned OFF.

-> Mode 1 – Blink: LED toggles at a fixed interval.

-> Mode 2 – Breathe: LED brightness smoothly increases and decreases using a software timing loop.

-> Mode 3 – Pattern: LED blinks in a predefined on/off pattern.

-> Mode 4 – Game: A simple reaction game where the user responds to a UART prompt.

Each mode represents a distinct application state.

## Task Flow / State Machine

System Start </br>
     ↓</br>
Print UART Help Menu</br>
     ↓</br>
Wait for UART Command</br>
     ↓</br>
Update Current Mode</br>
     ↓</br>
Execute Mode Behavior</br>
     ↺ (loop continues without reset)</br>





## Timing Behavior

Timing for blink, breathe, and pattern modes is implemented using software delays within the application loop. These delays control LED toggle rates and brightness transitions. The timing is blocking but sufficient for demonstrating mode behavior in a single-task system.


## Driver Orchestration

The application layer does not access hardware directly. Instead:

--> UART APIs are used to receive user commands and display status messages.

--> GPIO APIs are used to control the LED state.

--> Timing behavior is managed through a delay utility function.



## Edge Cases and Error Handling

--> Invalid UART input: Characters outside the defined mode commands are ignored.

--> Mode switching: Mode changes take effect immediately without requiring a reset.

--> Repeated commands: Re-selecting the same mode does not disrupt execution.

--> Blocking delays: While delays are blocking, UART input is still checked between mode executions.

## Design Rationale

This application design was chosen for simplicity, clarity, and ease of demonstration. It clearly shows how application logic can manage multiple operational states while remaining independent of hardware-specific details, making it easy to extend with additional modes, timers, or an RTOS in the future.




















