//to input the test temperature, display it and as well as display the increasing temperatures.
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
const int sensor=A0;
int sensor_temp;
int temp=1;
int relay=9;
/*int pump=10;
 char Tempc;
 
 String temp_S="";
 
char octaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {1,2,3,4};
byte colPins[COLS] = {5,6,7,8};
Keypad customKeypad = Keypad(makeKeymap(octaKeys), rowPins, colPins, ROWS, COLS); //mapping my whole keypad
LiquidCrystal_I2C lcd(0x21, 16, 2);  */

void setup(){
  digitalWrite(sensor, INPUT);
  //lcd.backlight();
  //lcd.init(); 
  digitalWrite(relay,LOW);
  Serial.begin(9600);
}
void loop()
{ 
  Serial.println("HEy there1!");
/*while(Tempc!='C') //only made in centigradfe. can give them farenheit facility too. discuss.
{
   Tempc = customKeypad.getKey();
   temp=(temp*10)+atoi(Tempc);
  temp_S+=Tempc;
  if (Tempc){
    lcd.clear();  //clear screening
    lcd.setCursor(0, 0); 
    lcd.print(Tempc); //displaying inputted temperature
  }
}*/
//temp=temp_S.toFloat();
digitalWrite(relay,HIGH);
delay(100);
 //Serial.println(" Stopping temperature is: "+temp);//integer stopping temperature
 //after this lcd will display the sensor read temperatures
 Serial.println("HEy there!");
float vout=analogRead(sensor); //Reading the value from sensor
vout=(vout*500)/1023;
   sensor_temp= vout;            //conversion to temp Celsius
Serial.print(sensor_temp);
Serial.println(" degree centigrade");
delay(500);
  if(sensor_temp==(temp))   //assuming temperature loss is 5
  {
    //digitalWrite(relay,LOW);
    //igitalWrite(pump, HIGH);
   Serial.println("PUMP IS STARTING TO WORK ARDUINO DID IT'S WORK");
    delay(10000);
  }
  /*else
  {
    Serial.print("Temperature= "); 
  Serial.println(temp);
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(sensor_temp);
  lcd.print(" C");
  }*/
}
