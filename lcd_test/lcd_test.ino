#include <LiquidCrystal.h>

LiquidCrystal lcd (2,3,4,5,6,7);

int time = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Ross' Display");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print(time);
  delay(1000);
  time++;
}
