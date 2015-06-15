#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NUMPIXELS1        6
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

#define PIN1              7
#define druk              6
# define tilt             5

int stand = 0;
uint8_t r = 0;
int g = 0;

boolean status_energy =   1;

void setup() {
  Serial.begin(38400);
  pinMode(tilt, INPUT);
  pinMode(druk, INPUT);
    pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {

  if ((digitalRead (druk) == HIGH)) { // reset to counting mode with light off , ready to excercise
    status_energy = 1;
    r = 0;
  }

  if (status_energy == 1) {
    if ((digitalRead (tilt) == HIGH)) {
      r++;
      g = 0, 56 * r;
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, r, g , 0);  // light orange light when excercising
        pixels1.show();
        if (r == 255) {
          status_energy = 0;
        }
        delay(100);
      }
    }
  }
  else {
    for (int i = 0; i < 60; i++) {   // light with max values 
      pixels1.setPixelColor(i, r, g , 0);
      pixels1.show();
    }
  }
}


