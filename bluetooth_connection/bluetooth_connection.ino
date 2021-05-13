#include <Servo.h>
Servo gripservo;

int servoOpened = 10;

void setup() 
{
  gripservo.attach( 9 );
  Serial.begin(9600);
}


void loop()
{

Serial.println( "Servo before: " ); 
Serial.println( servoOpened ); 

  if ( Serial.available() > 0 ) {
    char keypressed = Serial.read();
    Serial.println( "Keypressed ... " );
    Serial.println( keypressed );
    
    if ( keypressed == 'U' ) {
      servoOpened = servoOpened + 10;
      Serial.println( "Pressed U" );
      Serial.println( servoOpened );
    
    } else if ( keypressed == 'D' ) {
      servoOpened = servoOpened - 10;
      Serial.println( "Pressed D" );
      Serial.println( servoOpened );
    }
  }

//  if ( servoOpened >= 10 && servoOpened <= 50 ) {
//    gripservo.write( servoOpened );
//  }

//  if ( servoOpened < 10 ) {
//    servoOpened = 10;
//  }
//  if ( servoOpened > 50 ) {
//    servoOpened = 50;
//  }

Serial.println( "Servo after: " ); 
Serial.println( servoOpened ); 
  delay( 50 );
}
