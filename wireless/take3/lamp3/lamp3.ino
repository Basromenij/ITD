#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              3
#define druk1             2
#define druk2             4
#define led1              5
#define led2             6

#define NUMPIXELS1        60

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

uint8_t x = 0;
int stand2 = 0;
int stand1 = 0;
int currentState = 0;
int switch0 = 0;
int switch1 = 0;
int delayval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(druk1, INPUT);
  pinMode(druk2, INPUT);

  // analogWrite(led2, HIGH);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {

  switch0 = digitalRead(druk1);
  switch1 = digitalRead(druk2);

  if (switch0 == 0  && currentState != 0) {
    analogWrite(led1, 255);
    analogWrite(led2, 255);

    Serial.println(0);
    currentState = 0;
    delay(100);
  }

  if (switch0 == 1 && switch1 == 0 && currentState != 1) {

    analogWrite(led1, 255);
    analogWrite(led2, 0);

    Serial.println(1);
    currentState = 1;
    delay(100);

  }

  if (switch0 == 1  && switch1 == 1 && currentState != 2 ) {

    analogWrite(led2, 255);
    analogWrite(led1, 0);

    Serial.println(2);
    currentState = 2;
    delay(100);

  }



  //  if (Serial.available() > 0) { // check if communciation is available
  //
  //
  //    x = Serial.read();   // read the serial communicated value and assign this to x
  //
  //    if (stand1 == 1 && stand2 == 0) {
  //      //        x --;
  //      for (int i = 0; i < 60; i++) {
  //        pixels1.setPixelColor(i, 0, 0, x);  // shine blue light when just switch one is high
  //      }
  //      for (int i = 0; i < 2; i++) {
  //        Serial.write(sendData[i]);
  //      }
  //      delay(delayval); // Delay for a period of time (in milliseconds).
  //    }
  //
  //
  //    if (stand1 == 1 && stand2 == 1) {  // shine red light when both switches are high
  //      //        x --;
  //      for (int i = 0; i < 60; i++) {
  //        pixels1.setPixelColor(i, x , 0 , 0);
  //      }
  //      for (int i = 0; i < 2; i++) {
  //        Serial.write(sendData[i]);
  //      }
  //      delay(delayval); // Delay for a period of time (in milliseconds).
  //    }
  //
  //
  //    if (stand1 == 0  && stand2 == 0) {  // shine red light when both switches are high
  //      for (int i = 0; i < 60; i++) {
  //        pixels1.setPixelColor(i, 0 , 0 , 0);
  //      }
  //      for (int i = 0; i < 2; i++) {
  //        Serial.write(sendData[i]);
  //      }
  //      delay(delayval); // Delay for a period of time (in milliseconds).
  //    }
  //
  //    pixels1.show();
  //  }
}



