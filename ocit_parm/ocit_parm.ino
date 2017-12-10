#include "cactus_io_DHT22.h"

#define DHT22_1 7
#define DHT22_2 10
#define DHT22_3 9



String input = "";
String id = "OC2";



void setup() {
  Serial.begin(9600);
}

void loop() {

  input = Serial.readString();
  delay(1000);

  if (input != "") {
    delay(1000);
    if (input == "who") {
    Serial.print(id);
    }
    if (input == "check") {
      DHT22 dht1(DHT22_1);

      dht1.readHumidity();
      dht1.readTemperature();
      if (isnan(dht1.humidity) || isnan(dht1.temperature_C)) {
        Serial.print("&t1:99#r1:99");
      }
      else {
        Serial.print("&t1:");
        Serial.print(dht1.temperature_C);
        Serial.print("#r1:");
        Serial.print(dht1.humidity);
      }
      DHT22 dht2(DHT22_2);
      dht2.readHumidity();
      dht2.readTemperature();
      if (isnan(dht2.humidity) || isnan(dht2.temperature_C)) {
        Serial.print("#t2:99#r2:99");
      }
      else {
        Serial.print("#t2:");
        Serial.print(dht2.temperature_C);
        Serial.print("#r2:");
        Serial.print(dht2.humidity);
      }


      DHT22 dht3(DHT22_3);
      dht3.readHumidity();
      dht3.readTemperature();


      if (isnan(dht3.humidity) || isnan(dht3.temperature_C)) {
        Serial.print("#t3:99#r3:99");
      }
      else {
        Serial.print("#t3:");
        Serial.print(dht3.temperature_C);
        Serial.print("#r3:");
        Serial.print(dht3.humidity);
      }
    }

  }

  Serial.flush();
}


