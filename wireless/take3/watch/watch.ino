const int tilt = 7;
const int led = 6;
int stand = 0;
int x = 0;

boolean status_energy =   1;

void setup() {
  Serial.begin(9600);
  pinMode(tilt, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  //  if (Serial.available() > 0) {

  digitalWrite(led, HIGH);
  boolean status_energy =   1;

  if (x < 255) {
    status_energy = 1 ;
  }

  if (status_energy == 1) {
    if ((digitalRead (tilt) == HIGH)) {
      x++;
      Serial.write(x);
      Serial.println(x);
      digitalWrite(led, LOW);
      delay(500);
      if (x == 255) {
        status_energy = 0 ;
      }
    }
  }
}

//    stand = digitalRead(drukknop);
//    Serial.write(stand);
//    Serial.println(stand);
//
//    if (stand == 0) {
//      digitalWrite(led, LOW);
// }
