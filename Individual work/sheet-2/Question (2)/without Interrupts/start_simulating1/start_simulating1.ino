

const int led =13 ;
const int pb1 =2 ;
const int pb2 =3 ;
int b1,b2,x;


void setup()
{Serial.begin(9600);
  pinMode(pb1, INPUT);
  pinMode(pb2, INPUT);

  pinMode(led, OUTPUT);
  x=1;
}

void loop()
  
{   b1=digitalRead(pb1);
    b2=digitalRead(pb2);
  if(b1==1){
    x=x+1;

    }
 if(b2==1){
    x=x-1;

    }
   Serial.print(x);
	digitalWrite(led,HIGH);
    delay(x*1000);
    digitalWrite(led,LOW);
    delay(x*1000);
  
 

}