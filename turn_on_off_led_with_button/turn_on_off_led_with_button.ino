
const byte ledPin = 13;
const byte buttonPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode( ledPin, OUTPUT );
  pinMode( buttonPin, INPUT );
}

void loop() {
  boolean buttonState = digitalRead( buttonPin );
  
  Serial.println( buttonState );

 
 // digitalWrite( ledPin, digitalRead( buttonPin ) );
  delay( 100 );
}
