const int CLOCK = 10;
const int LATCH = 9;
const int SER = 8;
const int IR = A0;

int rank[9] = {0,1,3,7,15,31,63,127,255};
int val;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop() {
  val = map(analogRead(IR), 0, 500, 0, 8);
  val = constrain(val, 0, 8);

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, MSBFIRST, rank[val]);
  digitalWrite(LATCH, HIGH);
  delay(10);
}
