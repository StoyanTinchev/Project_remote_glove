#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>
#include <SoftwareSerial.h>
int state = 0;

#define button1 6
#define button2 7

SoftwareSerial bt(14, 15);
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;
int flag = 0;

void setup() {
  bt.begin(9600);
  //Serial.begin(9600); // Default communication rate of the Bluetooth module
  Serial.begin(9600);
  Wire.begin();
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  mpu.initialize();
  if (!mpu.testConnection()) 
  {
    while (1);
  }
}

void loop() 
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = (gx) / 300;
  vy = (gy) / 300;

  if(bt.available()>0)
  {
    state = bt.read(); // assign incoming data to variable state
    Serial.write(state);
  }


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
