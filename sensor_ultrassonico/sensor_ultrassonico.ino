/* Data: 26/04/2023
  Nomes: Isabelle e Stephany
*/
#include "Ultrasonic.h" //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int echoPin = 33; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 34; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)
Ultrasonic ultrasonic(trigPin, echoPin); //INICIALIZANDO OS PINOS DO ARDUINO
int distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING
//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
void hcsr04() {
  digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
  delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
  digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
  delayMicroseconds(10); //INTERVALO DE 10 MICROSSEGUNDOS
  digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE
  //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
  //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA
  //NA VARIAVEL "distancia"
  distancia = (ultrasonic.Ranging(CM)); //VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
  result = String(distancia); //VARIÁVEL GLOBAL DO TIPO STRING RECEBE A DISTÂNCIA(CONVERTIDO DE INTEIRO PARA STRING)
  //delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}
void setup() {
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  lcd.begin(16, 2);
  Serial.begin(9600);//INICIALIZA A PORTA SERIAL
}
void loop() {
  hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"
  lcd.setCursor(0, 0 );
  lcd.print("Distancia: ");
  lcd.print(result);
  lcd.print("cm");
  Serial.print("Distancia "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(result); ////IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  Serial.println("cm"); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(500);
  lcd.clear();
}