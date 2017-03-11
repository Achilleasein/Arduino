#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 4
#define pirPin  7

unsigned long current = millis();
unsigned long previous_pir = millis();
unsigned long previous_humtem = millis();
unsigned long diff;

long lastSend = 0;
 
void setup()
{
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  Serial.println("DHT11 Humidity and Temperature Digital Sensor test sketch");
}

  void motion(){
          Serial.println("MOVEMENT");
            }
    


  void requestEvent(){

    Serial.print("Sensor status: ");

    Serial.print("Humidity (%): ");
    Serial.println(DHT11.humidity, DEC);

    Serial.print("Temperature (C): ");
    Serial.println(DHT11.temperature, DEC);   
    }

 
void loop()
{
   int pirVal = digitalRead(pirPin); 
   current = millis();
   diff =  current - previous_pir;
  if(pirVal == HIGH && diff >= 14000){
    previous_pir = millis();
    motion();
  }

  current = millis();
  diff =  current - previous_humtem;
  
  if(diff >= 120000){
    previous_humtem = millis();
  }

}




