#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#define PIN1              3

int x = 0;
int led = 6;

#define NUMPIXELS1        60
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {

  if (Serial.available() > 0) {
    x = Serial.read();
    Serial.println(x);
   analogWrite(led, x);
   
    for (int i = 0; i < 60; i++) {
      pixels1.setPixelColor(i, 0, 0, x);  // shine blue light when just switch one is high
      pixels1.show();
    }
  }
}
