void setup() {
  Serial.begin(9600);
}

void loop() {
  byte bytesInSerialBuffer = Serial.available();
  byte incomingByte = Serial.read();
  
  Serial.println( "-------------" );
  Serial.println( bytesInSerialBuffer );
  Serial.println( incomingByte, BIN );
  delay( 500 );
 
}
