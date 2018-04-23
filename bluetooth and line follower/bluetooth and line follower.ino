//declare motor pins 
const byte mrf = 52 ;
const byte mrb = 53 ;
const byte mlf = 50 ;
const byte mlb = 51 ;
const byte mrs = 2 ;
const byte mls = 3 ;
//declare ultrasonic pins
const byte trig = 11 ;
const byte echo = 9 ;
int action = 0 ;
int action1 = 0 ;

// ultrasonic variable
long duration ;
int distance ;
//line follower pins
const int l2 = 4;
const int l1 = 5;
const int c = 6;
const int r1 = 7;
const int r2 = 10;
//line follwer variables
int l2state;
int l1state;
int cstate ;
int r1state;
int r2state;

void forward()
{
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , LOW);
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , HIGH);
  analogWrite(mrs,200);
  analogWrite(mls,200);
}

void backward()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,200);
  analogWrite(mls,200);
}

void right()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,200);
  analogWrite(mls,200);
}

void left()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,200);
  analogWrite(mls,200);
}
void right2()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,160);
  analogWrite(mls,160);
}

void left2()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,160);
  analogWrite(mls,160);
}

void forwardRight1()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,60);
  analogWrite(mls,200);
}

void forwardLeft1()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,200);
  analogWrite(mls,60);
}

void forwardRight2()
{
  digitalWrite(mrf , LOW);
  digitalWrite(mlf , HIGH);
  digitalWrite(mrb , HIGH);
  digitalWrite(mlb , LOW);
  analogWrite(mrs,80);
  analogWrite(mls,255);
}

void forwardLeft2()
{
  digitalWrite(mrf , HIGH);
  digitalWrite(mlf , LOW);
  digitalWrite(mrb , LOW);
  digitalWrite(mlb , HIGH);
  analogWrite(mrs,255);
  analogWrite(mls,80);
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
{ if(Serial.available() > 0)
  {
    action1 = Serial.read();
    if(action1=='X')
    {
      l2state = digitalRead(l2);
  l1state = digitalRead(l1);
  cstate = digitalRead(c);
  r1state = digitalRead(r1);
  r2state = digitalRead(r2);
  
  if( cstate == 1 && r2state == 1 )
  {
    forward();
  }
  else if( cstate == 1 && r1state == 1 )
  {
    forwardRight1(); 
  }
  else if( cstate == 1 && l1state == 1 )
  {
    forwardLeft1();
  }
  else if( r1state == 1 && r2state == 1 )
  {
    forwardRight2(); 
  }
  else if( l1state == 1 && l2state == 1 )
  {
    forwardLeft2(); 
  }
  else if( cstate == 1 )
  {
    forward();
  }
  else if(l1state == 1 )
  {
    left2(); 
  }
  else if(r1state == 1 )
  {
    right2();
  }
  else if(l2state == 1 )
  {
    left();
  }
  else if(r2state == 1 )
  {
    right();
  }
    }
    else if (action1=='x')
    {
     digitalWrite(trig , LOW);
  delayMicroseconds(2);
  digitalWrite(trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH) ;
  distance = duration * (0.034/2) ;
  
  if(Serial.available() > 0)
  {
    action = Serial.read();

    if(action == 'F')
    {
      forward();
    }
   
    
    else if(action == 'B')
    {
      backward();
    }
    else if(action == 'R')
    {
      right();
    }
    else if(action == 'L')
    {
      left();
    }
    else
    {
      stopp();
    }
  }
  
    }
    
    
   
  }
}

