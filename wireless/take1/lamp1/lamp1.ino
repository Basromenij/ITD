
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              2

#define druk1             3
#define druk2             4

#define led               8

#define NUMPIXELS1        60

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

int sendData[] = { 0, 0, 0};

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second
int delayval2 = 1; // delay for half a second

void setup() {

  pinMode (druk1, INPUT);
  pinMode (druk2, INPUT);
  pinMode (led, OUTPUT);

  pixels1.begin(); // This initializes the NeoPixel library.

  Serial.begin(9600);
}

void loop() {
  Serial.println(x);

  digitalWrite (led, HIGH);

  if (Serial.available() > 0) {

    int x = Serial.parseInt();
    if (x > 0); {
      digitalWrite (led, LOW);;
      delay(500);
    }
  }



  //    sendData[0] = digitalRead(druk1);
  //    sendData[1] = digitalRead(druk2);
  //    sendData[2] = x;
  //
  //    for (int i = 0; i < 3; i++) {
  //      Serial.write(sendData[i]);
  //    }
  //
  //    if (x > 0 ) {
  //      status_energy == 1;
  //    }
  //
  //    if (status_energy = 1) {
  //      if (digitalRead(druk1) == HIGH && digitalRead(druk2) == LOW) {
  //        for (x ; x > 0; x -= stepSize) { //
  //          for (int i = 0; i < 3; i++) {
  //            pixels1.setPixelColor(i, x);
  //            pixels1.show();
  //
  //            if (x == 0) {
  //              status_energy = 0 ;
  //              break;
  //            }
  //            if ((digitalRead(druk1) == LOW || digitalRead(druk2) == HIGH))  {
  //              for (int i = 0; i < 3; i++) {
  //                Serial.write(sendData[i]);
  //              }
  //              break;
  //            }
  //            delay(delayval); // Delay for a period of time (in milliseconds).
  //          }
  //        }
  //      }
  //
  //      if (digitalRead(druk1) == HIGH && digitalRead(druk2) == HIGH) {
  //        for (x ; x > 0; x -= stepSize) { //
  //          for (int i = 0; i < 3; i++) {
  //            pixels1.setPixelColor(i, Wheel(x));
  //            pixels1.show();
  //            if (x == 0) {
  //              status_energy = 0 ;
  //              break;
  //            }
  //            if ((digitalRead(druk1) == LOW || digitalRead(druk2) == HIGH))  {
  //              for (int i = 0; i < 3; i++) {
  //                Serial.write(sendData[i]);
  //              }
  //              break;
  //            }
  //            delay(delayval); // Delay for a period of time (in milliseconds).
  //          }
  //        }
  //      }
  //    }
  //  }
  //// }
  //
  //uint32_t Wheel(byte intensity) {
  //  RainbowColor = RainbowColor + ColorChanger;
  //  if (RainbowColor == 255) {
  //    RainbowColor = 0 ;
  //  }
  //
  //  float mappedintensity = map(intensity, 0, maxbrightness, 0, 100) * 0.01;
  //
  //  int MappedRainbowColor1 = map(RainbowColor, 0, resolutie , 0, Brightness);
  //  int MappedRainbowColor2 = map(RainbowColor, resolutie + 1 , resolutie * 2 + 1, Brightness, 0);
  //  int MappedRainbowColor3 = map(RainbowColor, resolutie * 2 + 2 , resolutie * 3 + 2, 0, Brightness);
  //  int MappedRainbowColor4 = map(RainbowColor, resolutie * 3 + 3 , resolutie * 4 + 3, Brightness, 0);
  //  int MappedRainbowColor5 = map(RainbowColor, resolutie * 4 + 4 , resolutie * 5 + 4, 0, Brightness);
  //  int MappedRainbowColor6 = map(RainbowColor, resolutie * 5 + 5 , resolutie * 6 + 5, Brightness, 0);
  //
  //  MappedRainbowColor1 = constrain(MappedRainbowColor1, 0, Brightness);
  //  MappedRainbowColor2 = constrain(MappedRainbowColor2, 0, Brightness);
  //  MappedRainbowColor3 = constrain(MappedRainbowColor3, 0, Brightness);
  //  MappedRainbowColor4 = constrain(MappedRainbowColor4, 0, Brightness);
  //  MappedRainbowColor5 = constrain(MappedRainbowColor5, 0, Brightness);
  //  MappedRainbowColor6 = constrain(MappedRainbowColor6, 0, Brightness);
  //
  //  if (RainbowColor <= resolutie) {
  //    r = Brightness;
  //    g = 0;
  //    b = MappedRainbowColor1;
  //    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  //  } if (RainbowColor <= resolutie * 2) {
  //    r = MappedRainbowColor2;
  //    g = 0;
  //    b = Brightness;
  //    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  //  } if (RainbowColor <= resolutie * 3) {
  //    r = 0;
  //    g = MappedRainbowColor3;
  //    b = Brightness;
  //    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  //  }
  //  if (RainbowColor <= resolutie * 4) {
  //    r = 0;
  //    g = Brightness;
  //    b = MappedRainbowColor4;
  //    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  //  } if (RainbowColor <= resolutie * 5) {
  //    r = MappedRainbowColor5;
  //    g = Brightness;
  //    b = 0;
  //    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity );
  //  } if (RainbowColor <= resolutie * 6) {
  //    r = Brightness;
  //    g = MappedRainbowColor6;
  //    b =  0;
  //    return pixels1.Color(r * mappedintensity, g * mappedintensity, b * mappedintensity);
  //  }

}

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
