int left =11;
int center =10;
int mid=1;
int right=12;
int en=3;   //left B
int en1=5;   //right A
int red=2;
int green=4;
//int extraleft=A2;
//int extraright=A3


int leftforward =6;
int leftbackward =7;
int rightforward =8;
int rightbackward =9;


bool l, c, r, m;

void setup() {
  // put your setup code here, to run once:
pinMode(l,INPUT);
pinMode(c,INPUT);
pinMode(r,INPUT);
pinMode(m,INPUT);
pinMode(leftforward,OUTPUT);
pinMode(leftbackward,OUTPUT);
pinMode(rightforward,OUTPUT);
pinMode(rightbackward,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(en,OUTPUT);
//Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(red,LOW);
  //digitalWrite(green,LOW);
  readSensor();
  
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  
//ROBOT MOVE FORWARD

  if(l && !c && !m && r){
    motorFwd();
    }
    //use led
  if(!l && !c && !m && r){                                                                              //  MOVE STRAIGHT NOT left 
     //delstopmotor();
     //delmotorFwd();
    motorFwd();
     }
  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  

//ALL RIGHT TURN CODE HERE

          //1
   if(l && c && !m && r){
     
     motorRight();
    }         
            //2
  
  if(l && c && m &&!r)                                                                                  // RIGHT TURN
  {
    
    //LEDred();
    
    do{
      motorRight();
      }
    while(l && c && !m && r);
    
    do{
      motorRight();
      }
    while(l && !c && !m && r);
    
   }
   
   //3
   if(l && !c && !m && !r)
   {
     do{
       
       motorRight();
      }
     while(l && c && !m && r);
    
     do{
       motorRight();
      }
     while(l && !c && !m && r);
  
      //4
 if(l && c && !m && !r){ 
   motorRight();
    } 
    
   }
    
  
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  // ALL LEFT TURN CODE HERE
                //1
   if(l && !c && m && r){ 
     motorLeft();
    }
             //2
  if(!l && c && m && r){      //LEFT TURN
  
     ///LEDred();
     
   
     do{
       motorLeft();
     
     }
     while(l && !c && m && r);
        
     do{
       motorLeft();
       }
     while(l && !c && !m && r);
   delay(500);
}
            //3
if(!l && !c && m && r){ 
  motorLeft();
    }
  
  
  
  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  //T-JUNCATION --LEFT IS FIRST PRIORITY ORDER
  
  if(!l && c && m &&!r )                                                                //T-JUNCATION --LEFT IS FIRST PRIORITY ORDER SO ROBOT IS LEFT TURN
  {
    //LEDred();
    
    do{
      motorRight();
      }
    while(l && c && !m && r);
    
    do{
      motorRight();
      }
    while(l && !c && !m && r);   
  
  }
  //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  // 180 DEGREE RIGHT TURN
  
  if(l && c && m && r)                                                                 // 180 DEGREE RIGHT TURN
  {
    
    do{
      motorRot();
    }
    while(l && c && m && !r);
    do{
      motorRight();
      }
    while(l && c && !m && r);
    
    do{
      motorRight();
      }
    while(l && !c && !m && r);
  }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  
  
  //STOP IN THE DESTINATION  
  
  if(!l && !c && !m &&! r)                                                                                    //STOP IN THE DESTINATION  
  {
    
    stopmotor();
    deLEDgreen();
  } 
} 


void readSensor(){
  l = digitalRead(left);
  c = digitalRead(center);
  r = digitalRead(right);
  m = digitalRead(mid);
}


void motorFwd(){
    //Fod 
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
  analogWrite(en,83);
  analogWrite(en1,101);
 }
 
  
void motorBack()
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,HIGH);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,HIGH);
  analogWrite(en,58);
  analogWrite(en1,80);
}
      
   
   
void motorLeft()
{
   digitalWrite(leftforward,LOW);
   digitalWrite(leftbackward,HIGH);
   digitalWrite(rightforward,HIGH);
   digitalWrite(rightbackward,LOW);
   analogWrite(en,46);
   analogWrite(en1,64);
   
}


void motorRight()
{
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,HIGH);
  analogWrite(en,51); //left
  analogWrite(en1,69); //right
}
   
void motorRot()
{
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,HIGH);
  analogWrite(en,46);
  analogWrite(en1,64);
}
  
void stopmotor()
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,LOW);
  analogWrite(en,58);
  analogWrite(en1,80);
}  
  
void delstopmotor()
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,LOW);
  digitalWrite(red,HIGH);
  analogWrite(en,58);
  analogWrite(en1,80); 
 // delay(1000);
}

void delmotorFwd(){
    //Fod 
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
  analogWrite(en,58);
  analogWrite(en1,80);
  //delay(100);
 }  
  
  
void powerLeft(){
    //Fod 
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,HIGH);
  digitalWrite(rightforward,HIGH);
  digitalWrite(rightbackward,LOW);
  analogWrite(en,58);
  analogWrite(en1,80);
}

void powerRight(){
    //Fod 
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,HIGH);
  analogWrite(en,58);
  analogWrite(en1,80);
}

void LEDred()
{
  digitalWrite(red,HIGH);
}
        
void LEDgreen()
{
  digitalWrite(green,HIGH);
}

void deLEDred()
{
  digitalWrite(red,HIGH);
  //delay(1000);
}
        
void deLEDgreen()
{
  digitalWrite(green,HIGH);
  //delay(1000);
}   
    
