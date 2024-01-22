



#include "Arduino.h"
#include "I2C_Array.h"
#include <Wire.h>


I2C_Array::I2C_Array() {
}

//Master

//
void I2C_Array::begin() {
  Wire.begin();
  while (Wire.available()) {
    Wire.read();
  }
}

//Send an Array to an Slave
void I2C_Array::sendArray(int SlaveId, int Length, uint8_t Data[]) {
  Wire.beginTransmission(SlaveId);
  for (int i = 0; i < Length; i++) {  //Send on byte after the other
    Wire.write(Data[i]);
  }
  Wire.endTransmission();
}

//request an Array from a Slave
void I2C_Array::requestArray(int SlaveId, int Length, uint8_t Data[]) {
  Wire.requestFrom(SlaveId, Length);
  delay(10);
  for (int i = 0; i < Length; i++) {
    while (Wire.available() == 0) {
      delay(1);  // add failsave
    }
    Data[i] = Wire.read();
  }
}

//Slave

//recieves the Array bit by bit
void I2C_Array::recieveData(int Length, uint8_t Data[]) {
  for (int i = 0; i < Length; i++) {
    Data[i] = Wire.read();
  }
}

//sends the Array bit by bit
void I2C_Array::sendData(int Length, uint8_t Data[]) {
  for (int i = 0; i < Length; i++) {
    Wire.write(Data[i]);
  }
}


//Privat

//get the nummber of bytes from an array
int Length(byte Data[]) {
int _Length = sizeof(Data) / sizeof(Data[0]);

return _Length;
} 
