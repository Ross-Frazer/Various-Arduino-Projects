const int bridge = 9;
const int gate1 = 3;
const int gate2 = 4;
const int pot = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);
}
