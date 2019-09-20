const int motor = 9;
const int pot = 0;
int val =0;

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(motor, val);
  Serial.println(val);
}
