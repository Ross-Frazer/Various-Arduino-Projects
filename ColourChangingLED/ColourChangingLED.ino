const int LED_B = 9;
const int LED_G = 10;
const int LED_R = 11;
const int BUTTON = 2;
boolean currentButton = LOW;
boolean lastButton = LOW;
int mode = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last){
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void setMode(int mode){
  if (mode == 1)                     //red
  {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_G, LOW);
  }
  else if (mode == 2)                //green
  {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_G, HIGH);
  }
  else if (mode == 3)                //blue
  {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_G, LOW);
  }
  else if (mode == 4)                //purple
  {
    digitalWrite(LED_R, 127);
    digitalWrite(LED_B, 127);
    digitalWrite(LED_G, 0);
  }
  else if (mode == 5)                //teal
  {
    digitalWrite(LED_R, 0);
    digitalWrite(LED_B, 127);
    digitalWrite(LED_G, 127);
  }
  else if (mode == 6)                //orange
  {
    digitalWrite(LED_R, 127);
    digitalWrite(LED_B, 0);
    digitalWrite(LED_G, 127);
  }
  else if (mode == 7)                //white
  {
    digitalWrite(LED_R, 85);
    digitalWrite(LED_B, 85);
    digitalWrite(LED_G, 85);
  }
  else                             //off
  {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_G, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    mode++;    
  }
  lastButton = currentButton;
  if (mode == 8) mode = 0;
  setMode(mode);
}
