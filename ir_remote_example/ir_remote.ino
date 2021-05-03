#include <IRremote.h>   

IRrecv ir_receiver(7);     
decode_results ir_results;
     
void setup() {     
  Serial.begin(9600);     
  ir_receiver.enableIRIn(); 
  ir_receiver.blink13(true);
}

const double PRESSED_ONE = 3810010651;
const double PRESSED_TWO = 5316027;
const double PRESSED_THREE = 4001918335;
const double PRESSED_FOUR = 1386468383;
const double PRESSED_FIVE = 3622325019;
const double PRESSED_SIX = 553536955;
const double PRESSED_SEVEN = 4034314555;
const double PRESSED_EIGHT = 2747854299;
const double PRESSED_NINE = 3855596927;
const double PRESSED_ZERO = 2538093563;
const double PRESSED_STAR = 3238126971;
const double PRESSED_HASH = 4039382595;
const double PRESSED_UP = 1033561079;
const double PRESSED_RIGHT = 71952287;
const double PRESSED_DOWN = 465573243;
const double PRESSED_LEFT = 2351064443;
const double PRESSED_OK = 1217346747;

void loop()  {     
  if (ir_receiver.decode(&ir_results)){     
    if ( 
        ir_results.value!= 4294967295 && 
        ir_results.value!= 255
    ) {
//      Serial.println(ir_results.value);
      
      switch (ir_results.value) {
        case 3810010651: {
          Serial.println( "pressed 1" );
          break;
        }
        case 5316027: {
          Serial.println( "pressed 2" );
          break;
        }
        case 4001918335: {
          Serial.println( "pressed 3" );
          break;
        }
      }
      
      delay(10);
    }
    
    ir_receiver.resume();
  }   
}
