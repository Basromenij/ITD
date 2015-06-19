const int tilt = 7;
const int led1 = 6;
const int led2 = 3;
int currentState = 0;
int state = 0;
uint8_t x = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tilt, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    currentState = Serial.read();
  }


  //    if (currentState == 0) {
  //        x++;
  //        analogWrite(led1, x);
  //        analogWrite(led2, 0);
  //        delay(10);
  //      }
  //
  //     if (currentState == 1) {
  //        x++;
  //        analogWrite(led1, 0);
  //        analogWrite(led2, x);
  //                delay(10);
  //      }
  // }

  if (currentState == 0) { //  && (digitalRead (tilt)) == HIGH) {
    if (digitalRead (tilt) == HIGH) {
      x =  x + 50;
      analogWrite(led1, x);
      analogWrite(led2, 255);
      delay(500);
    }
  }

  if (currentState == 1) { // && (digitalRead (tilt)) == HIGH) {
    if (digitalRead (tilt) == HIGH) {
      x =  x + 50;
      analogWrite(led1, 255);
      analogWrite(led2, x);
      delay(500);


    }
  }

  if (currentState == 2 || currentState == 3) {
    if (digitalRead (tilt) == HIGH) {
      x =  x - 50;
      analogWrite(led1, x);
      analogWrite(led2, 255);
      Serial.write(x);

      delay(500);
    }
  }
}


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


