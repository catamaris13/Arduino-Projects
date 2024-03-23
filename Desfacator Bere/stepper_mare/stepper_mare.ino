/*   
 *   Basic example code for controlling a stepper without library
 *      
 *   by Dejan, https://howtomechatronics.com
 */

// defines pins
#define stepPin 10
#define dirPin 9
#define IR_SENSOR_RIGHT 11
#define Micro1 3
 int ok=0;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(Micro1,OUTPUT);
  digitalWrite(Micro1,HIGH);
}
void loop() {
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  if (rightIRSensorValue == LOW && ok==0){
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(700);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(700); 
  }
  ok=1;
  }
 
 
}