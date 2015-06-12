const int drukknop = 7;
const int led = 6;
int stand = 0;
int x = 0;

boolean status_energy =   1;

void setup() {
  Serial.begin(9600);
  pinMode(drukknop, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  //  if (Serial.available() > 0) {

  digitalWrite(led, HIGH);
  boolean status_energy =   1;

  if (status_energy == 1) {
    x++;
    Serial.write(x);
    Serial.println(x);
    delay(1000);
    if (x == 255) {
      status_energy = 0 ;
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
