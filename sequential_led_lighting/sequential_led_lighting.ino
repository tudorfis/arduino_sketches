
const byte buttonPin = 7;

void setup() {
  pinMode( buttonPin, INPUT );
  Serial.begin(9600);

}

void lightLed( int ledPin ) {
  digitalWrite( ledPin, HIGH );
  delay( 150 );
  digitalWrite( ledPin, LOW );
  delay( 150 );
}

const byte startPin = 10;
const byte endPin = 12;

void loop() {
  boolean buttonState = digitalRead( buttonPin );
  Serial.println( buttonState ); 
  
  if ( buttonState == 1 ) {
    for ( int ledPin = startPin; ledPin <= endPin; ledPin++ ) {
      lightLed( ledPin );
    }  
  }
  else {
    for ( int ledPin = endPin; ledPin >= startPin; ledPin-- ) {
      lightLed( ledPin );
    }
  }
   
   delay(10);
}
