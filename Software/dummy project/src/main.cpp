#include <Arduino.h>

#define FIRMWARE_REV "dummy-dev-0.0.1"

//Include library

//Include files
#include "variables.h"



void loopCount(); //For function telemetry purpose / Homemade Ultra lite RTOS



//===========================================
//===========================================
//====================Setup==================
//===========================================
//===========================================
void setup()
{

  Serial.begin(115200);



  pinMode(LED_DATA_PIN, OUTPUT);
  digitalWrite(LED_DATA_PIN, 1);

  Serial.printf("Dongle is booting\r\n");
  Serial.printf("Firmware rev: %s\r\n", FIRMWARE_REV);
  Serial.printf("Firmware was built the: %s at %s\r\n\r\n", __DATE__, __TIME__);

  Serial.printf("__          __  _                            _          _____  __  __ _  __ \r\n");
  Serial.printf("\\ \\        / / | |                          | |        |  __ \\|  \\/  | |/ / \r\n");
  Serial.printf(" \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |__) | \\  / | ' /  \r\n");
  Serial.printf("  \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  |  ___/| |\\/| |  <   \r\n");
  Serial.printf("   \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |    | |  | | . \\  \r\n");
  Serial.printf("    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___| \\__ \\___/  |_|    |_|  |_|_|\\_\\ \r\n\r\n\r\n");
}



void loop()
{
  //------------------------------------------------------ledTask
  if(micros() - ledTask.beginTime >= ledTask.interval)
  {
    ledTask.beginTime = micros();
    ledTask.inBetweenTime = ledTask.beginTime - ledTask.endTime;

    //**functions

    ledTask.endTime = micros();
    ledTask.counter++;
    ledTask.duration = ledTask.endTime - ledTask.beginTime;
  }
}



void loopCount()
{
  //Task frequency counter
  if(ledTask.counter == 0)
  {
    ledTask.startCounterTime = micros();
  }
  if(micros() - ledTask.startCounterTime > 1000000)
  {
    ledTask.frequency = ledTask.counter;
    //Serial.println(ledTask.counter);
    ledTask.counter = 0;
  }
}