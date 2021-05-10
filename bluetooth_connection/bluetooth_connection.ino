
void setup() 
{
  Serial.begin(38400);
}


void loop()
{

  if ( Serial.available() > 0 ) {
    char data = Serial.read();
    Serial.println( data );  
  }

  delay( 50 );
}
