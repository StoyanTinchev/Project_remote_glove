#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>


MPU6050 mpu;
int16_t ax, ay, az; 
int16_t gx, gy, gz; 



void setup() {

  Serial.begin(9600);
  Wire.begin();
  
  mpu.initialize();
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

long x=map(ax,-17000,17000,20000,20008);
long y=map(ay,-17000,17000,30000,30008);
Serial.println(x);
delay(10);
Serial.println(y);
delay(10);
if( analogRead(A0)>= 1000){
  Serial.println(80000);
}
if( analogRead(A1)>= 1000){
  Serial.println(90000);
}
if( analogRead(A3) >= 1000){
  Serial.println(70000);
}if( analogRead(A4)>= 1000){
  Serial.println(60000);
}
if( analogRead(A5)>= 1000){
  Serial.println(60500);
}



}
