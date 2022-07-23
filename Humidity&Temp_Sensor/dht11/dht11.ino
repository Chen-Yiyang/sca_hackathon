#include "dht.h"


#define dht_apin A0 // Analog Pin sensor is connected to
#define fan_pin A1 //Fan pin is connected to 
dht DHT;

void setup(){
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);
  pinMode(fan_pin, OUTPUT);
  digitalWrite(fan_pin,LOW);
}
 
void loop(){
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(1000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.

    if(DHT.temperature < 26) {
      digitalWrite(fan_pin, HIGH);
    } else{
      digitalWrite(fan_pin, LOW);
    }
 
}
