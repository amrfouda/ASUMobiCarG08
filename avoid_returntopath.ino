//the motor pins//
int rm1=0;
int rm2=1;
int lm1=2;
int lm2=3;
//ultrasonic pins//
int trig1=4;
int echo1=5;
int trig2=6;
int echo2=7;
int trig3=8;
int echo3=9;
  void setup()
  {
    pinMode(rm1,OUTPUT);
    pinMode(rm2,OUTPUT);
    pinMode(lm1,OUTPUT);
    pinMode(lm2,OUTPUT);
    pinMode(trig1,OUTPUT);
    pinMode(echo1,INPUT);
    pinMode(trig2,OUTPUT);
    pinMode(echo2,INPUT);
    pinMode(trig3,OUTPUT);
    pinMode(echo3,INPUT);
    Serial.begin(9600);
  }
  
  void loop ()
  {
    long duration1,distance1,duration2,distance2,duration3,distance3; 
    digitalWrite(trig1,LOW);  //clearing ultrasonic//
    digitalWrite(trig2,LOW);
    digitalWrite(trig3,LOW);
    delayMicroseconds(2);
    digitalWrite(trig1,HIGH); //creating pulse//
    digitalWrite(trig2,HIGH);
    digitalWrite(trig3,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1,LOW);
    digitalWrite(trig2,LOW);
    digitalWrite(trig3,LOW);
    duration1=pulseIn(echo1,HIGH);   //measuring time of pluse//
    duration2=pulseIn(echo2,HIGH);
    duration3=pulseIn(echo3,HIGH);
    distance1=duration1*0.034/2;
    distance2=duration2*0.034/2;
    distance3=duration3*0.034/2;
    
    
    if((distance1<15)&&((distance2>15)||(distance3>15))) //when there is option to turn right ot left trun right//
    { 
      //car turns right//
      digitalWrite(rm1,LOW);  
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      //as long as the obstacle remains continue forward//
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH); 
      //when the obstcale is finished turn left to continue orignal path//
      if(distance3>15)  
     {
       digitalWrite(rm1,LOW);
       digitalWrite(rm2,LOW);
       digitalWrite(lm1,LOW);
       digitalWrite(lm2,HIGH);
       //car returns to orignal path//
       digitalWrite(rm1,LOW);
       digitalWrite(rm2,HIGH);
       digitalWrite(lm1,LOW);
       digitalWrite(lm2,HIGH); 
     }
    }
    
    else if ((distance1<15)&&(distance2<15)&&(distance3>15)) //no option but to turn left//
    {
      //car turns left//
       digitalWrite(rm1,LOW);
       digitalWrite(rm2,LOW);
       digitalWrite(lm1,LOW);
       digitalWrite(lm2,HIGH);
      //as long as the obstacle remains continue forward//
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH); 
      if(distance2>15)
      {
      digitalWrite(rm1,LOW);  
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      //car returns to orignal path//
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH); 
     }
    }
    else
    {
      digitalWrite(rm1,LOW); 
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
    }
  }
       
