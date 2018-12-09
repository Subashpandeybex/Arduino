const int trig1 =6;
const int echo1 = 7;


const int ledred = A0;
const int ledgreen = A1;
const int ledyellow = A2;

int duration1 = 0;
int distance1 = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(trig1 , OUTPUT);
  pinMode(echo1 , INPUT);
  
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(13, OUTPUT);
  
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig1 , HIGH);
  //delayMicroseconds(1000);
  digitalWrite(trig1 , LOW);
  
  duration1 = pulseIn(echo1 , HIGH);
  distance1 = (duration1/2)/28.5;
  Serial.println(distance1);
  
  
  digitalWrite(ledred, 255);
  digitalWrite(ledgreen, 255);
  digitalWrite(ledyellow, 255);
  
  
  if(distance1 > 9 && distance1 < 15)
  {
    digitalWrite(ledred, 0);
    digitalWrite(13, LOW);
    delay(800);
  }
  /*else
  {
    pinMode(ledred, 0);
    pinMode(13, HIGH);
    //delay(1000);
  }
  */
  else if(distance1 > 14  && distance1 < 20)
  {
    
    digitalWrite(ledgreen, 0);
    delay(800);
  }
  /*
  else
  {
    pinMode(ledgreen, 0);
  }*/
  
  else if(distance1 > 19 && distance1 < 25)
  {
    digitalWrite(ledyellow, 0);
    delay(800);
  }
  else
  {
    digitalWrite(ledred, 255);
    digitalWrite(ledyellow, 255);
    digitalWrite(ledgreen, 255);
  }
  

}
