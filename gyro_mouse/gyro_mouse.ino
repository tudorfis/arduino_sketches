#include <MPU6050_tockn.h>
#include <Wire.h>
#include "Mouse.h"

MPU6050 mpu6050(Wire);
#include "Keyboard.h"
int r=4;
int l=5;
int e=6;

void setup() {
  // put your setup code here, to run once:
    Keyboard.begin();
 Wire.begin();
  mpu6050.begin();
   Mouse.begin();
  mpu6050.calcGyroOffsets(true);
}
int IX=mpu6050.getAngleX();
int IY=mpu6050.getAngleZ();
void loop() {
  // put your main code here, to run repeatedly:
   mpu6050.update();
  int x = mpu6050.getAngleX();
 
  int y = mpu6050.getAngleZ();
  int ry=IY-y;
  int rx=IX-x;
  if((abs(ry)>=30)&&(abs(ry)<=40)){
    if(ry>0)
    Mouse.move(0, -3, 0);
    else if(ry<0)
     Mouse.move(0, 3, 0);
  }

   else if((abs(ry)>=40)&&(abs(ry)<=60)){
   if(ry>0)
    Mouse.move(0, -6, 0);
    else if(ry<0)
     Mouse.move(0, 6, 0);
  }

  if((abs(rx)>=30)&&(abs(rx)<=40)){
    if(rx>0)
    Mouse.move(3, 0, 0);
    else if(rx<0)
     Mouse.move(-3, 0, 0);
  }

   else if((abs(rx)>=40)&&(abs(rx)<=60)){
   if(rx>0)
    Mouse.move(6, 0, 0);
    else if(rx<0)
     Mouse.move(-6, 0, 0);
  }
  int rr=digitalRead(r);
   int ll=digitalRead(l);
     int ee=digitalRead(e);
if(rr== HIGH){
Mouse.press(MOUSE_RIGHT);
delay(2);
Mouse.release(MOUSE_RIGHT);}
else if(ll==HIGH){
Mouse.click();}
else if(ee==HIGH){
Keyboard.press('r');
Keyboard.release('r');
}

delay(5);
}
