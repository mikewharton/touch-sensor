#include "CapacitiveSensor.h"
#include <Wire.h>

const int mPin = 7;
CapacitiveSensor cs_6_5 = CapacitiveSensor(6, 5);
bool on = false;
float prev = 0;
const byte n = 20; // 15
const float th = 20; // 20

void setup() {
  pinMode(mPin, OUTPUT);
  cs_6_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  // Serial.begin(9600);
}

void loop() {
  long s1 = cs_6_5.capacitiveSensor(30);
  float avg = avgMoving(s1);

  if (avg - prev > th && !on) {
    on = true;
    digitalWrite(mPin, HIGH);
  } else if (avg - prev < -th && on) {
    on = false;
    digitalWrite(mPin, LOW);
  }

  prev = avg;

  // Serial.print(s1);
  // Serial.print("\t");
  // Serial.print(avg);
  // Serial.print("\t");
  // Serial.print(avg - prev);
  // Serial.print("\n");

  delay(5);
}

float avgMoving(float v) {
  static byte c = 0;
  static byte nv = 0;
  static float s = 0;
  static float val[n];
  
  s += v;
  if (nv == n) {
    s -= val[c];
  }
  val[c] = v;
  if (++c >= n) {
    c = 0;
  }
  if (nv < n) {
    nv++;
  }
  
  return s / nv;
}
