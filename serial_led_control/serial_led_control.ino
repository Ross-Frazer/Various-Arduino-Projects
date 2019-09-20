const int LED_B = 11;
const int LED_G = 10;
const int LED_R = 9;

int R_val = 0;
int G_val = 0;
int B_val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  while (Serial.available() > 0)
  {
    R_val = Serial.parseInt();
    G_val = Serial.parseInt();
    B_val = Serial.parseInt();

    if (Serial.read() == '\n')
    {
      analogWrite(LED_R, R_val);
      analogWrite(LED_G, G_val);
      analogWrite(LED_B, B_val);
    }
  }
}
