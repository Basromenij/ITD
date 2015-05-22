
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              2

  

#define NUMPIXELS1        3


boolean status_energy =   1;
int stepSize =            1;
int x =                   0;
int telwaarde =           0;
int r =                   0;
int g =                   0;
int b =                   0;
int teller  =  0;
int druk =  0;
int schakelaar =  0;
int RainbowColor =       100;
int ColorChanger =       1;

float fadeValue =        150;

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);


int delayval = 50; // delay for half a second
int delayval2 = 5; // delay for half a second

void setup() {

  pinMode ( 6, INPUT_PULLUP);
  pinMode (teller, INPUT);
  pinMode (druk, INPUT);
  pinMode (schakelaar, INPUT);
  //  pinMode (schakel, INPUT);

  pixels1.begin(); // This initializes the NeoPixel library.

  Serial.begin(9600);
}

void loop() {

 
      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize) {
        x = fadeValue;
        for (int i = 0; i < 3; i++) {
          pixels1.setPixelColor(i, Wheel(x));

          pixels1.show();


        }
        if (x == 0) {
          fadeValue = 150;
        }

        delay(delayval2);
      }
    }
 


// changing color of the rainbow


uint32_t Wheel(byte intensity) {

  RainbowColor = RainbowColor - ColorChanger;
  if (RainbowColor == 0) {
    RainbowColor = 150;
  }


  float mappedintensity = map(intensity, 0, 150, 0, 100) * 0.01;

  Serial.print("mappedintesnity");
  Serial.print(mappedintensity);
  Serial.print("       ");
  Serial.print("RainbowColor");
  Serial.print(RainbowColor);
  Serial.print("       ");
  Serial.print("r");
  Serial.print(r);
  Serial.print("       ");
  Serial.print("g");
  Serial.print(g);
  Serial.print("       ");
  Serial.print("b");
  Serial.println(b);

  if (RainbowColor <= 50) {
    r = 150 - RainbowColor;
    g = 0;
    b = RainbowColor ;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  } if (RainbowColor <= 100) {
    r = 0;
    g = RainbowColor;
    b = 150 - RainbowColor * 1,5;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  } else {
    r = RainbowColor;
    g = 150 - RainbowColor;
    b =  0;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  }

}
