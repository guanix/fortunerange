const int average_counts = 16;
const int analog_pin = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  int sum = 0;
  for (ptrdiff_t i = 0; i < average_counts; i++) {
    sum += analogRead(analog_pin);
  }
  
  digitalWrite(13, HIGH);
  while (!Serial);
  while (!Serial.dtr());
  Serial.write(map(sum, 0, 1023*average_counts, 0, 255));
  Serial.send_now();
  delay(100);
  digitalWrite(13, LOW);
  
  delay(100);
}

