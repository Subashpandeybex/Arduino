int L =2;
int C =3;
int R =4;
int leftforward =6;
int leftbackward =7;
int rightforward =8;
int rightbackward =9;
int vl[3];

void setup() {
  // put your setup code here, to run once:
  pinMode(L,INPUT);
  pinMode(R,INPUT);
  pinMode(C,INPUT);
  pinMode(leftforward,OUTPUT);
  pinMode(leftbackward,OUTPUT);
  pinMode(rightforward,OUTPUT);
  pinMode(rightbackward,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  
  vl[0] = digitalRead(L);
  vl[1] = digitalRead(C);
  vl[2] = digitalRead(R);



if(vl[0]=0,vl[1]=0,vl[2]=0)
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,LOW);
}
if(vl[0]=1,vl[1]=0,vl[2]=1)
{
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
}
if(vl[0]=0,vl[1]=0,vl[2]=1)
{
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,HIGH);
}
if(vl[0]=1,vl[1]=0,vl[2]=0)
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,HIGH);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
}


}
