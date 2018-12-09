const int trig1 =2;
const int echo1 = 4;
const int trig2 =5;
const int echo2 = 6;


const int ledred = A0;
const int ledgreen = A1;
const int ledyellow = A2;

unsigned long duration1 = 0;
int distance1 = 0;
unsigned long duration2 = 0;
int distance2 = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(trig1 , OUTPUT);
  pinMode(echo1 , INPUT);
  pinMode(trig2 , OUTPUT);
  pinMode(echo2 , INPUT);

  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(13, OUTPUT);
  
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig1 , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig1 , LOW);
  
  duration1 = pulseIn(echo1 , HIGH);
  distance1 = (duration1/2)/28.5;
  Serial.println(distance1);
  
  digitalWrite(trig2 , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig2 , LOW);
  
  duration2 = pulseIn(echo2 , HIGH);
  distance2 = (duration2/2)/28.5;
  Serial.println(distance2);
  
  
  if(distance1 < 10 || distance2 < 10)
  {
    digitalWrite(ledred, 255);
    pinMode(13, LOW);
    delay(1000);
  }
  else
  {
    digitalWrite(ledred, 0);
    pinMode(13, HIGH);
    delay(1000);
  }
 
  if(distance1 < 15 || distance2 < 15)
  {
    digitalWrite(ledgreen, 255);
  }
  else
  {
    digitalWrite(ledgreen,0 );
  }
  
  if(distance1 < 20 || distance2 < 20)
  {
    digitalWrite(ledyellow, 255);
  }
  else
  {
    digitalWrite(ledyellow, 0);
  }
  

}
