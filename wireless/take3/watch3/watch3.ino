const int tilt = 7;
const int led = 6;
uint8_t x = 0;

// boolean status_energy =   1;

void setup() {
  Serial.begin(9600);
  pinMode(tilt, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  if ((digitalRead (tilt) == HIGH)) {
    x++;
    Serial.write(x);
    analogWrite(led, x);
    if (x == 255) {
      x = 0;
    }
    delay(10);
  }
}


