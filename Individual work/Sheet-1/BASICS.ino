int LED =13; 

void setup ()
{
  pinMode(led, OUTPUT); //initialization the digital pin as an output
}
void loop ()
{
  digitalWrite(LED, HIGH); //apply high voltage
  delay(1000); //wait for a second
  digitalWrite(LED, LOW); //apply low voltage
  delay(1000); //wait for a second 
}

