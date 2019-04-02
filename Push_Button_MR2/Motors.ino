void stop(){
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, HIGH);
  digitalWrite(rm3, HIGH);
  digitalWrite(rm4, HIGH);
}

void drive(){
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
  digitalWrite(rm3, LOW);
  digitalWrite(rm4, LOW);
}

