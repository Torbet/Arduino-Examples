#include <Servo.h>
#include <IRremote.h>

String serialData;

Servo serx;
Servo sery;

void setup() {
  serx.attach(7);
  sery.attach(8);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  //
}

void serialEvent() {
  serialData = Serial.readString();
  serx.write(parseDataX(serialData));
  sery.write(180 - parseDataY(serialData) + 20);
}

int parseDataX(String data) {
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);
  return data.toInt();
}

int parseDataY(String data) {
  data.remove(0, data.indexOf("Y") + 1);
  return data.toInt();
}
