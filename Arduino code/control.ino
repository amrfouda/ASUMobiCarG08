const byte mrf = 52 ;
const byte mrb = 53 ;
const byte mlf = 50 ;
const byte mlb = 51 ;
const byte mrs = 2 ;
const byte mls = 3 ;


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
 
}

void loop() 
{
 
}
