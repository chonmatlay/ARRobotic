#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include "checker.h"
#include <unordered_map>

typedef struct Packet {
    int code;
    const char *contentType;
    const char *content;
} RespondPacket;

struct URLMethod {
    const char *url;
    const char *method;

    URLMethod(const char *_url, const char *_method) {
        this->url = _url;
        this->method = _method;
    }

    bool operator==(const URLMethod &other) const {
        return (std::strcmp(url, other.url) || std::strcmp(method, other.method)) == 0;
    }
};

struct hashFunction {
    std::size_t operator() (const URLMethod &urlmethod) const {
        std::size_t h1 = std::hash<const char*>() (urlmethod.url);
        std::size_t h2 = std::hash<const char*>() (urlmethod.method);

        return h1 ^ h2;    
    }
};

typedef RespondPacket (*handler)(AsyncWebServerRequest*);

class Asynchronous_Server {
private:
    AsyncWebServer *server;
    std::unordered_map<URLMethod, handler, hashFunction> mapHandler;
    char* currentURI;
public:
    Asynchronous_Server();
    
    Asynchronous_Server(uint16_t _port);

    ~Asynchronous_Server();

    void startServer();

    AsyncCallbackWebHandler& registerGET(const char* _uri, handler _handler);

    AsyncCallbackWebHandler& registerPOST(const char* _uri, handler _handler);

};


