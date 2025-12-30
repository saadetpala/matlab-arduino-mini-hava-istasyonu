#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();

  Serial.begin(9600);   // MATLAB icin

  lcd.setCursor(0, 0);
  lcd.print("DHT11 Basladi");
  delay(1500);
  lcd.clear();
}

void loop() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();

  if (isnan(nem) || isnan(sicaklik)) {
    return;
  }

  // MATLAB'a giden veri
  Serial.print(sicaklik);
  Serial.print(",");
  Serial.println(nem);

  // LCD
  lcd.setCursor(0, 0);
  lcd.print("Sic: ");
  lcd.print(sicaklik);
  lcd.print(" C   ");

  lcd.setCursor(0, 1);
  lcd.print("Nem: ");
  lcd.print(nem);
  lcd.print(" %   ");

  delay(2000);
}
