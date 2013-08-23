const int FAILURE_PIN = 12;
const int SUCCESS_PIN = 13;

void setup() {
  pinMode(FAILURE_PIN, OUTPUT);
  pinMode(SUCCESS_PIN, OUTPUT);
  startLED();
  Serial.begin(9600);
  while (!Serial) {;}
}

void startLED() {
  flicker(FAILURE_PIN);
  flicker(SUCCESS_PIN);
}

void loop() {
  if (Serial.available()) watch();
}

void watch() {
  int rest_sec = Serial.parseInt();
  if (rest_sec > 0) failure(rest_sec);
  else success();
}

void success() {
  digitalWrite(SUCCESS_PIN, HIGH);
}

void failure(int sec) {
  digitalWrite(SUCCESS_PIN, LOW);
  for (int i = 0;i < sec; i++) flicker(FAILURE_PIN);
}

void flicker(int pin) {
  digitalWrite(pin, HIGH);
  delay(700);
  digitalWrite(pin, LOW);
  delay(300);
}
