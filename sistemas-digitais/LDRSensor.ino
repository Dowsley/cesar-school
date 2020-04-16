int t=100;
int MIN = 100;
int MAX = 750;
 
void setup() {
  pinMode(9, OUTPUT); //red
  pinMode(10, OUTPUT); //green
  pinMode(11, OUTPUT); //blue
  Serial.begin(9600);
}

void loop() {
 if Serial.available()>0{
 MIN = Serial.parseInt();
 MAX = Serial.parseInt()
 }
 Serial.println(analogRead(A1));
 if (analogRead(A1)<100){
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
 }
 if ((analogRead(A1)>=100) and (analogRead(A1)<=750)){
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
 }
 if (analogRead(A1)>750){
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
 }
}
