const int motor = 9;
const int pot = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(motor, val);
  Serial.println(val);
}
