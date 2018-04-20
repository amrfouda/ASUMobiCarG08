#include <EEPROM.h>
#include <IRremote.h>
int irRxPin = 9;
int f = 38; // 40, 36, 38
IRrecv irrecv(irRxPin);
IRsend irsend;
decode_results results;
int codeLength = 0;
int currentCode = 0;
void setup()
{
  Serial.begin(9600);
Serial.println("0-9 to set code memory, s - to send");
irrecv.enableIRIn();
setCodeMemory(0);
}

void loop()
{
if (Serial.available())
{
char ch = Serial.read();
if (ch >= '0' && ch <= '9')
{
setCodeMemory(ch - '0');
}
else if (ch == 's')
{
sendIR();
}
}
if (irrecv.decode(&results))
{
  storeCode();
irrecv.resume();
}
}

void setCodeMemory(int x)
{
currentCode = x;
Serial.print("Set current code memory to: ");
Serial.println(currentCode);
irrecv.resume();
}

void storeCode()
{
  // write the code to EEPROM, first byte is length
int startIndex = currentCode * (RAWBUF + 1);
int len = results.rawlen - 1;
EEPROM.write(startIndex, (unsigned byte)len);
for (int i = 0; i < len; i++)
{
if (results.rawbuf[i] > 255)
{
EEPROM.write(startIndex + i + 1, 255); 
}
else
{
EEPROM.write(startIndex + i + 1, results.rawbuf[i]);
}
}
Serial.print("Saved code, length: ");
Serial.println(len);
  
}

void sendIR()
{
  // construct a buffer from the saved data in EEPROM and send it
int startIndex = currentCode * (RAWBUF + 1);
int len = EEPROM.read(startIndex);
unsigned int code[RAWBUF];
for (int i = 0; i < len; i++) 
{
int pulseLen = EEPROM.read(startIndex + i + 2);
if (i % 2)
{
code[i] = pulseLen * USECPERTICK + MARK_EXCESS;
}
else
{
code[i] = pulseLen * USECPERTICK - MARK_EXCESS;
}
}
irsend.sendRaw(code, len, f);
Serial.print("Sent code length: ");
Serial.println(len);
}

