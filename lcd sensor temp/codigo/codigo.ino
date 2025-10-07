// Biblioteca do DHT
#include "DHT.h"
// Biblioteca do LCD
#include <LiquidCrystal.h>

// Pinos do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Porta e tipo do sensor DHT
#define DHTPIN 7       // Defina a porta do sensor (ajuste conforme seu circuito)
#define DHTTYPE DHT11  // Tipo do sensor

DHT dht(DHTPIN, DHTTYPE);

// Variável para armazenar temperatura
float temperatura;

void setup() {
  Serial.begin(9600);   // Inicializa monitor serial
  dht.begin();          // Inicializa o sensor
  lcd.begin(16, 2);     // Inicializa o LCD 16x2
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000); // Aguarda dois segundos entre as leituras

  temperatura = dht.readTemperature(); // Lê temperatura em Celsius

  // Verifica se a leitura falhou
  if (isnan(temperatura)) {
    Serial.println("ERRO NO SENSOR!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ERRO NO SENSOR!");
  } else {
    Serial.print("Temp: ");
    Serial.print(temperatura);
    Serial.println(" C");

    // Exibe no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura:");
    lcd.setCursor(0, 1);
    lcd.print(temperatura);
    lcd.print(" C");
  }
}
