void walk() {
  digitalWrite(mTR, LOW);
  digitalWrite(mBL, LOW);
  analogWrite(ptl, stl);
  analogWrite(pbr, sbr);

  delay(700);
  //  analogWrite(ptl, 255);
  analogWrite(pbr, 255);

  //  delay(500);
  //  analogWrite(ptl, stl-50);
  //  analogWrite(pbr, sbr-50);
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
    Serial.println("BL");
    digitalWrite(mBL, LOW);
  }
  digitalWrite(mBL, HIGH);

  while (digitalRead(hall_fr) != 0) {
    Serial.println("FR");
    digitalWrite(mTR, LOW);
  }
  digitalWrite(mTR, HIGH);


  analogWrite(pbr, sbr);
  analogWrite(ptl, stl);

  while (digitalRead(hall_br) != 0 || digitalRead(hall_fl) != 0) {
    Serial.println("BR - " + String(digitalRead(hall_br)) + "  FL - " + String(digitalRead(hall_fl)));
    if (digitalRead(hall_br) == 0){
      analogWrite(pbr, 0);
    }
    if (digitalRead(hall_fl) == 0){
      analogWrite(ptl, 0);
    }
  }
  stop();
}
