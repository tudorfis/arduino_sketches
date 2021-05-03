#include <Servo.h>

Servo servo1;
const byte potentiometerPin = A0;

void setup() {
  Serial.begin(9600);
  servo1.attach( 8 )
  
//  for ( int ledPin = 9; ledPin <= 11; ledPin++ ) {
//    pinMode( ledPin, OUTPUT );
//  }
}

void loop() {
  int potentiometerData = analogRead( potentiometerPin );
  byte servoData = map( potentiometerData, 0, 1023, 0, 180 );
  
  servo1.write(servoData);  

  
//  
//  if ( Serial.available() > 0 ) {
//    char userSelection = Serial.read();
//    
//    if ( userSelection == 'a' ) {
//      digitalWrite( 9, HIGH );
//    }
//    else if ( userSelection == 'b' ) {
//      digitalWrite( 10, HIGH );
//    }
//    else if ( userSelection == 'c' ) {
//      digitalWrite( 11, HIGH );
//    }
//    else if ( userSelection == 'd' ) {
//      digitalWrite( 9, LOW );
//      digitalWrite( 10, LOW );
//      digitalWrite( 11, LOW );
//    }
//    
//    Serial.println( userSelection ); 
//
//    
//  }
//  
//  int volumeData = analogRead( volumePin );
//  byte ledData = map( volumeData, 0, 1023, 0, 8 );
//
//  for ( int ledPin = 9; ledPin <= 11; ledPin++ ) {
//    digitalWrite( ledPin, LOW);
//  }
//
//  switch ( ledData ) {
//    case 0: {
//      break;
//    }
//    case 1: {
//      digitalWrite( 9, HIGH );
//      break;
//    }
//    case 2: {
//      digitalWrite( 10, HIGH );
//      break;
//    }
//    case 3: {
//      digitalWrite( 11, HIGH );
//      break;
//    }
//    case 4: {
//      digitalWrite( 11, HIGH );
//      digitalWrite( 10, HIGH );
//      break;
//    }
//    case 5: {
//      digitalWrite( 11, HIGH );
//      digitalWrite( 10, HIGH );
//      digitalWrite( 9, HIGH );
//      break;
//    }
//    case 6: {
//      digitalWrite( 10, HIGH );
//      digitalWrite( 9, HIGH );
//      break;
//    }
//    case 7: {
//      digitalWrite( 9, HIGH );
//      break;
//    }
//    case 8: {
//      break;
//    }
//  }
//
//  Serial.println( volumeData );
//  Serial.println( ledData );
//  Serial.println( "---------" );
//

//  delay( 10 );

}
