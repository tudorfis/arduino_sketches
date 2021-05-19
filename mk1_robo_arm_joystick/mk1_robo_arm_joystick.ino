#include <Servo.h>
Servo gripservo;
Servo baseservo;
Servo updownservo;
Servo forwardservo;

void setup() 
{
  gripservo.attach( A0 );
  baseservo.attach( A1 );
  forwardservo.attach( A2 );
  updownservo.attach( A3 );
  
  Serial.begin(9600);
}

void loop()
{
  int joystickRightY = analogRead( A4 );
  int joystickRightX = analogRead( A5 );
  int joystickLeftY = analogRead( A6 );
  int joystickLeftX = analogRead( A7 );

  int baseservo_value = map( joystickLeftX, 0, 1023, 0, 180 );
  int updownservo_value = map( joystickLeftY, 0, 1023, 50, 160 );
  int forwardservo_value = map( joystickRightY, 0, 1023, 60, 160);
  int gripservo_value = map( joystickRightX, 0, 1023, 0, 70 );

  gripservo.write( gripservo_value );
  baseservo.write( baseservo_value );
  forwardservo.write( forwardservo_value );
  updownservo.write( updownservo_value );
  
  delay( 10 );
}
