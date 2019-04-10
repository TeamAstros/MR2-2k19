#define dir 5
#define pwm 6

#define pwm1 9
#define dir1 8

#define mTL 34
#define mTR 36
#define mBL 40
#define mBR 42

#define hall_fl 21
#define hall_fr 20
#define hall_bl 19
#define hall_br 18

volatile int count = 0;
volatile unsigned long timer = 0;
volatile bool flag = 0;

void setup() {
  Serial.begin(9600);

  pinMode(mTL, OUTPUT);
  pinMode(mTR, OUTPUT);
  pinMode(mBL, OUTPUT);
  pinMode(mBR, OUTPUT);
  pinMode(dir, OUTPUT);

  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  digitalWrite(dir, LOW);
  analogWrite(pwm, 150);

  digitalWrite(dir1, LOW);
  analogWrite(pwm1, 150);

  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);

  pinMode(10, OUTPUT);

  digitalWrite(10, LOW);

  Serial.println("In Setup");

  //  digitalWrite(mTL, LOW);
  //  while (1);
  stop();

  initialize();
//  while (1);
  delay(1000);
}

void loop() {
  Serial.println("Hall : " + String(digitalRead(hall_bl)));
  walk();
  while(!digitalRead(hall_bl)) Serial.println("Hall : " + String(digitalRead(hall_bl)));
  while(digitalRead(hall_bl)) Serial.println("Hall : " + String(digitalRead(hall_bl)));
  stop();
  initialize();
  delay(2000);
}

void hall() {
  Serial.print("Front Left : " + String(digitalRead(hall_fl)));
  Serial.print(" Front Right : " + String(digitalRead(hall_fr)));
  Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
  Serial.println(" Back Right : " + String(!digitalRead(hall_br)));
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
