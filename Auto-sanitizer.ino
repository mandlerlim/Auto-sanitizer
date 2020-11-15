#include <Servo.h>

int trig = 8;
int echo = 9;
Servo servo;

int ussreading;
int prevstate = LOW;

long time = 0; 
long debounce = 1000; 

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(10);
  servo.write(120);

}

void loop() 
  {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  unsigned long duration = pulseIn(echo, HIGH);
 
  float distance = duration / 29.0 / 2.0;

  if(distance > 2.0 && distance <12)
  {
  ussreading = HIGH;
  }
  else
  ussreading = LOW;
  
  if (ussreading == HIGH && prevstate == LOW && millis() - time > debounce)
    {
    servo.write(55);
    delay(300);
    servo.write(120);
    }
    else                 
     time = millis();
  
  prevstate = ussreading;
  delay(200);
}


  
