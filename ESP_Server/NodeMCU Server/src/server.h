#include <WiFiServer.h>


class Server {
private:
    WiFiServer  server;
    void*       handler;
public:
    Server(uint8_t _port);

    ~Server();

    void registerHandler(void* _handler);

    
};