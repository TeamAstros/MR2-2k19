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
    Serial.println("Set to hone de re ");

    while (digitalRead(hall_fr) != 0){
      digitalWrite(mTR, LOW);
     
    }
    digitalWrite(mTR, HIGH);

    while (digitalRead(hall_br) != 1){
      digitalWrite(mBR, LOW);
    }
    digitalWrite(mBR, HIGH);

    while (digitalRead(hall_fl) != 0){
      digitalWrite(mTL, LOW);
    }
    digitalWrite(mTL, HIGH);

    /*
    while (digitalRead(hall_bl) != 0){
      digitalWrite(mBL, LOW);
      hall();
    }
    digitalWrite(mBL, HIGH);
    */
}
