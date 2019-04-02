#define m1 8
#define m2 9
#define m3 10
#define m4 11

#define hall_fl 30
#define hall_fr 32
#define hall_bl 34
#define hall_br 36

bool test_flag = 1;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);

  test();

  initialize();
  delay(2000);

  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void loop() {
  //Lol idhar kuch bhi nahi hai
}



void initialize() {
  digitalWrite(m1, LOW);
  while (!digitalRead(hall_fl));
  digitalWrite(m1, HIGH);

  digitalWrite(m2, LOW);
  while (!digitalRead(hall_fr));
  digitalWrite(m2, HIGH);

  digitalWrite(m3, LOW);
  while (!digitalRead(hall_bl));
  digitalWrite(m3, HIGH);

  digitalWrite(m4, LOW);
  while (!digitalRead(hall_br));
  digitalWrite(m4, HIGH);
}

void test() {
  if (test_flag)
    while (!Serial.available()) {
      Serial.print("Front Left : " + String(digitalRead(hall_fl)));
      Serial.print("Front Right : " + String(digitalRead(hall_fr)));
      Serial.print("Back Left : " + String(digitalRead(hall_bl)));
      Serial.println("Back Right : " + String(digitalRead(hall_br)));
    }

   else
    return;
}

