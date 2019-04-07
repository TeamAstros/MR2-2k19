void flow() {
  //  initialize();
  //  delay(1000);
  //  gerege();
  line1();
  //  turn();
  //  sand_dune();
  //  after_sand_dune();
  //  final_turn();
  //  tussock();
  //  uphill();
}

void gerege() {
  while (digitalRead(ir_gerege));
}

void line1() {
  walk();
  //  while(counter1 <= count_line1);
  //  stop();
  counter1 = 0;
}

void turn() {
  if (lflag) {
    walk(0, 255, 0, 255);
    while (counter1 <= turn_count);
    stop();
  }

  else {
    walk(255, 0, 255, 0);
    while (counter1 <= turn_count);
    stop();
  }
  counter1 = 0;
}

void sand_dune() {
  walk();
  while (counter1 <= sand_dune_count);
  stop();
  counter1 = 0;
}

void after_sand_dune() {
  turn();
  while (counter1 <= turn_count2);
  stop();
  counter1 = 0;
}

void final_turn() {
  lflag = !lflag;
  turn();
  while (counter1 <= ninety_count);
  stop();
  counter1 = 0;
  lflag = !lflag;
}

void tussock() {
  walk();
  while (counter1 <= tussock_count);
  stop();
  counter1 = 0;
}

void uphill() {
  walk();
  while (counter1 <= uphill_count);
  stop();
  counter1 = 0;
}

