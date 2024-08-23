#include "DUST.h"
#include <Arduino.h>

int samplingTime = 280; // time required to sample signal coming out   of the sensor
int deltaTime = 40; // 
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;


double dust_density(int measurePin,int ledPower){
  pinMode(ledPower,OUTPUT);
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);
  
  voMeasured = analogRead(measurePin); // read the dust value
  
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
  // 0 - 5V mapped to 0 - 1023 integer values

  // recover voltage
  calcVoltage = voMeasured * (5.0 / 1024.0);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  dustDensity = (170 * calcVoltage - 0.1);
  return dustDensity; // unit: ug/m3
}

