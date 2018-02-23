int Led =13; 

void setup ()
{
  pinMode(led, OUTPUT); //initialization the digital pin as an output
}
void loop ()
{
  digitalWrite(Led, HIGH); //apply high voltage
  delay(1000); //wait for a second
  digitalWrite(Led, LOW); //apply low voltage
  delay(1000); //wait for a second 
}

