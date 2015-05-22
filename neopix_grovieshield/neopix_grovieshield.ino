// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN1            5
#define PIN2            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS1      4
#define NUMPIXELS2      3


boolean status_energy = 1;

const int teller = 8;
const int druk = 2;
// const int schakel = 7;

float fadeValue = 0;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);


int delayval = 50; // delay for half a second
float stepSize = 1;
int x = 0;


void setup() {
  pinMode ( 6, INPUT_PULLUP);
  pinMode (teller, INPUT);
  pinMode (druk, INPUT);
  //  pinMode (schakel, INPUT);

  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel libr nary.
  Serial.begin(9600);
}

void loop() {

//  Serial.print("waarde van x: ");
//  Serial.println(x);
  //  Serial.println(" ");
  //  Serial.print("status teller");
  //  Serial.println(digitalRead(teller));
  //  Serial.println(" ");
//  Serial.print("status druk");
//  Serial.println(digitalRead(druk));
  //  Serial.println(" ");

  if (digitalRead(druk) == HIGH) {
//    Serial.println("poepchineeeees");
    status_energy = 1;
  }


  if (status_energy == 1) {

    //    if (digitalRead(druk) == HIGH && digitalRead(schakel) == LOW) // schakel lamp

    if (digitalRead(druk) == HIGH)


    {
      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize)
      {
        x = (int) 1 * fadeValue;
        Serial.print("waarde van x: ");
        Serial.println(x);
        Serial.println(digitalRead(druk));
        pixels1.setPixelColor(0, pixels1.Color(x, x, x)); // sets a white color for neopix with a brightness x
        pixels1.setPixelColor(1, pixels1.Color(x, x, x)); // sets a white color for neopix with a brightness x
        pixels1.setPixelColor(2, pixels1.Color(x, x, x)); // sets a white color for neopix with a brightness x
        pixels2.setPixelColor(0 , 0); // turns off neopix
        pixels2.setPixelColor(1 , 0); // turns off neopix
        pixels2.setPixelColor(2 , 0 ); // turns off neopix
        pixels1.show(); // This sends the updated pixel color to the hardware.
        pixels2.show(); // This sends the updated pixel color to the hardware.

        if (x == 0)

        {
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

    // //      if (digitalRead(druk) == HIGH && digitalRead(schakel) == HIGH) // schakel lamp
    //
    //    {
    //      for (fadeValue ; fadeValue > 0; fadeValue -= stepSize)
    //      {
    //        x = (int) 1 * fadeValue;
    //        Serial.print(x);
    //        Serial.print("   ");
    //        Serial.println(digitalRead(druk));
    //        pixels1.setPixelColor(0, pixels1.Color(x, x, x)); // sets a white color for neopix with a brightness x
    //        pixels1.setPixelColor(1, pixels1.Color(x, x, x)); // sets a white color for neopix with a brightness x
    //        pixels1.setPixelColor(2, pixels1.Color(x, x, x)); // sets a white color for neopix with a brightness x
    //        pixels2.setPixelColor(0 , 0); // turns off neopix
    //        pixels2.setPixelColor(1 , 0); // turns off neopix
    //        pixels2.setPixelColor(2 , 0 ); // turns off neopix
    //        pixels1.show(); // This sends the updated pixel color to the hardware.
    //        pixels2.show(); // This sends the updated pixel color to the hardware.
    //
    //        if (x == 0)
    //
    //        {
    //          status_energy = 0 ;
    //          break;
    //          Serial.println("waarde is nu een");
    //
    //        }
    //        if ((digitalRead(druk)) == LOW)  {     // turn other led strip on
    //          Serial.print(" hij komt in de break if");
    //          break;
    //        }
    //
    //
    //        delay(delayval); // Delay for a period of time (in milliseconds).
    //      }

  }

  else {

    x = (int) 1 * fadeValue;
    Serial.print(x);
    Serial.print("   ");
    Serial.println(digitalRead(druk));

    pixels1.setPixelColor(0 , 0); // turns off neopix
    pixels1.setPixelColor(1 , 0); // turns off neopix.
    pixels1.setPixelColor(2 , 0 ); // turns off neopix
    pixels2.setPixelColor(0, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
    pixels2.setPixelColor(1, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
    pixels2.setPixelColor(2, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x.
    pixels1.show(); // This sends the updated pixel color to the hardware.
    pixels2.show(); // This sends the updated pixel color to the hardware.


    if (digitalRead(teller) == HIGH) {
      for (fadeValue ; fadeValue < 150; fadeValue += 1)
      {
        Serial.print("hij is aan het tellen");
        fadeValue ++;
        break;
      }

      //       delay(delayval);
    }



    //        x = (int)1 * fadeValue;
    //        Serial.print(x);
    //        Serial.print("hij komt in de loop van de teller");
    //        Serial.println(digitalRead(druk));
    //
    //        pixels1.setPixelColor(0 , 0); // turns off neopix
    //        pixels1.setPixelColor(1 , 0); // turns off neopix.
    //        pixels1.setPixelColor(2 , 0 ); // turns off neopix
    //        pixels2.setPixelColor(0, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
    //        pixels2.setPixelColor(1, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x
    //        pixels2.setPixelColor(2, pixels2.Color(x, x, x)); // sets a white color for neopix with a brightness x.
    //        pixels1.show(); // This sends the updated pixel color to the hardware.
    //        pixels2.show(); // This sends the updated pixel color to the hardware.

  }

  //      delay (delayval); // Delay for a period of time (in milliseconds)
}

// }
// }
//delay(delayval);
//}
