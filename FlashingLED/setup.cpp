void setup() {
  pinMode(13, OUTPUT); // 板上 LED 通常是 13
}

void loop() {
  digitalWrite(13, HIGH); // 開燈
  delay(500);
  digitalWrite(13, LOW);  // 關燈
  delay(500);
}
