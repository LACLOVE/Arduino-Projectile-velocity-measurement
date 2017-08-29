int pin = 13;
int pin1 = 12;
int val,va2;
unsigned long t1=0;
unsigned long t2=0;
unsigned long t;
long v;
int s=1000;
void setup()
{ Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(pin1, OUTPUT);
  attachInterrupt(0, blink0, RISING);
  attachInterrupt(1, blink1, RISING);
}

void loop()
{ 
   float  t=t2-t1;
   float  v=s/t;
   val = digitalRead(pin);
   va2 = digitalRead(pin1);
  if(val==LOW&&va2==HIGH){
  Serial.print("total:");
  Serial.print(t);
  Serial.print("ms");
  Serial.print("\t");
  Serial.print("speed=");
  Serial.print(v);
  Serial.print("mm/ms");
  delay(10000000);
   }
}

void blink0()
{  
  t1=millis();
  Serial.print(t1);
  Serial.print("\n");
  digitalWrite(pin,1);
}
void blink1()
{  
  t2=millis();
  Serial.print(t2);
  Serial.print("\n");
  digitalWrite(pin1,1);
  digitalWrite(pin,0);
}
