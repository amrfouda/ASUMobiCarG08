byte squareWavePin = 13 ;

void setup() 
{
  pinMode(squareWavePin,OUTPUT);
}

void loop() 
{
  digitalWrite(squareWavePin,HIGH);
  delay(500);
  digitalWrite(squareWavePin,LOW);
  delay(1500);

}
