#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>

#define button1 6
#define button2 7


MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;
int flag = 0;

void setup() {

  Serial.begin(9600);
  Wire.begin();
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  mpu.initialize();
  if (!mpu.testConnection()) //tova e ako zabie, da razberem 
  {
    while (1);
  }
}

void loop() 
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = (gx) / 300;
  vy = (gy) / 300;

  Serial.print("gx = ");
  Serial.print(gx);
  Serial.print(" | gz = ");
  Serial.print(gz);

  Serial.print("        | X = ");
  Serial.print(vx);
  Serial.print(" | Y = ");
  Serial.println(vy);

  Mouse.move(vx, vy);

  if (digitalRead(button1) == HIGH && flag == 0) 
  {
    Mouse.press(MOUSE_LEFT);
    delay(200);
    flag = 1;
  }
  else if (digitalRead(button1) == LOW && flag)
  {
    Mouse.release(MOUSE_LEFT);
    flag = 0;
  }
  else if (digitalRead(button2) == HIGH) 
  {
    Mouse.press(MOUSE_RIGHT);
    delay(100);
    Mouse.release(MOUSE_RIGHT);
    delay(200);
  }
  delay(10);
}
