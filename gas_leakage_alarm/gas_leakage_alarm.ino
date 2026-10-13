#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns and 2 rows

// MQ-5 Gas Sensor pin
int gasSensorPin = A0;

// Buzzer pin
int buzzerPin = 8;

// Threshold for gas detection (adjust based on your environment)
int gasThresholdLow = 300;
int gasThresholdHigh= 400;

// Setup
void setup() {
  // Start the LCD
  lcd.begin(16, 2);
  lcd.print("Gas & Smoke Det.");

  // Setup buzzer pin
  pinMode(buzzerPin, OUTPUT);

  // Start serial communication for debugging
  Serial.begin(9600); // Adjusted baud rate for proper debug output

  delay(1000);  // Short delay to ensure LCD is initialized properly
  lcd.clear();
}

// Main loop
void loop() {
  // Read gas sensor value
  int gasLevel = analogRead(gasSensorPin);

  // Print sensor data to Serial Monitor for debugging
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  // Display gas level on LCD
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasLevel);

  // Check if the gas level exceeds the threshold
  if (gasLevel > gasThresholdLow) {
    // Trigger buzzer if gas level is high
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Gas Detected!");
  } else {
    // No gas detected, turn off buzzer
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("No Gas Detected");
  }

  // No delay here to make it more responsive
}
