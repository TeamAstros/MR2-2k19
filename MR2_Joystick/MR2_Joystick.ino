#include <PS2X_lib.h>

#define Pstr_DAT 28
#define Pstr_CMD 30
#define Pstr_SEL 32
#define Pstr_CLK 34

#define hall_fr 50
#define hall_fl 52
#define hall_bl 51
#define hall_br 53

#define mtrd 6
#define mtrp 7

#define mtld 8
#define mtlp 9

#define mbrd 22
#define mbrp 2

#define mbld 3
#define mblp 4

#define spd 255
PS2X ps;

void setup() {
  Serial.begin(38400);

  pinMode(mbld, OUTPUT);
  pinMode(mbrd, OUTPUT);
  pinMode(mtld, OUTPUT);
  pinMode(mtrd, OUTPUT);

  pinMode(5, OUTPUT);
//  pinMode(7, OUTPUT);
//  pinMode(4, OUTPUT);
//
//  pinMode(24, OUTPUT);
//  pinMode(26, OUTPUT);
  

  pinMode(hall_fr, INPUT);
  pinMode(hall_fl, INPUT);
  pinMode(hall_br, INPUT);
  pinMode(hall_bl, INPUT);

  digitalWrite(5, LOW); //TL
//  digitalWrite(7, LOW);  //TR

  digitalWrite(mbld, HIGH);
  digitalWrite(mbrd, HIGH);
  digitalWrite(mtld, HIGH);
  digitalWrite(mtrd, HIGH);

  int error = ps.config_gamepad(Pstr_CLK, Pstr_CMD, Pstr_SEL, Pstr_DAT, false, false);

  while (error)
  {
    Serial.println("Not connected");
    error = ps.config_gamepad(Pstr_CLK, Pstr_CMD, Pstr_SEL, Pstr_DAT, false, false);
    delay(2000);
  }

  Serial.println("Connected");
}

void loop() {
    joystickRun();
//  initialize();
}

void joystickRun() {
  ps.read_gamepad();

  if (ps.Button(PSB_START)) {}
  else if (ps.Button(PSB_CIRCLE) && ps.Button(PSB_L1)) {
    digitalWrite(mtrd, LOW);
    analogWrite(mtrp, spd);
    Serial.println("Top Right leg (B)");
  }
  else if (ps.Button(PSB_CIRCLE)) {

    digitalWrite(mtrd, HIGH);
    analogWrite(mtrp, spd);
    Serial.println("Top Right leg (F)");
  }



  else if (ps.Button(PSB_TRIANGLE) && ps.Button(PSB_L1)) {
    digitalWrite(mtld, LOW);
    analogWrite(mtlp, spd);
    Serial.println("Top Left leg (B)");
  }
  else if (ps.Button(PSB_TRIANGLE)) {
    digitalWrite(mtld, HIGH);
    analogWrite(mtlp, spd);
    Serial.println("Top Left leg (F)");
  }


  else if (ps.Button(PSB_SQUARE) && ps.Button(PSB_L1)) {
    digitalWrite(mbld, LOW);
    analogWrite(mblp, spd);
    Serial.println("Bottom Left leg (B)");
  }
  else if (ps.Button(PSB_SQUARE)) {
    digitalWrite(mbld, HIGH);
    analogWrite(mblp, spd);
    Serial.println("Bottom Left leg (F)");
  }


  else if (ps.Button(PSB_CROSS) && ps.Button(PSB_L1)) {
    digitalWrite(mbrd, LOW);
    analogWrite(mbrp, spd);
    Serial.println("Bottom Right leg (B)");
  }
  else if (ps.Button(PSB_CROSS)) {
    digitalWrite(mbrd, HIGH);
    analogWrite(mbrp, spd);
    Serial.println("Bottom Right leg (F)");
  }

  else if (ps.Button(PSB_PAD_UP)) {
    initialize();
  }

  else if (ps.Button(PSB_R1)) {
    digitalWrite(mbld, HIGH);
    digitalWrite(mbrd, HIGH);
    digitalWrite(mtld, HIGH);
    digitalWrite(mtrd, HIGH);
    analogWrite(mtrp, spd);
    analogWrite(mbrp, spd);
    analogWrite(mtlp, spd);
    analogWrite(mblp, spd);

    Serial.println("All Motors");
  }

  else {
    analogWrite(mtlp, 0);
    analogWrite(mbrp, 0);
    analogWrite(mblp, 0);
    digitalWrite(mtrp, 0);

  }
  delay(50);
}
