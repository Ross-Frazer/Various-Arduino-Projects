const int EN = 9;
const int MC1 = 6;
const int MC2 = 3;
const int pot = A0;
int val = 0;
int velocity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  pinMode(pot, INPUT);
  brake();
}

void loop() {
  val = analogRead(pot);
  Serial.println(val);
  if (val > 562){
    velocity = map(val, 563, 1023, 0, 255);
    forward(velocity);
  }
  else if (val < 462){
    velocity = map(val, 461, 0, 0, 255);
    backward(velocity);
  }
  else brake();
}

////////////////////////////////////////////

void forward(int rate){
  //motor forward at given rate
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);
}

void backward(int rate){
  //motor forward at given rate
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  analogWrite(EN, rate);
}

void brake(){
  //motor forward at given rate
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  analogWrite(EN, HIGH);
}
