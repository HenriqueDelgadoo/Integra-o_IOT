// Pinos
const int sensorPin = A0;
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorPin);
  float temperatura = (leitura * 5.0 * 100.0) / 1024.0; // Conversão para °C

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Controle dos LEDs
  if (temperatura < 26.0) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (temperatura >= 26.0 && temperatura <= 30.0) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  delay(1000); // Atualiza a cada 1 segundo
}
