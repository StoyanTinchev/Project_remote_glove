#include <SoftwareSerial.h>
int state = 0;

SoftwareSerial bt(14, 15);
void setup() {
  bt.begin(38400);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() 
{
  if(bt.available()>0)
  {
    state = bt.read(); // assign incoming data to variable state
    Serial.write(state);
  }
}
