const int CLOCK = 10;
const int LATCH = 9;
const int SER = 8;

int seq[14] = {1,2,4,8,16,32,64,128,64,32,16,8,4,2};

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  for(int i=0; i<14; i++){
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLOCK, MSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
