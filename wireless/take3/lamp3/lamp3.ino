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
#define aftelDelay        470


Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

uint8_t x =                0;
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
int RainbowColor =         0;



int delayval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(druk1, INPUT);
  pinMode(druk2, INPUT);

  // analogWrite(led2, HIGH);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {

  switch0 = digitalRead(druk1);
  switch1 = digitalRead(druk2);
  //  badWeather = digitalRead(druk3);
  sportingTogether = digitalRead(druk4);

  if (Serial.available() > 0) {
    x = Serial.read();
  }

  if (switch0 == 0  && sportingTogether == 0 &&  currentState != 0) {
    analogWrite(led1, 0);
    analogWrite(led2, 255);

    Serial.write(0);
    currentState = 0;
    delay(buttonDelay);

    for (int i = 0; i < 46; i++) {
      pixels1.setPixelColor(i, 0 , 0 , 0 );
      pixels1.show();
    }
  }

  if (switch0 == 0 && sportingTogether == 1 && currentState != 1) {
    analogWrite(led1, 0);
    analogWrite(led2, 255);

    for (int i = 0; i < 46; i++) {
      pixels1.setPixelColor(i, 0 , 0 , 0 );
      pixels1.show();
    }
    Serial.write(1);
    currentState = 1;
    delay(buttonDelay);
  }


  if (switch0 == 1 && switch1 == 0 && currentState != 2) {
    Serial.write(2);
    currentState = 2;
    delay(buttonDelay);
  }

  if (switch0 == 1  && switch1 == 0 ) {
    for (int i = 0; i < 46; i++) {
      pixels1.setPixelColor(i, x);
      pixels1.show();
    }
    analogWrite(led1, 255);
    analogWrite(led2, 0);
  }

  if (switch0 == 1  && switch1 == 1 && currentState != 3 ) {
    Serial.write(3);
    currentState = 3;
    delay(buttonDelay);
  }

  if (switch0 == 1  && switch1 == 1 ) {
    for (int i = 0; i < 46; i++) {
      pixels1.setPixelColor(i, Wheel(x));
    }
    pixels1.show();
    analogWrite(led1, 255);
    analogWrite(led2, 0);
  }
}

uint32_t Wheel(byte intensity) {

  RainbowColor = RainbowColor + ColorChanger;

  if (RainbowColor == 255) {
    RainbowColor = 0 ;
  }


  float mappedintensity = map(intensity, 0, Brightness, 0, 100) * 0.01;

  int MappedRainbowColor1 = map(RainbowColor, 0, resolutie , 0, Brightness);
  int MappedRainbowColor2 = map(RainbowColor, resolutie + 1 , resolutie * 2 + 1, Brightness, 0);
  int MappedRainbowColor3 = map(RainbowColor, resolutie * 2 + 2 , resolutie * 3 + 2, 0, Brightness);
  int MappedRainbowColor4 = map(RainbowColor, resolutie * 3 + 3 , resolutie * 4 + 3, Brightness, 0);
  int MappedRainbowColor5 = map(RainbowColor, resolutie * 4 + 4 , resolutie * 5 + 4, 0, Brightness);
  int MappedRainbowColor6 = map(RainbowColor, resolutie * 5 + 5 , resolutie * 6 + 5, Brightness, 0);
  MappedRainbowColor1 = constrain(MappedRainbowColor1, 0, Brightness);
  MappedRainbowColor2 = constrain(MappedRainbowColor2, 0, Brightness);
  MappedRainbowColor3 = constrain(MappedRainbowColor3, 0, Brightness);
  MappedRainbowColor4 = constrain(MappedRainbowColor4, 0, Brightness);
  MappedRainbowColor5 = constrain(MappedRainbowColor5, 0, Brightness);
  MappedRainbowColor6 = constrain(MappedRainbowColor6, 0, Brightness);

  if (RainbowColor <= resolutie) {
    r = Brightness;
    g = 0;
    b = MappedRainbowColor1;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  } if (RainbowColor <= resolutie * 2) {
    r = MappedRainbowColor2;
    g = 0;
    b = Brightness;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  } if (RainbowColor <= resolutie * 3) {
    r = 0;
    g = MappedRainbowColor3;
    b = Brightness;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  }
  if (RainbowColor <= resolutie * 4) {
    r = 0;
    g = Brightness;
    b = MappedRainbowColor4;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  } if (RainbowColor <= resolutie * 5) {
    r = MappedRainbowColor5;
    g = Brightness;
    b = 0;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  } if (RainbowColor <= resolutie * 6) {
    r = Brightness;
    g = MappedRainbowColor6;
    b =  0;
    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  }
  delay (aftelDelay);
}



