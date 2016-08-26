#include <Servo.h> 

Servo leftServo;  
Servo rightServo;                

void setup() 
{ 
  Serial.begin(9600);
  leftServo.attach(9);  
  leftServo.write(91);
  rightServo.attach(8);
  rightServo.write(90);
  Serial.println("Connection succesful!");
} 


void loop() 
{ 
  if (Serial.available() > 0) 
  {
    int data = Serial.read();	
    switch(data)
    {
    case 'w' : 
      moveForward(); 
      break;
    case 's' : 
      moveBackward(); 
      break;
    case 'a' : 
      moveLeft(); 
      break;
    case 'd' : 
      moveRight(); 
      break;
    case 'e' : 
      moveStop(); 
      break;
    }
  }
 
void moveBackward(){
  Serial.println("Moving Backward");
  rightServo.write(180);
  leftServo.write(0); 
}

void moveForward(){
  Serial.println("Moving Forward");
  rightServo.write(0);
  leftServo.write(180);
}

void moveRight(){
  Serial.println("Turning Right");
  rightServo.write(0);
  leftServo.write(0);  
}

void moveLeft(){
  Serial.println("Turning Left"); 
  rightServo.write(180);
  leftServo.write(180);
}

void moveStop(){
  Serial.println("Stopping");
  rightServo.write(90);
  leftServo.write(90); 
}

