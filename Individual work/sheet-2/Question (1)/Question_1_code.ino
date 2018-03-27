const int bit0= 0 ;
const int bit1= 1 ;
const int bit2= 2 ;
const int bit3= 3 ;
const int bit4= 4 ;
const int bit5= 5 ;
const int bit6= 6 ;
const int bit7= 7 ;
const int Led= 13 ;


void setup() {
  pinMode(bit0,INPUT);
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
  pinMode(bit3,INPUT);
  pinMode(bit4,INPUT);
  pinMode(bit5,INPUT);
  pinMode(bit6,INPUT);
  pinMode(bit7,INPUT);
  pinMode(Led,OUTPUT);

}

void loop() {
  int b0,b1,b2,b3,b4,b5,b6,b7 ;
  int Duration ;
  b0=digitalRead(bit0) ;
  b1=digitalRead(bit1) ;
  b2=digitalRead(bit2) ;
  b3=digitalRead(bit3) ;
  b4=digitalRead(bit4) ;
  b5=digitalRead(bit5) ;
  b6=digitalRead(bit6) ;
  b7=digitalRead(bit7) ;
  Duration =(b0*4+b1*8+b2*16+b3*32+b4*64+b5*128+b6*256+b7*512)*1000 ;
  digitalWrite(Led,HIGH);
  delay(Duration);
  digitalWrite(Led,LOW);
  
  

}
