
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1            3
#define PIN2            5
#define teller          8
#define schakelaar      4
#define druk            2

#define NUMPIXELS1      4
#define NUMPIXELS2      3

boolean status_energy = 1;
int stepSize = 1;
int x = 0;
int telwaarde = 0;

float fadeValue = 150;

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second

void setup() {

  pinMode ( 6, INPUT_PULLUP);
  pinMode (teller, INPUT);
  pinMode (druk, INPUT);
  pinMode (schakelaar, INPUT);
  //  pinMode (schakel, INPUT);

  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel libr nary.
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(druk) == HIGH) {
    Serial.println("poepchineeeees");
    status_energy = 1;
  }

  if (status_energy == 1) {

    if (digitalRead(druk) == HIGH) {
      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize) {
        x = fadeValue;

        Serial.println(digitalRead(druk));
        for(int j=0; j<x; j++) {
    for(int i=0; i<3; i++) {
      pixels1.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels1.show();
  }
        pixels2.setPixelColor(0 , 0); // turns off neopix
        pixels2.setPixelColor(1 , 0); // turns off neopix
        pixels2.setPixelColor(2 , 0 ); // turns off neopix
        pixels1.show(); // This sends the updated pixel color to the hardware.
        pixels2.show(); // This sends the updated pixel color to the hardware.

        if (x == 0) {
          status_energy = 0 ;
          break;
          Serial.println("waarde is nu een");
        }
        if ((digitalRead(druk)) == LOW)  {     // turn other led strip on
          Serial.print(" hij komt in de break if");
          break;
        }
        delay(delayval); // Delay for a period of time (in milliseconds).
      }
    }
  }

  if (digitalRead(druk) == LOW) {
    x = fadeValue;

    pixels1.setPixelColor(0 , 0); // turns off neopix
    pixels1.setPixelColor(1 , 0); // turns off neopix.
    pixels1.setPixelColor(2 , 0 ); // turns off neopix
    pixels2.setPixelColor(0, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
    pixels2.setPixelColor(1, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
    pixels2.setPixelColor(2, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x.
    pixels1.show(); // This sends the updated pixel color to the hardware.
    pixels2.show(); // This sends the updated pixel color to the hardware.


    telwaarde = digitalRead(teller);
    if (telwaarde == HIGH) {
      for (fadeValue ; fadeValue < 150; fadeValue += 1) {
        Serial.print("hij is aan het tellen");
        fadeValue ++;
        break;
      }
    }
  }
  Serial.print("waarde van x: ");
  Serial.println(x);
}

uint32_t Wheel(byte WheelPos) {
  
   return pixels1.Color(WheelPos * x, WheelPos * x, 0);
  
}
