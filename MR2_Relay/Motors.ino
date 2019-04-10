void walk() {
  digitalWrite(mTL, LOW);
  digitalWrite(mTR, LOW);
  digitalWrite(mBL, LOW);
  digitalWrite(mBR, LOW);
}

void stop() {
  digitalWrite(mTL, HIGH);
  digitalWrite(mTR, HIGH);
  digitalWrite(mBL, HIGH);
  digitalWrite(mBR, HIGH);
}

void initialize() {
  stop();

  while (digitalRead(hall_fr)) {
    digitalWrite(mTR, LOW);
    hall();
  }
  digitalWrite(mTR, HIGH);


  while (digitalRead(hall_bl)) {
    digitalWrite(mBL, LOW);
    hall();
  }
  digitalWrite(mBL, HIGH);

    digitalWrite(mBR, LOW);
    delay(1000);
  digitalWrite(mBR, HIGH);

  
  while (digitalRead(hall_fl)) {
    digitalWrite(mTL, LOW);
    hall();
  }
  digitalWrite(mTL, HIGH);
}

void hall() {
  Serial.print("Front Left : " + String(digitalRead(hall_fl)));
  Serial.print(" Front Right : " + String(digitalRead(hall_fr)));
  Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
  Serial.println(" Back Right : " + String(digitalRead(hall_br)));
}
