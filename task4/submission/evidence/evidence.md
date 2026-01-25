# Verification:

--> The firmware was tested by selecting different modes through UART and observing corresponding LED behaviors such as blink, breathe, pattern, and game modes.</br>

--> UART communication, mode switching without reset, and GPIO control worked as expected during testing.</br>

--> The current implementation uses software delays instead of hardware timers or PWM, which limits timing accuracy and efficiency.</br>
