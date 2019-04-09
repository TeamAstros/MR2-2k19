#define hall_pin 0
#define motorPin 8
int c = 0, pc = 0;
unsigned long timer = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
//  digitalWrite(motorPin, 0);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.println("inSetup -------------------------");

  //  pinMode(hall_pin, INPUT_PULLUP); //DATA (Y)
  //  attachInterrupt(1, hall_func, RISING);
}

void loop() {
  Serial.println("inLoop");
  digitalWrite(motorPin, LOW);
  delay(1000);
  digitalWrite(motorPin, HIGH);
  delay(1000);
  Serial.println(String(analogRead(A0)));
}

void runWithHall() {
  while (!comparator(digitalRead(hall_pin)));
  while (comparator(digitalRead(hall_pin)));

  c++;
  Serial.println(c);
  analogWrite(motorPin, 255);
  Serial.println("inLoop");
  //  while(1);
}

int comparator(int v) {
  if (v > 200)
    return 1;
  else
    return 0;
}
//
//void whileWala() {
//  while (!digitalRead(hall_pin));
//  while (digitalRead(hall_pin));
//
//  c++;
//  Serial.println(c);
//  digitalWrite(43, HIGH);
//
//
//  while (1);
//}
//void interruptWala() {
//  timer = millis();
//  while (millis() - timer < 30000)
//  {
//    if (pc != c)
//    {
//      Serial.println(c);
//      pc = c;
//    }
//  }
//  Serial.println(c * 2);
//  while (1);
//}
//
//void hall_func() {
//  c++;
//}
