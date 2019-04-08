void hall_test(){
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

void motors_test(){
  walk(125, 0, 0, 0);
  delay(1500);
  walk(0, 250, 0, 0);
  delay(1500);
  walk(0, 0, 250, 0);
  delay(1500);
  walk(0, 0, 0, 250);
  while(!Serial.available());
  stop();
}

void test(){
  hall_test();
  motors_test();
}
