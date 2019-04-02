#define m1 8
#define m2 9
#define m3 10
#define m4 11

#define hall_fl 24
#define hall_fr 22
#define hall_bl 26
#define hall_br 28

bool test_flag = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  pinMode(hall_fl, INPUT_PULLUP);
  pinMode(hall_fr, INPUT_PULLUP);
  pinMode(hall_bl, INPUT_PULLUP);
  pinMode(hall_br, INPUT_PULLUP);

  digitalWrite(m1, HIGH);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, HIGH);

  test();

  initialize();
  Serial.println("Initialized");
  delay(2000);

  drive();
}

void loop() {
  Serial.println("Count : " + String(count));
  if(!digitalRead(hall_fl)){
    while(!digitalRead(hall_fl));
    count++;
  }
    

  if(count % 4 == 1){
    stop();
    initialize();
    delay(1000);
    count++;
  }

  else
    drive();
}



void initialize() {
  while(digitalRead(hall_fr))
  {
    test();
    digitalWrite(m4, LOW);
  }
  digitalWrite(m4, HIGH);

  while(digitalRead(hall_bl))
  {
    test();
    digitalWrite(m2, LOW);
  }
  digitalWrite(m2, HIGH);
  
  while(digitalRead(hall_fl))
  {
    test();
    digitalWrite(m3, LOW);
  }
  digitalWrite(m3, HIGH);
  
  while(digitalRead(hall_br))
  {
    test();
    digitalWrite(m1, LOW);
  }
  digitalWrite(m1, HIGH);

  Serial.println("Initialize done");
}

void test() {
//  if (test_flag)
//    while (!Serial.available()) {
      Serial.print("Front Right : " + String(digitalRead(hall_fr)));
      Serial.print(" Back Left : " + String(digitalRead(hall_bl)));
      Serial.print(" Front Left : " + String(digitalRead(hall_fl)));
      Serial.println(" Back Right : " + String(digitalRead(hall_br)));
//    }
//
//   else
//    return;
}

