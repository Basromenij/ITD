const int druk0 = 2;
const int druk1 = 4;

const int led0 = 5;
const int led1 = 6;

int i = 0;
  int sendData[] = {0,0};

void setup() {
  // put your setup code here, to run once:

  pinMode (druk0, INPUT);
  pinMode (druk1, INPUT);

  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  analogWrite(led0, 0);
  analogWrite(led1, 0);

  sendData[0] = digitalRead(druk0);
  sendData[1] = digitalRead(druk1);

  if (sendData[0] == HIGH) {
    for ( i = 0; i < 2; i++) {
      if ( i  == 0) {
        Serial.print(sendData[i]);
      }
      else {
        Serial.print(',');
        Serial.print(sendData[i]);
      }
    }
    Serial.print('\n');

    analogWrite(led0, 255);
    delay (500);
  }

  if (  sendData[1] == HIGH) {
    for ( i = 0; i < 2; i++) {
      if ( i  == 0) {
        Serial.print(sendData[i]);
      }
      else {
        Serial.print(',');
        Serial.print(sendData[i]);
      }
    }
    Serial.print('\n');

    analogWrite(led1, 255);
    delay (500);
  }
}

