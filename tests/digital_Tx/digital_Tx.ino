#include <SoftwareSerial.h>
#define button 8

int buttonState=0;
SoftwareSerial bt(3, 4);
void setup() 
{
  bt.begin(38400);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState == HIGH)
  {
    bt.print('1'); // Sends '1' to serialout
    Serial.print(1);
  }
  else
  {
    bt.print('0');
    Serial.print(0);
  }
}
