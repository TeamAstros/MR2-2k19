const int mTLd = 10;
const int mTLp = 11;
const int mTRd = 8;
const int mTRp = 9;
const int mBLd = 52;
const int mBLp = 50;
const int mBRd = 5;
const int mBRp = 6;

const int gerege_dir = 11;
const int gerege_pwm = 12;

const int hall_fr = 19;
const int hall_fl = 18;
const int hall_br = 21;
const int hall_bl = 20;

const int ir_gerege = 10;

bool state = HIGH;
byte reading = 0;
volatile int counter1 = 0, counter2 = 0, counter3 = 0;
bool a1Flag = 0, b1Flag = 0, a2Flag = 0, b2Flag = 0, a3Flag = 0, b3Flag = 0, lflag = 1;
int count_line1 = 100, turn_count = 50, sand_dune_count = 20, turn_count2 = 30, ninety_count = 40, tussock_count = 50, uphill_count = 60;
unsigned long timer = 0;

int hall_count = 0;

void walk(byte tl = 250, byte tr = 250, byte bl = 250, byte br = 250);

void setup() {
  pinMode(mTLd, OUTPUT);
  pinMode(mTRd, OUTPUT);
  pinMode(mBLd, OUTPUT);
  pinMode(mBRd, OUTPUT);
  pinMode(gerege_dir, OUTPUT);

  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);

  pinMode(ir_gerege, INPUT_PULLUP);

  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(48, OUTPUT);

  digitalWrite(mTLd, !HIGH);
  digitalWrite(mTRd, HIGH);
  digitalWrite(mBLd, HIGH);
  digitalWrite(mBRd, HIGH);

  digitalWrite(12, LOW);   //Ground
  digitalWrite(7, LOW);    //Ground
  digitalWrite(48, LOW);   //Ground

  Serial.begin(9600);
  initialize();
  delay(3000);
}

void loop() {
  //  while(!Serial.available());
  walk();

  while (digitalRead(hall_fl))
    Serial.println("Waiting for hall in count");
  hall_count++;
  Serial.println("Count = " + String(hall_count));

  if (hall_count % 2 == 0) {
    initialize3();
    delay(500);
  }
  else
    while (!digitalRead(hall_fl));
}

void initialize3() {
  while (digitalRead(hall_br) != 0) {
    walk(0, 0, 0, 250);
    printHall();
  }

  walk(0, 250, 250, 0);

  while (digitalRead(hall_fr) || digitalRead(hall_bl)) {
    if (!digitalRead(hall_fr))
      analogWrite(mTRp, 0);

    if (!digitalRead(hall_bl))
      analogWrite(mBLp, 0);

    printHall();
  }

  stop();

  delay(1000);


}
