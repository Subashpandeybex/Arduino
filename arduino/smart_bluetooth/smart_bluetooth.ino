// Smartphone Controlled Arduino Robot
int leftforward = 2;
int leftbackward = 13;
int rightforward = 4;
int rightbackward = 5;
//int vel = 255; // Velocidad de los motores (0-255)
//int estado = 'g'; // inicia detenido
  

void setup() {

  Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth

pinMode(leftforward, OUTPUT);
pinMode(leftbackward, OUTPUT);
pinMode(rightforward, OUTPUT);
pinMode(rightbackward, OUTPUT);
}

void loop() {
char e;
  char f = 0;
  while(Serial.available()>0){ // lee el bluetooth y almacena en estado
     e = Serial.read();
     f+=e;
}
if(f=='FORWARD'){ // Forward
//Serial.println(estado);
digitalWrite(leftbackward, HIGH);
//analogWrite(rightbackward,LOW);
//analogWrite(leftforward, HIGH);
//analogWrite(leftforward, HIGH);
delay(500);
}

/*
if(f=='RIGHT'){ // right
//Serial.println(estado);
analogWrite(rightforward, HIGH);
analogWrite(rightbackward, LOW);
analogWrite(leftforward, LOW);
analogWrite(leftbackward, HIGH);
delay(500);
}
if(f=='STOP'){ // Stop
//Serial.println(estado);
analogWrite(leftbackward, LOW);
analogWrite(leftforward, LOW);
analogWrite(rightforward, LOW);
analogWrite(rightbackward, LOW);
delay(500);
}
if(f=='LEFT'){ // left
//Serial.println(eo);
analogWrite(rightforward, LOW);
analogWrite(rightbackward, HIGH);
analogWrite(leftbackward, LOW);
analogWrite(leftforward, HIGH);
delay(500);
}
if(f=="BACKWARD"){ // Reverse
//Serial.println(estado);
analogWrite(leftforward, LOW);
analogWrite(rightforward,LOW);
analogWrite(leftbackward, HIGH);
analogWrite(rightbackward, HIGH);
delay(500);
}

*/
//estado="";
//if (estado =='f'){ // Boton ON se mueve sensando distancia
//}
//if (estado=='g'){ // Boton OFF, detiene los motores no hace nada
//}
//estado="";
}
