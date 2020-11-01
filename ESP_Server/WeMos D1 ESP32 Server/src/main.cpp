#include <Arduino.h>
#include "wifi.h"

Wifi_Station wifiClient;

void setup() {
  Serial.begin(9600);
  delay(5000);
  wifiClient = Wifi_Station("Mindi", "huantuyendieuminhanh");
  wifiClient.setLimitTime(20);
  wifiClient.connectWifi();
}
int a = 0;
void loop() {
  // a++;
  delay(500);
  if (a == 30) wifiClient.disconnectWifi();
}