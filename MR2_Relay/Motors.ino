void walk() {
  digitalWrite(mTR, LOW);
  digitalWrite(mBL, LOW);
  analogWrite(ptl, stl);
  analogWrite(pbr, sbr);

  delay(1000);
  //    analogWrite(ptl, 180);
  analogWrite(pbr, 255);
  //
  //  delay(500);
  //  analogWrite(ptl, stl);
  //  analogWrite(pbr, sbr);
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

  analogWrite(pbr, sbr);
  analogWrite(ptl, stl);

  int flag = 0;
  while ((digitalRead(hall_br) != 0 || digitalRead(hall_fl) != 0) && flag < 2) {
    Serial.println("BR - " + String(digitalRead(hall_br)) + "  FL - " + String(digitalRead(hall_fl)));
    if (digitalRead(hall_br) == 0) {
      flag++;
      analogWrite(pbr, 0);
    }
    if (digitalRead(hall_fl) == 0) {
      flag++;
      analogWrite(ptl, 0);
    }
  }
  stop();
}
