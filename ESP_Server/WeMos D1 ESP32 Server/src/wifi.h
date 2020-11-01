#include <WiFi.h>

#define WIFI_SUCCESS 1
#define WIFI_FAILED 2

class Wifi_Station {
private:
    String networkName;
    String password;
    IPAddress localIP;
    int    limitConnectTime;
public:
    Wifi_Station();

    Wifi_Station(String _networkName, String _password);

    ~Wifi_Station();

    int connectWifi();
    
    int disconnectWifi();
    
    String getLocalIP();

    void setLimitTime(int _limitConnectTime);
};
