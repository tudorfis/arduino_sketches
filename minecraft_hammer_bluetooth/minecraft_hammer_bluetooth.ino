
#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

void setup() {  
  Serial.begin(38400);

  mpu6050.begin();
//  mpu6050.calcGyroOffsets(true);
}

int IX = mpu6050.getAngleX();
int IY = mpu6050.getAngleY();
int IZ = mpu6050.getAngleZ();

void loop() {
  mpu6050.update();
  
  byte sendX = mpu6050.getAngleX();
  int x = mpu6050.getAngleX();
  int y = mpu6050.getAngleY();
  int z = mpu6050.getAngleZ();

  Serial.write( sendX );
  
  Serial.print( x );
  Serial.print( " " );
  Serial.print( y );
  Serial.print( " " );
  Serial.println( z );
 
  delay(150);
}
