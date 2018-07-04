boolean y[8] ;
float actualAngle1 ;
float actualAngle2 ;
char mode;
char actionPh1;
char actionPh3;
float motionValue;
int noOfNumbers ;
int number[10];
int x = ',';

const byte trig = 11 ;
const byte echo = 10;

long duration ;
int distance ;

//declare motor pins 
const byte mrf = 52 ;
const byte mrb = 53 ;
const byte mlf = 50 ;
const byte mlb = 51 ;
const byte mrs = 7 ;
const byte mls = 9 ;

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

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  Serial.begin(9600);
  
  pinMode(30,INPUT);
  pinMode(31,INPUT);
  pinMode(32,INPUT);
  pinMode(33,INPUT);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
  pinMode(36,INPUT);
  pinMode(37,INPUT);
  pinMode(38,INPUT);   
}

void loop()
{
  if(Serial.available() > 0)
  {
    mode = Serial.read();
    if(mode == '1')
    {
      while(1)
      {
        if(Serial.available() > 0)
        {
          digitalWrite(trig , LOW);
          delayMicroseconds(2);
          digitalWrite(trig , HIGH);
          delayMicroseconds(10);
          digitalWrite(trig , LOW);
          
          duration = pulseIn(echo , HIGH) ;
          distance = duration * (0.034/2) ;
          
          actionPh1 = Serial.read();
          if(distance <= 40)
          {
            left();
          }
          else if(actionPh1 == 'F' && distance > 40)
          {
            forward();
          }
          else if(actionPh1 == 'B')
          {
            backward();
          }
          else if(actionPh1 == 'R')
          {
            right();
          }
          else if(actionPh1 == 'L')
          {
            left();
          }
          else if(actionPh1 == 'S')
          {
            stopp();
          }
          if(actionPh1 == 'o')
          {
            break;
          }
          Serial.println(actionPh1);
        }
      }
    }
    else if(mode == '3')
    {
      while(1)
      {
        actualAngle1 = 0;
        for(int i = 0 ; i <= 7 ; i++ )
        {
          y[i] = digitalRead(i+30);
          actualAngle1 += (y[i]*pow(2,i));      
        }
        if(digitalRead(38) == 1)
        {
          actualAngle1 = actualAngle1 * -1;
        }
        if(Serial.available() > 0)
        {
          actionPh3 = Serial.read();
          if(actionPh3 == 'r')
          {
            noOfNumbers = 0 ;
            do
            {
              x = Serial.read();
              if((x >= 48) && (x <= 57))
              {
               number[noOfNumbers] = x - 48 ;
               noOfNumbers ++;
              }
              if(noOfNumbers >= 9)
              {
                break;
              }
            }while(x != '.');
          
            motionValue = 0 ;
            for(int i = 0 ; i < noOfNumbers ; i++)
            {
              motionValue += number[i] * pow(10 , noOfNumbers - 1 - i);
            }
            Serial.println(actualAngle1);
            while( ((actualAngle2 - actualAngle1) < (motionValue - 5)) || ((actualAngle2 - actualAngle1) > (motionValue + 5)) )
            {
              right();
              actualAngle2 = 0;
              for(int i = 0 ; i <= 7 ; i++ )
              {
                y[i] = digitalRead(i+30);
                actualAngle2 += (y[i]*pow(2,i));      
              }
              if(digitalRead(38) == 1)
              {
                actualAngle2 = actualAngle2 * -1;
              }
              Serial.println(actualAngle2);
              if((actualAngle2 - actualAngle1) < 0)
              {
                actualAngle2 = actualAngle2 + 360 ;
              }
            }
            stopp();
          }
      
          if(actionPh3 == 'l')
          {
            noOfNumbers = 0 ;
            do
            {
              x = Serial.read();
              if((x >= 48) && (x <= 57))
              {
               number[noOfNumbers] = x - 48 ;
               noOfNumbers ++;
              }
              if(noOfNumbers >= 9)
              {
                break;
              }
            }while(x != '.');
          
            motionValue = 0 ;
            for(int i = 0 ; i < noOfNumbers ; i++)
            {
              motionValue += number[i] * pow(10 , noOfNumbers - 1 - i);
            }
            Serial.println(actualAngle1);
            while( ((actualAngle1 - actualAngle2) < (motionValue - 5)) || ((actualAngle1 - actualAngle2) > (motionValue + 5)) )
            {
              left();
              actualAngle2 = 0;
              for(int i = 0 ; i <= 7 ; i++ )
              {
                y[i] = digitalRead(i+30);
                actualAngle2 += (y[i]*pow(2,i));      
              }
              if(digitalRead(38) == 1)
              {
                actualAngle2 = actualAngle2 * -1;
              }
              Serial.println(actualAngle2);
              if((actualAngle1 - actualAngle2) < 0)
              {
                actualAngle2 = actualAngle2 - 360 ;
              }
            }
            stopp();
          }
          else if(actionPh3 == 'o')
          {
            break;
          }
        }
      }
    }
  }
}
