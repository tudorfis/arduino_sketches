#include <Servo.h>
Servo gripservo;
Servo baseservo;
Servo updownservo;
Servo forwardservo;

int gripservo_value = 10;
int baseservo_value = 0;
int updownservo_value = 0;
int forwardservo_value = 0;
boolean is_grip_open = false;

void setup() 
{
  gripservo.attach( A0 );
  baseservo.attach( A1 );
  updownservo.attach( A3 );
  forwardservo.attach( A2 );
  
  Serial.begin(9600);
}


void loop()
{

  if ( Serial.available() > 0 ) {
    char keypressed = Serial.read();
    
    if ( keypressed == 'U' ) {
        updownservo_value += 10;
        
        if ( updownservo_value > 180 ) {
          updownservo_value = 180;
        }
    } else if ( keypressed == 'D' ) {
        updownservo_value -= 10;
        
        if ( updownservo_value < 0 ) {
          updownservo_value = 0;
        }

        
    } else if ( keypressed == 'L' ) {
        baseservo_value += 10;
        
        if ( baseservo_value > 180 ) {
          baseservo_value = 180;
        }
    } else if ( keypressed == 'R' ) {
        baseservo_value -= 10;
        
        if ( baseservo_value < 0 ) {
          baseservo_value = 0;
        }

        
    } else if ( keypressed == 'H' ) {
        forwardservo_value += 10;
        
        if ( forwardservo_value > 180 ) {
          forwardservo_value = 180;
        }
    } else if ( keypressed == 'K' ) {
        forwardservo_value -= 10;
        
        if ( forwardservo_value < 0 ) {
          forwardservo_value = 0;
        }

        
    } else if ( keypressed == 'S' ) {
      if ( is_grip_open ) {
        is_grip_open = false;
      } else {
        is_grip_open = true;
      }
    }
  }

  Serial.println( updownservo_value );

  if ( is_grip_open ) {
    gripservo_value = 50;
  } else {
    gripservo_value = 10;
  }
  
  gripservo.write( gripservo_value );
  baseservo.write( baseservo_value );
//  forwardservo.write( forwardservo_value );
//  updownservo.write( updownservo_value );
  
  delay( 50 );
}
