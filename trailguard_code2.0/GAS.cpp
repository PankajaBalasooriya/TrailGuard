#include "GAS.h"
#include <Arduino.h>

double gas_level(int gas_pin) {
  int sensorValue = analogRead(gas_pin); // Read analog input pin
  return sensorValue;
  
}
