#define control 22
#define m1 24
#define m2 26
#define m3 28
#define m4 30

#define rm1 8
#define rm2 9
#define rm3 10
#define rm4 11

void setup()
{
  Serial.begin(9600);
  pinMode(m1, INPUT_PULLUP);
  pinMode(m2, INPUT_PULLUP);
  pinMode(m3, INPUT_PULLUP);
  pinMode(m4, INPUT_PULLUP);
  pinMode(control, INPUT_PULLUP);

  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(rm3, OUTPUT);
  pinMode(rm4, OUTPUT);
  
  stop();

}

void loop()
{
  if (!digitalRead(m1))
  {
    digitalWrite(rm1, LOW);
    while (!digitalRead(m1));
    digitalWrite(rm1, HIGH);
  }
  else if (!digitalRead(m2))
  {
    digitalWrite(rm2, LOW);
    while (!digitalRead(m2));
    digitalWrite(rm2, HIGH);
  }
  else if (!digitalRead(m3))
  {
    digitalWrite(rm3, LOW);
    while (!digitalRead(m3));
    digitalWrite(rm3, HIGH);
  }
  else if (!digitalRead(m4))
  {
    digitalWrite(rm4, LOW);
    while (!digitalRead(m4));
    digitalWrite(rm4, HIGH);
  }
  else if (!digitalRead(control))
  {
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    digitalWrite(rm3, LOW);
    digitalWrite(rm4, LOW);
    while (1);
  }
}
