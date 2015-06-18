const int druk0 = 2;
const int druk1 = 4;

const int led0 = 5;
const int led1 = 6;

int switch0 = 0;
int switch1 = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode (switch0, INPUT);
  pinMode (switch1, INPUT);

  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  analogWrite(led0, 0);
  analogWrite(led1, 0);

  switch0 = digitalRead(druk0);
  switch1 = digitalRead(druk1);
  
  if (switch0 == HIGH) {
    Serial.print(switch0);
    Serial.print(',');
    Serial.print(switch1);
    Serial.print('\n');

    analogWrite(led0, 255);
    delay (500);
  }

  if (switch1 == HIGH) {
    Serial.print(switch0);
    Serial.print(',');
    Serial.print(switch1);
    Serial.print('\n');

    analogWrite(led1, 255);
    delay (500);
  }

}

