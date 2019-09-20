const int speaker = 8;
const int d_pitch = A1;
const int d_gap = A0; 

void setup() {
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {


  //Serial.println(pitch);
  int pitch = analogRead(d_pitch);
  tone(speaker, pitch);
  pitch = analogRead(d_pitch);
  pitch = map(pitch, 0, 1023, 100, 1000);
  int gap = analogRead(d_gap);
  gap = map(gap, 0, 1023, 0, 2500);
  delay(gap);
  noTone(speaker);
  delay(gap);
}
