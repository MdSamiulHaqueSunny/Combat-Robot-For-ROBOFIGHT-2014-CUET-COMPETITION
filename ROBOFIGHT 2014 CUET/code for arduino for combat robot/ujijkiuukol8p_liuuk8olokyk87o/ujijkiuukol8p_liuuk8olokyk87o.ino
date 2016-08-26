 int Left1 = 2;
 int Left2 = 3;

 int Right1 = 4;
 int Right2 = 5;

/* int backLeft1 = 6;
 int backLeft2 = 7;

 int backRight1 = 8;
 int backRight2 = 9;*/


// Lifter

 int leftSide1 = 6;
 int leftSide2 = 7;

 int rightSide1 = 8;
 int rightSide2 = 9;


int command;
int flag;

void setup()
{
	Serial.begin(9600);
	pinMode( Left1, OUTPUT);
	pinMode( Left2, OUTPUT);
	pinMode( Right1, OUTPUT);
	pinMode( Right2, OUTPUT);
	/*pinMode( backLeft1, OUTPUT);
	pinMode( backLeft2, OUTPUT);
	pinMode( backRight1, OUTPUT);
	pinMode( backRight2, OUTPUT);
	pinMode( leftSide1, OUTPUT);
	pinMode( leftSide2, OUTPUT);
	pinMode( rightSide1, OUTPUT);
	pinMode( rightSide2, OUTPUT);*/
	
}

void goForward()
{
	digitalWrite(Left1, HIGH);
	digitalWrite(Left2, LOW);
	digitalWrite(Right1, HIGH);
	digitalWrite(Right2, LOW);
	/*digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, HIGH);
	digitalWrite(backRight2, LOW);*/
}

void goBackward()
{
	digitalWrite(Left1, LOW);
	digitalWrite(Left2, HIGH);
	digitalWrite(Right1, LOW);
	digitalWrite(Right2, HIGH);
	/*digitalWrite(backLeft1, LOW);
	digitalWrite(backLeft2, HIGH);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, HIGH);*/
}

/*void goLeft()
{
	digitalWrite(frontLeft1, LOW);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, HIGH);
	digitalWrite(frontRight2, LOW);
	digitalWrite(backLeft1, LOW);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, HIGH);
	digitalWrite(backRight2, LOW);
}

void goRight()
{
	digitalWrite(frontLeft1, HIGH);
	digitalWrite(frontLeft2, LOW);
	digitalWrite(frontRight1, LOW);
	digitalWrite(frontRight2, LOW);
	digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, LOW);


}
*/
void cturn360()
{
	digitalWrite(Left1, HIGH);
	digitalWrite(Left2, LOW);
	digitalWrite(Right1, LOW);
	digitalWrite(Right2, HIGH);
	/*digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, HIGH);*/

}
void ccwturn360()
{
	digitalWrite(Left1, LOW);
	digitalWrite(Left2, HIGH);
	digitalWrite(Right1, HIGH);
	digitalWrite(Right2, LOW);
	/*digitalWrite(backLeft1, HIGH);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);  
	digitalWrite(backRight2, HIGH);*/

}
void stopall()
{

	digitalWrite(Left1, LOW);
	digitalWrite(Left2, LOW);
	digitalWrite(Right1, LOW);
	digitalWrite(Right2, LOW);
digitalWrite(leftSide1, LOW);
digitalWrite(leftSide2, LOW);
digitalWrite(rightSide1, LOW);
digitalWrite(rightSide2,LOW);

	/*digitalWrite(backLeft1, LOW);
	digitalWrite(backLeft2, LOW);
	digitalWrite(backRight1, LOW);
	digitalWrite(backRight2, LOW);*/


}


//Write lifter motor codes here
void liftUp()
{
 digitalWrite(leftSide1, LOW);
digitalWrite(leftSide2, HIGH);
digitalWrite(rightSide1, HIGH);
digitalWrite(rightSide2,LOW);
}
void liftDown()
{
 digitalWrite(leftSide1, HIGH);
digitalWrite(leftSide2, LOW);
digitalWrite(rightSide1, LOW);
digitalWrite(rightSide2, HIGH);
}


void loop()
{
	if (Serial.available()>0)

{
		command = Serial.read();
		
		
		if(command=='2')
                  {
                     goForward();
                  if(flag == 0){
          Serial.println("Motor: forward");
          flag=1;
                 }
                }
                
                
		
	else if(command=='8')
                  {
                     goBackward();
                  if(flag == 0){
          Serial.println("Motor: Backward");
          flag=1;
                 }
		}

	
	else if(command=='6')
                  {
                     cturn360();
                  if(flag == 0){
          Serial.println("Motor: right");
          flag=1;
                 }
		}


	
	else if(command=='4')
                  {
                     ccwturn360();
                  if(flag == 0){
          Serial.println("Motor: left");
          flag=1;
                 }
		}

else if(command=='5')
                  {
                     stopall();
                  if(flag == 0){
          Serial.println("Motor: stop");
         flag=1;
                 }
		}
	
	
	else if(command=='3')
                  {
                     liftUp();
                  if(flag == 0){
          Serial.println("Motor: liftup");
         flag=1;
                 }
		}
else if(command=='1')
                  {
                     liftDown();
                  if(flag == 0){
          Serial.println("Motor: liftdown");
         flag=1;
                 }
		}


}}
