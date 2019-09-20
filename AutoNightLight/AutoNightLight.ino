const int RLED = 11;
const int LIGHT = 0;
const int MIN_LIGHT = 120;
const int MAX_LIGHT = 500;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RLED, OUTPUT);
  pinMode(LIGHT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(LIGHT);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  val = constrain(val, 0, 255);
  analogWrite(RLED, val);
}
