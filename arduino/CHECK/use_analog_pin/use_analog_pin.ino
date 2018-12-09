



//Pin 14 = Analog in 0;
//Pin 15 = Analog in 1;
//Pin 16 = Analog in 2;
//Pin 17 = Analog in 3;
//Pin 18 = Analog in 4;
//Pin 19 = Analog in 5;




int ledPin = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);

}
