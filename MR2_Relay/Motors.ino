void walk() {
  digitalWrite(mTR, LOW);
  digitalWrite(mBL, LOW);
  analogWrite(ptl, stl);
  analogWrite(pbr, sbr);
}

void stop() {
  digitalWrite(mTR, HIGH);
  digitalWrite(mBL, HIGH);
  analogWrite(ptl, 0);
  analogWrite(pbr, 0);
}

void initialize() {
  Serial.println("Set to hone de re");

  while (digitalRead(hall_bl) != 0) {
    digitalWrite(mBL, LOW);
  }
  digitalWrite(mBL, HIGH);

  while (digitalRead(hall_fr) != 0) {
    digitalWrite(mTR, LOW);
  }
  digitalWrite(mTR, HIGH);

  while (digitalRead(hall_br) != 0) {
    analogWrite(pbr, sbr);
  }
  analogWrite(pbr, 0);

  while (digitalRead(hall_fl) != 0) {
    analogWrite(ptl, stl);
  }
  analogWrite(ptl, 0);
}
