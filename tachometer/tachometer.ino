#include <LiquidCrystal.h>
LiquidCrystal lcd(11,10,15,16,17,18);

#define sensor 0


int countrpm()
{
    int i,j;
    unsigned int count=0;
    for(i=0;i<1000;i++) 
    {
      for(j=0;j<1000;j++)
      {
       if(digitalRead(sensor))
       {
         count++;
         delay(100);
       }
    }
  }
    return count;
}

void setup() 
{
  pinMode(sensor, INPUT);
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Tachometer");
}

void loop() 
{
     unsigned int counts=0,RPM=0;
     lcd.clear();
     int oldtime = millis();
     counts=countrpm();
     int newtime = millis();
     int times = newtime - oldtime;
     lcd.clear();
     lcd.print("Times=");
     lcd.print(times);
     RPM=(counts*6000)/times;
     delay(2000);
     lcd.clear();
     lcd.print("RPM=");
     lcd.print(RPM);
     delay(5000);
}
