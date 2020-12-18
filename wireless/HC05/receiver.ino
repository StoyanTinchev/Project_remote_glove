#include "Keyboard.h"
#include "Mouse.h"
#include <SoftwareSerial.h>
// software serial//Software Serial Port
long x;
long y;

SoftwareSerial mySerial(9, 8); // RX, TX
long serialA;
void setup() { // initialize the buttons' inputs:
  Serial.begin(9600);
  mySerial.begin(9600);
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
         
       if (mySerial.available() > 2) {
  serialA = mySerial.parseInt();
  Serial.println(serialA);

  }   

    if (serialA>= 20000 && serialA <20008){
    

    Serial.println("xread");
    Serial.println(x);
    
x=map(serialA,20000,20008,-4,4);
    delay(10);

    }
    
    if (serialA>= 30000 && serialA <30008){
    
    Serial.println("yread");
y=map(serialA,30000,30008,-4,4);
    Serial.println(y);
   
    delay(10);

    }  
Mouse.move(x, y);


    if (serialA== 80000){
    
    Serial.println("Left");
    Mouse.press(MOUSE_RIGHT);
    Serial.println(serialA);
    
    delay(10);

    }
    
    if (serialA== 90000){
    
    Serial.println("Right");
      Mouse.press(MOUSE_LEFT);
    Serial.println(serialA);
 
    delay(10);

    }
     if (serialA== 70000){
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(60);
    Keyboard.releaseAll();

    }
     if (serialA== 60500){
    
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(60);
      Keyboard.releaseAll();

    }
     if (serialA== 60000){

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press('v');
     delay(60);
     Keyboard.releaseAll();

    }else{
              
 Mouse.release(MOUSE_LEFT);
  Mouse.release(MOUSE_RIGHT);
      
    }

}
