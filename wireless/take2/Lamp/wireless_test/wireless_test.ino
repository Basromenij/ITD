#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              2
#define druk              3

#define NUMPIXELS1        60
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

int teller = 0;
int stand = 0;


void setup() {
  Serial.begin(9600);
  pinMode(druk, INPUT);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {
  if (Serial.available() > 0) {
    teller = Serial.read();
    stand = digitalRead(druk);

   Serial.print("teller");
   Serial.print(teller);
      Serial.print("       ");
    Serial.print("stand");
    Serial.println(stand);


    if (stand == 1 && teller == 0) {
        for (int i = 0; i < 60; i++) {
          pixels1.setPixelColor(i, 0 , 0, 50);
          pixels1.show();
      }
    }
      
          if (stand == 1 && teller == 1) {
        for (int i = 0; i < 60; i++) {
          pixels1.setPixelColor(i, 50 , 50, 50);
          pixels1.show();
      }
      //        for (int i = 0; i < 60; i++) {
      //        pixels1.setPixelColor(i, 0,0,255);
      //        pixels1.show();
      //  }
    }

    if (stand == 0) {
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, 50,0,0);
        pixels1.show();
      }
    }
  }
}

