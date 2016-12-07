#include <SoftwareSerial.h> // Biblioteca responsável pela comunicação serial no Arduino
 
SoftwareSerial bt(6, 7); // Objeto responsável pela comunicação serial através das respectivas portas RX e TX
int led = 13; // LED integrado na placa
int caractere; // Variável responsável pela leitura de caracteres através da porta serial
 
void setup() {
 bt.begin(9600); // Inicia a comunicação serial
 pinMode(led,OUTPUT); // Define o pino do led como saida
}
 
void loop() {
 if (bt.available()) { // Caso tenha algum caractere na porta serial
 caractere = bt.read(); // Le o caractere
 if(caractere == '1') { //Caso for 1, acende o led e escreve na porta.
 digitalWrite(led,HIGH);
 bt.println("OK, led ligado.");
 }
 if (caractere == '0') {//Caso for 0, apaga o led e escreve na porta.
 digitalWrite(led,LOW);
 bt.println("OK, led desligado.");
 }
 }
 delay(100);
}

