int left =11;
int center =10;
int right=12;
int en=3;
int en1=5;
int red=2;
int green=4;
//int extraleft=A2;
//int extraright=A3

int leftforward =6;
int leftbackward =7;
int rightforward =8;
int rightbackward =9;
//int b;

bool l, c, r, m;

void setup() {
  // put your setup code here, to run once:
pinMode(l,INPUT);
pinMode(c,INPUT);
pinMode(r,INPUT);
pinMode(leftforward,OUTPUT);
pinMode(leftbackward,OUTPUT);
pinMode(rightforward,OUTPUT);
pinMode(rightbackward,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(red,INPUT);
pinMode(green,INPUT);
pinMode(en,OUTPUT);
//Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  readSensor();
  
  if(l && !c && r) //ROBOT MOVE FORWAD
  {
  motorFwd();
  }
  

  if(l && c &&!r)// RIGHT TURN
  {
    //delay(50);
    motorRight();
    //LEDred();
  }
  if(!l && c && r){    //LEFT TURN
    motorLeft();
   // LEDred();
  }
  
if(!l && c &&!r )//T-JUNCATION --LEFT IS FIRST PRIORITY ORDER SO ROBOT IS RIGHT TURN
{
  motorLeft();
  //LEDred();
}
if(l && c && r)// 180 DEGREE RIGHT TURN
{
    //motorFwd();
    //delay(50);
  do{
    motorRight();
  }
  while(l && c && !r);
  do{
    motorRot();
    }
    while(l && !c && r);
}
if(!l && !c && r){    //  IF CONDITION IS TURN LEFT OR STRIAGHT MOVE LEFT  
  //LEDred();
  do{
    motorLeft();
  }
  while(!l && c && r);
  do{
    motorLeft();
    }
    while(l && !c && r);
}
if(l && !c && !r){  //  MOVE STRAIGHT NOT RIGHT 
  motorFwd();
  //LEDred();
}
  
if(!l &&! c &&! r)  //STOP IN THE DESTINATION  
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,LOW);
  analogWrite(en,58);
  analogWrite(en1,80); 
 LEDgreen();
} 
} 
void readSensor(){
  l = digitalRead(left);
  c = digitalRead(center);
  r = digitalRead(right);
//  m = digitalRead(mid);
  //el = digitalRead(extraleft);
  //er = digitalRead(extraright);
}

void motorFwd(){
    //Fod
    digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
  analogWrite(en,58);
  analogWrite(en1,80);
 
}
  
  void motorBack(){
      digitalWrite(leftforward,LOW);
      digitalWrite(leftbackward,HIGH);
      digitalWrite(rightforward,LOW);
      digitalWrite(rightbackward,HIGH);
      analogWrite(en,58);
      analogWrite(en1,80);
   }
   
   void motorLeft(){
       digitalWrite(leftforward,LOW);
      digitalWrite(leftbackward,HIGH);
      digitalWrite(rightforward,HIGH);
      digitalWrite(rightbackward,LOW);
      analogWrite(en,58);
      analogWrite(en1,80);
   }
   void motorRight(){
       digitalWrite(leftforward,HIGH);
      digitalWrite(leftbackward,LOW);
      digitalWrite(rightforward,LOW);
      digitalWrite(rightbackward,HIGH);
      analogWrite(en,58);
      analogWrite(en1,80);
   }
   
   void motorRot(){
       digitalWrite(leftforward,HIGH);
      digitalWrite(leftbackward,LOW);
      digitalWrite(rightforward,LOW);
      digitalWrite(rightbackward,HIGH);
      analogWrite(en,33);
      analogWrite(en1,55);
   }
     
     void LEDred(){
       digitalWrite(red,HIGH);
    delay(1000);
     }
     void LEDgreen(){
     digitalWrite(green,HIGH);
      delay(1000);
     } 
