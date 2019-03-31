const int mTLd = 8;
const int mTLp = 9;
const int mTRd = 6;
const int mTRp = 7;
const int mBLd = 3;
const int mBLp = 4;
const int mBRd = 22;
const int mBRp = 2;

const int gerege_dir = 11;
const int gerege_pwm = 12;

const int hall_fr = 52;
const int hall_fl = 53;
const int hall_br = 51;
const int hall_bl = 50;

const int ir_gerege = 10;

bool state = HIGH;
byte reading = 0;
volatile int counter1 = 0, counter2 = 0, counter3 = 0;
bool a1Flag = 0, b1Flag = 0, a2Flag = 0, b2Flag = 0, a3Flag = 0, b3Flag = 0, lflag = 1;
int count_line1 = 100, turn_count = 50, sand_dune_count = 20, turn_count2 = 30, ninety_count = 40, tussock_count = 50, uphill_count = 60;
unsigned long timer = 0;

void walk(byte tl = 250, byte tr = 250, byte bl = 250, byte br = 250);

void setup() {
  pinMode(mTLd, OUTPUT);
  pinMode(mTRd, OUTPUT);
  pinMode(mBLd, OUTPUT);
  pinMode(mBRd, OUTPUT);
  pinMode(gerege_dir, OUTPUT);

  pinMode(hall_fr, INPUT);
  pinMode(hall_fl, INPUT);
  pinMode(hall_br, INPUT);
  pinMode(hall_bl, INPUT);

  pinMode(5, OUTPUT);
  pinMode(ir_gerege, INPUT_PULLUP);

  digitalWrite(mTLd, HIGH);
  digitalWrite(mTRd, HIGH);
  digitalWrite(mBLd, HIGH);
  digitalWrite(mBRd, HIGH);

  digitalWrite(5, LOW);   //Ground

  Serial.begin(9600);
  walk(250, 250, 170, 250);
  while (1);
  //  initialize();
  //  delay(1500);
  //  while(1);
  delay(2000);
}

void loop() {
  //  while(!Serial.available());
  //    flow();
  //  timer = millis();
  //  while(millis() - timer <= 1300);
  //  stop();
  //  initialize();
}
