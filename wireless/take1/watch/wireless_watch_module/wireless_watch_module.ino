
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              3
#define tiltswitch        7
#define NUMPIXELS1        4
int fadeValue =           0;
int x =           0;
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
int delayval = 50; // delay for half a second




void setup() {

  pinMode (tiltswitch, INPUT);
  pixels1.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);

}

void loop() {

  Serial.println(digitalRead(tiltswitch));


  if (Serial.available() > 0) {

    if (digitalRead(tiltswitch) == HIGH) {
      x++ ;
    }   
    
 if (x > 255) {
      x = 0;
    }

    Serial.write(x);

  }

    int standschakelaar1 = Serial.parseInt();
    int standschakelaar2 = Serial.parseInt();
    int telwaarde = Serial.parseInt();

    Serial.print(standschakelaar1);

    if (standschakelaar1 == 0 || standschakelaar2 == 0 ); {
      if (digitalRead(tiltswitch) == HIGH) {
        for (fadeValue = 0; 255; fadeValue++) {
          int x =  fadeValue;
          Serial.write(x);
          break;
        }
      }
      if (standschakelaar2 == 0); {
        for (int i = 0; i < 3; i++) {
          pixels1.setPixelColor(i , fadeValue); // turns off neopix
          pixels1.show(); // This sends the updated pixel color to the hardware.
        }
        if (standschakelaar1 == 0 && standschakelaar2 == 0); {
          for (int i = 0; i < 3; i++) {
            pixels1.setPixelColor(i , fadeValue, (0.5 * fadeValue) , 0); // turns off neopix
            pixels1.show(); // This sends the updated pixel color to the hardware.
          }
        }
        delay(delayval);
      }
    }
  }



