#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

int trigPin = 3;
int echoPin = 2;

void setup() {
   Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   lcd.begin(16,2);
}

void loop() {

  long duration, distance;

  digitalWrite( trigPin, HIGH);
  delayMicroseconds( 1000 );
  digitalWrite( trigPin, LOW );
  
  duration = pulseIn( echoPin, HIGH );
  distance = ( duration / 2 ) / 29.1;

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Distanta este de");
  lcd.setCursor(0, 1); 
  lcd.print(distance);
  lcd.print(" CM");
  delay(100)
 
;}
