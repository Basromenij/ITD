#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              2
#define druk1             3
#define druk2             4
#define druk3             5

#define NUMPIXELS1        60
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

uint8_t x = 0;
int stand2 = 0;
int stand1 = 0;
int reset = 0;
boolean status_energy =   1;

int delayval = 50;

void setup() {
  Serial.begin(38400);
  pinMode(druk1, INPUT);
  pinMode(druk2, INPUT);
  pinMode(druk3, INPUT);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {

  stand1 = digitalRead(druk1);
  stand2 = digitalRead(druk2);
  reset = digitalRead(druk3);


  if (reset == HIGH) {  // reset
    status_energy == 1;
    x = 0;
  }

  if (status_energy == 1); {
    if (stand1 == 1 && stand2 == 0) {
      x --;
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, 0, 0, x);  // shine blue light when just switch one is high
        pixels1.show();
      }
      if (x == 0) {
        status_energy = 0;
      }
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    if (stand1 == 1 && stand2 == 1) {  // shine red light when both switches are high
      x --;
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, x , 0 , 0);
        pixels1.show();
      }
      if (x == 0) {
        status_energy = 0;
      }
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
  }
}





