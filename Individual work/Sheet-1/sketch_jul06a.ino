void zero()
{
  
  digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,0);
}
void one()
{
digitalWrite(0,0);
digitalWrite(1,1);
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
}
void two ()
{
  digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,0);
  digitalWrite(6,1);
}
void three ()
{
   digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,0);
  digitalWrite(6,1);
}
void four ()
{
   digitalWrite(0,0);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
}
void five ()
{
  
   digitalWrite(0,1);
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
}
void six ()
{
  
   digitalWrite(0,1);
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
}
void seven()
{
   digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
}
void eight ()
{
  
   digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
}
void nine ()
{
  
   digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
}
void setup() {
  // put your setup code here, to run once:
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   int t = 1000 ;
  zero();
  delay( t );
  one ();
 delay (t);
 two ();
 delay (t);
 three ();
 delay (t);
 four();
 delay (t);
 five();
 delay (t);
 six();
 delay (t);
 seven();
 delay (t);
 eight();
 delay (t);
 nine();
 delay (t);
}


