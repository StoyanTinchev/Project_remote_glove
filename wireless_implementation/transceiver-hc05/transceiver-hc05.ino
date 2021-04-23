#include <Wire.h>
#include <SoftwareSerial.h>
#include <I2Cdev.h>
#include <MPU6050.h>

#define button1 6
#define button2 7
//int flag_left=0;
int flag_right=0;

SoftwareSerial bt(14, 15);
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int vx, vy;


void setup()
{
  bt.begin(57600);
  Serial.begin(57600);
  Wire.begin();

  mpu.initialize();
}

void loop()
{
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

  if (digitalRead(button1) == HIGH)
  {
    bt.print("LEFT");
    bt.print(2000);
  }
  else if (digitalRead(button1) == LOW)
  {
    bt.print("LEFT");
    bt.print(3000);
  }
  if (digitalRead(button2) == HIGH && flag_right == 0) 
  {
    bt.print("RIGHT"); 
    bt.print(4000);
    flag_right=1;
  }
  else if(digitalRead(button2) == LOW && flag_right == 1)
  {
    bt.print("release");
    flag_right=0;
  }
  delay(7);
}
