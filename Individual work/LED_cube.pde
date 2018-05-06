#include <avr/pgmspace.h> 

#define CUBESIZE 4
#define PLANESIZE CUBESIZE*CUBESIZE
#define PLANETIME 3333 
#define TIMECONST 5


int LEDPin[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int LEDPinCount = 16;
int PlanePin[] = {16, 17, 18, 19};
int PlanePinCount  = 4;

void setup()
{
  int pin; // loop counter

  for (pin=0; pin<PLANESIZE; pin++) {
    pinMode( LEDPin[pin], OUTPUT );
  }

  for (pin=0; pin<CUBESIZE; pin++) {
    pinMode( PlanePin[pin], OUTPUT );
  }
}

void loop(){
  loopFor();

}


{
    for(int thisPlane = 0; thisPlane < PlanePinCount; thisPlane++){
      for(int thisPin = 0; thisPin < LEDPinCount; thisPin++){
        
        planesOff();
        digitalWrite(LEDPin[thisPin],HIGH);
        digitalWrite(PlanePin[thisPlane],LOW);
       
        
        delay(50);
        
        digitalWrite(LEDPin[thisPin],LOW);
        digitalWrite(PlanePin[thisPlane],HIGH);
        
        
      }
    }
}

void loopRand()
{
    int randPin = random(15);
    int randPlane = random(3);
    
    planesOff();
    
    digitalWrite(LEDPin[randPin],HIGH);
    digitalWrite(PlanePin[randPlane],LOW);
        
    delay(50);
           
      
    digitalWrite(LEDPin[randPin],LOW);
    digitalWrite(PlanePin[randPlane],HIGH);
     
     
}

void planesOff(){
    for(int thisPlane = 0; thisPlane < PlanePinCount; thisPlane++){
        digitalWrite(PlanePin[thisPlane],HIGH);
    }
}
