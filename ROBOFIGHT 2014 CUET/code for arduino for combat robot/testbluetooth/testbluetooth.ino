#include <SoftwareSerial.h>
char x;
SoftwareSerial bluetooth(6,7); //  bluetooth TX to pin 6, bluetooth RX to pin 7 

void setup(){
pinMode(13, OUTPUT);
Serial.begin(9600);
}

void loop()
{
 if(bluetooth.available()){
  x = bluetooth.read();
  
  if (x == 'a' || x == 'A'){
    digitalWrite(13, HIGH);
  } else {
   digitalWrite(13, LOW); 
  }
  
 } 
  
}
