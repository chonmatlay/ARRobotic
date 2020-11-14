#include <Arduino.h>
#include "wifi.h"
#include "server.h"

Wifi_Station wifiClient;
Asynchronous_Server *server;

RespondPacket Handler(AsyncWebServerRequest *request) {
  return RespondPacket{200, "text/plain", "Hello Worlddddddddddddddddddddddd"};
}

handler a = &Handler;

void setup() {
  Serial.begin(9600);
  delay(5000);
  // wifiClient = Wifi_Station("Mindi", "huantuyendieuminhanh");
  wifiClient = Wifi_Station("The Library Coffee L2", "22446688");
  wifiClient.setLimitTime(20);
  wifiClient.connectWifi();
  server = new Asynchronous_Server(5000);
  server->registerGET("/home", a);
  server->startServer();
}

void loop() {
  // a++;
  // delay(500);
  // if (a == 30) wifiClient.disconnectWifi();
}