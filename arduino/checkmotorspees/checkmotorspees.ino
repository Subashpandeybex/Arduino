int en=3;   //left B
int en1=5;   //right A

int leftforward =6;
int leftbackward =7;
int rightforward =8;
int rightbackward =9;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftforward,OUTPUT);
  pinMode(leftbackward,OUTPUT);
  pinMode(rightforward,OUTPUT);
  pinMode(rightbackward,OUTPUT);
  pinMode(en1,OUTPUT);
//pinMode(red,OUTPUT);
//pinMode(green,OUTPUT);
  pinMode(en,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
  //analogWrite(en,78);
  //analogWrite(en1,100);
  digitalWrite(en,HIGH);

}
