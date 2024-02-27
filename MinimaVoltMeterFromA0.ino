#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define BACKLIGHT 10

void setup() {
  //analogReadResolution(12); // Set 12 to 4096, 14 to 16383 (default is 10... 1023)
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);
  lcd.begin(16, 2);
}

void loop() {
  int analogValue = analogRead(A0);
  float voltageValue = mapFloat(analogValue, 0, 1023, 0, 5);  //10 bit 1023, 12 bit 4096, 14 bit 16383

  lcd.setCursor(0, 0);
  lcd.print(voltageValue);
  delay(200);
  lcd.print("    ");
  delay(200);
}


float mapFloat(float value, float fromLow, float fromHigh, float toLow, float toHigh) {
  return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}
