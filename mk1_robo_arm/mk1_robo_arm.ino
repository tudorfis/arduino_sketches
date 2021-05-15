#include <Servo.h>
Servo gripservo;
Servo baseservo;
Servo updownservo;
Servo forwardservo;

int gripservo_value = 10;
int baseservo_value = 1;
int updownservo_value = 90;
int forwardservo_value = 90;
boolean is_grip_open = false;

int modeSpeed = 1;
int maxModeSpeed = 7;
int multiplier = 3;

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

  if ( Serial.available() > 0 ) {
    char keypressed = Serial.read();
    
    if ( keypressed == 'U' ) {
        updownservo_value += 10;
//        updownservo_value = updownservo_value * modeSpeed * multiplier;
        
        if ( updownservo_value > 180 ) {
          updownservo_value = 160;
        }
    } else if ( keypressed == 'D' ) {
        updownservo_value -= 10;
//        updownservo_value = updownservo_value * modeSpeed * multiplier;
        
        if ( updownservo_value < 50 ) {
          updownservo_value = 0;
        }
        
    } else if ( keypressed == 'L' ) {
        baseservo_value += 10;
//        baseservo_value = baseservo_value * modeSpeed * multiplier;
        
        if ( baseservo_value > 180 ) {
          baseservo_value = 180;
        }
    } else if ( keypressed == 'R' ) {
        baseservo_value -= 10;
//        baseservo_value = baseservo_value * modeSpeed * multiplier;
        
        if ( baseservo_value < 0 ) {
          baseservo_value = 0;
        }

        
    } else if ( keypressed == 'K' ) {
        forwardservo_value += 10;
//        forwardservo_value = forwardservo_value * modeSpeed * multiplier;
        
        if ( forwardservo_value > 180 ) {
          forwardservo_value = 180;
        }
    } else if ( keypressed == 'H' ) {
        forwardservo_value -= 10;
//        forwardservo_value = forwardservo_value * modeSpeed * multiplier;
        
        if ( forwardservo_value < 90 ) {
          forwardservo_value = 0;
        }

        
    } else if ( keypressed == 'S' ) {
      if ( is_grip_open ) {
        is_grip_open = false;
      } else {
        is_grip_open = true;
      }
    } else if ( keypressed == 'T' ) {
      modeSpeed += 1;
      
      if ( modeSpeed > maxModeSpeed ) {
        modeSpeed = 1;
      }
    }
  }

  Serial.print( "baseservo_value= " );
  Serial.print( baseservo_value );
  
  Serial.print( " updownservo_value= " );
  Serial.print(  updownservo_value );
  
  Serial.print( " forwardservo_value= " );
  Serial.println( forwardservo_value );
  
  if ( is_grip_open ) {
    gripservo_value = 50;
  } else {
    gripservo_value = 10;
  }
  
  gripservo.write( gripservo_value );
  baseservo.write( baseservo_value );
  forwardservo.write( forwardservo_value );
  updownservo.write( updownservo_value );
  
  delay( 50 );
}
