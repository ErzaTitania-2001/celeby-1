//#include <Servo.h> 
#include <IRremote.h> 
#include "pins_arduino.h"
int c1=5;
int ac1=6;
int c2=7;
int ac2=8;
const int en1=4;
const int en2=9;                                   
//initialising all dc motor amd servo motor pins
/*80BF53AC-F 20DFD02F

80BF4BB4-B
80BF9966-L
80BF837C-R
80BF738C-S
*/
/*AF_DCMotor motor1(1); //one johnson motor ON RIGHT
AF_DCMotor motor2(2); //second johnson motor ONB LEFT
AF_DCMotor motor3(3); //setting arm motor*/

//Servo servo1;
//int i;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
//unsigned long preMillis;
unsigned long val;
void setup() 
{
  irrecv.enableIRIn(); // Start the receiver
  
  //servo1.attach(9); //servo port attached
  Serial.begin(9600);
  pinMode(c1,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(ac1,OUTPUT);
  pinMode(ac2,OUTPUT);
   pinMode(en1,OUTPUT);
    pinMode(en2,OUTPUT);
}


void loop() 
{
  if (irrecv.decode(&results))
    {
     if( results.value!=0xFFFFFFFF)
      val=results.value;  
 Serial.println(val, HEX);
 delay(100);

 if(val==0x20DF10EF) //power button
 {
  Serial.println("Max speed");
  analogWrite(en1,255);
  analogWrite(en2,255);
 }
 if(val==0x20DFC23D) //powerR1 button
 { Serial.println("Half speed");
  analogWrite(en1,200);
  analogWrite(en2,200);
 }
 if(val==0x20DF27D8) //power button
 { Serial.println("One-fourth speed");
  analogWrite(en1,150);
  analogWrite(en2,150);
 }
 if(val==0x20DFD02F) //power button
 {
  Serial.println("100 SPEED");
  analogWrite(en1,100);
  analogWrite(en2,100);
 }
 if(val==0x20DFDA25) //power button
 {
  Serial.println("50 SPEED");
  analogWrite(en1,50);
  analogWrite(en2,50);
 }
 
  if(val==0x20DF02FD)
  {
  Serial.println("FORWARD");
digitalWrite(c1,HIGH);
digitalWrite(c2,HIGH);
digitalWrite(ac1,LOW);
digitalWrite(ac2,LOW);
  }
  if(val==0x20DF827D)
  {
  Serial.println("BACKWARD");
 digitalWrite(c1,LOW);
digitalWrite(c2,LOW);
digitalWrite(ac1,HIGH);
digitalWrite(ac2,HIGH);
   delay(100);
  }
  if(val==0x20DFE01F)
  {
  Serial.println("LEFT");
  digitalWrite(c1,LOW);
  analogWrite(en1, 200);
digitalWrite(c2,HIGH);
digitalWrite(ac1,HIGH);
digitalWrite(ac2,LOW);
  delay(100);
  }
  if(val==0x20DF609F)
  {
  Serial.println("RIGHT");
  digitalWrite(c2,LOW);
  
digitalWrite(c1,HIGH);

digitalWrite(ac1,LOW);
digitalWrite(ac2,HIGH);
   delay(100);
  }
  if(val==0x20DF22DD)
  {
  Serial.println("STOP");
  digitalWrite(c1,LOW);
digitalWrite(c2,LOW);
digitalWrite(ac1,LOW);
digitalWrite(ac2,LOW);
  }
  irrecv.resume();
}
 
}
