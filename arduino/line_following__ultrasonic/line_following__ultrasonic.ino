//..................IR seensor pin
int left =11;
int center =10;
int mid=0;
int right=12;
//...................enable pin for motor
int en=3;   //left B
int en1=5;   //right A
//.......................LED BULB pin
int red=A0;
int green=A1;
int yellow = A2;
//....................................

//......................left ultrasonic
const int trig1 =13;
const int echo1 = 1;
int duration1 = 0;
int distance1 = 0;
//........................right ultrasonic
const int trig2 =2;
const int echo2 = 4;
int duration2 = 0;
int distance2 = 0;
//.....................motor
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
pinMode(en,OUTPUT);

pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(yellow,OUTPUT);
//Serial.begin(9600);

pinMode(trig1 , OUTPUT);
pinMode(echo1, INPUT);

pinMode(trig2 , OUTPUT);
pinMode(echo2 , INPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //..........................................................................................................................................................................
  digitalWrite(trig1 , HIGH);
    delay(1);
  digitalWrite(trig1 , LOW);
                                                                             // left ultrasonic sensor
  // Ultra sonic code distance measure 
  duration1 = pulseIn(echo1 , HIGH);
  distance1 = (duration1/2)/28.5;
    //Serial.println(distance1);
  //..........................................................................................................................................................................
  digitalWrite(trig2 , HIGH);
    delay(1);
  digitalWrite(trig2 , LOW);
                                                                       // right ultrasonic sesnsor
  // Ultra sonic code distance measure
  duration2 = pulseIn(echo2 , HIGH);
  distance2 = (duration2/2)/28.5;
    Serial.println(distance2);
  //...................................................................................................................................................................................
  // IR sensor 
  //digitalWrite(red,LOW);
  //digitalWrite(green,LOW);
  readSensor();
  
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  
//ROBOT MOVE FORWARD

  if(l && !c && !m && r){
    motorFwd();
    }
    //use led
  if(!l && !c && !m && r){                                                                              //  MOVE STRAIGHT NOT RIGHT 
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
    
    ///LEDred();
    do{
      motorRight();
      }
    while(l && c && !m && r);
    
    do{
      motorRight();
      }
    while(l && !c && !m && r);
    delay(200);
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
    
 if(l && c && !m && !r){ 
     motorRight();
   }
   
          //4
   
    }
    
  
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  // ALL LEFT TURN CODE HERE
                //1
   if(l && !c && m && r){ 
    motorLeft();
    }
             //2
   if(!l && c && m && r){                                                                      //LEFT TURN
     //LEDred();
   
     do{
       motorLeft();
     }
     while(l && !c && m && r);
   
     do{
       motorLeft();
       }
     while(l && !c && !m && r);
     delay(200);
  
  }
            //3
  if(!l && !c && m && r){ 
    motorLeft();
    }
  
  
  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  //T-JUNCATION --LEFT IS FIRST PRIORITY ORDER
  
  if(!l && c && m &&!r )                                                                //T-JUNCATION --LEFT IS FIRST PRIORITY ORDER SO ROBOT IS LEFT TURN
  {
    LEDred();
    
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
    //deLEDgreen();
  } 
  
  //......................................................................................................................................................................................
                                                                              
  // ultrasonic in 5 cm
  if (distance1 >=4 && distance1 <= 10)                                
  {
    //stopmotor();
    LEDred();
    //delay(500);
  }
  else
  {
    LEDredoff();                                                             // 5 cm
  }
  
  if (distance2 >= 4 && distance2 <= 10)                                
  {
    //stopmotor();
    LEDred();
    //delay(500);
  }
  else
  {
    LEDredoff();
  }
  
  
   //......................................................................................................................................................................................
  
  // ultrasonic in 10 cm
  if (distance1 >= 9 && distance1 <= 15 )
  {
    //stopmotor();
    LEDgreen();
    //delay(500);
  }
  else
  {
    LEDgreenoff();                                                               // 10cm
  }
  if (distance2 >= 9 && distance2 <= 15 )
  {
    //stopmotor();
    LEDgreen();
    //delay(500);
  }
  else
  {
    LEDgreenoff();
  }
  
  
   //......................................................................................................................................................................................
  
  // ultrasonic in 15 cm
  if (distance1 >= 14 && distance1 <= 20)
  {
   // stopmotor();
    LEDyellow();
    //delay(500);
  }
  else
  {
    LEDyellowoff();                                                                   // 15 cm
  }
  
  if (distance1 >= 14 && distance2 <= 20)
  {
   // stopmotor();
    LEDyellow();
    //delay(500);
  }
  else
  {
    LEDyellowoff();
  }
  
//........................................................................................................................................................................................  
} 
//.....................................................................................................................................................................................

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
  analogWrite(en,58);
  analogWrite(en1,76);
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
  analogWrite(en,46);
  analogWrite(en1,64);
}

   
void motorRot()
{
  digitalWrite(leftforward,HIGH);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,HIGH);
  analogWrite(en,43);
  analogWrite(en1,61);
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
/*  
void delstopmotor()
{
  digitalWrite(leftforward,LOW);
  digitalWrite(leftbackward,LOW);
  digitalWrite(rightforward,LOW);
  digitalWrite(rightbackward,LOW);
  digitalWrite(red,HIGH);
  analogWrite(en,58);
  analogWrite(en1,80); 
  //delay(1000);
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
*/
void LEDred()
{
  digitalWrite(red,HIGH);
}
        
void LEDgreen()
{
  digitalWrite(green,HIGH);
}

void LEDyellow()
{
  digitalWrite(yellow,HIGH);
}

void LEDredoff()
{
  digitalWrite(red,LOW);
}

void LEDgreenoff()
{
  digitalWrite(green,LOW);
}

void LEDyellowoff()
{
  digitalWrite(yellow,LOW);
}

/*
void deLEDred()
{
  digitalWrite(red,HIGH);
  //delay(1000);
}
        
void deLEDgreen()
{
  digitalWrite(green,HIGH);
  ///delay(1000);
}   

void deLEDyellow()
{
  digitalWrite(yellow,HIGH);
  ///delay(1000);
}   
    */
