#include <Wire.h>
#include <SoftwareSerial.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <IRremote.h>


#define leftBTN 6
#define rightBTN 7
#define switchAct 10

bool flag_right = false;
bool switch_activity = false; 
bool switchBTN = false;

SoftwareSerial bt(14, 15);
MPU6050 mpu;
IRsend irsend(9);

int16_t ax, ay, az;
int16_t gx, gy, gz;
int vx, vy;

//values for Panasonic's Remote
/*
unsigned long up_val = 33738799;
unsigned long down_val = 33714219;
unsigned long right_val = 33720439;
unsigned long left_val = 33687799;
*/

//values for A1's Remote
unsigned long up_val = 16764975;
unsigned long down_val = 16754775;
unsigned long right_val = 16724175;
unsigned long left_val = 16718055; 

void setup()
{
  bt.begin(57600);
  Serial.begin(57600);
  Wire.begin();

  mpu.initialize();
}

void loop()
{
  if (digitalRead(switchAct) == HIGH && switchBTN)
  {
    if (switch_activity)
      switch_activity = false;
    else
      switch_activity = true;

    switchBTN = false;
  }
  else
    switchBTN = true;

  switch(switch_activity)
  {
    case true:
      if(vx > 100)
      {
        Serial.println("Next program");
        irsend.sendNEC(up_val, 32);
      }
      else if(vx < -100)
      {
        Serial.println("Previous program");
        irsend.sendNEC(down_val, 32);
      }
      if(vy > 100)
      {
        Serial.println("Up volume");
        irsend.sendNEC(left_val, 32);
      }
      else if(vy < -100)
      {
        Serial.println("Down volume");
        irsend.sendNEC(right_val, 32);
      }
      break;
      
    case false:
      mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      vx = (gx) / 300;
      vy = (gy) / 300;
    
      Serial.print("        | X = ");
      bt.print("        | X = ");
      bt.print(vx + 1000);
      Serial.print(vx + 1000);
      Serial.print(" | Y = ");
      bt.print(" | Y = ");
      bt.print(vy + 500);
      Serial.println(vy + 500);
      
      if (digitalRead(leftBTN) == HIGH)
      {
        bt.print("LEFT");
        bt.print(2000);
      }
      else
      {
        bt.print("LEFT");
        bt.print(3000);
      }
      if (digitalRead(rightBTN) == HIGH && flag_right == 0) 
      {
        bt.print("RIGHT"); 
        bt.print(4000);
        flag_right = true;
      }
      else if(digitalRead(rightBTN) == LOW && flag_right == 1)
      {
        bt.print("release");
        flag_right = false;
      }
      delay(7);
      break;
  }
}
