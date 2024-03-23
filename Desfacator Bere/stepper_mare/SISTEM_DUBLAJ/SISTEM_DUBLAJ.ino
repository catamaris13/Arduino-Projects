const int BUTTON1 = 6;
const int BUTTON2 = 3;
const int LEDROSU = 2;
const int LEDVERDE = 5;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;
long rosunegru;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LEDROSU, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);

  Serial.print("Valoare:");
  Serial.print(rosunegru);
  randomSeed( analogRead(A0));
  rosunegru=random(99)%2;
}

void loop()
{
  
  BUTTONstate1 = digitalRead(BUTTON1);
  BUTTONstate2 = digitalRead(BUTTON2);
/*Serial.print("Valoare:");
  Serial.println(rosunegru);
  if (BUTTONstate1 == HIGH && rosunegru==1)
  {
    digitalWrite(LEDVERDE, HIGH);
    delay(2000);
    digitalWrite(LEDVERDE, LOW);
    Serial.print("Valoare:");
  Serial.print(rosunegru);
  } 
  else if(BUTTONstate2 == HIGH && rosunegru==0)
  {digitalWrite(LEDVERDE, HIGH);
  delay(2000);
  digitalWrite(LEDVERDE, LOW);
  }
  else if((BUTTONstate2 == HIGH && rosunegru==1) || (BUTTONstate1 == HIGH && rosunegru==0))
  {
    
    digitalWrite(LEDROSU, HIGH);
    delay(2000);
    digitalWrite(LEDROSU, LOW);
  }
  if(rosunegru==1)
  {

    digitalWrite(LEDVERDE,HIGH);
    delay(2000);
    digitalWrite(LEDVERDE,LOW);
    delay(2000);
  }
  else
  { digitalWrite(LEDROSU,HIGH);
  delay(2000);
    digitalWrite(LEDROSU,LOW);
    delay(2000);
  }*/
  if(BUTTONstate1==HIGH)
  {
    digitalWrite(LEDVERDE,HIGH);
  }
  else digitalWrite(LEDVERDE,LOW);
  
  if(BUTTONstate2==HIGH)
  {
    digitalWrite(LEDROSU,HIGH);
  }
  else digitalWrite(LEDROSU,LOW);
}

