

int pb1 = 2;
int pb2 = 3;
int led=13 ;
volatile int x = 1; 

void setup() {
   pinMode(led, OUTPUT); //set pin 13 as output
   attachInterrupt(digitalPinToInterrupt(pb1), inc, RISING);
   attachInterrupt(digitalPinToInterrupt(pb2), dec, RISING);
   
} 
void loop() { 
   digitalWrite(led, LOW);
   delay(x*1000);
   digitalWrite(led, HIGH);
   delay(x*1000);
} 

void inc() { 
   x=x+1;
}
void dec() { 
   x=x-1;
}
