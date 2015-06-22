const int tilt = 7;
const int led1 = 6;
const int led2 = 3;
const int stapGrootteOptellen = 10;
const int stapGrootteAftellen = 1;
const int aftelDelay = 50;  //470
const long interval = 50;

unsigned long previousMillis0 = 0;
unsigned long previousMillis1 = 0;


int currentState = 0;
int sportState0 = 0;
int sportState1 = 0;

int state = 0;
uint8_t x = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tilt, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (Serial.available() > 0) {
    currentState = Serial.read();
  }

  if (currentState == 0) {
    if (currentMillis - previousMillis0 >= interval) {
      previousMillis0 = currentMillis;

      if (digitalRead (tilt) == HIGH && sportState0 != 0) {
        x =  x + stapGrootteOptellen;
        x = constrain (x, 0, 255); // NEED TO WRITE LIMIT 255 AND STAYS THERE WITH BOLEAN TO STATE 2 AND 3
        sportState0 = 0;
      }
      if (digitalRead (tilt) == LOW && sportState0 != 1) {
        sportState0 = 1;
      }
      analogWrite(led1, x); // zet licht op de watch aan
      analogWrite(led2, 255);
    }
  }

  if (currentState == 1) {
    if (currentMillis - previousMillis1 >= interval) {
      previousMillis0 = currentMillis;

      if (digitalRead (tilt) == HIGH && sportState1 != 0)  {
        x =  x + stapGrootteOptellen;
        x = constrain (x, 0, 255); // NEED TO WRITE LIMIT 255 AND STAYS THERE WITH BOLEAN TO STATE 2 AND 3
        sportState1 = 0;
      }
      if (digitalRead (tilt) == LOW && sportState1 != 1) {
        sportState1 = 1;
      }
      analogWrite(led1, 255); // zet licht op de watch aan
      analogWrite(led2, x);
    }
  }

  if (currentState == 2 || currentState == 3) {
    x =  x - stapGrootteAftellen;
    analogWrite(led1, x );
    analogWrite(led2, x );
    Serial.write(x);
    delay(aftelDelay);
  }
}

//      if (currentMillis - previousMillis0 >= interval)
//        previousMillis0 = currentMillis;

//    int standschakelaar1 = Serial.parseInt();
//    int standschakelaar2 = Serial.parseInt();
//    //    int x = Serial.parseInt();
//
//    //  int telwaarde = Serial.parseInt();
//    if (Serial.read() == '\n') {
//      if (standschakelaar1 == 0 && standschaklelaar2 == 0 ) {
//
//        if (firstFlag == 1 ) {
//          counter = x;
//          firstFlag = 0;
//        }
//        counter++;
//      }
//
//
//
//
//      if (standschakelaar1 == 1)
//      {
//        analogWrite(led1, 255);
//        firstFlag = 1;
//      }
//
//      if (standschakelaar2 == 1)
//      {
//        analogWrite(led1, 0);
//        analogWrite(led2, 255);
//      }
//    }
//  }
//}

//  if ((digitalRead (tilt) == HIGH)) {
//    x++;
//    Serial.write(x);
//    analogWrite(led, x);
//    if (x == 255) {
//      x = 0;
//    }
//    delay(10);
//  }
//}

