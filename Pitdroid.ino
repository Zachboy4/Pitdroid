// Code By ZacHary Perrott 2022 
#include <IRremote.h>
#include <SimpleSDAudio.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
int LED = 7;
void setup()
{
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);//why does this line kill it 
  irrecv.enableIRIn(); // Start the receiver
   Serial.begin(9600);
  pinMode(LED, OUTPUT);
   SdPlay.setSDCSPin(4);
   
}

void loop()
{
  if (irrecv.decode(&results))
  {
    switch (results.value) {
      case 16756815:
        digitalWrite(LED, HIGH);
          SdPlay.setFile("test.wav"); 
          SdPlay.play();
       break;
    }
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
}
