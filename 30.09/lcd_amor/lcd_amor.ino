#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7 (ajuste conforme seus pinos)
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  // --- Primeira frase ---
  String msg1 = "Oi amor!";
  lcd.clear();
  centralizarTexto(msg1, 0);  // linha 0 (primeira linha)
  delay(2000);

  // --- Segunda frase ---
  String msg2 = "Eu te amo!";
  lcd.clear();
  centralizarTexto(msg2, 1);  // linha 1 (segunda linha)
  delay(2000);
}

// Função que escreve centralizado e letra por letra
void centralizarTexto(String msg, int linha) {
  int inicio = (16 - msg.length()) / 2;  // posição inicial p/ centralizar
  for (int i = 0; i < msg.length(); i++) {
    lcd.setCursor(inicio + i, linha);   // vai colocando letra por letra
    lcd.print(msg[i]);
    delay(250); // velocidade do "efeito de digitação"
  }
}
