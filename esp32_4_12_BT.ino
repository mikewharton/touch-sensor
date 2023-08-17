#include "BluetoothSerial.h"
#include <Wire.h>

BluetoothSerial SerialBT;

const int mPin = 12;
bool on = false;
float prev = 0;
const byte n = 5;
const float th = 2;

void setup() {
  pinMode(mPin, OUTPUT);
  Serial.begin(9600);
  SerialBT.begin("ESP32Bluetooth"); // Bluetooth device name
}

void loop() {
  long s1 = touchRead(4);
  float avg = movingAvg(s1);

  float gradient = avg - prev; // Calculate the gradient

  if (gradient < -th && !on) {
    on = true;
    digitalWrite(mPin, HIGH);
  } else if (gradient > th && on) {
    on = false;
    digitalWrite(mPin, LOW);
  }

  if (on) {
    Serial.print("1");
    SerialBT.print("1");
  } else {
    Serial.print("0");
    SerialBT.print("0");
  }
  Serial.print("\n");
  SerialBT.print("\n");
  prev = avg;
  delay(5);
}

float movingAvg(float v) {
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
