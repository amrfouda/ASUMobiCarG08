int led[]={4,5,6,7};

void setup()
{
  for(int index=0;index<4;index++)
  {
    pinMode(led[index],OUTPUT);
  }
}
void loop()
{
  for(int index=0;index<4;index++)
  {
  digitalWrite(led[index],HIGH);
  delay(1000);
  digitalWrite(led[index],LOW);
  }
  for(int index=3;index>-1;index--)
  {
  digitalWrite(led[index],HIGH);
  if(index==1||index==2)
  delay(1000);
  digitalWrite(led[index],LOW);
  }
}
