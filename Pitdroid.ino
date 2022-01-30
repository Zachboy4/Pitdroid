#include <IRremote.h>
#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
}

void loop()
{
     tmrpcm.setVolume(6);
     tmrpcm.play("test.wav");
 
  if (irrecv.decode(&results))
  {
    switch (results.value) {
      case 16756815:
         tmrpcm.setVolume(6);
         tmrpcm.play("test.wav");
        break;
    }
     
    irrecv.resume(); // Receive the next value
    
  }
     
}
