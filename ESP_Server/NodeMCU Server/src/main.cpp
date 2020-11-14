#include <Arduino.h>
#include "wifi.h"
#include <ESP8266WebServer.h>
Wifi_Station wifiClient;
ESP8266WebServer server(5000);

void handle() {
  server.send(200, "text/plain", "<!DOCTYPE html><html><head><style></style></head><body>A</body></html>");
}
void setup() {
  Serial.begin(9600);
  delay(5000);
  wifiClient = Wifi_Station("Mindi", "huantuyendieuminhanh");
  wifiClient.setLimitTime(20);
  wifiClient.connectWifi();
  server.on("/", handle);
  server.begin();
}
int a = 0;
void loop() {
  server.handleClient();
}