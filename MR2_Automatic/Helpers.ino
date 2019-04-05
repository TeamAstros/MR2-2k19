void initialize() {
  Serial.println("Set to hone de re ");

    while (digitalRead(hall_fl) != 0) {
    walk(250, 0, 0, 0);
    printHall();
  }

    while (digitalRead(hall_br) != 0) {
    walk(0, 0, 0, 250);
    printHall();
  }
  
  while (digitalRead(hall_fr) != 0) {
    walk(0, 250, 0, 0);
    printHall();
  }

  while (digitalRead(hall_bl) != 0) {
    walk(0, 0, 250, 0);
    printHall();
  }

  Serial.println("Set hu main");
  stop();
}

void printHall() {
  Serial.print(" Front Left : " + String(digitalRead(hall_fl)));
  Serial.print(" Front Right : " + String(digitalRead(hall_fr)));
  Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
  Serial.println(" Back Right " + String(digitalRead(hall_br)));
}
