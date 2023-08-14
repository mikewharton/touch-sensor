#include <Wire.h>

const int mPin = 12;
bool on = false;
float prev = 0;
const byte n = 5;
const float th = 5;

void setup() {
  pinMode(mPin, OUTPUT);
  Serial.begin(9600);
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
  
  prev = avg;

  Serial.print(s1);
  Serial.print("\t");
  Serial.print(avg);
  Serial.print("\t");
  Serial.print(prev);
  Serial.print("\t");
  Serial.print(gradient); // Print the gradient directly
  Serial.print("\n");
  
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
