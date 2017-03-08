#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define LED_TOO_COLD A0
#define LED_PERFECT A1
#define LED_TOO_HOT A2

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);

  dht.begin();
}

void loop()
{
  pinMode (A0 , OUTPUT);
  pinMode (A1 , OUTPUT);
  pinMode (A2 , OUTPUT);
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  if (t <= 20) {
    Serial.println("Too cold!");
    digitalWrite(A0, HIGH);
    delay (1000);
    digitalWrite(A0, LOW);
  }
  if (20 < t < 27) {
    Serial.println("Perfect temperature!");
    digitalWrite(A1, HIGH);
    delay (2000);
    digitalWrite(A1, LOW);
  }
  if (t >= 29) {
    Serial.println("Too hot!");
    digitalWrite(A2, HIGH);
    delay (1000);
    digitalWrite(A2, LOW);
  } 
 }
