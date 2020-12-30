#include "Mouse.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(14, 15); // rx, tx


int x, y;
long serialA;
void setup() 
{
  Serial.begin(38400);
  mySerial.begin(38400);
  Mouse.begin();
}

void loop() {

  for(int i=0; i<2; ++i)
  {
    if (mySerial.available() > 0)
      serialA = mySerial.parseInt();
    if(serialA>1200)
      break;
    if (serialA<1200 && serialA > 800)
    {
      Serial.println("xread");
      Serial.println(x);
      x = serialA-1000;
      
    }
    else if (serialA<700 && serialA > 300)
    {
      Serial.println("yread");
      Serial.println(y);
      y = serialA-500;
    }
    Mouse.move(x, y);
  }

  if (serialA == 2000)
  {
    Mouse.press(MOUSE_LEFT);
  }
    
  else if (serialA == 3000)
  {
    Mouse.release(MOUSE_LEFT);
  }
    
    
  else if (serialA == 4000)
  {
    Mouse.press(MOUSE_RIGHT);
    Mouse.release(MOUSE_RIGHT);
  }
}
