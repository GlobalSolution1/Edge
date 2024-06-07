// Bibliotecas utilizadas no projeto
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>


// Conexões dos sensores, dos leds e do botão com o Arduino
const byte sensorPin = 9;
const byte buzzer = 13;
const byte ledVermelho = 8;
const byte ledVerde = 7;


// Permite a comunicação com o arduíno, indicando o pino onde ele foi conectado
OneWire pin(sensorPin); 
// Solicita e obtêm leituras de temperatura dos sensores de temperatura DS18B20
DallasTemperature bus(&pin);
// Define o endereço com o nome de "sensor"
DeviceAddress sensor;
 
// Inicia o Lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Declara as váriaveis de temperaturas mínima, máxima e da leitura da temperatura atual em graus celsius
float minC;
float maxC;
float tempC;

// Temperaturas mínima e máxima que ativam o alerta
const float tempMx = 24;
const float tempMn = 18;

// Configurações do arduíno
void setup() {
  Serial.begin(9600);// Inicia monitor serial
  lcd.begin(16, 2); // Inicia o lcd
  pinMode(ledVermelho, OUTPUT);// Define o led vermelho como saída
  pinMode(ledVerde, OUTPUT);// Define o led verde como saída
  pinMode(buzzer, OUTPUT);// // Define o buzzer como saída
  lcd.clear(); // Limpa o display
  bus.begin(); // Inicia o bus
  bus.getAddress(sensor, 0); // Permite localizar o sensor de temperatura  
  // Define valores para a variável de mínima e máxima de temperatura na primeira leitura
  minC = 200;
  maxC = -200;

  // Som da introdução
  int intro[] = {65, 73, 82, 87, 98, 110, 123, 131, 147, 165, 175, 196, 220};

  // Laço que toca o som da introdução
  for (int i = 0; i < 13; i++) {
    tone(buzzer, intro[i]); // Define o tom como a array intro[]
    delay(200); // Duração de cada beep da introdução
    noTone(buzzer);// Encerra a introdução
  }
  delay(500);// Espera meio segundo antes de adicionar o logo
  
  // Limpa o lcd
  lcd.clear();

  // Mensagem de introdução com o nome e o logo da empresa
  char nomeLogo[] = "Ocean Shield";
  char slogan[] = "Protegendo o Mar" ;

  // Laço em que faz com que cada letra da intro entre 1 por vez
  for (int i = 0; i < sizeof(nomeLogo) - 1; i++) {
    lcd.setCursor(i+2, 0);  // Move o cursor para a próxima posição, e inicia ele no centro
    lcd.print(nomeLogo[i]);  // Printa uma letra por vez
    delay(300);  // Espera meio segundo
  }
  for (int i = 0; i < sizeof(slogan) - 1; i++) {
    lcd.setCursor(i, 1);  // Move o cursor para a próxima posição, e inicia ele no centro
    lcd.print(slogan[i]);  // Printa uma letra por vez
    delay(300);  // Espera meio segundo
  }

  // Adicona um tempo de 1 segundo antes de iniciar a leitura
  delay(1000);
}


void loop() {
  // Leitura do sensor
  bus.requestTemperatures(); // Faz a leitura do sensor
  tempC = bus.getTempC(sensor); // Temperatura em ºC
  // Atualiza temperaturas mínima e máxima: se a temperatura no lida for menor do que a temperatura armazenada em minC e o contrário para maxC
  if (tempC < minC)  minC = tempC;
  if (tempC > maxC)  maxC = tempC;
    
  celsius(); // Função que mostra os valores em ºC no display
    
  // Verifica a temperatura máxima e mínima estabelecidas como o padrão adequado
  if(tempC > tempMx){ // Se a temperatura for maior que a máxima permitida o alarme é ativado    
    alarme(); 
  } else if (tempC < tempMn) { // Se a temperatura for menor que a mínima permitida o alarme é ativado  
    alarme();   
  }else { // Se a temperatura for adequada o led vermelho é desligado e o verde ligado
    digitalWrite(ledVermelho, LOW); // Desligar o LED vermelho quando a temperatura estiver dentro do intervalo desejado
    digitalWrite(ledVerde, HIGH); // Ligar o LED verde quando a temperatura estiver dentro do intervalo desejado
    noTone(buzzer); // Interrompe o tom do buzzer
}

}

// Função que exibe a temperatura no display
void celsius() {
  // Mostra valores da temperatura no display
  lcd.setCursor(0,0);
  lcd.print("Temp.: "); 
  lcd.print(tempC); // Temperatura normal
  lcd.write(B11011111); // Símbolo de graus celsius
  lcd.print("C ");
  lcd.setCursor(0,1);
  lcd.print("B="); // Temperatura mínima lida
  lcd.print(minC);
  lcd.print(" A="); // Temperatura máxima lida
  lcd.print(maxC);
}

//Função do alarme
void alarme() { 
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledVerde, LOW); // Led verde é desligado
    tone(buzzer, 1350); // Tom da buzina
    delay(150);
    tone(buzzer, 1050); // Tom da buzina
    delay(150);
    digitalWrite(ledVermelho, HIGH); // Led vermelho é ligado
    delay(150);
    digitalWrite(ledVermelho, LOW);
  }
  noTone(buzzer);
}
