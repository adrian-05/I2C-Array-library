#include <I2C_Array.h>

//determan the length of an array
#define Array_Length(array) ((sizeof(array) / sizeof(array[0])))

//define all arrays for the recieved data

byte request[70];

//define all arrays for the send data

byte send[70];

void setup() {
  // put your setup code here, to run once:

  i2c.begin();
  Serial.begin(57600);
  Serial.println("start");
}

void loop() {
  // put your main code here, to run repeatedly:

  //request all inputs from the slaves
  i2c.requestArray(10, Array_Length(request), request);

  //send the output arrays to the slaves
  i2c.sendArray(10, Array_Length(send), send);


  
}
