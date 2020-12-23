#include <IRremote.h>
#include <Servo.h>

Servo serx;
Servo sery;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
const unsigned long int repeat = 4294967295;
const int repeat2 = 0;
unsigned long int data;
unsigned long int up = 16718055;
unsigned long int down = 16730805;
unsigned long int left = 16716015;
unsigned long int right = 16734885;

int xpos = 90;
int ypos = 90;

int speed = 10;

void setup() {

  serx.attach(7);
  sery.attach(8);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value != repeat) {
      data = results.value;
    }
    if (data == up) {
      Serial.println("up");
      ypos = ypos + speed;
      sery.write(ypos);
    }
    if (data == down) {
      Serial.println("down");
      ypos = ypos - speed;
      sery.write(ypos);
    }
    if (data == left) {
      Serial.println("left");
      xpos = xpos - speed;
      serx.write(xpos);
    }
    if (data == right) {
      Serial.println("right");
      xpos = xpos + speed;
      serx.write(xpos);
    }

    irrecv.resume(); // Receive the next value
  }
}
