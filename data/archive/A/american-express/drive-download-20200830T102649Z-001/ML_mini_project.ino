#include <SoftwareSerial.h> //importimg serial library


char Serialdata=0;
void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);     motor 1 (terminal 1)
pinMode(11,OUTPUT);     motor 2 (terminal 2)
pinMode(9,OUTPUT);      motor 1 (terminal 1)
pinMode(10,OUTPUT);     motor 2 (terminal 2)
//pinMode(10,OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)      //checking whether serial data is available or not
{
  Serialdata=Serial.read();     //reading serial data
  Serial.println(Serialdata);

  if(Serialdata == '0')         //condition 1 : Stop sign detected
  {
    digitalWrite(12,LOW);         //motor 1 off
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);          //motor 2 off
    digitalWrite(10,LOW);
    
  }
  else if(Serialdata == '1')    //condition 2 : turn right
  {
    digitalWrite(12,HIGH);      //motor 1 ON 
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);        //motor 2 OFF
    digitalWrite(10,LOW);
  }
    else if(Serialdata == '2')  //condition 3 : Go straight
  {
    digitalWrite(11,HIGH);      //motor 1 ON
    digitalWrite(12,HIGH);
    digitalWrite(9,LOW);        //motor 2 ON
    digitalWrite(10,LOW);
    
  }
    else if(Serialdata == '3')  //condition 4 : turn left
  {
    digitalWrite(12,LOW);       //motor 1 OFF
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);        //motor 2 ON
    digitalWrite(10,LOW);
}
    else if(Serialdata == '4')  //condition 5: animal crossing detected
  {
    digitalWrite(12,LOW);      //Motor 1 ON (runs slowly)
    analogWrite(11,100);
    digitalWrite(9,LOW);       //Motor 2 ON (runs slowly)
    analogWrite(10,100);
}
}
}
