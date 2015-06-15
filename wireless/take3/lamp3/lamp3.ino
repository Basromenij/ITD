#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              3
#define druk1             2
#define druk2             4
#define NUMPIXELS1        60

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

uint8_t x = 0;
int stand2 = 0;
int stand1 = 0;

int sendData[] = { 0, 0, 0};
int delayval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(druk1, INPUT);
  pinMode(druk2, INPUT);

  // analogWrite(led2, HIGH);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {
  sendData[0] = digitalRead(druk1);
  sendData[1] = digitalRead(druk2);
  //  sendData[2] = x;

  stand1 = digitalRead(druk1);
  stand2 = digitalRead(druk2);


  if (Serial.available() > 0) { // check if communciation is available


    x = Serial.read();   // read the serial communicated value and assign this to x

    if (stand1 == 1 && stand2 == 0) {
      //        x --;
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, 0, 0, x);  // shine blue light when just switch one is high
      }
      for (int i = 0; i < 2; i++) {
        Serial.write(sendData[i]);
      }
      delay(delayval); // Delay for a period of time (in milliseconds).
    }


    if (stand1 == 1 && stand2 == 1) {  // shine red light when both switches are high
      //        x --;
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, x , 0 , 0);
      }
      for (int i = 0; i < 2; i++) {
        Serial.write(sendData[i]);
      }
      delay(delayval); // Delay for a period of time (in milliseconds).
    }


    if (stand1 == 0  && stand2 == 0) {  // shine red light when both switches are high
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, 0 , 0 , 0);
      }
      for (int i = 0; i < 2; i++) {
        Serial.write(sendData[i]);
      }
      delay(delayval); // Delay for a period of time (in milliseconds).
    }

    pixels1.show();
  }
}



