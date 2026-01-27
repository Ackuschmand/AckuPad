# AckuPad
Ackupad – a compact, fully programmable macro pad with multiple buttons and a customizable encoder. Perfect for gaming, editing, or PC control, each button can have two functions, giving you maximum efficiency and control at your fingertips.






Ackupad – Programmable Macro Pad for Maximum Control

The Ackupad is a fully programmable macro pad for PC control, gaming, video editing, or any application that requires fast key sequences and versatile controls. It is compact, versatile, and ready to use once the PCB is assembled.

Features

6 Buttons + Toggle Switch: Each button can have two functions depending on the switch position.

Rotary Encoder: Fully customizable for volume, scrolling, zooming, or other functions.

User-Assembled PCB: All components must be soldered by you according to the provided PCB design.

3D-Printed Case: Sturdy, compact, and customizable; all CAD files included.

PC Compatibility: Works on Windows/Linux/Mac, sending keyboard inputs directly.

Flexible Firmware: Button functions and encoder behavior can be easily modified.

Repository Contents

/PCB – PCB design files, schematic, and assembly guide (components not pre-soldered)

/CAD – 3D printing files for the case (STL, STEP)

/Firmware – Arduino IDE project for Seeed XIAO RP2040, example code, libraries

Hardware

Required Components (to be soldered by the user):

Microcontroller: Seeed XIAO RP2040

6 Pushbuttons

1 Toggle Switch

1 Rotary Encoder

Resistors / other components per assembly guide

Wires for connections

GPIO Layout (XIAO RP2040):

Function	GPIO Pin
Button 1	28
Button 2	29
Button 3	0
Button 4	1
Button 5	2
Button 6	4
Toggle Switch	3
Encoder A/B	5 / 6
Software / Firmware

Arduino IDE:

Install the board definition for Seeed XIAO RP2040.

Open the firmware from the /Firmware folder.

Install required libraries (e.g., Keyboard.h or HID-Project).

Code Structure:

Each button checks the toggle switch state.

Depending on the switch, one of two functions is triggered.

The rotary encoder can control volume, scrolling, or other actions.

Example Functions:

Button 1 → Space

Toggle + Button 1 → Enter

Encoder → Volume up/down

Customization:

Functions can be freely changed or expanded.

Suitable for gaming, multimedia, or software control.

Usage

Solder all components onto the PCB according to the assembly guide.

Insert the XIAO RP2040 into the board.

Mount the PCB in the 3D-printed case.

Connect the Ackupad via USB to your PC.

Upload the firmware via Arduino IDE if needed.

Test buttons and encoder to ensure correct functionality.

Tips

Debouncing: Software debouncing is integrated in the firmware.

Case Customization: CAD files can be modified to adjust the design.

Expandability: Additional buttons, encoders, or LEDs can be added easily.

License

This project is licensed under the Apache License 2.0. You may copy, modify, or use the code commercially, provided you comply with the license terms.

Summary

The Ackupad combines multi-function buttons, a toggle switch, and a rotary encoder in a compact macro pad. PCB must be soldered by the user, and the case is 3D-printed. Ideal for gaming, video editing, or PC control – ready to use after assembly.
