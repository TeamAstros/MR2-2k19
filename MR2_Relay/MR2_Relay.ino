#define dir 5
#define pwm 6

#define mTL 35
#define mTR 41
#define mBL 37
#define mBR 43

#define hall_fl 21
#define hall_fr 20
#define hall_bl 19
#define hall_br 18

int count = 0;

void setup(){
  Serial.begin(9600);
  pinMode(mTL, OUTPUT);
  pinMode(mTR, OUTPUT);
  pinMode(mBL, OUTPUT);
  pinMode(mBR, OUTPUT);
  pinMode(dir, OUTPUT);
  
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  digitalWrite(dir, LOW);
  analogWrite(pwm, 200);

  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);

}

void loop(){
  initialize();
  delay(1000);
  walk();
  while (!digitalRead(hall_bl)) hall();
  while (digitalRead(hall_bl)) hall();
  stop();
}
