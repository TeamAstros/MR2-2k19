#define mTLd 5
#define mTLp 6
#define mTRd 52
#define mTRp 50
#define mBLd 8
#define mBLp 9
#define mBRd 10
#define mBRp 11

#define hall_fr 20
#define hall_fl 21
#define hall_br 18
#define hall_bl 19

unsigned long timer = 0;
byte prevTL = 0, prevTR = 0, prevBL = 0, prevBR = 0;
byte speedTL = 250, speedTR = 250, speedBL = 250, speedBR = 125;

int hall_count = 0;

void walk(byte tl = speedTL, byte tr = speedTR, byte bl = speedBL, byte br = speedBR);

void setup() {
  pinMode(mTLd, OUTPUT);
  pinMode(mTRd, OUTPUT);
  pinMode(mBLd, OUTPUT);
  pinMode(mBRd, OUTPUT);

  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);

  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(48, OUTPUT);

  digitalWrite(12, LOW);   //Ground
  digitalWrite(7, LOW);    //Ground
  digitalWrite(48, LOW);   //Ground
  
  digitalWrite(mTLd, LOW);
  digitalWrite(mTRd, LOW);
  digitalWrite(mBLd, LOW);
  digitalWrite(mBRd, LOW);

  Serial.begin(9600);

  walk(0, 250, 0, 0);
  while(1);
  
  initialize3();
  delay(1500);
}


void loop() {
  code();
}


void code() {
  walk();

  while (digitalRead(hall_fr));
  hall_count++;
  Serial.println("Count = " + String(hall_count));

  if (hall_count % 2 == 0 && hall_count != 0) {
    initialize3();
    delay(500);
  }

  else
    while (!digitalRead(hall_fr));
}

void initialize3() {
  while (digitalRead(hall_fr) != 0) walk(0, 250, 0, 0);
  while (digitalRead(hall_bl) != 0) walk(0, 0, 250, 0);

  walk(250, 0, 0, 125);
  while (digitalRead(hall_fl) || digitalRead(hall_br)) {
    if (!digitalRead(hall_fl))  analogWrite(mTLp, 0);
    if (!digitalRead(hall_br))  analogWrite(mBRp, 0);

    stop();
    delay(1000);
  }
}
