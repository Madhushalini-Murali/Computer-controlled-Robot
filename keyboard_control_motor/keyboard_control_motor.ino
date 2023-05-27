#include<LiquidCrystal.h>
LiquidCrystal lcd(11,10,5,4,3,2);

const int l1 = 0;
const int l2 = 1;
const int r1 = 24;
const int r2 = 25;
const int en =13; 

void Forward ()
{   
  digitalWrite(l1,1);
  digitalWrite(l2,0);
  digitalWrite(r1,1);
  digitalWrite(r2,0);
}
void Stop ()
{
  digitalWrite(l1,0);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,0);
  }

void Reverse()
{
  digitalWrite(l1,0);
  digitalWrite(l2,1);
  digitalWrite(r1,0);
  digitalWrite(r2,1);
  
}

void Right ()
{
  digitalWrite(l1,1);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,1);
}

void Left ()
{
  digitalWrite(l1,0);
  digitalWrite(l2,1);
  digitalWrite(r1,1);
  digitalWrite(r2,0);
}
void ConForward()

{ analogWrite(en,127); 
  digitalWrite(l1,1);
  digitalWrite(l2,0);
  digitalWrite(r1,1);
  digitalWrite(r2,0);
}


void ConReverse()
{ analogWrite(en,127);
  digitalWrite(l1,0);
  digitalWrite(l2,1);
  digitalWrite(r1,0);
  digitalWrite(r2,1);
  
}

void ConRight ()
{ analogWrite(en,127);
  digitalWrite(l1,1);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,1);
}

void ConLeft ()
{ analogWrite(en,127);
  digitalWrite(l1,0);
  digitalWrite(l2,1);
  digitalWrite(r1,1);
  digitalWrite(r2,0);
}


void setup()
{
  Serial.begin(9600);

  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);  
  lcd.begin(16,2);
  delay(1000);
}

void loop()
{
  lcd.clear();
  while(!Serial.available())
  {
    lcd.clear();
    Stop();
  }
  char c = Serial.read();
   Serial.println(c);
  lcd.print(c);
  delay(50);

  if(c == 'A')
  {
    Left();
    lcd.print("turning left");
    delay(50);
   }

   if(c == 'D')
   {
    Right ();
    lcd.print("turning right");
    delay(50);
   }

   if(c == 'W')
   {
    Forward ();
    lcd.print("moving forward");
    delay(50);
   }

   if(c == 'S')
   {
     Reverse();
     lcd.print("moving backwards");
     delay(50);
   }
   if(c == 'a')
  {
    ConLeft();
    lcd.print("turning left");
    delay(50);
   }

   if(c == 'd')
   {
    ConRight ();
    lcd.print("turning right");
    delay(50);
   }

   if(c == 'w')
   {
    ConForward ();
    lcd.print("moving forward");
    delay(50);
   }

   if(c == 's')
   {
     ConReverse();
     lcd.print("moving backwards");
     delay(50);
   }
   
   }
