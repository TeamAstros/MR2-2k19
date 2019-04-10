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
  Serial.println("setupppppp");

  pinMode(mTL, OUTPUT);
  pinMode(mTR, OUTPUT);
  pinMode(mBL, OUTPUT);
  pinMode(mBR, OUTPUT);
  pinMode(dir, OUTPUT);

  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  digitalWrite(dir, LOW);
  analogWrite(pwm, 200);

  digitalWrite(dir1, LOW);
  analogWrite(pwm1, 200);

  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);

  Serial.println("In Setup  ---------------------------------------");

  digitalWrite(mTL, LOW);
  digitalWrite(mTR, HIGH);
  digitalWrite(mBL, HIGH);
  digitalWrite(mBR, HIGH);
  while (1)
    hall();
}
void loop() {
  // put your main code here, to run repeatedly:

}

void init() {
  while (digitalRead(hall_fl) != 0)
    digitalWrite(mTL, LOW);
  digitalWrite(mTL, HIGH);

  while (1);

  while (!digitalRead(hall_br) != 0)
    digitalWrite(mBR, LOW);
  digitalWrite(mBR, HIGH);

  while (digitalRead(hall_fr) != 0)
    digitalWrite(mTR, LOW);
  digitalWrite(mTR, HIGH);

  while (digitalRead(hall_bl) != 0)
    digitalWrite(mBL, LOW);
  digitalWrite(mBL, HIGH);
}

void hall() {
  Serial.print("Front Left : " + String(digitalRead(hall_fl)));
  Serial.print(" Front Right : " + String(digitalRead(hall_fr)));
  Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
  Serial.println(" Back Right : " + String(!digitalRead(hall_br)));
}
