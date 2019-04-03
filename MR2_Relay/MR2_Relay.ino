#define m1 8
#define m2 9
#define m3 10
#define m4 11

#define hall_fl 24
#define hall_fr 22
#define hall_bl 26
#define hall_br 28

bool test_flag = 0;
int count = 0;

void setup() {
  Serial.begin(9600);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);

  digitalWrite(m1, HIGH);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, HIGH);

//  test();

//  initialize();b
  Serial.println("Initialized");
  delay(2000);

  digitalWrite(m4, LOW);
  digitalWrite(m2, LOW);

  while(1);
}

void loop() {
  Serial.println("Count : " + String(count));
  if (!digitalRead(hall_fl)) {
    while (!digitalRead(hall_fl));
    count++;
  }


  if (count % 4 == 0) {
    stop();
    initialize();
    delay(1000);
    count++;
  }

  else
    drive();
}


void initialize2(){
  while(digitalRead(hall_fr) || digitalRead(hall_bl)){
    if(digitalRead(hall_fr))  digitalWrite(m4, LOW);
    else  digitalWrite(m4, HIGH);

    if(digitalRead(hall_bl))  digitalWrite(m2, LOW);
    else  digitalWrite(m2, HIGH);
  }

  while(digitalRead(hall_fl) || digitalRead(hall_br)){
    if(digitalRead(hall_fl))  digitalWrite(m3, LOW);
    else   digitalWrite(m3, HIGH);

    if(digitalRead(hall_br))  digitalWrite(m1, LOW);
    else  digitalWrite(m1, HIGH);
  }
}

void initialize() {
  digitalWrite(m4, LOW);
  while (digitalRead(hall_fr)){
    test();
  }
  digitalWrite(m4, HIGH);


  digitalWrite(m2, LOW);
  while (digitalRead(hall_bl)){
    test();
  }
  digitalWrite(m2, HIGH);

  
  digitalWrite(m3, LOW);
  while (digitalRead(hall_fl)){
    test();
  }
  digitalWrite(m3, HIGH);


  digitalWrite(m1, LOW);
  while (digitalRead(hall_br)){
    test();
  }
  digitalWrite(m1, HIGH);

  Serial.println("Initialize done");
}

void test() {
  Serial.print("Front Right : " + String(digitalRead(hall_fr)));
  Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
  Serial.print(" Front Left : " + String(digitalRead(hall_fl)));
  Serial.println(" Back Right : " + String(digitalRead(hall_br)));
}
