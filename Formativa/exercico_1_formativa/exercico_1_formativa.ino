// Definição dos pinos
const int sensorPIRPin = 2;  // Pino digital para o sensor PIR
const int ledPin = 13;       // Pino digital para o LED
int contadorPessoas = 0;     // Variável para armazenar o número de pessoas

void setup() {
  pinMode(sensorPIRPin, INPUT);  // Configura o pino do sensor PIR como entrada
  pinMode(ledPin, OUTPUT);       // Configura o pino do LED como saída
  Serial.begin(9600);            // Inicializa a comunicação serial
}

void loop() {
  int estadoPIR = digitalRead(sensorPIRPin);  // Lê o estado do sensor PIR

  if (estadoPIR == HIGH) {   // Se o sensor PIR detectar movimento
    contadorPessoas++;       // Incrementa a contagem de pessoas
    digitalWrite(ledPin, HIGH); // Acende o LED para indicar movimento
    delay(500);              // Aguarda meio segundo para evitar múltiplas contagens rápidas

    Serial.print("Pessoas detectadas: ");
    Serial.println(contadorPessoas);  // Exibe a contagem de pessoas no Monitor Serial
  } else {
    digitalWrite(ledPin, LOW); // Apaga o LED se não houver movimento
  }
}

