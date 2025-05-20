#include <LiquidCrystal.h>
#include <Servo.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int lightPin = A0;
const int moisturePin = A1;

const int ledStripPin = 6;
const int servoPin = 8;
const int fanPin = 10;
const int rezistenta = 13;

const int pragUscat = 600;
const int pragLumina = 300;
const unsigned long durataDeschidere = 5000;
const unsigned long durataFanFaraTemp = 5000;
const unsigned long pauzaRobinet = 900000;

Servo robinet;

bool robinetDeschis = false;
bool robinetInPauza = false;
bool fanOn = false;
bool fanOnRobinet = false;
unsigned long momentDeschidere = 0;
unsigned long momentInchidere = 0;

void setup() {
  lcd.begin(16, 2);
  robinet.attach(servoPin);
  robinet.write(180);  // Închis

  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, 0);

  pinMode(ledStripPin, OUTPUT);
  digitalWrite(ledStripPin, LOW);

  pinMode(rezistenta, OUTPUT);
  digitalWrite(rezistenta, LOW);

  dht.begin();

  lcd.print("Init. sistem...");
  delay(1000);
  lcd.clear();
}

void loop() {
  unsigned long acum = millis();

  int umiditate = analogRead(moisturePin);
  int lumina = analogRead(lightPin);
  float temperatura = dht.readTemperature();

  // Lumina - control LED strip
  if (lumina > pragLumina) {
    digitalWrite(ledStripPin, HIGH); // aprinde
  } else {
    digitalWrite(ledStripPin, LOW);  // stinge
  }

  // Temperatura - control fan
  if (temperatura > 30 && fanOnRobinet == false)
  {
    analogWrite(fanPin, 255);

    fanOn = true;
  }
  else if (temperatura > 25) {
    analogWrite(fanPin, 180);  // pornește ventilator
    fanOn = true;

  } else if (temperatura < 20) {
    analogWrite(fanPin, 100);
    digitalWrite(rezistenta, HIGH);
  }
  else {
    analogWrite(fanPin, 0);    // oprește ventilator
    fanOn = false;
    digitalWrite(rezistenta, LOW);

  }

  // Umiditate - control robinet
  // umiditate mare, mai uscat
  if (umiditate > pragUscat && !robinetDeschis && !robinetInPauza) {
    robinet.write(150); // Deschide robinetul
    robinetDeschis = true;
    momentDeschidere = acum;
    if (fanOn == true)
    {
      analogWrite(fanPin, 0); // Fan oprit
      fanOnRobinet = true;
    }

  }

  if (robinetDeschis && acum - momentDeschidere >= durataDeschidere) {
    robinet.write(180); // Închide robinetul
    robinetDeschis = false;
    robinetInPauza = true;
    momentInchidere = acum;
    if (fanOn == true)
    {
      fanOnRobinet = false;
    }

  }

  if (robinetInPauza && acum - momentInchidere >= pauzaRobinet) {
    robinetInPauza = false;
  }

  // LCD - afișare
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.print((char)223); // simbol grade
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("U:");
  lcd.print(umiditate);
  lcd.print(" L:");
  lcd.print(lumina);

  delay(1000);
}
