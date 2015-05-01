
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

int RainbowColor =       100;
int ColorChanger =       1;

float fadeValue =        150;

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second
int delayval2 = 5; // delay for half a second

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
    //    Serial.println("poepchineeeees");
    status_energy = 1;
  }


  if (status_energy == 1) {

    if (digitalRead(druk) == HIGH && digitalRead(schakelaar) == HIGH) {
      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize) {
        x = fadeValue;

        //        Serial.println(digitalRead(druk));

        for (int i = 0; i < 3; i++) {
          pixels1.setPixelColor(i, Wheel(x));
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

    if (digitalRead(druk) == HIGH && digitalRead(schakelaar) == LOW) {
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
// changing color of the rainbow


uint32_t Wheel(byte intensity) {

  RainbowColor = RainbowColor + ColorChanger;
  if (RainbowColor == 150) {
    ColorChanger = -1;
  }
  if (RainbowColor == 0) {
    ColorChanger = 1;
  }

  float mappedintensity = map(intensity, 0, 150, 0, 10) * 0.01;

  Serial.print(mappedintensity);
  Serial.print("       ");
  Serial.println(RainbowColor);

  if (RainbowColor < 35) {
    return pixels1.Color(mappedintensity * (255 * RainbowColor), 255 * RainbowColor, 0);
  } else if (RainbowColor < 100) {
    return pixels1.Color(mappedintensity * (255 * RainbowColor), 0, 255 * RainbowColor);
  } else {
    return pixels1.Color(0, 255 * RainbowColor, 255 * RainbowColor);

  }

}
