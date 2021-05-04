#include <Servo.h>

Servo D1; 
Servo D2; 
Servo D3; 
Servo D4; 
Servo D5;
 
boolean runnedOnce = false;

void setup() {
  D1.attach(2);
  D2.attach(3);
  D3.attach(4);
  D4.attach(5);
  D5.attach(6);
}

void loop() {
//  return;
//  D1.write( 0 );
//  D2.write( 0 );
//  
//  delay( 1000 );
//  
//  D3.write( 0 );
//  D4.write( 0 );
//  D5.write( 0 );
  
  if ( !runnedOnce ) {
    
    for ( int i = 1; i <= 180; i++ ) {
      int servoRotation = i * 10;
      
      D1.write( servoRotation );
      delay( 100 );

      D2.write( servoRotation );
      delay( 100 );

      D3.write( servoRotation );
      delay( 100 );
      
      D4.write( servoRotation );
      delay( 100 );

      D5.write( servoRotation );
      delay( 100 );

      
    } 
     
    runnedOnce = true;
  }
  
}
