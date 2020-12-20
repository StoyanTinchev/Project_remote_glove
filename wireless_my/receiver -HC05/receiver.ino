#include "Keyboard.h"
#include "Mouse.h"
#include <SoftwareSerial.h>

int x, y, flag = 0;

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


  if (20000 > serialA > 10000)
  {
    Serial.println("xread");
    Serial.println(x);
    x = serialA;
  }


  if (serialA < 10000)
  {
    Serial.println("yread");
    y = serialA;
    Serial.println(y);
  }
  Mouse.move(x, y);


  if (serialA == 80000 && flag == 0)
  {
    Mouse.press(MOUSE_LEFT);
    delay(200);
    flag = 1;
  }
  else if (serialA == 80000 && flag)
  {
    Mouse.release(MOUSE_LEFT);
    flag = 0;
  }
  else if (serialA == 90000)
  {
    Mouse.press(MOUSE_RIGHT);
    delay(100);
    Mouse.release(MOUSE_RIGHT);
    delay(200);
  }
  delay(10);
}
