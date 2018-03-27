const byte mrf = 52 ;
const byte mrb = 53 ;
const byte mlf = 50 ;
const byte mlb = 51 ;
const byte mrs = 2 ;
const byte mls = 3 ;
const byte trig = 9 ;
const byte echo = 8 ;
int action = 0 ;

long duration ;
int distance ;

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
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  Serial.begin(9600);
  
}

void loop() 
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

    if(action == 'F' && distance > 40)
    {
      forward();
    }
    else if(action == 'F' )
    {
      while(distance <= 40)
      {
        left();
        
        delay(500);
        digitalWrite(trig , LOW);
        delayMicroseconds(2);
        digitalWrite(trig , HIGH);
        delayMicroseconds(10);
        digitalWrite(trig , LOW);

        duration = pulseIn(echo , HIGH) ;
        distance = duration * (0.034/2) ;
        
      }
      
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

    else if(action == 'G')
    {
      forwardLeft();
    }

    else if(action == 'I')
    {
      forwardRight();
    }

    else if(action == 'H')
    {
      backwardLeft();
    }
    
    else if(action == 'J')
    {
      backwardRight();
    }
    else
    {
      stopp();
    }
  }
  
}
