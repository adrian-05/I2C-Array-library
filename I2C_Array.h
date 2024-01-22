


#ifndef I2C_Array_h
#define I2C_Array_h

#include "Arduino.h"

// #define Array_Length(array) ((sizeof(array) / sizeof(array[0])))


class I2C_Array {
  public:
  //constructor
  I2C();

  //general
  void begin();



  //Master
  void sendArray(int SlaveId, int Length, uint8_t ArrayToSend[]);  //Send a Array to a Slave
  void requestArray(int SlaveId, int Length, uint8_t ArrayToStoreData[]); //Request an Array from a Slave

  //Slave

  void recieveData(int Length, uint8_t Data[]);
  void sendData(int Length, uint8_t Data[]);

  private:
  bool Slave = false;

  int Length(byte Data[]);
};

extern I2C_Array i2c;


#endif