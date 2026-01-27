#include <Keyboard.h>
#include <Encoder.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* ===== DISPLAY ===== */
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/* ===== BUTTONS ===== */
const int buttonPins[6] = {28, 29, 0, 1, 2, 4};

const uint8_t keyMap[2][6] = {
  {KEY_F13, KEY_F14, KEY_F15, KEY_F16, KEY_F17, KEY_F18}, // Modus 0
  {KEY_F19, KEY_F20, KEY_F21, KEY_F22, KEY_F23, KEY_F24}  // Modus 1
};

bool lastButtonState[6];

/* ===== MODE SWITCH ===== */
#define MODE_PIN 3
int mode = 0;
int lastMode = -1;

/* ===== ENCODER ===== */
Encoder encoder(6, 7);
long lastEncPos = 0;

const uint8_t encRight[2] = {KEY_F25, KEY_F27};
const uint8_t encLeft [2] = {KEY_F26, KEY_F28};

/* ===== SETUP ===== */
void setup() {
  Keyboard.begin();

  for (int i = 0; i < 6; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    lastButtonState[i] = HIGH;
  }

  pinMode(MODE_PIN, INPUT_PULLUP);

  Wire.setSDA(26);
  Wire.setSCL(27);
  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  updateDisplay();
}

/* ===== LOOP ===== */
void loop() {
  handleMode();
  handleButtons();
  handleEncoder();
}

/* ===== FUNCTIONS ===== */

void handleMode() {
  mode = (digitalRead(MODE_PIN) == LOW) ? 1 : 0;
  if (mode != lastMode) {
    updateDisplay();
    lastMode = mode;
  }
}

void handleButtons() {
  for (int i = 0; i < 6; i++) {
    bool cur = digitalRead(buttonPins[i]);
    if (lastButtonState[i] == HIGH && cur == LOW) {
      Keyboard.press(keyMap[mode][i]);
      delay(4);
      Keyboard.release(keyMap[mode][i]);
    }
    lastButtonState[i] = cur;
  }
}

void handleEncoder() {
  long pos = encoder.read() / 4;
  if (pos != lastEncPos) {
    if (pos > lastEncPos) {
      Keyboard.press(encRight[mode]);
      delay(3);
      Keyboard.release(encRight[mode]);
    } else {
      Keyboard.press(encLeft[mode]);
      delay(3);
      Keyboard.release(encLeft[mode]);
    }
    lastEncPos = pos;
  }
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("MODE ");
  display.print(mode);
  display.display();
}
