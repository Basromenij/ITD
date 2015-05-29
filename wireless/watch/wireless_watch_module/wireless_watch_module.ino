
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              3
#define PIN2              5
#define tiltswitch        7
#define schakelaar        4
#define druk              2

#define NUMPIXELS1        4
#define NUMPIXELS2        3

boolean status_energy =   1;
int stepSize =            1;
int x =                   0;
int telwaarde =           0;
int r =                   0;
int g =                   0;
int b =                   0;

int Brightness =          255;
int resolutie   =         42;

int RainbowColor =       0;
int ColorChanger =       1;

float fadeValue =        255;
int maxbrightness =      255;

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second
int delayval2 = 1; // delay for half a second

void setup() {

  pinMode ( 6, INPUT_PULLUP);
  pinMode (tiltswitch, INPUT);
  pinMode (druk, INPUT);
  pinMode (schakelaar, INPUT);
  //  pinMode (schakel, INPUT);

  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel libr nary.
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {

    String myString = Serial.read();
    int commaIndex = myString.indexOf(','); //  Search for the next comma just after the first
    int secondCommaIndex = myString.indexOf(',', commaIndex + 1);

    String firstValue = myString.substring(0, commaIndex);
    String secondValue = myString.substring(commaIndex + 1, secondCommaIndex);
    String thirdValue = myString.substring(secondCommaIndex + 1); // To the end of the string

    int standschakelaar1 = firstValue.toInt();
    int standschakelaar2 = secondValue.toInt();
    int telwaarde = thirdValue.toInt();

    if (standschakelaar1 == 0 || standschakelaar2 == 0 ); {
      if (digitalRead(tiltswitch) == HIGH) {
        for (fadeValue; 0 ; 255 += 1) {
       int x =  fadeValue ++;
          break;
        }
      }
      if (standschakelaar1 == 0); {
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

