int i, j, k ;
void setup() {
 
for (i=10;i<=13;i++)
{
  pinMode(i,OUTPUT);
}
}


void loop() {
 for(i=10;i<=12;i++)
 {
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
 }

 for(i=13;i>=11;i--)
 {
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
 }

}
