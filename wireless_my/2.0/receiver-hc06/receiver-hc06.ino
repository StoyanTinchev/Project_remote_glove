#include "Mouse.h"
#include <SoftwareSerial.h>



int x, y;

SoftwareSerial mySerial(9, 8); // rx, tx
long serialA;
void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  Mouse.begin();
}

void loop() {

  if (mySerial.available() > 2)
  {
    serialA = mySerial.parseInt();
    Serial.println(serialA);
  }


  if (700 > serialA > 300)
  {
    Serial.println("xread");
    Serial.println(x);
    x = serialA-500;
  }


  if (serialA < 300)
  {
    Serial.println("yread");
    y = serialA;
    Serial.println(y);
  }
  Mouse.move(x, y);


  if (serialA == 70000)
  {
    Mouse.press(MOUSE_LEFT);
    delay(200);
  }
  else if (serialA == 80000)
    Mouse.release(MOUSE_LEFT);
    
  else if (serialA == 90000)
  {
    Mouse.press(MOUSE_RIGHT);
    delay(100);
    Mouse.release(MOUSE_RIGHT);
    delay(200);
  }
  delay(10);
}
