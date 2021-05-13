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

  if ( Serial.available() > 0 ) {
    char keypressed = Serial.read();
    Serial.println( "Keypressed ... " );
    Serial.println( keypressed );
    
    if ( keypressed == 'U' ) {
      servoOpened = 50;
    
    } else if ( keypressed == 'D' ) {
      servoOpened = 10;
    }
  }

  gripservo.write( servoOpened );
  delay( 50 );
}
