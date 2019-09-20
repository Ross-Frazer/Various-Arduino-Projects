#include <Wire.h>
#define TEMP_ADDR 72

#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

byte degree[8] = {B00110, B01001, B01001, B00110, B00000, B00000, B00000, B00000};
byte fan_on[8] = {B00100, B10101, B01110, B11111, B01110, B10101, B00100, B00000};
byte fan_off[8] = {B00100, B00100, B00100, B11111, B00100, B00100, B00100, B00000};

const int speaker = 8;
const int down_button = 9;
const int up_button = 10;
const int fan = 11;

boolean lastDownTempButton = LOW;
boolean currentDownTempButton = LOW;
boolean lastUpTempButton = LOW;
boolean currentUpTempButton = LOW;

int set_temp = 20;
boolean one_time = false;

void setup() {
  pinMode(fan,OUTPUT);

  Wire.begin();
  lcd.begin(16,2);

  lcd.createChar(0, degree);
  lcd.createChar(1, fan_on);
  lcd.createChar(2, fan_off);

  lcd.setCursor(0,0);
  lcd.print("Current:");
  lcd.setCursor(10,0);
  lcd.write((byte)0);
  lcd.setCursor(11,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Set:");
  lcd.setCursor(10,1);
  lcd.write((byte)0);
  lcd.setCursor(11,1);
  lcd.print("C");
  lcd.setCursor(15,1);
  lcd.write(1); 
}

boolean debounce(boolean last, int pin){
  boolean current = digitalRead(pin);
  if (last != current){
    delay(5);
    current = digitalRead(pin);
  }
  return current;
}

void loop() {
  Wire.beginTransmission(TEMP_ADDR);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(TEMP_ADDR, 1);
  while(Wire.available() == 0);
  int c = Wire.read();
  lcd.setCursor(8,0);
  lcd.print(c);

  currentDownTempButton = debounce(lastDownTempButton, down_button);
  currentUpTempButton = debounce(lastUpTempButton, up_button);
  if (lastDownTempButton==LOW && currentDownTempButton==HIGH){
    set_temp--;
  }
  if (lastUpTempButton==LOW && currentUpTempButton==HIGH){
    set_temp++;
  }

  lcd.setCursor(8,1);
  lcd.print(set_temp);
  lastDownTempButton = currentDownTempButton;
  lastUpTempButton = currentUpTempButton;

  if (c >= set_temp){
    if(!one_time){
      tone(speaker,400);
      delay(500);
      one_time = true;
    }
    else{
      noTone(speaker);
    }
    digitalWrite(fan, HIGH);
    lcd.setCursor(15,1);
    lcd.write(1);
  }
  else{
    noTone(speaker);
    one_time = false;
    digitalWrite(fan, LOW);
    lcd.setCursor(15,1);
    lcd.write(2);
  }
}
