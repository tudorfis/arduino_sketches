
const int ledBlue = 13;
const int ledRed = 12;
const int ledWhite = 11;
const int buttonPin = 5;  

void setup() {
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledWhite, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}
void blink( int whichLed, int timeout = 1000 ) {
  digitalWrite( whichLed, 1 );
  delay( timeout );
  digitalWrite(whichLed, 0 );
  delay( timeout );
}
void blinkLeds( int timeout = 1000 ) {
    blink( ledBlue, timeout );
    blink( ledRed, timeout );
    blink( ledWhite, timeout ); 
}
void loop() {

  Serial.println( digitalRead(buttonPin) == 1 );
  
  if ( digitalRead(buttonPin) == 1 ) {
    blinkLeds( 400 );
  }
  else {
    blinkLeds( 50 );  
  }
  
}
