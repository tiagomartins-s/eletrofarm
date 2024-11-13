#include <DHT.h>
#define DHTPIN 23            // Pino do DHT22
#define DHTTYPE DHT22        // Tipo de sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

// Configuração do Sensor Ultrassônico HC-SR04
#define TRIG_PIN 22          // Pino Trigger
#define ECHO_PIN 21          // Pino Echo

// Configuração do Sensor PIR
#define PIR_PIN 15           // Pino do PIR

// Configuração do Sensor LDR
#define LDR_PIN 34           // Pino do LDR (analógico)

void setup() {
    Serial.begin(115200);
    dht.begin();
    
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(PIR_PIN, INPUT);
}

void loop() {
    // Leitura do sensor DHT22
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.print("°C, Umidade: ");
    Serial.print(humidity);
    Serial.println("%");

    // Regra para ativação da irrigação baseada em temperatura e umidade
    if (temperature > 50 && humidity < 50) {
        Serial.println("Condições extremas de umidade e temperatura detectadas! Irrigação ativada.");
    }

    // Leitura do sensor ultrassônico
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.0343) / 2; // Distância em cm
    Serial.print("Distância (reservatório): ");
    Serial.print(distance);
    Serial.println(" cm");

    // Regra para ativação da irrigação baseada na distância do reservatório
    if (distance > 100) {
        Serial.println("Nível de água baixo! Solicitada reposição de água.");
    }

    // Leitura do sensor PIR
    int motion_detected = digitalRead(PIR_PIN);
    if (motion_detected) {
        Serial.println("Movimento detectado! Sistema de alerta ativado.");
    } else {
        Serial.println("Nenhum movimento detectado.");
    }

    // Leitura do sensor LDR
    int light_level = analogRead(LDR_PIN);
    Serial.print("Nível de luminosidade: ");
    Serial.println(light_level);

    // Regra para ativação da irrigação baseada na luminosidade
    if (light_level > 100) {  // Somente ativa a irrigação se a luminosidade for superior a 100 lux
        Serial.println("Luminosidade acima de 100 lux! Irrigação ativada.");
    }

    // Delay para próxima leitura
    delay(2000);
}
