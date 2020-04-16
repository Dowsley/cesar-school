int x = 0;

void setup() {
  pinMode(7, OUTPUT); //Verde
  pinMode(8, OUTPUT); //Amarelo
  pinMode(11, OUTPUT); //Vermelho
  pinMode(13, OUTPUT); //Resistometro
  pinMode(A0, INPUT); //Leitura do resistometro
  pinMode(2, INPUT); //Botao leitura
  Serial.begin(9600);
}


void loop() {
digitalWrite(7, HIGH);
digitalWrite(13, HIGH);
if (x==0){
  Serial.println("Verde esta aceso, aperte o botao para passar.");
  x=x+1;
}
if (digitalRead(2)==1){
  digitalWrite(7, LOW);
  Serial.println("O verde apagou");
  digitalWrite(8, HIGH);
  Serial.println("O amarelo esta aceso");
  delay(5000);
  digitalWrite(8, LOW);
  Serial.println("O amarelo apagou");
  digitalWrite(11, HIGH);
  Serial.println("O vermelho acendeu");
  delay(10*analogRead(A0)+5000);
  digitalWrite(11, LOW);
  Serial.println("O vermelho apagou");
  x=0;
}
}
