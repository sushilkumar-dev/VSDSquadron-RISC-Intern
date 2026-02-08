# Demo Guide — How to Run and Verify

This guide explains how to flash the firmware, interact with the application, and verify correct behavior on the VSDSquadron Mini board.

***

### 1. Flashing Steps

1.1 Open a terminal and navigate to the project directory.

1.2 Initialize the project (if not already done):

    pio project init --board vsdsquadronMini


1.3 Build the firmware:

    pio run


1.4 Connect the VSDSquadron Mini board to the system via USB.

1.5 Flash the firmware:

    pio run -t upload


After flashing, the firmware starts running automatically.

***

### 2. UART Settings

 -> Baud Rate: 9600

 -> Data Bits: 8

 -> Parity: None

 -> Stop Bits: 1

 -> Flow Control: None

Connect VSD board to laptop


***

### 3. Open Serial Terminal

Use any serial terminal. Example using minicom:

    minicom -b 9600 -D /dev/ttyACM0

(Replace /dev/ttyACM0 with the correct serial port if needed.)

***

### 4. UART Commands to Type

After reset, type the following commands in the serial terminal:

h   → Show help menu c
0   → LED OFF mode </br>
1   → Blink mode </br>
2   → Breathe mode </br>
3   → Pattern mode </br>
4   → Game mode  </br>

***

### 5. Expected UART Output

On startup:

=== UART MODE MACHINE === </br>
0 : LED OFF </br>
1 : Blink </br>
2 : Breathe </br>
3 : Pattern </br>
4 : Game </br>
h : Help </br>


***

### 6. What to Observe on Hardware

--> Mode 0: LED remains OFF

--> Mode 1: LED blinks at a steady rate

--> Mode 2: LED brightness smoothly increases and decreases

--> Mode 3: LED blinks in a visible pattern

--> Mode 4: LED turns ON after a delay and turns OFF when the correct key is pressed

--> Mode changes occur without resetting the board.

***

### 7. Verification Checklist

--> Firmware flashes successfully

--> UART help menu is displayed

--> All modes respond correctly to UART commands

--> LED behavior matches the selected mode




