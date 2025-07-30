#include <ESP8266WiFi.h>
//Layslla Eduarda Oreti
 
//SSid = Nome do Wi-fi.
//Char por conta que a autentificação fica mais rápida.
char ssid[] = "IPhone";
char senha[] = "123456789";
WiFiServer = server(80); //Cria um servidor na porta 80 (HTTP).
 
void conectarWiFi(char SSID[], char SENHA[]){
  Serial.print("Conectando a Rede");
  Serial.println(SSID);
 
  WiFi.begin(SSID, SENHA); //Inicializa o modo Wi-Fi.
 
  while(WiFi.status ! = WL_CONNECTED){ //Enquanto o wifi não estiver conectado.
    delay(500); //Espera 0,5 segundos.
    Serial.print("."); //Imprime '.' no terminal.
  }
 
  Serial.print("");
  Serial.println("Wi-Fi Conectado");
  Serial.println("Endereço de IP:");
  Serial.println(WiFi.localIP()); //Função que imprime o valor IP do ESP.
}
 
void setup(){
  Serial.begin(11200); //Velocidade de transmissão com outras tecnologias (Por exemplo, ESP e Celular).
  conectarWiFi(ssid, senha);
  server.begin(); //Inicializar Servidor WiFi.
  Serial.println("Servidor Inicializado");
}                            
 
void loop(){
  WiFiClient cliente = server.avaliable(); //Variável para deixar o servidor disponível.
 
  if(!client){ //Se não tiver cliente, o loop reseta.
    return;
  }
 
  while(!cliente.avaliable()){
    delay(1);
  }
 
  cliente.print("HTTP/1.1 200 OK");
  cliente.println("Content-Type: text/html");
  cliente.println("");
  cliente.println("<!DOCTYPE HTML>");
  cliente.println("<html>");
  cliente.println("<head>");
  cliente.println("<meta charset="UTF-8"/>");
  cliente.println("<title>Seja bem-vindo ao SENAI Roberto Mange</title>");
  cliente.println("</head>");
  cliente.println("<h1>Layslla Eduarda Oreti</h1>");
  cliente.println("</body>");
  cliente.println("</html");
}
 
 