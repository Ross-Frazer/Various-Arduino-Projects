const int LEDr = 11;
const int LEDg = 10;
const int LEDb = 9;
const int tsen = 0;
int tval = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDr, OUTPUT);
  pinMode(LEDg, OUTPUT);
  pinMode(LEDb, OUTPUT);
  pinMode(tsen, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tval = analogRead(tsen);
  Serial.println(tval);
  delay(500);

  if (tval <= 139)
  {
    digitalWrite(LEDb, HIGH);
    digitalWrite(LEDr, LOW);
    digitalWrite(LEDg, LOW);
  }
  else if (tval > 140 && tval < 146)
  {
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDr, LOW);
    digitalWrite(LEDg, HIGH);
  }
  else if (tval >= 147)
  {
    digitalWrite(LEDb, LOW);
    digitalWrite(LEDr, HIGH);
    digitalWrite(LEDg, LOW);
  }
}
