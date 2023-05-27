int enablePin1 = 12; //digital pwm
int enablePin2 = 13; //digital pwm
int r1 = 0;

int r2 = 1;

int l1 = 24;
int l2 = 25;

int potPin = 28;               
void setup()

{

pinMode(r1, OUTPUT);

pinMode(r2, OUTPUT);

pinMode(l1, OUTPUT);

pinMode(l2, OUTPUT);

pinMode(enablePin1, OUTPUT);
pinMode(enablePin2, OUTPUT);
}

void loop()         

{

int speed1 = analogRead(potPin)/4;


/*setMotor(speed);

}

void setMotor(int speed)

{*/
/*int speed2 = map(speed1, 0, 255, 0, 1023); //converting pot's range of values to the range compatible with digital PWM*/
analogWrite(enablePin1, speed1);
analogWrite(enablePin2, speed1);
digitalWrite(l1,1);

digitalWrite(l2,0);

digitalWrite(r1,1);

digitalWrite(r2,0);

}
