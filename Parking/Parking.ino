#include "Connection.h"

ESP8266 wifi(Serial1);
Connection *connection = new Connection(&wifi, 0, "dlink-4", "abcd1234", true, 8080);

void setup(void) {
    Serial.begin(9600);
    Serial1.begin(9600);

    connection->start();
}

void loop(void) {
    uint8_t buffer[128] = {0};
    uint8_t mux_id;
    uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);

    if (len > 0) {
        // Serial.print("Status:[");
        // Serial.print(wifi.getIPStatus().c_str());
        // Serial.println("]");

        Serial.print("Received from :");
        Serial.print(mux_id);
        // Serial.print("[");
        for(uint32_t i = 0; i < 3; i++) {
            Serial.print((char)buffer[i]);
        }
        // Serial.print("]\r\n");

        if(wifi.send(mux_id, buffer, len)) {
            Serial.print("send back ok\r\n");
        } else {
            Serial.print("send back err\r\n");
        }

        if (wifi.releaseTCP(mux_id)) {
            Serial.print("release tcp ");
            Serial.print(mux_id);
            Serial.println(" ok");
        } else {
            Serial.print("release tcp");
            Serial.print(mux_id);
            Serial.println(" err");
        }

        Serial.print("Status:[");
        Serial.print(wifi.getIPStatus().c_str());
        Serial.println("]");
    }
}
