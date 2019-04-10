void hall_test()
{
  Serial.flush();
  while (!Serial.available())
  {
    Serial.print(" Front Left : " + String(digitalRead(hall_fl)));
    Serial.print(" Front Right : " + String(digitalRead(hall_fr)));
    Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
    Serial.println(" Back Right " + String(digitalRead(hall_br)));
  }
  Serial.println("Hall Sensor Test Success");
  delay(1000);
}

void motors_test()
{
  while (!Serial.available());
  while (1) {
    int test = Serial.parseInt();

    switch (test) {
      case 1:
        analogWrite(mTLp, 250);
        break;

      case 2:
        analogWrite(mTRp, 250);
        break;

      case 3:
        analogWrite(mBLp, 250);
        break;

      case 4:
        analogWrite(mBRp, 250);
        break;

      case 5:
        stop();
        break;

      case 6:
        return;
    }
  }

  Serial.println("Motors Tested Successfully");
  delay(1000);
}

void gerege_test()
{
  unsigned long timer = millis();
  raise_gerege();
  while (millis() - timer <= 500);
  low_gerege();
  timer = millis();
  while (millis() - timer <= 500);

  Serial.println("Gerege Mechanism Tested Successfully");
}

void test()
{
  hall_test();
  motors_test();
  motors_test();
  motors_test();
  motors_test();
//  gerege_test();
}
