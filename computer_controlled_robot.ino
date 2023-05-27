#include<LiquidCrystal.h>
LiquidCrystal lcd(11,10,5,4,3,2);

const int l1=24;
const int l2=25;
const int r1=0;
const int r2=1;

const int e1=16;
const int e2=15;
const int w1=14;
const int w2=13;

void Forward()
{
  digitalWrite(l1,1);
  digitalWrite(l2,0);
  digitalWrite(r1,1);
  digitalWrite(r2,0);  
}


void Stop()
{
  digitalWrite(l1,0);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,0);  

  digitalWrite(e1,0);
  digitalWrite(e2,0);
  digitalWrite(w1,0);
  digitalWrite(w2,0);  
  
}


void reverse()
{
  digitalWrite(l1,0);
  digitalWrite(l2,1);
  digitalWrite(r1,0);
  digitalWrite(r2,1);  
}

void right()
{
  digitalWrite(l1,1);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,1);  
}

void left()
{
  digitalWrite(l1,0);
  digitalWrite(l2,1);
  digitalWrite(r1,1);
  digitalWrite(r2,0);  
}

void elbowup()
{
  digitalWrite(e1,1);
 digitalWrite(e2,0);
}


void elbowdown()
{
  digitalWrite(e1,0);
 digitalWrite(e2,1);
}

void wristup()
{
  digitalWrite(w1,1);
 digitalWrite(w2,0);
}

void wristdown()
{
  digitalWrite(w1,0);
 digitalWrite(w2,1);
}



void setup() {
 Serial.begin(9600);


 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(e1,OUTPUT);
 pinMode(e2,OUTPUT);
 pinMode(w1,OUTPUT);
 pinMode(w2,OUTPUT);

 lcd.begin(16,2);

 lcd.print("HEY!!! WELCOME");
 delay(5000);
}

void loop() {
  lcd.clear();

  while(!Serial.available())
  {
    lcd.clear();
    lcd.print("NO DATA AVAILABLE - STOP");
    delay(50);
    Stop();  
  }

  char c = Serial.read();

  Serial.println(c);
  lcd.print(c);
  delay(50);


 if (c=='l')
 {
  left();
  lcd.print("TURNING LEFT");
  delay(50);
 }

if (c=='r')
 {
  right();
  lcd.print("TURNING RIGHT");
  delay(50);
 }

 if (c=='f')
 {
  Forward();
  lcd.print("GOING FORWARD");
  delay(50);
 }

 
 if (c=='b')
 {
 reverse();
  lcd.print("GOING REVERSE");
  delay(50);
 }


 if (c=='o')
 {
  wristup();
  lcd.print("OPEN");
  delay(50);
 }


 if (c=='c')
 {
  wristdown();
  lcd.print("CLOSE");
  delay(50);
 }

  if (c=='u')
 {
  elbowup();
  lcd.print("ARM UP");
  delay(50);
 }

 if (c=='d')
 {
  elbowdown();
  lcd.print("ARM DOWN");
  delay(50);
 }

}
