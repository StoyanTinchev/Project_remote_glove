#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

#define button1 6
#define button2 7
int flag=0;

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int vx, vy;


void setup()
{

  Serial.begin(9600);
  Wire.begin();

  mpu.initialize();
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  vx = (gx) / 300;
  vy = (gy) / 300;

  /*Serial.print("gx = ");
    Serial.print(gx);
    Serial.print(" | gz = ");
    Serial.print(gz);*/

  Serial.print("        | X = ");
  Serial.print(vx + 10000);
  Serial.print(" | Y = ");
  Serial.println(vy);

  if (digitalRead(button1) == HIGH && flag == 0)
  {
    Serial.println(70000);
    flag = 1;
  }
  else if (digitalRead(button1) == LOW && flag)
  {
    Serial.println(80000);
    flag = 0;
  }
  else if (digitalRead(button2) == HIGH) 
  {
    Serial.println(90000);
  }
  
//  if (analogRead(A0) >= 1000)
//    Serial.println(80000);
//
//  if ( analogRead(A1) >= 1000)
//    Serial.println(90000);
}
