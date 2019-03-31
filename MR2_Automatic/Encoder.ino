void interrupt1() {
  if (digitalRead(hall_fl))
    counter1++;
}

