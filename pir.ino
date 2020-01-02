#include <MyWifiSettings.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define DEVICE_ID "PIR_TEST"
#define NB_TRYWIFI    10

void setup(void){
  Serial.begin(115200);
  WiFi.begin(MYWIFISSID, MYWIFIPASSWORD);

  Serial.println("Connecting to WiFi.");
  int _try = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    _try++;
    if ( _try >= NB_TRYWIFI ) {
        Serial.println("Impossible to connect WiFi network, go to deep sleep");
        ESP.deepSleep(0);
    }
  }
  Serial.println("Connected to the WiFi network");

  callMiddleware("pir", "");

  ESP.deepSleep(0);
}

void loop(void){}

