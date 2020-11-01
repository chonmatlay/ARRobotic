#include "wifi.h"

Wifi_Station::Wifi_Station() {
    this->networkName = "";
    this->password = "";
    this->limitConnectTime = 20;
}

Wifi_Station::Wifi_Station(String _networkName, String _password) {
    this->networkName = _networkName;
    this->password = _password;
    this->limitConnectTime = 20;
}

Wifi_Station::~Wifi_Station() {};

int Wifi_Station::connectWifi() {
    WiFi.begin(this->networkName.c_str(), this->password.c_str());
    Serial.printf("Connecting to %s", (this->networkName).c_str());

    int maximum_connect = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        maximum_connect++;
        if (maximum_connect >= this->limitConnectTime) {
            Serial.println("Maximum Connection Time Reached! Connection Failed");
            return WIFI_FAILED;
        }
    }
    
    this->localIP = WiFi.localIP();
    Serial.println();
    Serial.print("Connected, local IP: ");
    Serial.print(this->localIP);
};
    
int Wifi_Station::disconnectWifi() {
    WiFi.disconnect();
    Serial.printf("Disconnecting from %s", (this->networkName).c_str());
    while (WiFi.status() != WL_DISCONNECTED) {
        Serial.print(".");
        break;
    }

    Serial.println();
    Serial.printf("Disconnected from %s \n", this->networkName.c_str());
    return 1;
};
    
    // String getLocalIP();

void Wifi_Station::setLimitTime(int _limitConnectTime) {
    this->limitConnectTime = _limitConnectTime;
};