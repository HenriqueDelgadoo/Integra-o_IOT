#include <LiquidCrystal.h>

// Pinos do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// LEDs
int ledVermelho = 8;
int ledAmarelo  = 9;
int ledVerde    = 10;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  // Define pinos como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // --- LED Vermelho ---
  digitalWrite(ledVermelho, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED VERMELHO");
  lcd.setCursor(0, 1);
  lcd.print("Ligado!");
  delay(4000);
  digitalWrite(ledVermelho, LOW);

  // --- LED Amarelo ---
  digitalWrite(ledAmarelo, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED AMARELO");
  lcd.setCursor(0, 1);
  lcd.print("Ligado!");
  delay(4000);
  digitalWrite(ledAmarelo, LOW);

  // --- LED Verde ---
  digitalWrite(ledVerde, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED VERDE");
  lcd.setCursor(0, 1);
  lcd.print("Ligado!");
  delay(4000);
  digitalWrite(ledVerde, LOW);
}
