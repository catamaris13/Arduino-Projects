#include <Servo.h>
Servo myservo;
#define IR_SENSOR_RIGHT_F 11
#define IR_SENSOR_LEFT_F 12
#define IR_SENSOR_RIGHT_B 2
#define IR_SENSOR_LEFT_B 4
#define IR_SENSOR_M 13
#define MOTOR_SPEED 180


//Right motor
int enableRightMotor=6;
int rightMotorPin1=7;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=9;
int leftMotorPin2=10;
//servo value
int val=0;
//verif
int ok=1;
int k=1;
//microfon 
int microfon = A0;
int trig=0;
int a=-1;
int c=0.5;


void setup()
{
  //The problem with TT gear motors is that, at very low pwm value it does not even rotate.
  //If we increase the PWM value then it rotates faster and our robot is not controlled in that speed and goes out of line.
  //For that we need to increase the frequency of analogWrite.
  //Below line is important to change the frequency of PWM signal on pin D5 and D6
  //Because of this, motor runs in controlled manner (lower speed) at high PWM value.
  //This sets frequecny as 7812.5 hz.
  TCCR0B = TCCR0B & B11111000 | B00000010 ; //00001
  
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT_F, INPUT);
  pinMode(IR_SENSOR_LEFT_F, INPUT);
  pinMode(IR_SENSOR_RIGHT_B, INPUT);
  pinMode(IR_SENSOR_LEFT_B, INPUT);
  pinMode(IR_SENSOR_M, INPUT);
  rotateMotor(0,0);  
  pinMode(microfon, INPUT);
  myservo.attach(3); 
  myservo.write(0);
  analogWrite(microfon,HIGH);


  Serial.begin(9600);
  
}


void loop()
{

  int rightIRSensorValue_F = digitalRead(IR_SENSOR_RIGHT_F);
  int leftIRSensorValue_F = digitalRead(IR_SENSOR_LEFT_F);
  int rightIRSensorValue_B = digitalRead(IR_SENSOR_RIGHT_B);
  int leftIRSensorValue_B = digitalRead(IR_SENSOR_LEFT_B);
  int IRSensorValue_M = digitalRead(IR_SENSOR_M);
  
 Serial.println(trig);
if(IRSensorValue_M == LOW && ok==1)
{
  myservo.write(90);
  delay(500);
  a=1;
  c=1;
  ok=0;
}
if(a==1)
{
  //If none of the sensors detects black line, then go straight
  if (rightIRSensorValue_F == LOW && leftIRSensorValue_F == LOW)
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  //If right sensor detects black line, then turn right
  else if (rightIRSensorValue_F == HIGH && leftIRSensorValue_F == LOW )
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);  
  }
  //If left sensor detects black line, then turn left  
  else if (rightIRSensorValue_F == LOW && leftIRSensorValue_F == HIGH )
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  } 
  //If both the sensors detect black line, then stop 
  else 
  {
    if(k==1)
    {
    myservo.write(-90);
    
    k=0;
    }
    rotateMotor(0, 0);
  }
}
else 
{
  if (rightIRSensorValue_B == LOW && leftIRSensorValue_B == LOW)
  {
    rotateMotor(-MOTOR_SPEED, -MOTOR_SPEED);
  }
  //If right sensor detects black line, then turn right
  else if (rightIRSensorValue_B == HIGH && leftIRSensorValue_B == LOW )
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);  
  }
  //If left sensor detects black line, then turn left  
  else if (rightIRSensorValue_B == LOW && leftIRSensorValue_B == HIGH )
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  }
}
}



void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}