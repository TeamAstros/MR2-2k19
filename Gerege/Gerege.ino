#define g_dir 2
#define g_pwm 3
#define limit 28

bool flag = 0;

void setup() {
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(g_dir, OUTPUT);
  pinMode(limit, INPUT_PULLUP);

  analogWrite(g_pwm, 0);
  digitalWrite(4, LOW);

  delay(1000);


  while(1)
    Serial.println(digitalRead(limit));
}

void loop() {
  if (digitalRead(limit) == 0 && !flag) {
    digitalWrite(g_dir, HIGH);
    analogWrite(g_pwm, 100);
    delay(1000);
    analogWrite(g_pwm, 0);
    flag = 1;
    delay(1000);
  }

  else if(flag){
    digitalWrite(g_dir, LOW);
    analogWrite(g_pwm, 80);
    delay(1000);
    analogWrite(g_pwm, 0);
    flag = 0;
  }
}
