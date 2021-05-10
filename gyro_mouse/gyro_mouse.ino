#include <MPU6050_tockn.h>
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

int IX = mpu6050.getAngleX();
int IY = mpu6050.getAngleZ();

void loop() {
 
  mpu6050.update();
  int x = mpu6050.getAngleX();
  int y = mpu6050.getAngleZ();
  
  int rx=IX-x;
  int ry=IY-y;
  

  Serial.println( x );
  
  
  delay(5);
}
