const int led0 = 3;
const int led1 = 6;

int switch0 = 0;
int switch1 = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(led0, 0);
  analogWrite(led1, 0);

  int switch0 = Serial.parseInt();
  int switch1 = Serial.parseInt();

  if (Serial.read() == '\n') {
    if (switch0 == 1 && switch1 == 0 ) {
      analogWrite(led0, 255);
      delay (500);
    }

    if (switch0 == 0 && switch1 == 1 ) {
      analogWrite(led1, 255);
      delay (500);
    }

    if (switch0 == 1 && switch1 == 1 ) {
      analogWrite(led0, 255);
      analogWrite(led1, 255);
      delay (500);
    }
  }
}
