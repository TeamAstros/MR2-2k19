#define dtl 8
#define ptl 9

#define dbr 5
#define pbr 6

#define mTR 44
#define mBL 42

#define hall_fl 18
#define hall_fr 19
#define hall_bl 20
#define hall_br 21

#define stl 150
#define sbr 150

volatile int count = 0;
volatile unsigned long timer = 0;
volatile bool flag = 0;

void setup() {
  Serial.begin(9600);

  pinMode(mTR, OUTPUT);
  pinMode(mBL, OUTPUT);
  pinMode(dbr, OUTPUT);
  pinMode(dtl, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(7, LOW);
  digitalWrite(10, LOW);

  digitalWrite(dbr, HIGH);
  digitalWrite(dtl, LOW);

  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);

  Serial.println("In Setup");
  stop();

  analogWrite(ptl, 150);
  while(1);

  initialize();
  delay(1000);
}

void loop() {
  //  Serial.println("Hall : " + /String(digitalRead(hall_bl)));
  walk();
  while (!digitalRead(hall_fr)) Serial.println("Hall : " + String(digitalRead(hall_fr)));
  while (digitalRead(hall_fr)) Serial.println("Hall : " + String(digitalRead(hall_fr)));
  stop();
  initialize();
  delay(2000);
}

void hall() {
  Serial.print("Front Left : " + String(digitalRead(hall_fl)));
  Serial.print(" Front Right : " + String(digitalRead(hall_fr)));
  Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
  Serial.println(" Back Right : " + String(digitalRead(hall_br)));
}

void isr() {
  timer = micros();
  while (micros() - timer <= 500);
  if (!digitalRead(hall_bl)) {
    count++;
    flag = true;
  }
  else
    return;
}
