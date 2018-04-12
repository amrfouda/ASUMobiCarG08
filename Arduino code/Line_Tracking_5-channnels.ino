const byte mrf = 52 ;
const byte mrb = 53 ;
const byte mlf = 50 ;
const byte mlb = 51 ;
const byte mrs = 2 ;
const byte mls = 3 ;

int action = 0 ;

const int l2 = 4;
const int l1 = 5;
const int c = 6;
const int r1 = 7;
const int r2 = 10;
int l2state=0;
int l1state=0;
int cstate=0;
int r1state=0;
int r2state=0;



void forward()
{
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , LOW);
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , HIGH);
  analogWrite(mrs,255);
  analogWrite(mls,255);
}

void backward()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,255);
  analogWrite(mls,255);
}

void right()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,255);
  analogWrite(mls,255);
}

void left()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,255);
  analogWrite(mls,255);
}

void forwardRight()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,20);
  analogWrite(mls,255);
}

void forwardLeft()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,255);
  analogWrite(mls,20);
}

void backwardRight()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,20);
  analogWrite(mls,255);
}

void backwardLeft()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,255);
  analogWrite(mls,20);
}
void stopp()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , LOW);
  analogWrite(mrs, 0);
  analogWrite(mls, 0);
}

void setup() 
{
  pinMode(mrf , OUTPUT);
  pinMode(mrb , OUTPUT);
  pinMode(mrs , OUTPUT);
  pinMode(mlf , OUTPUT);
  pinMode(mlb , OUTPUT);
  pinMode(mls , OUTPUT);

  pinMode(l1,INPUT);
  pinMode(l2,INPUT);
  pinMode(c,INPUT);
  pinMode(r1,INPUT);
  pinMode(r2,INPUT);

  
  Serial.begin(9600);
  
}

void loop() 
{


  l2state = digitalRead(l2);
  l1state = digitalRead(l1);
  cstate = digitalRead(c);
  r1state = digitalRead(r1);
  r2state = digitalRead(r2);
  
  if(l2state == HIGH)
  {
    left();
  }
  if(l1state == HIGH)
  {
    forwardleft();
  }
  if(cstate == HIGH)
  {
    forward();
  }
  if(r1state == HIGH)
  {
    forwardright();
  }
  if(r2state == HIGH)
  {
    right();
  }
  
}
