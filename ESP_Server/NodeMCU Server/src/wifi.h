#include <ESP8266WiFi.h>

#define WIFI_SUCCESS 1
#define WIFI_FAILED 2

class Wifi_Station {
private:
    String      networkName;
    String      password;
    IPAddress   localIP;
    uint8_t     limitConnectTime;
public:
    Wifi_Station();

    Wifi_Station(String _networkName, String _password);

    ~Wifi_Station();

    int connectWifi();
    
    int disconnectWifi();

    void createServer(uint8_t port);
    
    IPAddress getLocalIP();

    void setLimitTime(uint8_t _limitConnectTime);
};
