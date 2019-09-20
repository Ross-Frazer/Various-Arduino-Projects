const int POT = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  delay(500);
  //val = map(val, 820, 1023, 0, 255);
  Serial.println(val);
}
