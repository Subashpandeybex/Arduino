int led = 13;

void setup ()

{

pinMode (13, OUTPUT); // We configure the output pin 13

digitalWrite (led, HIGH);

Serial.begin (9600); // we begin the serial port

}

void loop ()
{char data;


if(Serial.available ()>0)

{

     data = Serial.read ();
}

if (data == 'n') // If we send an 'a' turn off the led
{
     digitalWrite (led, HIGH);
}
if(data == 'f')
{

      digitalWrite (led, LOW);

}
/*
if (data == 'b') {// If we send a 'b' turn on the LED

Serial.write (data);

data = 0;

digitalWrite (led, HIGH);

}

}
*/
}

