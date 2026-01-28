# RP2040 Programmable Makropad  
**6 Buttons • Mode Key • Encoder • OLED • PCB • 3D Printed Case**

This project is a **fully programmable Makropad** based on the **Seeed XIAO RP2040**.  
All buttons and the rotary encoder are **assigned on the PC**, not fixed in firmware.

The mode switching is done using a **normal mechanical keyboard switch**, identical to the other buttons.

---

## ✨ Features

- 6 mechanical keyboard switches  
- 1 mechanical keyboard switch as **Mode key**  
- 2 functions per button using the mode key  
- Rotary encoder (no click), PC-assignable  
- OLED display showing current mode  
- USB HID device (keyboard emulation)  
- Free PC software (AutoHotkey)  
- Custom PCB  
- 3D printed enclosure  

---

## 📁 Project Structure


---

## 🔌 Electronics

### Microcontroller
- **Seeed Studio XIAO RP2040**

### Inputs
- 6 × Mechanical keyboard switches (momentary)
- 1 × Mechanical keyboard switch (Mode key)
- 1 × Rotary encoder (A/B only, no push button)

### Output
- 1 × I²C OLED Display (128×64)

### Mechanical
- 4 × M3x5mx4mm heatset inserts
- 4 × M3x16mm screws
- 1 × 3d-printed Box
- 1 × PCB

All switches work exactly the same electrically.

---

## 🧷 Pin Assignment

### Buttons
| Function | GPIO |
|--------|------|
| Button 1 | GPIO 28 |
| Button 2 | GPIO 29 |
| Button 3 | GPIO 0 |
| Button 4 | GPIO 1 |
| Button 5 | GPIO 2 |
| Button 6 | GPIO 4 |

### Mode Key (Mechanical Switch)
| Function | GPIO |
|--------|------|
| Mode Button | GPIO 3 |

(All switches connect to **GND**, internal pull-ups are used)


---

### Rotary Encoder
| Signal | GPIO |
|------|------|
| A | GPIO 6 |
| B | GPIO 7 |

---

### OLED Display (I²C)
| Signal | GPIO |
|------|------|
| SDA | GPIO 26 |
| SCL | GPIO 27 |


<img width="601" height="824" alt="Circuit diagram" src="https://github.com/user-attachments/assets/740a71b3-1ff4-48f9-bc8d-6027682f144f" />


<img width="716" height="566" alt="PCB" src="https://github.com/user-attachments/assets/c375da47-4e1f-46ed-bf93-26b88f67f15b" />


---

## 🧠 How It Works

- The RP2040 acts as a **USB HID keyboard**
- Each button sends a **unique key combination**
- The **mode key acts as a layer switch**
- When the mode key is pressed, all buttons and the encoder change their function
- The encoder sends different key events depending on rotation direction and mode
- The OLED displays the currently active mode

➡️ No macros are hardcoded in the firmware.

---

## 💻 PC Software

- **AutoHotkey (free & open-source)**
- Script file: `Test Script.ahk`

The script maps received key combinations to actions such as:
- Application control
- Media keys
- System shortcuts
- Custom scripts

All changes are done on the PC side.

---

## 🧾 Bill of Materials (BOM)

### Electronics
| Quantity | Part |
|--------|------|
| 1 | Seeed XIAO RP2040 |
| 7 | Mechanical keyboard switches (MX-compatible) |
| 1 | Rotary encoder |
| 1 | 0.91 inch OLED displays |
| 1 | Custom PCB |
| - | Pin headers / wiring |

---

### Mechanical
| Quantity | Part |
|--------|------|
| 1 | 3D printed case – top |
| 1 | 3D printed case – bottom |
| 1 | 3D printed case – switch holder |
| 1 | Encoder knob |
| 7 | Blank DSA keycaps |
| 4 | Screws (M3x16mm) |
| 4 | Heatset inserts (M3x5mx4mm) |


---

## 🖨️ 3D Printed Case

- Files located in `/CAD`
- Designed for:
  - XIAO RP2040
  - Custom PCB
  - Mechanical keyboard switches
  - OLED display
  - Rotary encoder
- Recommended filament: **PLA or PETG**
- Printing orientation: flat on bed
- Supports: Required for the lid and the switch holder


<img width="743" height="575" alt="3D model" src="https://github.com/user-attachments/assets/f4cd8f48-4f7b-4f7c-bfca-46a6c5788267" />


---

## 🧪 Setup Instructions

1. Solder all switches and components onto the PCB  
2. Flash `RP2040 Code.ino` using Arduino IDE  
3. Connect the Makropad via USB  
4. Install AutoHotkey  
5. Run `Test Script.ahk`  
6. Assign functions in the script  
7. Hold or press the mode key to access second-layer functions  

---

## 🔧 Customization Ideas

- Add more layers
- Display active functions on the OLED
- Multiple AutoHotkey profiles
- Different layouts for:
  - Gaming
  - Video editing
  - Streaming
  - CAD

---

## 📜 License

This project is licensed under the **Apache License 2.0**.

---

## 📷 Media

Add images of:
- PCB (front and back)
- Assembled Makropad
- 3D printed enclosure
- OLED in operation

---

## ⭐ Notes

- Firmware remains generic
- All logic is PC-controlled
- Easy to modify and extend

---

**If you like this project, consider starring the repository ⭐**
