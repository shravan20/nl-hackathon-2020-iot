
/***
* Simple Piezo Electric Buzzer program
* Simple Hands on - Testing
*/

const int buzzerPin = 15;

void setup() {

 Serial.begin(115200);
 // setup pin 5 as a digital output pin
 //  pinMode (buzzer, OUTPUT);

}

void loop() {
   Serial.println("Hello");
   digitalWrite (ledPin, HIGH);  // turn on the LED
   delay(500); // wait for half a second or 500 milliseconds
   digitalWrite (ledPin, LOW); // turn off the LED
   delay(500); // wait for half a second or 500 milliseconds
}
