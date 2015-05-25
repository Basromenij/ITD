
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              3
#define PIN2              5
#define teller            8
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

int Brightness =          256;
int resolutie   =         42;

int RainbowColor =       0;
int ColorChanger =       1;

float fadeValue =        150;
int maxbrightness =      150;

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second
int delayval2 = 1; // delay for half a second

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


  if (status_energy == 1) {

    if (digitalRead(druk) == HIGH && digitalRead(schakelaar) == HIGH) {
      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize) {
        x = fadeValue;

        //        Serial.println(digitalRead(druk));

        for (int i = 0; i < 3; i++) {
          pixels1.setPixelColor(i, x);
          pixels2.setPixelColor(i, 0); // sets a white color for neopix with a brightness x
          pixels1.show();
          pixels2.show();
          if (x == 0) {
            status_energy = 0 ;
            break;
            //            Serial.println("waarde is nu een");
          }
          if ((digitalRead(druk)) == LOW)  {     // turn other led strip on
            //            Serial.print(" hij komt in de break if");
            break;
          }
          delay(delayval); // Delay for a period of time (in milliseconds).

        }
      }
    }

    if (digitalRead(druk) == HIGH && digitalRead(schakelaar) == LOW) { // SPECIAL RAINBOW
      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize) {
        x = fadeValue;
        for (int i = 0; i < 3; i++) {
          pixels1.setPixelColor(i, Wheel(x));
          pixels2.setPixelColor(i, 0); // sets a white color for neopix with a brightness x
          pixels1.show();
          pixels2.show();

        }
        if (x == 0) {
          status_energy = 0 ;
          break;
          Serial.println("waarde is nu een");
        }
        if ((digitalRead(druk)) == LOW)  {     // turn other led strip on
          Serial.print(" hij komt in de break if");
          break;
        }          
          delay(delayval2);
        }
      }
    }

    if (digitalRead(druk) == LOW) {
      x = fadeValue;
      for (int i = 0; i < 3; i++) {
        pixels1.setPixelColor(i , 0); // turns off neopix
        pixels2.setPixelColor(i, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
        pixels1.show(); // This sends the updated pixel color to the hardware.
        pixels2.show(); // This sends the updated pixel color to the hardware.
      }

      telwaarde = digitalRead(teller);
      if (telwaarde == HIGH) {
        for (fadeValue ; fadeValue <= maxbrightness ; Brightness += 1) {
          Serial.print("hij is aan het tellen");
          fadeValue ++;
          break;
        }
      }
    }
    Serial.print("waarde van x: ");
    Serial.println(x);
  }
  // changing color of the rainbow


  uint32_t Wheel(byte intensity) {

    RainbowColor = RainbowColor + ColorChanger;

    if (RainbowColor == 255) {
      RainbowColor = 0 ;
    }


    float mappedintensity = map(intensity, 0, maxbrightness, 0, 100) * 0.01;

    int MappedRainbowColor1 = map(RainbowColor, 0, resolutie , 0, Brightness);
    int MappedRainbowColor2 = map(RainbowColor, resolutie + 1 , resolutie * 2 + 1, Brightness, 0);
    int MappedRainbowColor3 = map(RainbowColor, resolutie * 2 + 2 , resolutie * 3 + 2, 0, Brightness);
    int MappedRainbowColor4 = map(RainbowColor, resolutie * 3 + 3 , resolutie * 4 + 3, Brightness, 0);
    int MappedRainbowColor5 = map(RainbowColor, resolutie * 4 + 4 , resolutie * 5 + 4, 0, Brightness);
    int MappedRainbowColor6 = map(RainbowColor, resolutie * 5 + 5 , resolutie * 6 + 5, Brightness, 0);

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




    if (RainbowColor <= resolutie + 1) {
      r = Brightness;
      g = 0;
      b = MappedRainbowColor1;
      return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
    } if (RainbowColor <= resolutie * 2 + 2) {
      r = MappedRainbowColor2;
      g = 0;
      b = Brightness;
      return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
    } if (RainbowColor <= resolutie * 3 + 3) {
      r = 0;
      g = MappedRainbowColor3;
      b = Brightness;
      return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
    }
    if (RainbowColor <= resolutie * 4 + 4) {
      r = 0;
      g = Brightness;
      b = MappedRainbowColor4;
      return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
    } if (RainbowColor <= resolutie * 5 + 5) {
      r = MappedRainbowColor5;
      g = Brightness;
      b = 0;
      return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
    } if (RainbowColor <= resolutie * 6 + 5) {
      r = Brightness;
      g = MappedRainbowColor6;
      b =  0;
      return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
    }

  }
