```
#define TRIG 9
#define ECHO 10
#define BUZZER 6

long duracao;
float distancia;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

float medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duracao = pulseIn(ECHO, HIGH);

  distancia = duracao * 0.034 / 2;
  return distancia;
}

void loop() {

  float d = medirDistancia();
  Serial.println(d);

  // LONGE → bip fraco e lento
  if (d > 100) {
    tone(BUZZER, 400);
    delay(80);
    noTone(BUZZER);
    delay(1200);
  }

  // MÉDIO → bip médio
  else if (d > 50 && d <= 100) {
    tone(BUZZER, 900);
    delay(120);
    noTone(BUZZER);
    delay(600);
  }

  // PERTO → bip forte e rápido
  else if (d <= 50) {
    tone(BUZZER, 1500);
    delay(200);
    noTone(BUZZER);
    delay(150);
  }
}
