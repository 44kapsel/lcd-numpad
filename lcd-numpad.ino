#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define I2C_ADDR 0x27 // Defining the LCD I2C address

LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2); // Initialize LCD with I2C address, columns, and rows

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};

byte rowPins[ROWS] = {10, 11, 12, 13}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9};    // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);        // Initialize the LCD
  lcd.backlight();         // Turn on the backlight
  lcd.setCursor(0, 0);     // Set cursor to the first column, first row
  lcd.print("Press a key"); // Print a welcome message
  delay(2000);
}

void loop() {
  char keypressed = keypad.getKey(); // Get the key pressed
  if (keypressed != NO_KEY) {
    lcd.clear();
    lcd.print(keypressed); // Display the key pressed
    // optional:
    Serial.println(keypressed);
  }
}
