#include <SPI.h>

const int SS1 = 10;
const int SS2 = 9;

const int SPEAKER = 8;
int freq = 100;

const byte REG0 = B00000000;
const byte REG1 = B00010000;

void setup() {
  pinMode(SS1, OUTPUT);
  pinMode(SS2, OUTPUT);

  SPI.begin();
}

void setREG(int SS, int reg, int level){
  digitalWrite(SS, LOW);
  SPI.transfer(reg);
  SPI.transfer(level);
  digitalWrite(SS, HIGH);
}

void loop() {
  tone(SPEAKER, freq);
  for (int i=0; i<=128; i++){
    setREG(SS1, REG0, i);
    setREG(SS1, REG1, i);
    setREG(SS2, REG0, i);
    setREG(SS2, REG1, i);
    delay(1);
  }
  delay(150);
  for (int i=128; i>=0; i--){
    setREG(SS1, REG0, i);
    setREG(SS1, REG1, i);
    setREG(SS2, REG0, i);
    setREG(SS2, REG1, i);
    delay(1);
  }
  freq = freq+100;
  if (freq > 800) freq = 100;
}
