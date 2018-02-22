int led[]={4,5,6,7} ;
int i;
void setup() 
{
 
for (i=4;i<=7;i++)
  {
    pinMode(i,OUTPUT);
  }
}


void loop()
{
 for(i=4;i<=7;i++)
 {
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
 }

 for(i=7;i>=4;i--)
 {
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
 }

}
