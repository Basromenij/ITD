#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              3
#define druk1             2
#define druk2             4
#define druk3             7
#define druk4             8
#define led1              5
#define led2              6



#define NUMPIXELS1        45

#define buttonDelay       100
#define resolutie          42
#define ColorChanger        1
#define Brightness        255



Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

int stand2 =               0;
int stand1 =               0;
int currentState =         0;
int switch0 =              0;
int switch1 =              0;
int badWeather =           0;
int sportingTogether =     0;
int r =                    0;
int g =                    0;
int b =                    0;
int i =                    0;
uint8_t hue =             255;
uint8_t intensity =      100;
int aftellen =             0;

unsigned long previousMillis0 = 0;
unsigned long previousMillis1 = 0;

int interval0 = 50;
int interval1 = 470;

int delayval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(druk1, INPUT);
  pinMode(druk2, INPUT);

  // analogWrite(led2, HIGH);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {

  unsigned long currentMillis = millis();

  //  badWeather = digitalRead(druk3);
  //  sportingTogether = digitalRead(druk4);

  switch0 = digitalRead(druk1);
  switch1 = digitalRead(druk2);
  Serial.println(hue);
  if (switch0 == 1  && switch1 == 1 ) {
    if (currentMillis - previousMillis0 >= interval0) {
      previousMillis0 = currentMillis;

      if (aftellen != 1) {
        hue++;
        if ( hue == 254) {
          aftellen = 1;
        }
      }
      if (aftellen != 0) {
        hue--;
        if ( hue == 1) {
          aftellen = 0;
        }
      }
    }

    if (currentMillis - previousMillis1 >= interval1) {
      previousMillis1 = currentMillis;
      intensity--;
    }

    uint32_t color = rainbow(hue, intensity);

    for (int i = 0; i < 46; i++) {
      pixels1.setPixelColor(i, color);
    }

    pixels1.show();
  }
}

uint32_t rainbow(uint8_t hue, uint8_t intensity) {

  // FUNCTIE LOOPT AANTAL KEREN ALS ER PIXELS ZIJN
  // WAAR ZIT DE DELAY INGEBAKKEN, IK ZIE HEM NIET?

  int MappedRainbowColor1 = map(hue, 0, resolutie , 0, Brightness);                          // de waarde van de rainbow color wordt gemapt in 6 gelijke delen, een veelvoud van resolutie. Deze waarde is 42. Dus van 0 tot 42 wordt MappedRainbowColor1 0 tot 255 enzovoort
  int MappedRainbowColor2 = map(hue, resolutie + 1 , resolutie * 2 + 1, Brightness, 0);
  int MappedRainbowColor3 = map(hue, resolutie * 2 + 2 , resolutie * 3 + 2, 0, Brightness);
  int MappedRainbowColor4 = map(hue, resolutie * 3 + 3 , resolutie * 4 + 3, Brightness, 0);
  int MappedRainbowColor5 = map(hue, resolutie * 4 + 4 , resolutie * 5 + 4, 0, Brightness);
  int MappedRainbowColor6 = map(hue, resolutie * 5 + 5 , resolutie * 6 + 5, Brightness, 0);

  MappedRainbowColor1 = constrain(MappedRainbowColor1, 0, Brightness); // om er zeker voro te zijn dat we gaan min getallen krijgen
  MappedRainbowColor2 = constrain(MappedRainbowColor2, 0, Brightness);
  MappedRainbowColor3 = constrain(MappedRainbowColor3, 0, Brightness);
  MappedRainbowColor4 = constrain(MappedRainbowColor4, 0, Brightness);
  MappedRainbowColor5 = constrain(MappedRainbowColor5, 0, Brightness);
  MappedRainbowColor6 = constrain(MappedRainbowColor6, 0, Brightness);

  float mappedintensity = map(intensity, 0, Brightness, 0, 100) * 0.01;  // hierin wordt de waarde van x, die in deze functie al intensity wordt aangegeven gemapt van 0 naar 100 en maal 0,01 gedaan om zo een afnemende felheid te hebben.

  if (hue <= resolutie) {
    r = Brightness;
    g = 0;
    b = MappedRainbowColor1;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  } if (hue <= resolutie * 2) {
    r = MappedRainbowColor2;
    g = 0;
    b = Brightness;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  } if (hue <= resolutie * 3) {
    r = 0;
    g = MappedRainbowColor3;
    b = Brightness;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  }
  if (hue <= resolutie * 4) {
    r = 0;
    g = Brightness;
    b = MappedRainbowColor4;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  } if (hue <= resolutie * 5) {
    r = MappedRainbowColor5;
    g = Brightness;
    b = 0;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  } if (hue <= resolutie * 6) {
    r = Brightness;
    g = MappedRainbowColor6;
    b =  0;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  }
}



