#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1              2
#define druk1             3
#define druk2             4
#define led1              5
#define led2              6

#define NUMPIXELS1        60
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);

int x = 0;
int stand2 = 0;
int stand1 = 0;
boolean status_energy =   1;

int delayval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(druk1, INPUT);
  pinMode(druk2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pixels1.begin(); // This initializes the NeoPixel library.
}

void loop() {
  //  if (Serial.available() > 0) {
  x = Serial.read();
  stand1 = digitalRead(druk1);
  stand2 = digitalRead(druk2);

  Serial.print("x");
  Serial.print(x);
  Serial.print("      ");
  Serial.print("druk1");
  Serial.print(druk1);
  Serial.print("      ");
  Serial.print("druk2");
  Serial.println(druk2);

  if (stand1 == HIGH) {
    digitalWrite(led1, HIGH);
    delay (500);
    digitalWrite(led1, LOW);
  }

  if (status_energy == 0) {
    status_energy == 1;
  }

  if (status_energy == 1); {
    if (stand1 == 1 && stand2 == 0) {
      x --;
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, x);
        pixels1.show();
      }
      if (x == 0) {
        status_energy = 0;
      }
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
    else {
      for (int i = 0; i < 60; i++) {
        pixels1.setPixelColor(i, 0);
        pixels1.show();
      }
    }

  }
}


// }






