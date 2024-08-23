#include "PH.h"
#include <Arduino.h>

double phValue;

double map(int x, int in_min, int in_max, double out_min, double out_max) {
  return (double(x - in_min) * (out_max - out_min) / double(in_max - in_min)) + out_min;
}

double ph_value(int ph_pin){
  
  int analogValue = 0;
  
  analogValue = analogRead(ph_pin); 
  
  if (analogValue == 520) {
    phValue = 7; } 
  
  else if (analogValue > 520) {
    phValue = map(analogValue, 520, 1023, 7, 0);} 
    
  else {
    phValue = map(analogValue, 0, 520, 14, 7);
  }
  
  phValue = round(phValue * 100.0) / 100.0;
  
  return phValue;
}



