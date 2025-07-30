//Layslla Eduarda Oreti

//LED_BUILDIN
//LED = 2

const byte LED = 2; //const é uma variável que não muda durante o código
//octeto de bit

void setup(){ //serve para configurar os pinos
  pinMode(LED,OUTPUT); //serve para definir o tipo de pino
}

void loop(){
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}

