
 / Ultrasonic sensor variables
const int ultrasonicTrigger = 6; //pin selection for trigger
const int ultrasonicEcho = 7;      //pin selection for echo
unsigned long ultrasonicValue=0;
float distance=0;
/*
* distance  value
* 
* <20 cm     -ve  & 6<     backward
*
* >30 cm     +ve     forward
*
* 20<x<30 cm  +ve/-ve  standstill
*/
// IR sensor variable
const int irIn_1=A0;
const int irIn_2=A1;
unsigned int irLeft_value=0;
unsigned int irRight_value=0;
/*
*  irLeft    |  irRight
*  
*  Low(<30) | Low(<30)  outof range 
*           |   
*  High(>30)| Low(<30)  left turn
*           |
*  Low(<30) | High(>30)  right turn
*           |
*  High(>30)| High(>30)   stright
*
*/
//motor driving variable
const int motorLeft_A=8;
const int motorLeft_B=9;
const int motorRight_A=10;
const int motorRight_B=11;
/*
* motorLeft    |   motorRight
* A     B     |   A     B
* 0     0     |   0     0     Stop both
*             |
* 1     0     |   1     0     both forward
*             |
* 0     1     |   0     0    both backward
*             |
* 1     1     |   1     1       stop
*             |
*             |
*             |
*/
/*****************************************************/
float sum=0;
int i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setUpUltrasonic();
  setUpIrSensor();
  setUpMotor();
  stopMotor();
}
/*********** Main module******************************************/
void loop() 
{
  /*****************control logic or infinite running module******************/
  //triggerUltra();
  distance=getDistance();
  irLeft_value=0;
  irRight_value=0;
  for(i=0;i<100;i++){
     irLeft_value+=analogRead(irIn_1);
     irRight_value+=analogRead(irIn_2);
      
  }
  irLeft_value/=100;
  irRight_value/=100;
  delayMicroseconds(100);
  sum=getDistance();
  
.  if(irLeft_value>40 && irRight_value<40 ){i
    leftDirection();
    Serial.print("left \n");
  }
  else if(irLeft_value<40 && irRight_value>40){
    rightDirection(); 
    Serial.print("right \n");
   }
   else if(irLeft_value>40 && irRight_value>40){
        if(distance<6 ||((distance<7)&&(accelarationObject(sum,distance)==2))){
          backward(); 
          Serial.print("backward \t");
          Serial.print(distance);
          Serial.print("\n");
         }
        else if(((distance>8)&&(accelarationObject(sum,distance)==1))){
          forward(); 
          Serial.print("forward \t");
          Serial.print(distance);
          Serial.print("\n");
         }  
         else if(((distance<8)&&(distance>7))){
              stopMotor(); 
              Serial.print("stop \t");
              Serial.print(distance);
               Serial.print("\n");
         }
   }
   else{
      stopMotor();
    }
    
}
/*****************************************************************/
void setUpUltrasonic(){
  pinMode(ultrasonicTrigger,OUTPUT);
  pinMode(ultrasonicEcho,INPUT);  
}
void setUpIrSensor(){
  pinMode(irIn_1,INPUT);
  pinMode(irIn_2,INPUT);
}
void setUpMotor(){
  pinMode(motorLeft_A,OUTPUT);
  pinMode(motorLeft_B,OUTPUT);
  pinMode(motorRight_A,OUTPUT);
  pinMode(motorRight_B,OUTPUT);  
}
/*************************************************************************************/
/*******************Ultrasonic functions *************************************************/
float getDistance(){
  sum=0;
  for(i=0;i<100;i++){
    triggerUltra();
    ultrasonicValue=pulseIn(ultrasonicEcho,HIGH);
    distance=ultrasonicValue*0.034/2;
    sum+=distance;
    
    }
    sum/=100;
    return sum;
}
void triggerUltra(){
    digitalWrite(ultrasonicTrigger,LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasonicTrigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonicTrigger,LOW); 
  }
int accelarationObject(float newDis, float oldDis){
 
    if((newDis-oldDis)>0){
        //+ve
        return 1;
      }
      else if((newDis-oldDis)<0){
        //-ve
        return 2;
      }
      else{
          
         return 3;
       }
}
  /***************************************************************************************/
  /****************** Motor control function *************************************************/
void rightDirection(){
  digitalWrite(motorLeft_A,LOW);
  digitalWrite(motorLeft_B,LOW);
  digitalWrite(motorRight_A,HIGH);
  digitalWrite(motorRight_B,LOW);
}
void leftDirection(){
  digitalWrite(motorLeft_A,HIGH);
  digitalWrite(motorLeft_B,LOW);
  digitalWrite(motorRight_A,LOW);
  digitalWrite(motorRight_B,LOW);
}
 void stopMotor(){
  digitalWrite(motorLeft_A,LOW);
  digitalWrite(motorLeft_B,LOW);
  digitalWrite(motorRight_A,LOW);
  digitalWrite(motorRight_B,LOW);
 
 }
 void forward(){
  digitalWrite(motorLeft_A,HIGH);
  digitalWrite(motorLeft_B,LOW);
  digitalWrite(motorRight_A,HIGH);
  digitalWrite(motorRight_B,LOW

}
