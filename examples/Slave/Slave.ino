#include "I2C_Array.h"
#include <Wire.h>


#define Array_Length(array) ((sizeof(array) / sizeof(array[0])))

//set the slava adress
static int adress = 10;

byte send[70];
byte recieve[70];

void setup() {
  // put your setup code here, to run once:
  Wire.begin(adress);
  i2c.begin();
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);

  Serial.begin(57600);
  Serial.println("finished setup");
}

void loop() {
  // put your main code here, to run repeatedly:
}

void receiveEvent() {
  i2c.recieveData(Array_Length(recieve), recieve);

  Serial.println("recieve");
}


void requestEvent() {
  i2c.sendData(Array_Length(send), send);
  Serial.println("Send");
}