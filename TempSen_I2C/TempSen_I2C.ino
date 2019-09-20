#include <Wire.h>
int temp_address = 72; 
const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

int vals[8] = {1,3,7,15,31,63,127,255};

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
  Wire.beginTransmission(temp_address);
  Wire.write(0);
  Wire.endTransmission(temp_address);

  Wire.requestFrom(temp_address, 1);
  while(Wire.available() == 0);
  int c = Wire.read();

  int graph = map(c, 20, 30, 0, 7);
  graph = constrain(graph, 0, 7);

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, MSBFIRST, vals[graph]);
  digitalWrite(LATCH, HIGH);
  
  int f = round(c*9.0/5.0 + 32.0);

  Serial.print(c);
  Serial.print("C,");
  Serial.print(f);
  Serial.print("F.");

  delay(500);
}
