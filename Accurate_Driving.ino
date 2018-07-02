
int acc_distance=0 ;                                 //the variable distance input from the user
float time = (acc_distance)/(170/60*2*22/7*3.25);    //forward motion duration = distance required/(rps * wheel circumference)
time = time *1000;                                   // time in milliseconds


void loop() 
{
  if(acc_distance =/= 0)
  { 
    forward();      
    delay(time);
  }
  else
    stop();
}
