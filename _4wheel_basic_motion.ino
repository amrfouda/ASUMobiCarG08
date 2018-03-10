int rm1=0;
int rm2=1;
int lm1=2;
int lm2=3;

void setup()
{
  //inputs of H-bridge, motors on one side work together//
  //when " rm1 is low & rm2 is high "right side motors moveclockwise and similatily the left side motors//
 
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
 
//set the serial communication rate
   Serial.begin(9600);
   }
   void loop()
   {
      //check whether arduino is reciving signal or not 
     while(Serial.available() == 0);
     char val = Serial.read() ;//reads the signal
     Serial.print(val);
     
  //forward//
  if(val=='F')
  {
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
  }
  //backward//
  else if(val=='B')
  {
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
  }
  //right//
  else if(val=='R')
  {
    digitalWrite(rm1,LOW);  
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
  }
  //left//
  else if(val=='L')
  {
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  }
  
  
}
