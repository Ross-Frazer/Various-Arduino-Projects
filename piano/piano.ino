const int speaker = 9;
const int B_C = 2;
const int B_D = 3;
const int B_E = 4;
const int B_G = 5;
const int B_A = 6;

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_A4  440

void setup() {
}

void loop() {
  while(digitalRead(B_C))
    tone(speaker, NOTE_C4);
  while(digitalRead(B_D))
    tone(speaker, NOTE_D4);
  while(digitalRead(B_E))
    tone(speaker, NOTE_E4); 
  while(digitalRead(B_G))
    tone(speaker, NOTE_G4); 
  while(digitalRead(B_A))
    tone(speaker, NOTE_A4);
  noTone(speaker);  
}
