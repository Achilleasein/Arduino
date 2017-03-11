#include <DHT.h> // Including libary to read DHT11

//initialize constant variables
#define DHTPIN 7 //to Vout tou sensora kataligei sto pin 7 tou arduino
#define DHTTYPE DHT11
#define LED_TOO_COLD A0 //to kokkino led kataligei sto pin A0 tou arduino
#define LED_PERFECT A1 //to kitrino led kataligei sto pin A1 tou arduino
#define LED_TOO_HOT A2 //to prasino led kataligei sto pin A3 tou arduino

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600); // Opening serial connection at 9600bps

  dht.begin();
} //end "setup()"

void loop()
{
//Start of Program
  pinMode (A0 , OUTPUT); // Sets the pins as output for LED
  pinMode (A1 , OUTPUT);
  pinMode (A2 , OUTPUT);
  delay(2000);  //Wait 2 seconds before accessing sensor again.

  //orizoume ta h,t,f
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
 
  
  //Entoles gia to keimeno pou tha emfanizete analoga me to h kai to t
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
 
// Setting the colours of LED based on temperature
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
  if (t >= 27) {
    Serial.println("Too hot!");
    digitalWrite(A2, HIGH);
    delay (1000);
    digitalWrite(A2, LOW);
  } 
 } // end loop()
