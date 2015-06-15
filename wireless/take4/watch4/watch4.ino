int x = 0;
int led = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
   for (x  = 0; x <= 255; x+= 50) {
   Serial.write(x);
   analogWrite(led, x);
   delay(500);
 }
}
