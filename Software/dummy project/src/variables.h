#ifndef VARIABLE_H
#define VARIABLE_H

//--------------------------------------------------Define--------------------------------------------------
//----------Global values
#define MIRCOS2SECONDS 1000000

//----------GPI

//----------GPO

//----------ADC

//----------PWM

//----------LED
#define LED_DATA_PIN 9

//----------Peripherals
//---UART
//HardwareSerial debug = HardwareSerial(0);

//---I2C

//---SPI

//--------------------------------------------------Initialize libraries--------------------------------------------------

//--------------------------------------------------Structs--------------------------------------------------
struct Task
{
  uint16_t counter;
  unsigned long beginTime = 0;
  unsigned long startCounterTime = 0;
  unsigned long endTime = 0;
  unsigned long duration = 0;
  const    long interval = 1000; // in us
  uint8_t frequency = 0;
  unsigned long inBetweenTime = 0;
};

enum TaskId {
  led,
  debug,
  main,
  NUMBER_OF_TASKS
}

Task task[TaskId.NUMBER_OF_TASKS];

//--------------------------------------------------Variables--------------------------------------------------

#endif