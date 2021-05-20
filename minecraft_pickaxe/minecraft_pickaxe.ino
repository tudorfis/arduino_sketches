
#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

void setup() 
{
  Serial.begin(9600);
  mpu6050.begin();
}

//int IX = mpu6050.getAngleX();
//int IY = mpu6050.getAngleY();
//int IZ = mpu6050.getAngleZ();

void loop()
{
  
  mpu6050.update();
  
  int x = mpu6050.getAngleX();
  int y = mpu6050.getAngleY();
  int z = mpu6050.getAngleZ();


  Serial.print( "x=" );
  Serial.print( x );
  Serial.print( " y=" );
  Serial.print( y );
  Serial.print( " z=" );
  Serial.println( z );
 
  delay( 10 );
}
