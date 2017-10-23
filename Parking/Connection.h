#ifndef CONNECTION_H
#define CONNECTION_H

// Biblioteca utilizada para definir métodos de comunicação.

#include <string.h>
#include "ESP8266.h"

class Connection {
    private:
        ESP8266 *wifi;
        String SSID = "dlink-4";
        String PWD = "abcde1234";
        int HOST_PORT = (8080);
        int mode;
        bool MUX;

    public:
        Connection(ESP8266 *wifi, int mode, String SSID, String PWD, bool MUX, int HOST_PORT);
        void start();
        void setMode();
        void join();
        void enableMux();
        void startServerTCP();
};

#endif




