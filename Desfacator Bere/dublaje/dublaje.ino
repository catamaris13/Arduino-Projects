#define LED_PIN1 4
#define BUTTON_PIN1 3
#define LED_PIN2 10
#define BUTTON_PIN2 9
long randomNumber;
int ok=0;
void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(BUTTON_PIN1, INPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(BUTTON_PIN2, INPUT);

  randomSeed(analogRead(A0));
  randomNumber=random(2);
}
void loop() {
/*  if (digitalRead(BUTTON_PIN1) == HIGH) {
    digitalWrite(LED_PIN1, HIGH);
  }
  else {
    digitalWrite(LED_PIN1, LOW);
  }
  if (digitalRead(BUTTON_PIN2) == HIGH) {
    digitalWrite(LED_PIN2, HIGH);
  }
  else {
    digitalWrite(LED_PIN2, LOW);
  }*/
  if(ok==0)
  {
  if(digitalRead(BUTTON_PIN1) == HIGH && randomNumber==0)
  {
    digitalWrite(LED_PIN1, HIGH);
    delay(2000);
    digitalWrite(LED_PIN1, LOW);
    ok=1;
  }
  if(digitalRead(BUTTON_PIN2) == HIGH && randomNumber==1)
  {
    digitalWrite(LED_PIN1, HIGH);
    delay(2000);
    digitalWrite(LED_PIN1, LOW);
    ok=1;
  }
  if(digitalRead(BUTTON_PIN1) == HIGH && randomNumber==1)
  {
    digitalWrite(LED_PIN2, HIGH);
    delay(2000);
    digitalWrite(LED_PIN2, LOW);
    ok=1;
  }
  if(digitalRead(BUTTON_PIN2) == HIGH && randomNumber==0)
  {
    digitalWrite(LED_PIN2, HIGH);
    delay(2000);
    digitalWrite(LED_PIN2, LOW);
    ok=1;
  }
  }
  
}