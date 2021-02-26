#define dirPin 3
#define stepPin 4
#define enablePin 2

void setup() {

  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
}

void loop()
{
  int i = 0;
  digitalWrite(dirPin, HIGH);
//  digitalWrite(stepPin, HIGH);
  for (i = 0; i <= 700; i++) 
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(550);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(550);
  }
//
//  delay(1000);
//
//  digitalWrite(dirPin, LOW);
//  int a = 0;
//
//  for (a = 0; a <= 700; a++)
//  {
//    digitalWrite(stepPin, HIGH);
//    digitalWrite(stepPin, LOW);
//  }
//  delay(1000);
}
