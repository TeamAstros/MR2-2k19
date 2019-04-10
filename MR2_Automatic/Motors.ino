void walk(byte tl = 250, byte tr = 250, byte bl = 250, byte br = 125) {
  analogWrite(mTLp, tl);
  analogWrite(mTRp, tr);
  analogWrite(mBLp, bl);
  analogWrite(mBRp, br);
}

void stop() {
  analogWrite(mTLp, 0);
  analogWrite(mTRp, 0);
  analogWrite(mBLp, 0);
  analogWrite(mBRp, 0);
}

void low_gerege() {
  digitalWrite(gerege_dir, LOW);
  analogWrite(gerege_pwm, 100);
}

void raise_gerege() {
  digitalWrite(gerege_dir, !LOW);
  analogWrite(gerege_pwm, 100);
}
