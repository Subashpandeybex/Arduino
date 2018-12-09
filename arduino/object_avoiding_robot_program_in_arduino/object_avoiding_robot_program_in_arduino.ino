const int trig =12;
const int echo = 11;
const int leftForward = 2;
const int leftBackward =3;
const int rightForward = 4;
const int rightBackward =5;

int duration = 0;
int distance = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  
  duration = pulseIn(echo , HIGH);
  distance = (duration/2)/28.5;
  Serial.println(distance);
  
  if (distance < 15)
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , HIGH);
  }
  else
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }
} 
