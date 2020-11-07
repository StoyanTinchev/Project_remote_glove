#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>


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
  Serial.print(vx+10000);
  Serial.print(" | Y = ");
  Serial.println(vy);

  if (analogRead(A0) >= 1000)
    Serial.println(80000);
    
  if ( analogRead(A1) >= 1000)
    Serial.println(90000);
}
