#include "server.h"
// #include <ESPAsyncWebServer.h>
// #include <AsyncTCP.h>

Asynchronous_Server::Asynchronous_Server() {
    this->server = new AsyncWebServer(80);
}

Asynchronous_Server::Asynchronous_Server(uint16_t _port) {
    this->server = new AsyncWebServer(_port);
}

void Asynchronous_Server::startServer() {
    server->begin();
    Serial.println("ESP Server Started");
}

AsyncCallbackWebHandler& Asynchronous_Server::registerGET(const char* _uri, handler _handler) {
    Serial.print("GET Function Registered on URI: ");
    Serial.println(_uri);

    this->mapHandler[URLMethod{_uri, "GET"}] = _handler;
    this->currentURI = (char*)_uri;
    

    server->on(_uri, HTTP_GET, [&](AsyncWebServerRequest *request){
        checkGETArgs(request);
        
        RespondPacket respond = this->mapHandler[URLMethod{this->currentURI, "GET"}](request);
        request->send(respond.code, respond.contentType, respond.content);
});}