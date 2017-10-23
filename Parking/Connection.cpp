#include "Connection.h"

/* Constructor */
Connection::Connection(ESP8266 *wifi, int mode, String SSID, String PWD, bool MUX, int HOST_PORT) {
    this->wifi = wifi;
    this->mode = mode;
    this->SSID = SSID;
    this->PWD = PWD;
    this->MUX = MUX;
    this->HOST_PORT=(HOST_PORT);
}

/* Connection functions */
void Connection::start() {
    Serial.print("ESP8266 firmware version: ");
    Serial.println(this->wifi->getVersion());

    setMode();
    join();
    enableMux();
    startServerTCP();
}

void Connection::setMode() {
    if (this->wifi->setOprToStationSoftAP())
        Serial.println("Station + AP mode enabled.");
    else
        Serial.println("Mode setting failed.");
}

void Connection::join() {
    if (this->wifi->joinAP(this->SSID, this->PWD)) {
        Serial.print("Join AP success\r\n");
        Serial.print("IP: ");
        Serial.println(this->wifi->getLocalIP().c_str());
    } else {
        Serial.print("Join AP failure\r\n");
    }
}

void Connection::enableMux() {
    if (this->wifi->enableMUX())
        Serial.println("Multiple connections setting enabled.");
    else
        Serial.println("Multiple connections setting failed.");
}

void Connection::startServerTCP() {
    if (this->wifi->startTCPServer(this->HOST_PORT))
        Serial.println("Started TCP Server successfully.");
    else
        Serial.println("Started TCP Server with error.");
}

