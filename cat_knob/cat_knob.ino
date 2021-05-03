#include <Servo.h>

Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(9600);
  servoX.attach( 9 );
  servoY.attach( 10 );
}

void loop() {
  
  byte servoDataX = map( analogRead( A0 ), 0, 1023, 0, 180 );
  byte servoDataY = map( analogRead( A1 ), 0, 1023, 0, 180 );

  servoX.write( servoDataX );
  servoY.write( servoDataY );

  delay( 10 );

}
